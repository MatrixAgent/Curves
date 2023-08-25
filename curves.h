#pragma once

#include <iostream>

class Point
{
public:
	double x, y, z;
	Point(double x, double y, double z) : x(x), y(y), z(z) { }

	friend std::ostream& operator<<(std::ostream& s, const Point& p)
	{
		s << p.x << ", " << p.y << ", " << p.z;
		return s;
	}
};

class Curve
{
public:
	double a, b;

	Curve(double a, double b) : a(a), b(b) { }

	virtual Point point(double t) const = 0;
	virtual Point derivative(double t) const = 0;
};

class Circle : public Curve
{
public:
	double r;

	Circle(double r, double a, double b) :
		r(r), Curve(a, b)
	{ }

	Point point(double t) const override;
	Point derivative(double t) const override;
};

class Ellipse : public Curve
{
public:
	double r, q;

	Ellipse(double r, double q, double a, double b) :
		r(r), q(q), Curve(a, b)
	{ }

	Point point(double t) const override;
	Point derivative(double t) const override;
};

class Helix : public Curve
{
public:
	double r, step;

	Helix(double r, double a, double b, double step) :
		r(r), Curve(a, b), step(step)
	{ }

	Point point(double t) const override;
	Point derivative(double t) const override;
};
