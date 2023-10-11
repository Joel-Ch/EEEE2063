#include "math.h"
#include "stdio.h"


//function to calculate the distance between two points

// inputs are the x and y coordinates of the two points

// output is the distance between the two points

// required header file: math.h

// copyright Joel Chiappetti

double distanceBetweenLocations(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}


// function to calculate the total distance of a route

// inputs are the x and y coordinates of the possible locations, and the order in which they are visited

// output is the total distance of the route

// required header file: math.h

template <size_t N>
float totalDistanceOfRoute(float xCoordOfPossibleLocations[N], float yCoordOfPossibleLocations[N], int (&orderedLocationsVisitedOnThisRoute)[N])
{
    constexpr size_t arrSize = N;

    float totalDistance = 0;
    for (size_t i = 0; i < arrSize - 1; i++)
    {
        int j = orderedLocationsVisitedOnThisRoute[i];
        int k = orderedLocationsVisitedOnThisRoute[i + 1];
        totalDistance += distanceBetweenLocations(xCoordOfPossibleLocations[j], yCoordOfPossibleLocations[j], 
                                                  xCoordOfPossibleLocations[k], yCoordOfPossibleLocations[k]);
        printf("total on round %i : %f Coords:%f,%f\n", orderedLocationsVisitedOnThisRoute[i], totalDistance, xCoordOfPossibleLocations[j], yCoordOfPossibleLocations[j]);
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
    float xCoordsArray[10]        = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    float yCoordsArray[10]        = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int orderedLocationsArray[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    int newLocationOrdersArray[5] = {};

    for (size_t i = 0; i < sizeof(orderedLocationsArray)/sizeof(orderedLocationsArray[0]); i++)
    {
        printf("Location %i : (%f, %f)\n", orderedLocationsArray[i], xCoordsArray[i], yCoordsArray[i]);
    }

    bool exitVar = 0;
    do
    {
        size_t i = 0;
        int newLocation;
        scanf("Please enter location to visit: %i", &newLocation);
        
        if (newLocation > 10)
        {
            printf("error: value too high\n");
        }
        else if (newLocation> 0 && newLocation<10)
        {
            newLocationOrdersArray[i] = newLocation;
        }
        
        else if (newLocation == 0)
            exitVar = 1;
        

    } while (exitVar != 1);
    

    float totalDistance = totalDistanceOfRoute(xCoordsArray, yCoordsArray, newLocationOrdersArray);

    printf("Total distance of route is %f\n", totalDistance);
    
    return 0;
    
}