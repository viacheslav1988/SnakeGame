#pragma once

#include <memory>
#include <list>
#include <deque>
#include <iostream>
#include <algorithm>
#include <random>
#include <chrono>
#include "IModel.h"
#include "Point.h"
#include "Move.h"

class Snake :public IModel
{
	Move move_;
	std::shared_ptr<const int> size_;
	std::shared_ptr<std::shared_ptr<int[]>[]> field_;
	std::deque<Point> body_;
	std::list<Point> food_;
	std::default_random_engine dre_;
	void cultivate();
	void draw();
public:
	Snake(const int& size = 10, const Point& = { 0, 0 }, const Move& = Move::Down);
	Snake(const Snake&);
	Snake& operator= (const Snake&);
	Snake(const Snake&&);
	Snake& operator= (const Snake&&);
	int getSize() const;
	std::shared_ptr<std::shared_ptr<int[]>[]> getField() const;
	int getScore() const;
	void calculate(std::deque<Point>&, std::list<Point>&, const Point&);
	void step();
	void step(const Move&);
	~Snake();
};

std::wostream& operator<< (std::wostream&, const Snake&);