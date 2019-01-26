#pragma once

#include "IModel.h"

class IModel;

class IView
{
public:
	virtual ~IView();
	virtual void Update(IModel* theChangedModel) = 0;
protected:
	IView();
};