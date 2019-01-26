#include "pch.h"
#include "ConsoleController.h"

ConsoleController::ConsoleController(Snake* snake)
	: snake_{ snake } { }

ConsoleController::~ConsoleController() { }

void ConsoleController::start()
{
	snake_->Notify();
	while (true)
	{
		if (_kbhit())
		{
			switch (_getch())
			{
			case 32:
				snake_->step();
				break;
			case 65: case 97: case 148: case 228:
			Left:
				snake_->step(Move::Left);
				break;
			case 87: case 119: case 150: case 230:
			Up:
				snake_->step(Move::Up);
				break;
			case 68: case 100: case 130: case 162:
			Right:
				snake_->step(Move::Right);
				break;
			case 83: case 115: case 155: case 235:
			Down:
				snake_->step(Move::Down);
				break;
			case 224:
				switch (_getch())
				{
				case 75: goto Left;
				case 72: goto Up;
				case 77: goto Right;
				case 80: goto Down;
				}
			default: return;
			}
		}
	}
}