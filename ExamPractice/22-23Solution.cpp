/// Comment to examiners: This exam is open Book and hence students have
/// available the various module materials to cut/paste/modify - hence
/// not "excessive" typing
/// The paper is most definitely & deliberately graded. Task 1 is regarded as the
/// basic pass, Tasks 2-4 as moving up into the 1sts and task 5 for a excellent 1st.
/// "Comments" have been assessed via coursework so will not be awarded marks here
/// Code efficiency is not an issue here - unless very stupid!
#include <stdio.h>
/// Task 1(40% in total): Basic object created to professional good practice standards
/// Emphasis less on syntax, rather design decisions when marked
/// We prefer but won't mark down not using separate header and cpp files for declarations and definitions
class meal {
public:
// Sensible naming strategy throughout 5%
// Constructor declaration 2%
 meal(const int _ID,const float _cost);
// If they put in default arguments or alternative constructor with no arguments they must
// include a "reasonable" comment about how they justify such a default behaviour
// Destructor declaration 2%
 ~meal();
// Copy constructor declaration 2%
 meal(const meal& m);
// Assignment declaration 5%
 meal& operator=(const meal& m);
// Get & sets declarations 2%
 virtual float getCost(); /// virtual for task 5 - additional 2%
 void setCost(const float _cost);
 int getID();
 void setID(const int _ID);
/// Task 2 Stream operator declarations: 5%
 friend ostream& operator<<(ostream& out,const meal& m);
 friend ostream& operator>>(istream& in,meal& m);
private:
// Making data private - 5%
 int ID;
 float cost;
};
//---------------------------------------------------------------------------
// Get & sets declarations 3%
float meal::getCost() {return(cost);}
void meal::setCost(const float _cost){cost=_cost;}
int meal::getID() {return(ID);}
void meal::setID(const int _ID){ID=_ID;}
//---------------------------------------------------------------------------
// 3%
~meal::meal(){}
//---------------------------------------------------------------------------
// 3%
meal::meal(const int _ID,const float _cost):ID(_ID),cost(_cost){}
//---------------------------------------------------------------------------
// 3%
meal::meal(const meal& m):ID(m.ID),cost(m.cost){}
//---------------------------------------------------------------------------
// 5%
meal& meal::operator=(const meal& m){
 if(&m==this) return(*this);
 ID=m.ID;
 cost=m.cost;
 return(*this);
}
//---------------------------------------------------------------------------
/// Task 2: 5% for implementations - must be a MATCHED PAIR! and non-member fns
//---------------------------------------------------------------------------
ostream& operator<<(ostream& out,const meal& m){
 out<<m.ID<<" "<<m.cost;
 return(out);
}
//---------------------------------------------------------------------------
ostream& operator>>(istream& in,meal& m){
 in>>m.ID>>m.cost
 return(in);
}
//---------------------------------------------------------------------------
/// Task 3(30% in total): More sophisticated object created to professional good practice
standards
/// More emphasis on syntax than task 1
class event{
public:
// Constructor declaration 2%
 event();
// Must manage variable length array. Here design always defaults to an empty event, with
meals added one at a time
// Sensible -commented upon - alternatives acceptable
// Destructor declaration 2%
 ~event();
// Copy constructor declaration 2%
 event(const event& e);
// Assignment declaration 2%
 event& operator=(const event& e);
// 2%
 void addMeal(const meal& m);
/// Task 4: 5% - cos something not "always there"
 float totalMealCost();
private:
// Correct variable choice and types - 5%
 unsigned int numberOfMeals;
 meal* meals;
};
//---------------------------------------------------------------------------
// 3%
event::event():numberOfMeals(0),meals(NULL){}
//---------------------------------------------------------------------------
// 3%
event::~event(){
 if(meals!=NULL) delete[] meals;
}
//---------------------------------------------------------------------------
// 3%
event& operator=()(const event& e){
 if(this==&e) return(*this);
 if(meals!=NULL) delete[] meals;
 numberOfMeals=e.numberOfMeals;
 meals=new meal[numberOfMeals];
 for(int i=0;i<numberOfMeals;i++) meals[i]=e.meals[i];
 return(*this);
}
//---------------------------------------------------------------------------
// 3% - or for explicit equivalent
event::event(const event& e){
 *this=e;
}
//---------------------------------------------------------------------------
// 3%
void event::addMeal(const meal& m){
 meal* oldMeals=new meal[numberOfMeals];
 for(int i=0;i<numberOfMeals;i++) oldMeals[i]=meals[i];
 if(meals!=NULL) delete[] meals;
 meals=new meal[numberOfMeals+1];
 for(int i=0;i<numberOfMeals;i++) meals[i]=oldMeals[i];
 meals[numberOfMeals]=m;
 ++numberOfMeals;
}
//---------------------------------------------------------------------------
/// Task 4:
//---------------------------------------------------------------------------
// 5%
void event::totalMealCost(){
 float total(0.);
 for(int i=0;i<numberOfMeals;i++) total+=meals[i].getCost();
 return(total);
}
//---------------------------------------------------------------------------
/// Task 5: Not many marks - 1st class cake icing ! Remember 2% given above for the base
class having a virtual fn
//---------------------------------------------------------------------------
class largerMeal:public meal { // 2% for inheritance
 public:
// "All Big 4 reusing base class implementations" - 2%
 largerMeal(const int _ID,const float _cost):meal(_ID,_cost){}
 ~largerMeal(){}
// Being initialisable from a MEAL is a design decision!
 meal(const meal& m):meal(m){}
// Design decision as for copy
 largerMeal& operator=(const meal& m){
 meal::operator=(m);
 return(*this);
 }
 virtual float getCost(); // virtual is optional syntax but 2% for redeclaring it
};
//---------------------------------------------------------------------------
// 2%
float largerMeal::getCost(){
 return(1.20*meal::getCost());
}
//---------------------------------------------------------------------------