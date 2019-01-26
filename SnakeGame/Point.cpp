#include "pch.h"
#include "Point.h"

Point::Point(const int& x, const int& y)
	: x_{ std::make_shared<int>(x) }, y_{ std::make_shared<int>(y) }
{ }

Point::Point(const Point& point)
	: x_{ std::make_shared<int>(*point.x_) }, y_{ std::make_shared<int>(*point.y_) }
{ }

Point& Point::operator= (const Point& point)
{
	x_.reset(new int{ *point.x_ });
	y_.reset(new int{ *point.y_ });
	return *this;
}

Point::Point(const Point&& point)
	: x_{ std::make_shared<int>(*point.x_) }, y_{ std::make_shared<int>(*point.y_) }
{ }

Point& Point::operator= (const Point&& point)
{
	x_.reset(new int{ *point.x_ });
	y_.reset(new int{ *point.y_ });
	return *this;
}

void Point::setX(const int& x)
{
	*x_ = x;
}

void Point::setY(const int& y)
{
	*y_ = y;
}

int Point::getX() const
{
	return *x_;
}

int Point::getY() const
{
	return *y_;
}

Point::~Point() { }

bool operator== (const Point& p1, const Point& p2)
{
	return p1.getX() == p2.getX() && p1.getY() == p2.getY();
}