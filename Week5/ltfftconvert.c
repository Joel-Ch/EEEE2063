

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>


int main( int argc, char *argv[] ) {
	FILE *flt, *fout;
	double freq, dB, phase;
	char line[1024], fname[1024];
	double maxf;
	double minf = -1.;
	double maxdB;
	int nline = 0.;
	int i;
	
	double writef, writedB, writep;
	double incm;
	
	if( argc < 2 ) {
		printf( "Drag file LTSpice .txt export file onto program to start processing..." );
		exit( 0 );
	}
	
	printf( "Trying to open %s for reading...", argv[1] );
	
	if( !(flt = fopen( argv[1], "r" )) ) {
		printf( "failed.\n" );
		exit( 0 );
	}
	
	printf( "done.\n" );
	
	while( fgets( line, 1024, flt ) ) {
		if( sscanf( line, "%lf\t(%lfdB,%lf", &freq, &dB, &phase ) == 3 ) {
			if( minf == -1. ) {
				minf = maxf = freq;
				maxdB = dB;
			} else {
				if( freq > maxf ) maxf = freq;
				if( freq < minf ) minf = freq;
				if( dB > maxdB ) maxdB = dB;
			}
		}
			
		nline++;
	}

	
	nline--;
	
	printf( "Min freq: %g, max freq %g, nfreq = %d, maxDB = %g\n", minf, maxf, nline, maxdB );
	
	fseek( flt, 0, SEEK_SET );
	
	strncpy( fname, argv[1], 1019 );
	
	strcpy( fname + strlen(fname) - 4, "_out.txt" );
	
	printf( "Trying to open %s for writing...", fname );
	
	if( !(fout = fopen( fname, "w" )) ) {
		printf( "failed.\n" );
		exit(0);
	}
	
	printf( "done.\n" );
	
	if( minf < 0.1 ) minf = 0.1;
	
	incm = pow( maxf/minf, 1./3000. );
	
	fgets( line, 1024, flt );
	
	writef = minf * incm;
	
	freq = 0.;
	
	printf( "Frequency increase factor: %g\n", incm );
	
	fprintf( fout, "Freq\tMagn\tMagn (dB)\tMagn(Norm)\tMagn(Norm dB)\tphase\n" );
	i = 0;
	while( i < nline ) {
		
		while( freq < writef && i < nline ) {
			if( !fgets( line, 1024, flt ) || sscanf( line, "%lf\t(%lfdB,%lf", &freq, &dB, &phase ) != 3 ) {
				fprintf( fout, "%g\t%g\t%g\t%g\t%g\t%g\n", freq, pow( 10., (dB)/20. ), dB, pow( 10., (dB-maxdB)/20. ), dB-maxdB, phase );
				fclose( flt );
				fclose( fout );
				system( "pause" );
				exit( 0 );
			}
			i++;
		}
		
		fprintf( fout, "%g\t%g\t%g\t%g\t%g\t%g\n", freq, pow( 10., (dB)/20. ), dB, pow( 10., (dB-maxdB)/20. ), dB-maxdB, phase );
		writef = freq;
		writef *= incm;
	}
		
	fclose( flt );
	fclose( fout );
	
	system( "pause" );
}
