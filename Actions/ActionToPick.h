#pragma once
#include "Action.h"
class ActionToPick:public Action
{
public:
	ActionToPick(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};

