#pragma once
#include "Action.h"
class PlayRecAction :
    public Action
{
public:
    PlayRecAction(ApplicationManager* pApp);
    void Execute();
    void ReadActionParameters();
    void UpdateRECInterface();
};

