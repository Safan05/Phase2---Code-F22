#pragma once
#include "Action.h"
class Pick_color :public Action
{
private:
	Point P;
public:
	Pick_color(ApplicationManager* pApp);//constructor

	//Reads parameters required for action to execute (code depends on action type)
	virtual void ReadActionParameters();

	//Execute action (code depends on action type)
	virtual void Execute();
};
