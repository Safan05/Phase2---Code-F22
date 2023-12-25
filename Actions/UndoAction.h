#pragma once
#include "Action.h"

class UndoAction : public Action
{

public:
	UndoAction(ApplicationManager* pApp);//constructor

	//Reads parameters required for action to execute (code depends on action type)
	virtual void ReadActionParameters();

	//Execute action (code depends on action type)
	virtual void Execute();


};