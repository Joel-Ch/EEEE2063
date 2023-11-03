#include "math.h"
#include "stdio.h"
#include "float.h"

//---------------------------------------------------------------------------

// function to calculate the factorial of a number

// input is the number

// output is the factorial of the number

// required header file: none

unsigned long int factorial(unsigned int n)
{
    unsigned long int v = 1;
    for (int i = 2; i <= n; i++)
        v *= i;
    return (v);
}
//---------------------------------------------------------------------------

// function to calculate the next route in the sequence

// inputs are the current permutation, the number of objects and a pointer to the route

// output is the next permutation

// required header file: none

// reference: https://en.wikipedia.org/wiki/Permutation#Generation_in_lexicographic_order

void get_next_route(const unsigned int permutation, const unsigned int no_objects, unsigned int *const route)
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

float distanceBetweenLocations(const float x1, const float y1, const float x2, const float y2)
{
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

// --------------------------------------------------------------------------

// function to calculate the total distance of a route

// inputs are the x and y coordinates of the possible locations, and the order in which they are visited

// also calculates the distance from the "depot" (location 0) to the first point, and from the last point back to the "depot"

// output is the total distance of the route

// required header file: math.h

// copyright Joel Chiappetti

// NOTE: there is an additional input: the number of locations in the route

float totalDistanceOfRoute(const float *xCoordOfPossibleLocations, const float *yCoordOfPossibleLocations, const unsigned int *orderedLocationsVisitedOnThisRoute, const unsigned int numberOfLocations)
{
    // from the "depot" to the first point
    float totalDistance = distanceBetweenLocations(0, 0, xCoordOfPossibleLocations[orderedLocationsVisitedOnThisRoute[0]],
                                                   yCoordOfPossibleLocations[orderedLocationsVisitedOnThisRoute[0]]);

    // from the first point to the second point, third point, etc.
    for (size_t i = 0; i < numberOfLocations - 1; i++)
    {
        int j = orderedLocationsVisitedOnThisRoute[i];
        int k = orderedLocationsVisitedOnThisRoute[i + 1];
        // define this point and the next point
        totalDistance += distanceBetweenLocations(xCoordOfPossibleLocations[j],
                                                  yCoordOfPossibleLocations[j],
                                                  xCoordOfPossibleLocations[k],
                                                  yCoordOfPossibleLocations[k]);
    }

    // add the distance back to the "depot"
    totalDistance += distanceBetweenLocations(xCoordOfPossibleLocations[orderedLocationsVisitedOnThisRoute[numberOfLocations - 1]],
                                              yCoordOfPossibleLocations[orderedLocationsVisitedOnThisRoute[numberOfLocations - 1]], 0, 0);

    return totalDistance;
}

// --------------------------------------------------------------------------

// function to calculate the minimum distance of a route

// inputs are the x and y coordinates of the possible locations, the locations that the user wants to visit, the number of locations in the route and a pointer to the minimum route

// output is the minimum distance of the route

// the function also saves the minimum route in the array pointed to by the pointer

// required header file: math.h

// copyright Joel Chiappetti

float GetMinimumRoute(const float *xCoordOfPossibleLocations, const float *yCoordOfPossibleLocations, unsigned const int *orderedLocationsFromUser, unsigned const int userRouteLength, unsigned int *minimumRoute)
{
    float minimumDistance = FLT_MAX;
    float totalDistance = 0;

    // array to store the permutated index
    unsigned int RouteOrder[userRouteLength];

    // array to store the ordered route
    unsigned int OrderedRoute[userRouteLength];

    // Initialise an array route with N integer locations where N is the size of the route array
    for (size_t i = 0; i < factorial(userRouteLength); i++)
    {
        // get the next route index
        get_next_route(i, userRouteLength, RouteOrder);

        // order the locations based on the new index
        for (size_t j = 0; j < userRouteLength; j++)
        {
            OrderedRoute[j] = orderedLocationsFromUser[RouteOrder[j]];
        }

        // calculate the total distance of the route
        totalDistance = totalDistanceOfRoute(xCoordOfPossibleLocations, yCoordOfPossibleLocations, OrderedRoute, userRouteLength);

        // check if minimum
        if (totalDistance < minimumDistance)
        {
            minimumDistance = totalDistance;
            for (size_t j = 0; j < userRouteLength; j++)
            {
                minimumRoute[j] = OrderedRoute[j];
            }
        }
    }
    return minimumDistance;
}

// sample main for testing purposes

// int main()
// {
//     float xCoordsArray[11]        = {0, 9, 6, 7, 1, 21, 7, 11, 5, 9, 8};
//     float yCoordsArray[11]        = {0, 8, 8, 8, 1, 11, 11, 11, 5, 9, 1};
//     int orderedLocationsArray[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
//     float totalDistance = totalDistanceOfRoute(xCoordsArray, yCoordsArray, orderedLocationsArray);
//     printf("Total distance of route is %f\n", totalDistance);
// }
// --------------------------------------------------------------------------

// user input main for testing purposes

// asks user for the number of locations in the route and the locations in the route

// Then calls the function GetMinimumRoute to calculate the minimum distance and the minimum route

// print the minimum distance and the route

int main()
{
    const float xCoordOfPossibleLocations[11] = {0, 9, 6, 7, 1, 21, 7, 11, 5, 9, 8};
    const float yCoordOfPossibleLocations[11] = {0, 8, 8, 8, 1, 11, 11, 11, 5, 9, 1};
    unsigned int userRouteLength = 0;
    // print the coordinates of the possible locations
    for (unsigned int i = 0; i < 11; i++)
    {
        printf("Coordinates of location %2i: (%4.1f, %4.1f)\n", i, xCoordOfPossibleLocations[i], yCoordOfPossibleLocations[i]);
    }

    // get the number of locations in the route
    printf("Please enter the length of the route: (1-5) ");
    scanf("%i", &userRouteLength);
    if (userRouteLength > 5 || userRouteLength <= 0)
        userRouteLength = 5;

    unsigned int orderedLocationsFromUser[userRouteLength];

    // get the locations in the route
    printf("Please enter a sequence of locations: \n");
    for (unsigned int i = 0; i < userRouteLength; i++)
    {
        printf("Location %i: ", i + 1);
        scanf("%i", &orderedLocationsFromUser[i]);
        if (orderedLocationsFromUser[i] > 10 || orderedLocationsFromUser[i] < 0)
        {
            orderedLocationsFromUser[i] = 0;
            // if input is not valid, set to zero
        }
    }

    // find minimum route and distance
    unsigned int minimumRoute[userRouteLength];
    float minimumDistance = GetMinimumRoute(xCoordOfPossibleLocations, yCoordOfPossibleLocations, orderedLocationsFromUser, userRouteLength, minimumRoute);

    // print the minimum distance and the route
    printf("The shortest possible distance to travel is %f which requires visiting in the order 0 ", minimumDistance);
    for (size_t i = 0; i < userRouteLength; i++)
    {
        printf("%i ", minimumRoute[i]);
    }
    printf("0\n");

    return 0;
}
// --------------------------------------------------------------------------