#include "math.h"
#include "stdio.h"
#include "float.h"

//---------------------------------------------------------------------------
unsigned long int factorial(int n)
{
    unsigned long int v = 1;
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

float distanceBetweenLocations(float x1, float y1, float x2, float y2)
{
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

// --------------------------------------------------------------------------



// function to calculate the total distance of a route

// inputs are the x and y coordinates of the possible locations, and the order in which they are visited

// also calculates the distance from the "depot" (location 0) to the first point, and from the last point back to the "depot"

// output is the total distance of the route

// required header file: math.h

// NOTE: there is an additional input: the number of locations in the route

float totalDistanceOfRoute(float *xCoordOfPossibleLocations, float *yCoordOfPossibleLocations, int *orderedLocationsVisitedOnThisRoute, int numberOfLocations)
{
    // from the "depot" to the first point
    float totalDistance = distanceBetweenLocations(0, 0, xCoordOfPossibleLocations[orderedLocationsVisitedOnThisRoute[0]],
                                                         yCoordOfPossibleLocations[orderedLocationsVisitedOnThisRoute[0]]);


    for (int i = 0; i < numberOfLocations - 1; i++)
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



// sample main for testing purposes

// int main()
// {
//     float xCoordsArray[10]        = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
//     float yCoordsArray[10]        = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
//     int orderedLocationsArray[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
//     float totalDistance = totalDistanceOfRoute(xCoordsArray, yCoordsArray, orderedLocationsArray);
//     printf("Total distance of route is %f\n", totalDistance);
// }
// --------------------------------------------------------------------------

// --------------------------------------------------------------------------


// user input main for testing purposes
int main()
{
    float xCoordOfPossibleLocations[11] = {0, 9, 6, 7, 1, 21, 7, 11, 5, 9, 8};
    float yCoordOfPossibleLocations[11] = {0, 8, 8, 8, 1, 11, 11, 11, 5, 9, 1};
    int userRouteLength = 0;
    // print the coordinates of the possible locations
    for (int i = 0; i < 11; i++)
    {
        printf("Coordinates of location %2i: (%4.1f, %4.1f)\n", i, xCoordOfPossibleLocations[i], yCoordOfPossibleLocations[i]);
    }

    // get the number of locations in the route
    printf("Please enter the length of the route: (0-5) ");
    scanf("%i", &userRouteLength);
    if (userRouteLength > 5 || userRouteLength <= 0)
        userRouteLength = 5;

    int orderedLocationsFromUser[userRouteLength];

    // get the locations in the route
    printf("Please enter a sequence of locations: \n");
    for (unsigned int i = 0; i < userRouteLength; i++)
    {
        printf("Location %i: ", i+1);
        scanf("%i", &orderedLocationsFromUser[i]);
        if (orderedLocationsFromUser[i] > 9 || orderedLocationsFromUser[i] < 0)
        {
            orderedLocationsFromUser[i] = 0;
            // if input is not valid, set to zero
        }
    }


    float totalDistance = 0;
    float minDistance = FLT_MAX;
    int minRoute[userRouteLength];
    int RouteOrder[userRouteLength];
    int OrderedRoute[userRouteLength];
    // Initialise an array route with N integer locations where N is the size of the route array
    for (size_t i = 0; i < factorial(userRouteLength); i++)
    {
        get_next_route(i, userRouteLength, RouteOrder);

        for (size_t i = 0; i < userRouteLength; i++)
        {
            OrderedRoute[i] = orderedLocationsFromUser[RouteOrder[i]];
        }

        totalDistance = totalDistanceOfRoute(xCoordOfPossibleLocations, yCoordOfPossibleLocations, OrderedRoute, userRouteLength);

        // check if minimum
        if (totalDistance < minDistance)
        {
            minDistance = totalDistance;
            for (int j = 0; j < userRouteLength; j++)
            {
                minRoute[j] = OrderedRoute[j];
            }
        }
    }

    printf("The shortest possible distance to travel is %f which requires visiting in the order 0 ", minDistance);
    for (size_t i = 0; i < userRouteLength; i++)
    {
        printf("%i ", minRoute[i]);
    }
    printf("0\n");

    return 0;
}
// --------------------------------------------------------------------------