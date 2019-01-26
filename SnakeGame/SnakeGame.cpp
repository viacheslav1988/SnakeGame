#include "pch.h"
#include "RussianEncoding.h"
#include "Snake.h"
#include "ConsoleView.h"
#include "ConsoleController.h"

int wmain()
{
	RUSSIAN_SUPPORT_ENCODING
	Snake snake{ 15 };
	ConsoleView view{ &snake };
	ConsoleController controller{ &snake };
	controller.start();
}