#include "math.h"
#include "stdio.h"
#include "float.h"


// --------------------------------------------------------------------------
// Function declarations \& descriptions
// --------------------------------------------------------------------------



/**
 * Function: factorial
 * -------------------
 * This function calculates the factorial of a number.
 *
 * Input:
 * - n: The number to calculate the factorial of.
 *
 * Output:
 * - The function returns the factorial of the input number.
 *
 * Example:
 * - If n = 5, the function returns 120.
 * 
 * Required header file:
 * - None
 */
unsigned long int factorial(unsigned int n);

/**
 * Function: get_next_route
 * ------------------------
 * This function calculates the next route in the sequence.
 *
 * Inputs:
 * - permutation: The current permutation.
 * - no_objects: The number of objects.
 * - route: A pointer to the route.
 *
 * Output:
 * - The function modifies the route to represent the next permutation.
 *
 * Example:
 * - If permutation = 3, no_objects = 4, and route points to an array [0, 1, 2, 3],
 *   the function modifies the array to [0, 2, 1, 3].
 * 
 * Required header file: 
 * - None
 * 
 * Reference: 
 * https://en.wikipedia.org/wiki/Permutation#Generation_in_lexicographic_order
 */
void get_next_route(const unsigned int permutation, const unsigned int no_objects, unsigned int *const route);

/**
 * Function: distanceBetweenLocations
 * ----------------------------------
 * This function calculates the distance between two points.
 *
 * Inputs:
 * - x1, y1: The x and y coordinates of the first point.
 * - x2, y2: The x and y coordinates of the second point.
 *
 * Output:
 * - The function returns the distance between the two points.
 *
 * Example:
 * - If x1 = 1, y1 = 2, x2 = 4, y2 = 6, the function returns 5
 * 
 * Required header file:
 * - math.h
 * 
 * Copyright Joel Chiappetti
 */
float distanceBetweenLocations(const float x1, const float y1, const float x2, const float y2);

/**
 * Function: totalDistanceOfRoute
 * ------------------------------
 * This function calculates the total distance of a route.
 *
 * Inputs:
 * - xCoordOfPossibleLocations, yCoordOfPossibleLocations: The x and y coordinates of the possible locations.
 * - orderedLocationsVisitedOnThisRoute: The order in which the locations are visited.
 * - numberOfLocations: The number of locations in the route.
 *
 * Output:
 * - The function returns the total distance of the route.
 *
 * Example:
 * - If xCoordOfPossibleLocations = [0, 1, 2], yCoordOfPossibleLocations = [0, 1, 2],
 *   orderedLocationsVisitedOnThisRoute = [0, 1, 2], and numberOfLocations = 3,
 *   the function returns approximately 2.83.
 * 
 * Required header file:
 * - math.h
 * 
 * NOTE: there is an additional input: the number of locations in the route
 * 
 * Copyright Joel Chiappetti
 */
float totalDistanceOfRoute(const float *xCoordOfPossibleLocations, const float *yCoordOfPossibleLocations, const unsigned int *orderedLocationsVisitedOnThisRoute, const unsigned int numberOfLocations);

/**
 * Function: GetMinimumRoute
 * -------------------------
 * This function calculates the minimum distance of a route.
 *
 * Inputs:
 * - xCoordOfPossibleLocations, yCoordOfPossibleLocations: The x and y coordinates of the possible locations.
 * - orderedLocationsFromUser: The locations that the user wants to visit.
 * - userRouteLength: The number of locations in the route.
 * - minimumRoute: A pointer to the minimum route.
 *
 * Output:
 * - The function returns the minimum distance of the route.
 * - The function also modifies the array pointed to by minimumRoute to represent the minimum route.
 *
 * Example:
 * - If xCoordOfPossibleLocations = [0, 9, 6], yCoordOfPossibleLocations = [0, 8, 8],
 *   orderedLocationsFromUser = [0, 1, 2], userRouteLength = 3, and minimumRoute points to an array [0, 0, 0],
 *   the function returns approximately 25.04 and modifies the array pointed to by minimumRoute to [0, 1, 2].
 * 
 * Required header file:
 * - math.h
 * 
 * Copyrght Joel Chiappetti
 */
float GetMinimumRoute(const float *xCoordOfPossibleLocations, const float *yCoordOfPossibleLocations, unsigned const int *orderedLocationsFromUser, unsigned const int userRouteLength, unsigned int *minimumRoute);

/**
 * Function: getUserInput
 * ----------------------
 * This function prompts the user to enter an integer within a specified range.
 * It validates the input and keeps prompting until a valid input is entered.
 *
 * Inputs:
 * - min: The minimum acceptable value for the input.
 * - max: The maximum acceptable value for the input.
 *
 * Output:
 * - The function returns the valid input entered by the user.
 *
 * Example:
 * - If min = 1 and max = 10, and the user enters 5, the function returns 5.
 * - If the user enters a value outside the range or a non-integer, the function prompts the user to enter a valid input.
 * 
 * Required header file:
 * - stdio.h
 * 
 * Copyright Joel Chiappetti
 */
int getUserInput(const unsigned int min, const unsigned int max);

/**
 * Function: main (task 2 sample version)
 * --------------
 * This would be the entry point of the program.
 *
 * The function initializes arrays for the x and y coordinates of the locations,
 * and an array for the order in which the locations are visited.
 * It then calculates the total distance of the route and prints it.
 *
 * Inputs:
 * - None.
 *
 * Output:
 * - The function returns 0 to indicate successful execution.
 * - The function also prints the total distance of the route.
 *
 * Example:
 * - The function initializes xCoordsArray = [0, 9, 6, 7, 1, 21, 7, 11, 5, 9, 8],
 *   yCoordsArray = [0, 8, 8, 8, 1, 11, 11, 11, 5, 9, 1],
 *   and orderedLocationsArray = [2, 3, 1, 4].
 * - It then calculates the total distance of the route and prints it.
 * 
 * Required header file:
 * - stdio.h
 * 
 * NOTE: this function is not used in the main program
 * 
 * Copyright Joel Chiappetti
 */

/**
 * Function: main (task 3 version)
 * --------------
 * This is the entry point of the program.
 *
 * The function initializes arrays for the x and y coordinates of the locations,
 * and an array for the order in which the locations are visited.
 * It then prompts the user to enter the length of the route and the sequence of locations.
 * The function calculates the minimum distance of the route and prints it along with the order of locations.
 *
 * Inputs:
 * - None.
 *
 * Output:
 * - The function returns 0 to indicate successful execution.
 * - The function also prints the coordinates of the possible locations, prompts the user for input,
 *   and prints the minimum distance of the route and the order of locations.
 *
 * Example:
 * - The function initializes xCoordOfPossibleLocations = [0, 9, 6, 7, 1, 21, 7, 11, 5, 9, 8],
 *   yCoordOfPossibleLocations = [0, 8, 8, 8, 1, 11, 11, 11, 5, 9, 1].
 * - It then prompts the user to enter the length of the route and the sequence of locations.
 * - The function calculates the minimum distance of the route and prints it along with the order of locations.
 * 
 * Test Data:
 * - User Input: 4 followed by 1, 2, 3, 4
 *   Output: The shortest possible distance to travel is 25.044359 which requires visiting in the order 0 2 3 1 4 0
 * - User Input: 4 followed by 1, 4, 7, 9
 *   Output: The shortest possible distance to travel is 31.203493 which requires visiting in the order 0 1 7 9 4 0
 * 
 * 
 * Required header file: 
 * - stdio.h
 * 
 * Copyright Joel Chiappetti
 */
int main();





// --------------------------------------------------------------------------
// Function definitions
// --------------------------------------------------------------------------





unsigned long int factorial(unsigned int n)
{
    unsigned long int v = 1;
    for (int i = 2; i <= n; i++)
        v *= i;
    return (v);
}

// --------------------------------------------------------------------------

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

// --------------------------------------------------------------------------

float distanceBetweenLocations(const float x1, const float y1, const float x2, const float y2)
{
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

// --------------------------------------------------------------------------

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

// --------------------------------------------------------------------------

int getUserInput(const unsigned int min, const unsigned int max)
{
    int userInput;
    while (scanf("%i", &userInput) != 1 || userInput < min || userInput > max)
    {
        while(getchar() != '\n'); // clear the input buffer
        printf("Invalid input. Please enter a number between %i and %i: ", min, max);
    }
    return userInput;
}

// --------------------------------------------------------------------------




// --------------------------------------------------------------------------
// Main functions
// --------------------------------------------------------------------------





// int main()
// {
//     float xCoordsArray[11]        = {0, 9, 6, 7, 1, 21, 7, 11, 5, 9, 8};
//     float yCoordsArray[11]        = {0, 8, 8, 8, 1, 11, 11, 11, 5, 9, 1};
//     int orderedLocationsArray[4] = {2, 3, 1, 4};
//     float totalDistance = totalDistanceOfRoute(xCoordsArray, yCoordsArray, orderedLocationsArray);
//     printf("Total distance of route is %f\n", totalDistance);
// 
//     return 0;
// }

// --------------------------------------------------------------------------

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
    userRouteLength = getUserInput(1, 5);
    unsigned int orderedLocationsFromUser[userRouteLength];

    // get the locations in the route
    printf("Please enter a sequence of locations: \n");
    for (unsigned int i = 0; i < userRouteLength; i++)
    {
        printf("Location %i: ", i);
        orderedLocationsFromUser[i] = getUserInput(0, 10);
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