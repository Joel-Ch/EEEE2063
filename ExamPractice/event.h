#include <iostream>
using namespace std;
#include "meal.h"

class event
{
    private:
    meal * listOfMeals;
    int mealNumber;

    public:
    event() : listOfMeals(NULL), mealNumber(0) {} 

    ~event()
    {
        if (listOfMeals != NULL) delete[] listOfMeals; 
    }

    event(const event &e)
    {
        *this = e;
    }

    event &operator=(const event &e)
    {
        mealNumber = e.mealNumber;

        if(listOfMeals != NULL) delete[] listOfMeals;
        // dont delete a NULL bc you will die
        listOfMeals = new meal[mealNumber];
        // create new list
        for(int i=0;i<mealNumber;i++) listOfMeals[i]=e.listOfMeals[i];
        // copy data

        return *this;
    }

    int addMeal(meal newMeal)
    {
        meal* oldListOfMeals=new meal[mealNumber];
        for(int i=0;i<mealNumber;i++) oldListOfMeals[i]=listOfMeals[i];
        // copy old list

        listOfMeals = new meal[mealNumber+1];
        for(int i=0;i<mealNumber;i++) listOfMeals[i]=oldListOfMeals[i];
        // create new list 1 longer and copy old data in

        listOfMeals[mealNumber] = newMeal;
        // put new meal in

        mealNumber++;
        return 0;
    }

    int calculateTotalCost()
    {
        int totalCost = 0;
        for (int i = 0; i < mealNumber; i++)
        {
            totalCost += listOfMeals[i].getCost();
        }
        
        return totalCost;
    }
    
};