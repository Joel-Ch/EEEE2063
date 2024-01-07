/// Comment to examiners: This exam is online and hence students have
/// available the various module materials to cut/paste/modify - hence
/// not "excessive" typing
/// Sorry, the layout is not designed for word!
/// Part 1(20% in total)
//---------------------------------------------------------------------------
// Interface for a simple archaeological survey tool
// copyright, P Sewell 2021
// Required header files: stdio.h (for printf, scanf ...)
/// 5% For a suitable comments throughout
/// 5% for overall structure
/// 5% for implementational correctness
/// 5% for protecting against illegal entry
#include <stdio.h>
//---------------------------------------------------------------------------
int main()
{
    float surfaceResistances[8][8]; // A 2D grid with step 1m. Units Ohms
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
            surfaceResistances[i][j] = 0;
    }
    for (;;)
    {
        printf("\nEnter Option: 0) to enter new measurement, 1) to show all measurements, 2) To terminate\n ");
            int selectedOption;
        while (scanf("%d", &selectedOption) != 1 // fails if don't enter a legitimate integer 
            ||selectedOption < 0 // OR fails if illegal option
            ||selectedOption > 2)  {
            fflush(stdin); // The Illegal data entered needs to be "flushed out of the system"
            printf("\nIllegal option entered: Must be an integer in the range 0 to 2 - try again\n");
        }
        if (selectedOption == 0) { // Enter new value
            printf("\nEnter grid indices, i,j each in the range 0-7, and then the surface resistance\n");
            int i, j;
            while (scanf("%d", &i) != 1  // fails if don't enter a legitimate integer
                   || selectedOption < 0 // OR fails if illegal option
                   || selectedOption > 7)
            {
                fflush(stdin); // The Illegal data entered needs to be "flushed out of the system"
                printf("\nIllegal i entered: Must be an integer in the range 0 to 7 - try again\n");
            }
            while (scanf("%d", &j) != 1  // fails if don't enter a legitimate integer
                   || selectedOption < 0 // OR fails if illegal option
                   || selectedOption > 7)
            {
                fflush(stdin); // The Illegal data entered needs to be "flushed out of the system"
                printf("\nIllegal j entered: Must be an integer in the range 0 to 7 - try again\n");
            }
            while (scanf("%f", &surfaceResistances[i][j]) != 1)
            { // fails if don't enter a legitimate integer
                    fflush(stdin); // The Illegal data entered needs to be "flushed out of the system"
                    printf("\nIllegal surface resistance entered: Must be an float value\n");
            }
        }
        else if (selectedOption == 1)
        { // Show data
            for (int i = 0; i < 8; i++)
            {
                printf("\n");
                for (int j = 0; j < 8; j++)
                    printf("%1.1f ", surfaceResistances[i][j]);
            }
        }
        else
        {
            break;
        }
    }
    return (0);
}
//---------------------------------------------------------------------------
/// Part 2(20% in total)
//---------------------------------------------------------------------------
// A simple C code to demonstrate C user interactions and memory management.
// P Sewell, 2021.
#include <iostream> // Required for cin & cout
#include <limits>   // Required for error testing
/// Correct use of cin 5%
/// Correct use of cout 5%
/// Correct use of new and delete[] 5%
/// Correct use of cin.fail 5% - this was given in a case study!
using namespace std; // Required for cin & cout
int main()
{
    int n;
    cout << "\nPlease enter the size of the array\n";
    // cin>>n; // For Alternative
    while (cin >> n, cin.fail())
    { // For Alternative while(cin.fail()){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        printf("Illegal value\n");
        // cin>>n; // For Alternative
    }
    double *d = new double[n];
    // some code that uses d;
    cout << "\nCompleted allocation of " << n * sizeof(double) << " bytes";
    delete[] d;
}
//---------------------------------------------------------------------------
/// Part 3(30% in total)
//---------------------------------------------------------------------------
class lightBulb; /// 5%
//---------------------------------------------------------------------------
class lightBulb
{ /// 10%
public:
    float voltageRating;  // Volts
    float maximumumPower; // Watts
    float currentDrawn();
};
//---------------------------------------------------------------------------
float lightBulb::currentDrawn()
{ /// 5%
    return (maximumumPower / voltageRating);
}
//---------------------------------------------------------------------------
// Simple test of basic lightBulb object
// P Sewell 2021
// A successful run gives "Total current=0.0416667"
#include <iostream> // Required for cout
//---------------------------------------------------------------------------
using namespace std; // Required for cout
int main()
{ /// 10%
    lightBulb bulbs[4];
    bulbs[0].voltageRating =
        bulbs[1].voltageRating =
            bulbs[2].voltageRating =
                bulbs[3].voltageRating = 240.;
    bulbs[0].maximumumPower = 1;
    bulbs[1].maximumumPower = 2;
    bulbs[2].maximumumPower = 3;
    bulbs[3].maximumumPower = 4;
    cout << "\nTotal current=" << bulbs[0].currentDrawn() + bulbs[1].currentDrawn() + bulbs[2].currentDrawn() + bulbs[3].currentDrawn();
    return (0);
}
//---------------------------------------------------------------------------
/// Part 4(30% in total)
//---------------------------------------------------------------------------
class lightBulb;
//---------------------------------------------------------------------------
class lightBulb
{
public:
    lightBulb(float _voltageRating, float _maximumumPower); /// 5% and for
    implementation below
    lightBulb(const lightBulb &L); /// 5% and for
    implementation below
        lightBulb &
        operator=(const lightBulb &L);                                         /// 5% and for
    implementation below ~lightBulb() {}                                       /// 5% and for
    implementation below float get_voltageRating() { return (voltageRating); } /// All gets and sets 5%
    float get_maximumumPower() { return (maximumumPower); }
    void set_voltageRating(float _voltageRating) { voltageRating = _voltageRating; }
    void set_maximumumPower(float _maximumumPower) { maximumumPower = _maximumumPower; }
    float currentDrawn();

private:                  /// 5%
    float voltageRating;  // Volts
    float maximumumPower; // Watts
};
//---------------------------------------------------------------------------
lightBulb::lightBulb(float _voltageRating, float _maximumumPower)
    : voltageRating(_voltageRating),
      maximumumPower(_maximumumPower) {}
//---------------------------------------------------------------------------
lightBulb::lightBulb(const lightBulb &L)
    : voltageRating(L.voltageRating),
      maximumumPower(L.maximumumPower) {}
//---------------------------------------------------------------------------
lightBulb &lightBulb::operator=(const lightBulb &L)
{
    if (this == &L)
        return (*this);
    voltageRating = L.voltageRating;
    maximumumPower = L.maximumumPower;
    return (*this);
}
//---------------------------------------------------------------------------
float lightBulb::currentDrawn()
{ /// 5%
    return (maximumumPower / voltageRating);
}
//---------------------------------------------------------------------------
// Simple test of basic lightBulb object
// P Sewell 2021
// A successful run gives "Total current=0.0416667"
#include <iostream> // Required for cout
//---------------------------------------------------------------------------
using namespace std; // Required for cout
int main()
{ /// 10%
    lightBulb A(240, 60);
    lightBulb B(A);
    A.set_voltageRating(120);
    B = A;
    return (0);
}
//---------------------------------------------------------------------------