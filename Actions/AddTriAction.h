#pragma once
#include "Action.h"
class AddTriAction : public Action
{
private:
	Point Vertex1;
	Point Vertex2;
	Point Vertex3;
	GfxInfo TriGfxInfo;
public:
	AddTriAction(ApplicationManager* pApp);

	//Reads Tri parameters
	virtual void ReadActionParameters();
	bool Valid();
	bool ValidP(Point);
	//Add Tri to the ApplicationManager
	virtual void Execute();

};