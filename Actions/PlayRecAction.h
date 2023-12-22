#pragma once
#include "Action.h"
#include "..\Figures\CFigure.h"

class PlayRecAction :
    public Action
{
private:
public:
    PlayRecAction(ApplicationManager* pApp);
    void Execute();
    void ReadActionParameters();
    void UpdateRECInterface();
    void CompareID(int f,int index);
};

