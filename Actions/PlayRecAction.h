#pragma once
#include "Action.h"
#include "..\Figures\CFigure.h"

class PlayRecAction :
    public Action
{
public:
    PlayRecAction(ApplicationManager* pApp);
    void Execute();
    void ReadActionParameters();
    void UpdateRECInterface();
    void CompareID(CFigure * f,int index);
};

