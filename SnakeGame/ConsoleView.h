#pragma once

#include <iostream>
#include "IModel.h"
#include "IView.h"
#include "Snake.h"

class ConsoleView : IView
{
public:
	ConsoleView(Snake*);
	virtual ~ConsoleView();
	virtual void Update(IModel*);
	virtual void Draw();
private:
	Snake* snake_;
};