#include <iostream>
using namespace std;

float calculateMPG(int milesTravelled, float litresConsumed)
{
    if (litresConsumed == 0)
    {
        printf("Error: Litres consumed cannot be 0\n");
        exit(1);
    }

    float mpg = 4.55 * milesTravelled / litresConsumed;
    return mpg;
}

int main()
{
    // Declare variables
    unsigned int milesTravelled;
    float litresConsumed;
    float mpg;

    // Get miles driven
    cout << "Enter miles driven: ";
    cin >> milesTravelled;

    // Get gallons used
    cout << "Enter litres used: ";
    cin >> litresConsumed;

    // Calculate miles per gallon
    mpg = calculateMPG(milesTravelled, litresConsumed);

    // Display miles per gallon
    cout << "Miles per gallon: " << mpg << endl;

    return 0;
}