#pragma once
#include "Action.h"
class FillingAction :public Action
{

private:
	GfxInfo colorGfX;
	color filling;
	drawstyle s;
	Point P;
	//GreenAction* c;
	//BlackAction* b;
public:
	FillingAction(ApplicationManager* pApp);//constructor
	//	bool ClickPoint(Point po);
		//Reads parameters required for action to execute (code depends on action type)
	virtual void ReadActionParameters();

	//Execute action (code depends on action type)
	virtual void Execute();
};

