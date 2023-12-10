#pragma once
#include "Action.h"
class StartRecAction :
    public Action
{

public:
    StartRecAction(ApplicationManager* pApp);
    void Execute();
    void ReadActionParameters();
    
};

