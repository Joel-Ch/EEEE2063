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

double distanceBetweenLocations(double x1, double y1, double x2, double y2)
{
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}
// --------------------------------------------------------------------------

// function to calculate the total distance of a route

// inputs are the x and y coordinates of the possible locations, and the order in which they are visited

// output is the total distance of the route

// required header file: math.h

float totalDistanceOfRoute(float *xCoordOfPossibleLocations, float *yCoordOfPossibleLocations, int *orderedLocationsVisitedOnThisRoute)
{
    float totalDistance = 0;
    // start at zero
    for (size_t i = 0; i < (sizeof(orderedLocationsVisitedOnThisRoute) / sizeof(orderedLocationsVisitedOnThisRoute[0]))-1; i++)
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

int main()
{
    float xCoordOfPossibleLocations[11]={0,9,6,7,1,21,7,11,5,9,8};
    float yCoordOfPossibleLocations[11]={0,8,8,8,1,11,11,11,5,9,1};
    int N;
    for (int i = 0; i <= 11; i++)
    {
        printf("Coordinates of location %2i: (%4.1f, %4.1f)\n", i, xCoordOfPossibleLocations[i], yCoordOfPossibleLocations[i]);
    }
    
    printf("Please enter the length of the route: (0-5) ");
    scanf("%i", &N);
    N+=1;

    int orderedLocationsFromUser[N];
    orderedLocationsFromUser[0] = 0;
    orderedLocationsFromUser[N] = 0;

    printf("Please enter a sequence of locations: \n");
    for (unsigned int i = 1; i < N; i++)
    {
        printf("Location %i: ", i);
        scanf("%i", &orderedLocationsFromUser[i]);
        if (orderedLocationsFromUser[i] > 9 || orderedLocationsFromUser[i] < 0)
        {
            orderedLocationsFromUser[i] = 0;
        }
    }
    printf("Locations: ");
    for (size_t i = 0; i <= N; i++)
    {
        printf("%i ", orderedLocationsFromUser[i]);
    }

    float totalDistance = totalDistanceOfRoute(xCoordOfPossibleLocations, yCoordOfPossibleLocations, orderedLocationsFromUser);

    printf("\nTotal distance of route is %f\n", totalDistance);

    float minDistance = FLT_MAX;
    int minRoute[N];
    // Initialise an array route with N integer locations where N is the size of the route array
    for (size_t i = 0; i < N; i++)
    {
        get_next_route(i, N-1, orderedLocationsFromUser);
        totalDistance = totalDistanceOfRoute(xCoordOfPossibleLocations, yCoordOfPossibleLocations, orderedLocationsFromUser);

        if (totalDistance < minDistance)
        {
            minDistance = totalDistance;
            for (int j = 0; j <= N; j++)
            {
                minRoute[j] = orderedLocationsFromUser[j];
            }
            
        }

    }

    printf("The shortest route is: ");
    for (size_t i = 0; i <= N; i++)
    {
        printf("%i ", minRoute[i]);
    }
    printf("\nTotal distance of route is %f\n", minDistance);

    return 0;
}
// --------------------------------------------------------------------------