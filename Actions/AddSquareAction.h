#pragma once
#include "Action.h"
class AddSquareAction : public Action
{
private:
	Point P;		//Square Center
	GfxInfo SquareGfxInfo;
public:
	AddSquareAction(ApplicationManager* pApp);

	//Reads Square parameters
	virtual void ReadActionParameters();
	bool Valid();
	bool ValidP(Point);
	//Add Square to the ApplicationManager
	virtual void Execute();

};