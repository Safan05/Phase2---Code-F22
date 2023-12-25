#pragma once
#include "Action.h"
class RedoAction : public Action
{
public:
	RedoAction(ApplicationManager* pApp);//constructor

	//Reads parameters required for action to execute (code depends on action type)
	virtual void ReadActionParameters();

	//Execute action (code depends on action type)
	virtual void Execute();
	//virtual void Undo(Action* b);

};