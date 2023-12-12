#pragma once
#include "Action.h"
class DrawingAction : public Action
{

private:
	GfxInfo colorGfX;
	color drawing;
	drawstyle s;
	Point P;
public:
	DrawingAction(ApplicationManager* pApp);//constructor
	//	bool ClickPoint(Point po);
		//Reads parameters required for action to execute (code depends on action type)
	virtual void ReadActionParameters();

	//Execute action (code depends on action type)
	virtual void Execute();
};
