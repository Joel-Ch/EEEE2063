#include <iostream>
using namespace std;

class meal
{
    private:
    int id;
    float cost;

    public:
    meal(int _id, float _cost)
    {
        id = _id;
        cost = _cost;
    }

    meal()
    {
        id = 0;
        cost = 1;
        // basic and easily changeable but we can now declare arrays easily
    }

    ~meal(){}

    meal(const meal &m)
    {
        cost = m.cost;
        id = m.id;
    }

    meal &operator=(const meal &m)
    {
        cost = m.cost;
        id = m.id;
        return *this;
    }

    virtual float getCost()
    {
        return cost;
    }
    // virtual for later

    void setCost(float _cost)
    {
        cost = _cost;
    }
    int getId()
    {
        return id;
    }
    void setId(int _id)
    {
        id = _id;
    }

    friend ostream &operator<<(ostream &os, const meal &m)
    {
    os << "Cost = " << m.cost << "\nID = " << m.id << endl;
    return os;
    }

    friend istream &operator>>(istream &is, meal &m)
    {
    is >> m.cost >> m.id;
    return is;
    }

    
};

class largerMeal:public meal
{
    private:
    // these are the same as the meal so we can just inherit them

    public:
    float getCost(){return 1.2*meal::getCost();}
    // this is the only function which is different when larger
};