#pragma once

#include <memory>

class Point
{
	std::shared_ptr<int> x_, y_;
public:
	Point(const int& = 0, const int& = 0);
	Point(const Point&);
	Point& operator= (const Point&);
	Point(const Point&&);
	Point& operator= (const Point&&);
	void setX(const int&);
	void setY(const int&);
	int getX() const;
	int getY() const;
	~Point();
};

bool operator== (const Point&, const Point&);