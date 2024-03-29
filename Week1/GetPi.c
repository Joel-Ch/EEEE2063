#include "stdlib.h"
#include "stdio.h"
#include "math.h"
#include "time.h"

//-------------------------------------------------------------
// Function to evaluate pi to a given accuracy
//-------------------------------------------------------------

// Copyright Joel Chiappetti

// Input argument: The required accuracy defined so that the returned
//                 value is ESTIMATED to be pi +/- accuracy required

// Return value  : The estimate of pi

// Methodology: Monte Carlo Simulation

// Required header files: math.h for sqrt(), stdio.h for printf(), stdlib.h for rand()

// Warning: There is no check on whether the function can acheive a
//          very demanding accuracy, e.g. 10^(-99)

double get_pi(const double accuracy);

double get_pi(const double accuracy)
{
// Return estimate of pi within estimated error of +/- accuracy.

// Uses Monte Carlo simulation to estimate pi.

//    pi/4 = ratio of "hits" to "throws" in a Monte Carlo simulation

// Warning: There is no check on whether the function can achieve a
//          very demanding accuracy, e.g. 10^(-99) which may result
//          in becoming stuck in the loop. Possible upgrade.

// rudimentary error checking (unecessary but here anyway)
    if (accuracy <= 0)
    {
        printf("error: accuracy cannot be <= 0");
        exit(0);
    }


// declare variables

    int D = 0; // Total number of "throws"
    int N = 0; // Number of "hits"

// working variables
    float x, y; 
    double calculatedAccuracy;


// seed the random number generator
    srand (time(NULL));
//---------------------

    do
    {
        // generate random x \& y coordinates
        x = (float)(rand()%RAND_MAX)/(RAND_MAX/2) -1;
        y = (float)(rand()%RAND_MAX)/(RAND_MAX/2)-1;
        
        //check if within the circle
        if (sqrt(x*x+y*y) <= 1)
            N+=1;
            // increment the "number of darts in the circle (N)"

        // increment the "number of darts thrown (D)"
        D+=1;

        // calculate accuracy
        calculatedAccuracy = 4/((float)D+1);

        // printf("\nx=%10.7f, y=%10.7f, D=%7d, N=%7d, calculatedAccuracy=%7.7f, pi=%7.7f",x,y,D,N,calculatedAccuracy, 4* ((float)N / (float)D));

    // repeat while number of darts < 100 OR the accuracy estimate is too big
    } while ((D < 100) || (calculatedAccuracy >= accuracy));

    // since pi/4 = N/D
    // therefore pi = 4*(N/D)
    double pi = 4* ((float)N / (float)D);

    // return the calculated value of pi
    return (pi);
}

//-------------------------------------------------------------
//
// Main program to demonstrate the use of the get_pi function

// Copyright Phil Sewell

// Required header files: stdio.h (for printf), time.h ( for clock() etc)

//-------------------------------------------------------------
int main() {

// This code shows use of the get_pi function and assesses its
// ability to correctly function with a range of accuracy demands

      double accuraryRequired=1;

      for(accuraryRequired=1;accuraryRequired>1e-10;accuraryRequired/=10.){

            clock_t begin = clock(); // Time just the function all

            float estimateOfPi=get_pi(accuraryRequired);

            clock_t end = clock();

            double computationTime = (double)(end - begin)/CLOCKS_PER_SEC;

            printf("\nThe estimate of pi= %4.12f when the accuracy demand=%4.10f: Computation time=%3.4f seconds",

                   estimateOfPi,accuraryRequired,computationTime

                   );
      }

      return(0);
}