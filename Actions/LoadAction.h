#pragma once
#include "Action.h"
class LoadAction : public Action
{
private:
	string FileName;
public:
	LoadAction(ApplicationManager* pApp);
	void ReadActionParameters();
	void Execute() ;

};

