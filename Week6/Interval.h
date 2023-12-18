#ifndef INTERVAL_H
#define INTERVAL_H

#include <iostream>
using namespace std;

/**
 * @brief The interval class represents a mathematical interval.
 * It stores the lower and upper bounds of the interval.
 */
class interval
{
private:
    float low, high; // Lower and upper bounds of the interval

public:
    /**
     * @brief Constructs an interval object with given lower and upper bounds.
     *
     * @param l The lower bound of the interval.
     * @param h The upper bound of the interval.
     */
    interval(float l, float h);

    /**
     * @brief Constructs an interval object with a single number.
     * The lower bound is set to number - 0.1 and the upper bound is set to number + 0.1.
     *
     * @param number The number to create the interval from.
     */
    interval(float number);

    /**
     * @brief Default constructor that initializes the interval with zero bounds.
     */
    interval() : low(0), high(0) {}

    /**
     * @brief Destructor for the interval class.
     */
    ~interval() {}

    /**
     * @brief Copy constructor that creates a new interval object with the same bounds as the given interval.
     *
     * @param i The interval to be copied.
     */
    interval(const interval &i);

    /**
     * @brief Assignment operator that assigns the bounds of the given interval to the current interval.
     *
     * @param i The interval to be assigned.
     * @return interval& The reference to the current interval after assignment.
     */
    interval &operator=(const interval &i);

    /**
     * @brief Compound assignment operator that adds the bounds of the given interval to the current interval.
     *
     * @param i The interval to be added.
     * @return interval& The reference to the current interval after addition.
     */
    interval &operator+=(const interval &i);

    /**
     * @brief Compound assignment operator that subtracts the bounds of the given interval from the current interval.
     *
     * @param i The interval to be subtracted.
     * @return interval& The reference to the current interval after subtraction.
     */
    interval &operator-=(const interval &i);

    /**
     * @brief Binary addition operator that adds the bounds of two intervals and returns a new interval.
     *
     * @param i The interval to be added.
     * @return interval The new interval after addition.
     */
    interval operator+(const interval &i) const;

    /**
     * @brief Binary subtraction operator that subtracts the bounds of two intervals and returns a new interval.
     *
     * @param i The interval to be subtracted.
     * @return interval The new interval after subtraction.
     */
    interval operator-(const interval &i) const;

    /**
     * @brief Binary multiplication operator that multiplies the bounds of two intervals and returns a new interval.
     *
     * @param i The interval to be multiplied.
     * @return interval The new interval after multiplication.
     */
    interval operator*(const interval &i) const;

    /**
     * @brief Binary division operator that divides the bounds of two intervals and returns a new interval.
     *
     * @param i The interval to be divided.
     * @return interval The new interval after division.
     */
    interval operator/(const interval &i) const;

    /**
     * @brief Binary exponentiation operator that raises the bounds of the current interval to the power of the bounds of the given interval.
     *
     * @param i The interval representing the exponents.
     * @return interval The new interval after exponentiation.
     */
    interval operator^(const interval &i) const;

    /**
     * @brief Overloaded output stream operator that prints the bounds of the interval.
     *
     * @param os The output stream object.
     * @param i The interval to be printed.
     * @return ostream& The reference to the output stream object.
     */
    friend ostream &operator<<(ostream &os, const interval &i);

    /**
     * @brief Overloaded input stream operator that reads the bounds of the interval from the input stream.
     *
     * @param is The input stream object.
     * @param i The interval to be read.
     * @return istream& The reference to the input stream object.
     */
    friend istream &operator>>(istream &is, interval &i);
};

/**
 * @brief Overloaded addition operator that adds a float to an interval and returns a new interval.
 *
 * @param f The float to be added.
 * @param i The interval to be added to.
 * @return interval The new interval after addition.
 */
interval operator+(float f, const interval &i);

/**
 * @brief Overloaded subtraction operator that subtracts a float from an interval and returns a new interval.
 *
 * @param f The float to be subtracted.
 * @param i The interval to be subtracted from.
 * @return interval The new interval after subtraction.
 */
interval operator-(float f, const interval &i);

/**
 * @brief Overloaded multiplication operator that multiplies a float with an interval and returns a new interval.
 *
 * @param f The float to be multiplied.
 * @param i The interval to be multiplied with.
 * @return interval The new interval after multiplication.
 */
interval operator*(float f, const interval &i);

/**
 * @brief Overloaded division operator that divides a float by an interval and returns a new interval.
 *
 * @param f The float to be divided.
 * @param i The interval to be divided by.
 * @return interval The new interval after division.
 */
interval operator/(float f, const interval &i);

#endif