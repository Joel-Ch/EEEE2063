#include "math.h"
#include "stdio.h"
#include <iostream>

//---------------------------------------------------------------------------
unsigned long int factorial(int n)
{
    unsigned long int v(1);
    for (int i = 2; i <= n; i++)
        v *= i;
    return (v);
}
//---------------------------------------------------------------------------
void get_next_route(const int permutation, const int no_objects, int *const route)
{
    // Each value of permutation is a different route in the range 0<= permutation < no_objects!
    for (unsigned int j = 0; j < no_objects; j++)
        route[j] = j;
    unsigned long int ft = 1;
    for (unsigned int j = 2; j <= no_objects; j++)
    {
        ft *= j - 1;
        int s = j - ((permutation / ft) % j);
        int tmp = route[s - 1];
        route[s - 1] = route[j - 1];
        route[j - 1] = tmp;
    }
}
//--------------------------------------------------------------------------

// function to calculate the distance between two points

// inputs are the x and y coordinates of the two points

// output is the distance between the two points

// required header file: math.h

// copyright Joel Chiappetti

double distanceBetweenLocations(double x1, double y1, double x2, double y2)
{
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

// function to calculate the total distance of a route

// inputs are the x and y coordinates of the possible locations, and the order in which they are visited

// output is the total distance of the route

// required header file: math.h

template <size_t N>
// allows it to work for any length of array
float totalDistanceOfRoute(float xCoordOfPossibleLocations[N], float yCoordOfPossibleLocations[N], int (&orderedLocationsVisitedOnThisRoute)[N])
{
    float totalDistance = 0;
    // start at zero
    for (size_t i = 0; i < N; i++)
    {
        int j = orderedLocationsVisitedOnThisRoute[i];
        int k = orderedLocationsVisitedOnThisRoute[i + 1];
        // define this point and the next point
        totalDistance += distanceBetweenLocations(xCoordOfPossibleLocations[j], yCoordOfPossibleLocations[j],
                                                  xCoordOfPossibleLocations[k], yCoordOfPossibleLocations[k]);
        // add the distance between the two points to the total distance
        // printf("\nGoing from %i to %i: Running Total: %f", j, k, totalDistance);
        // print the running total
    }

    return totalDistance;
}

// sample main for testing purposes

// int main()
// {
//     float xCoordsArray[10]        = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
//     float yCoordsArray[10]        = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
//     int orderedLocationsArray[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

//     float totalDistance = totalDistanceOfRoute(xCoordsArray, yCoordsArray, orderedLocationsArray);

//     printf("Total distance of route is %f\n", totalDistance);
// }

int main()
{
    float xCoordsArray[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    float yCoordsArray[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int orderedLocationsFromUser[4];

    printf("Please enter a sequence of locations: ");
    for (unsigned int i = 0; i < 5; i++)
    {
        scanf("%i", &orderedLocationsFromUser[i]);
        if (orderedLocationsFromUser[i] > 9 || orderedLocationsFromUser[i] < 0)
        {
            orderedLocationsFromUser[i] = 0;
        }
    }
    printf("Locations: ");
    for (size_t i = 0; i < 5; i++)
    {
        printf("%i ", orderedLocationsFromUser[i]);
    }

    float totalDistance = totalDistanceOfRoute(xCoordsArray, yCoordsArray, orderedLocationsFromUser);

    printf("\nTotal distance of route is %f\n", totalDistance);

    // Initialise an array route with N integer locations where N is the size of the route array
    for (size_t i = 0; i < N-1; i++)
    {
        get_next_route(i,N,route);
    }

    return 0;
}