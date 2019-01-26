#include "pch.h"
#include "Snake.h"

#pragma region CULTIVATE

void Snake::cultivate()
{
	std::uniform_int_distribution<int> uni(0, *size_ - 1);
	while (true)
	{
		if (food_.size() >= *size_ / 2) break;
		Point point{ uni(dre_), uni(dre_) }, zero;
		if (zero == point | std::find(body_.begin(), body_.end(), point) != body_.end()) continue;
		food_.push_back(point);
	}
}

#pragma endregion

#pragma region DRAW

void Snake::draw()
{
	for (int i = 0; i < *size_; ++i)
	{
		for (int j = 0; j < *size_; ++j)
		{
			Point point{ j, i };
			if (!body_.empty())
			{
				if (std::find(body_.begin(), body_.end(), point) != body_.end())
				{
					field_[i][j] = 1;
					continue;
				}
			}
			if (!food_.empty())
			{
				if (std::find(food_.begin(), food_.end(), point) != food_.end())
				{
					field_[i][j] = 2;
					continue;
				}
			}
			field_[i][j] = 0;
		}
	}
	Notify();
}

#pragma endregion

#pragma region »Õ»÷»¿À»«¿÷»ﬂ  À¿——¿

Snake::Snake(const int& size, const Point& start, const Move& move)
	: move_{ move }, size_{ std::shared_ptr<const int>(new int{ size }) },
	field_{ std::shared_ptr<std::shared_ptr<int[]>[]>(new std::shared_ptr<int[]>[*size_]) },
	body_{ start }, food_{ }, dre_{ }
{
	for (int i = 0; i < *size_; ++i) field_[i] = std::shared_ptr<int[]>(new int[*size_]);
	cultivate();
	draw();
}

Snake::Snake(const Snake& snake)
	: move_{ snake.move_ }, size_{ std::shared_ptr<const int>(new int{ *snake.size_ }) },
	field_{ std::shared_ptr<std::shared_ptr<int[]>[]>(new std::shared_ptr<int[]>[*size_]) },
	body_(snake.body_), food_(snake.food_), dre_{ snake.dre_ }
{
	for (int i = 0; i < *size_; ++i) field_[i] = std::shared_ptr<int[]>(new int[*size_]);
	draw();
}

Snake& Snake::operator=(const Snake& snake)
{
	move_ = snake.move_;
	size_.reset(new const int{ *snake.size_ });
	field_ = std::shared_ptr<std::shared_ptr<int[]>[]>(new std::shared_ptr<int[]>[*size_]);
	for (int i = 0; i < *size_; ++i) field_[i] = std::shared_ptr<int[]>(new int[*size_]);
	body_ = snake.body_;
	food_ = snake.food_;
	dre_ = snake.dre_;
	draw();
	return *this;
}

Snake::Snake(const Snake&& snake)
	: move_{ snake.move_ }, size_{ std::shared_ptr<const int>(new int{ *snake.size_ }) },
	field_{ std::shared_ptr<std::shared_ptr<int[]>[]>(new std::shared_ptr<int[]>[*size_]) },
	body_(snake.body_), food_(snake.food_), dre_{ snake.dre_ }
{
	for (int i = 0; i < *size_; ++i) field_[i] = std::shared_ptr<int[]>(new int[*size_]);
	draw();
}

Snake& Snake::operator=(const Snake&& snake)
{
	move_ = snake.move_;
	size_.reset(new const int{ *snake.size_ });
	field_ = std::shared_ptr<std::shared_ptr<int[]>[]>(new std::shared_ptr<int[]>[*size_]);
	for (int i = 0; i < *size_; ++i) field_[i] = std::shared_ptr<int[]>(new int[*size_]);
	body_ = snake.body_;
	food_ = snake.food_;
	dre_ = snake.dre_;
	draw();
	return *this;
}

Snake::~Snake() { }

#pragma endregion

#pragma region √≈“≈–€

int Snake::getSize() const
{
	return *size_;
}

std::shared_ptr<std::shared_ptr<int[]>[]> Snake::getField() const
{
	return field_;
}

int Snake::getScore() const
{
	return body_.size() - 1;
}

#pragma endregion

#pragma region CALCULATE

void Snake::calculate(std::deque<Point>& body, std::list<Point>& food, const Point& segment)
{
	body.push_back(segment);
	auto b_it = std::find(body.begin(), body.end() - 1, segment);
	if (body.size() > 4 && b_it != body.end() - 1) body.erase(body.begin(), b_it);
	auto f_it = std::find(food.begin(), food.end(), segment);
	if (f_it == food.end()) body.pop_front();
	else
	{
		food.remove(*f_it);
		cultivate();
	}
}

#pragma endregion

#pragma region STEP

void Snake::step()
{
	int x = 0, y = 0;
	switch (move_)
	{
	case Move::Left:
		x = body_.back().getX();
		calculate(body_, food_, Point{ --x < 0 ? *size_ - 1 : x , body_.back().getY() });
		break;
	case Move::Up:
		y = body_.back().getY();
		calculate(body_, food_, Point{ body_.back().getX(), --y < 0 ? *size_ - 1 : y });
		break;
	case Move::Right:
		x = body_.back().getX();
		calculate(body_, food_, Point{ ++x >= *size_ ? 0 : x , body_.back().getY() });
		break;
	case Move::Down:
		y = body_.back().getY();
		calculate(body_, food_, Point{ body_.back().getX(), ++y >= *size_ ? 0 : y });
		break;
	}
	draw();
}

void Snake::step(const Move& move)
{
	if (((move == Move::Right) & (move_ == Move::Left)) |
		((move == Move::Down) & (move_ == Move::Up)) |
		((move == Move::Left) & (move_ == Move::Right)) |
		((move == Move::Up) & (move_ == Move::Down))) return;
	move_ = move;
	step();
}

#pragma endregion

#pragma region OPERATOR<<

std::wostream& operator<<(std::wostream& wos, const Snake& snake)
{
	wos << L"Score: " << snake.getScore() << std::endl << std::endl;
	for (int i = 0; i < snake.getSize(); ++i)
	{
		for (int j = 0; j < snake.getSize(); ++j)
		{
			switch (snake.getField()[i][j])
			{
			case 0: wos << L'.';
				break;
			case 1: wos << L'*';
				break;
			case 2: wos << L'+';
				break;
			}
			wos << L' ';
		}
		wos << std::endl;
	}
	return wos;
}

#pragma endregion