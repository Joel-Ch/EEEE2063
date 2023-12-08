#include <iostream>
using namespace std;
#include "Interval.h"

int main()
{
    interval x(3.0, 3.1); // Initialisation from complete data
    interval y(7);        // Sensible (?) initialisation from a single float
    interval a = x + y;
    interval b = x - y;
    interval c = x * y;
    interval d = x / y;
    interval p(x);
    p += a; // and as a professional you realise that this suggests you should also add?
    cout << d;
    cin >> a;
    float f(5.);
    interval g = a + f; // and as a professional you realise that this suggests you should also add?
    // A challenge for that final 1/50 mark – i.e. just to prove you can and beat the crowd
    interval h = f + a;
}