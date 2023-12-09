#pragma once
#include "Action.h"
class StopRecAction :
    public Action
{
public:
    StopRecAction(ApplicationManager* pApp);
    void Execute();
    void ReadActionParameters();

};

