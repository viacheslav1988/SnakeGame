#include "pch.h"
#include "IModel.h"

IModel::IModel() { }


IModel::~IModel() { }

void IModel::Attach(IView* v)
{
	views_.push_back(v);
}

void IModel::Detach(IView* v)
{
	views_.remove(v);
}

void IModel::Notify()
{
	for (auto view : views_) view->Update(this);
}