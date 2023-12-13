#pragma once
#include "Action.h"
class pick_both :public Action
{
private:
	Point P;
public:
	pick_both(ApplicationManager* pApp);//constructor

	//Reads parameters required for action to execute (code depends on action type)
	virtual void ReadActionParameters();

	//Execute action (code depends on action type)
	virtual void Execute();
};


