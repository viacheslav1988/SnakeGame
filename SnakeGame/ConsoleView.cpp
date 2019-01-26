#include "pch.h"
#include "ConsoleView.h"

ConsoleView::ConsoleView(Snake* snake)
{
	snake_ = snake;
	snake_->Attach(this);
}

ConsoleView::~ConsoleView()
{
	snake_->Detach(this);
}

void ConsoleView::Update(IModel* theChangedModel)
{
	if (theChangedModel == snake_) Draw();
}

void ConsoleView::Draw()
{
	system("cls");
	std::wcout << *snake_;
}