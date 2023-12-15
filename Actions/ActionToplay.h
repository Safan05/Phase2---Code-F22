#pragma once
#include "Action.h"
class ActionToplay :public Action
{
public:
	ActionToplay(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};


