#pragma once

#include <list>
#include "IView.h"

class IView;

class IModel
{
public:
	~IModel();
	virtual void Attach(IView*);
	virtual void Detach(IView*);
	virtual void Notify();
protected:
	IModel();
private:
	std::list<IView*> views_;
};