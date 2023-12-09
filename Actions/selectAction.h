#include "Action.h"

class selectAction :public Action
{
private:
	Point P;
public:
	selectAction(ApplicationManager* pApp);//constructor

	//Reads parameters required for action to execute (code depends on action type)
	virtual void ReadActionParameters();

	//Execute action (code depends on action type)
	virtual void Execute() ;
};