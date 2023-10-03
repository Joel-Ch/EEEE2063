#include <iostream>
using namespace std;
#include <math.h>
// Joel Chiappetti

// Functions to convert from polar to rectangular coordinates and vice versa.

//-----------------------------------------------------------------

// Input Polar Coordinates(r, theta), Output Rectangular Coordinates (x, y).
float PolarToRectangular(float r, float theta, float *x, float *y)
{
    *x = r * cos(theta);
    *y = r * sin(theta);
    return 0;
}

// Input Rectangular Coordinates (x, y), Output Polar Coordinates(r, theta).
float RectangularToPolar(float x, float y, float *r, float *theta)
{
    *r = sqrt(x * x + y * y);
    *theta = atan(y / x);
    return 0;
}

//-----------------------------------------------------------------
int main()
{
    // test case for PolarToRectangular
    float r, theta, x, y;
    cout << "Enter r: ";
    cin >> r;
    cout << "Enter theta: ";
    cin >> theta;
    PolarToRectangular(r, theta, &x, &y);
    cout << "x = " << x << " y = " << y << endl;

    // test case for RectangularToPolar
    float x2, y2, r2, theta2;
    cout << "Enter x: ";
    cin >> x2;
    cout << "Enter y: ";
    cin >> y2;
    RectangularToPolar(x2, y2, &r2, &theta2);
    cout << "r = " << r2 << " theta = " << theta2 << endl;

    return 0;
}