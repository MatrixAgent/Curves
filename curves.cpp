#include "curves.h"

#define _USE_MATH_DEFINES
#include <math.h>

Point Circle::point(double t) const
{
    return Point(a + r*cos(t), b + r*sin(t), 0);
}

Point Circle::derivative(double t) const
{
    return Point(-r*sin(t), r*cos(t), 0);
}

Point Ellipse::point(double t) const
{
    return Point(a + r * cos(t), b + q * sin(t), 0);
}
Point Ellipse::derivative(double t) const
{
    return Point(-r * sin(t), q * cos(t), 0);
}

Point Helix::point(double t) const
{
    return Point(a + r * cos(t), b + r * sin(t), t/2/M_PI*step);
}

Point Helix::derivative(double t) const
{
    return Point(-r * sin(t), r * cos(t), step/2/M_PI);
}
