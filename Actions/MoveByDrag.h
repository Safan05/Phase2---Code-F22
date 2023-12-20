#pragma once
#include "Action.h"
class MoveByDrag : public Action
{
private:
	Point d;
public:
	MoveByDrag(ApplicationManager* pApp);//constructor

	//Reads parameters required for action to execute (code depends on action type)
	virtual void ReadActionParameters();

	//Execute action (code depends on action type)
	virtual void Execute();


};

