#pragma once
#include "Action.h"
class delete_action:public Action
{
private:
public:
	delete_action(ApplicationManager* pApp);//constructor

	//Reads parameters required for action to execute (code depends on action type)
	virtual void ReadActionParameters();

	//Execute action (code depends on action type)
	virtual void Execute();
};

