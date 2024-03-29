#pragma once
#include "Action.h"
class MoveAction : public Action
{
private:
	Point d;
	//selectAction* s;
public:
	MoveAction(ApplicationManager* pApp);//constructor

	//Reads parameters required for action to execute (code depends on action type)
	virtual void ReadActionParameters();

	//Execute action (code depends on action type)
	virtual void Execute();
};

