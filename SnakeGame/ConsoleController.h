#pragma once

#include <conio.h>
#include "IController.h"
#include "Snake.h"

class ConsoleController : IController
{
public:
	ConsoleController(Snake*);
	virtual ~ConsoleController();
	virtual void start();
private:
	Snake* snake_;
};