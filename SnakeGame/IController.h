#pragma once

#include "IModel.h"

class IController
{
public:
	virtual ~IController();
	virtual void start() = 0;
protected:
	IController();
};