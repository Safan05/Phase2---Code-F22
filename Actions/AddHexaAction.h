#pragma once
#include "Action.h"
class AddHexaAction : public Action
{
private:
	Point center;		//Hexagon Center
	GfxInfo HexaGfxInfo;
public:
	AddHexaAction(ApplicationManager* pApp);

	//Reads Square parameters
	virtual void ReadActionParameters();
	bool Valid();
	bool ValidP(Point);
	virtual void Execute();

};