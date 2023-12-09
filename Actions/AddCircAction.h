#pragma once
#include "Action.h"
class AddCircAction : public Action
{
private:
	Point center;	//Circle Center
	Point point;
	GfxInfo CircGfxInfo;
public:
	AddCircAction(ApplicationManager* pApp);

	//Reads Square parameters
	virtual void ReadActionParameters();
	bool Valid();
	bool Valid_point(Point p1);
	bool ValidP(Point);
	//Add Square to the ApplicationManager
	virtual void Execute();

};