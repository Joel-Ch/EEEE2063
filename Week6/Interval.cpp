#include "Interval.h"

interval::interval(float l, float h)
{
    low = l;
    high = h;
}

interval::interval(float number)
{
    low = number - 1;
    high = number + 1;
}

interval::interval(const interval &i)
{
    low = i.low;
    high = i.high;
}

interval &interval::operator=(const interval &i)
{
    low = i.low;
    high = i.high;
    return *this;
}

interval &interval::operator+=(const interval &i)
{
    low += i.low;
    high += i.high;
    return *this;
}

interval &interval::operator-=(const interval &i)
{
    low -= i.low;
    high -= i.high;
    return *this;
}

interval interval::operator+(const interval &i) const
{
    interval temp;
    temp.low = low + i.low;
    temp.high = high + i.high;
    return temp;
}

interval interval::operator-(const interval &i) const
{
    interval temp;
    temp.low = low - i.low;
    temp.high = high - i.high;
    return temp;
}

interval interval::operator*(const interval &i) const
{
    interval temp;
    temp.low = min(min(low * i.low, low * i.high), min(high * i.low, high * i.high));
    temp.high = max(max(low * i.low, low * i.high), max(high * i.low, high * i.high));
    return temp;
}

interval interval::operator/(const interval &i) const
{
    interval temp;
    temp.low = min(min(low / i.low, low / i.high), min(high / i.low, high / i.high));
    temp.high = max(max(low / i.low, low / i.high), max(high / i.low, high / i.high));
    return temp;
}

#include <cmath>
interval interval::operator^(const interval &i) const
{
    interval temp;
    temp.low = min(min(pow(low, i.low), pow(low, i.high)), min(pow(high, i.low), pow(high, i.high)));
    temp.high = max(max(pow(low, i.low), pow(low, i.high)), max(pow(high, i.low), pow(high, i.high)));
    return temp;
}

ostream &operator<<(ostream &os, const interval &i)
{
    os << "[" << i.low << ", " << i.high << "]";
    return os;
}

istream &operator>>(istream &is, interval &i)
{
    is >> i.low >> i.high;
    return is;
}

interval operator+(float f, const interval &i)
{
    return i + f; // Use the member function defined above.
}

interval operator-(float f, const interval &i)
{
    return interval(f) - i; // Use the member function defined above.
}

interval operator*(float f, const interval &i)
{
    return i * f; // Use the member function defined above.
}

interval operator/(float f, const interval &i)
{
    return interval(f) / i; // Use the member function defined above.
}