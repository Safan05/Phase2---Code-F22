#include "ApplicationManager.h"
#include "Actions\AddRectAction.h"
#include "Actions\AddSquareAction.h"
#include "Actions\AddTriAction.h"
#include "Actions\AddCircAction.h"
#include "Actions\AddHexaAction.h"
#include "Actions\selectAction.h"
#include "Actions\delete_action.h"
#include "Actions\SaveAction.h"
#include "Actions\LoadAction.h"
#include "Actions\VoiceAction.h"
#include "Actions\pick_figure.h"
#include "Actions\ActionToPick.h"
#include "Actions\FillingAction.h"
#include "Actions\DrawingAction.h"
#include "Actions\ClearAllAction.h"
#include "Figures/CCirc.h"
#include "Figures/CHexa.h"
#include "Figures/CRectangle.h"
#include "Figures/CSquare.h"
#include "Figures/CTri.h"
#include "Actions\StartRecAction.h"
#include "Actions\StopRecAction.h"
#include "Actions\PlayRecAction.h"
#include "Actions/MoveAction.h"
#include <fstream>

//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();
	FigCount = 0;
	//Create an array of figure pointers and set them to NULL		
	for(int i=0; i<MaxFigCount; i++)
		FigList[i] = NULL;	
	for (int i = 0; i < MaxRecActions; i++)
		ActionList[i] = NULL;
}
int ApplicationManager::count_fig(int Fig_t) {
	int count = 0;
	switch (Fig_t) {
	case ITM_RECT:
		for (int i = 0; i < FigCount; i++) {
			CRectangle* r = dynamic_cast<CRectangle*>(FigList[i]);
			if (r)
				count++;
		}
		break;
	case ITM_CIRC:
		for (int i = 0; i < FigCount; i++) {
			CCirc* c = dynamic_cast<CCirc*>(FigList[i]);
			if (c)
				count++;
		}
		break;
	case ITM_TRI:
		for (int i = 0; i < FigCount; i++) {
			CTri* t = dynamic_cast<CTri*>(FigList[i]);
			if (t)
				count++;
		}
		break;
	case ITM_HEXA:
		for (int i = 0; i < FigCount; i++) {
			CHexa* h = dynamic_cast<CHexa*>(FigList[i]);
			if (h)
				count++;
		}
		break;
	case ITM_SQUARE:
		for (int i = 0; i < FigCount; i++) {
			CSquare* s = dynamic_cast<CSquare*>(FigList[i]);
			if (s)
				count++;
		}
		break;
}
	return count;
};
int ApplicationManager::count_fig(color col) {
	int count = 0;
	for (int i = 0; i < FigCount; i++)
		if (FigList[i]->get_color() == col)
			count++;
	return count;
}
void ApplicationManager::SaveAll(ofstream &Out)
{
	for (int i = 0; i < FigCount; i++) {
		if(FigList[i]!=NULL)
		FigList[i]->Save(Out);
	}
}
int ApplicationManager::GetFigCount()
{
	return FigCount;
}
int ApplicationManager::count_fig(int Fig_t, color col) {
	int count = 0;
	switch (Fig_t) {
	case ITM_RECT:
		for (int i = 0; i < FigCount; i++) {
			CRectangle* r = dynamic_cast<CRectangle*>(FigList[i]);
			if (r&&FigList[i]->get_color()==col)
				count++;
		}
		break;
	case ITM_CIRC:
		for (int i = 0; i < FigCount; i++) {
			CCirc* c = dynamic_cast<CCirc*>(FigList[i]);
			if (c&&FigList[i]->get_color() == col)
				count++;
		}
		break;
	case ITM_TRI:
		for (int i = 0; i < FigCount; i++) {
			CTri* t = dynamic_cast<CTri*>(FigList[i]);
			if (t&&FigList[i]->get_color() == col)
				count++;
		}
		break;
	case ITM_HEXA:
		for (int i = 0; i < FigCount; i++) {
			CHexa* h = dynamic_cast<CHexa*>(FigList[i]);
			if (h && FigList[i]->get_color() == col)
				count++;
		}
		break;
	case ITM_SQUARE:
		for (int i = 0; i < FigCount; i++) {
			CSquare* s = dynamic_cast<CSquare*>(FigList[i]);
			if (s && FigList[i]->get_color() == col)
				count++;
		}
		break;
	}
	return count;
};
void ApplicationManager::Clearall()
{	
	for (int i = 0; i < FigCount; i++) {
		delete FigList[i];
		FigList[i] = NULL;
	}
	FigCount = 0;
	pOut->ClearStatusBar();
}
void ApplicationManager::set_selected(CFigure* pFig) {
	SelectedFig = pFig;
};
CFigure* ApplicationManager::Get_selected()const {
	return SelectedFig; 
}
//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
ActionType ApplicationManager::GetUserAction() const
{
	//Ask the input to get the action from the user.
	return pIn->GetUserAction();		
}
////////////////////////////////////////////////////////////////////////////////////
//Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType) 
{
	Action* pAct = NULL;
	
	//According to Action Type, create the corresponding action object
	switch (ActType)
	{
		case DRAW_RECT:
			pAct = new AddRectAction(this);
			break;
		case DRAW_SQUARE:
			pAct = new AddSquareAction(this);
			break;
		case DRAW_TRI:
			pAct = new AddTriAction(this);
			break;
		case DRAW_CIRC:
			pAct = new AddCircAction(this);
			break;
		case DRAW_HEXA:
			pAct = new AddHexaAction(this);
			break;
		case SELECT:
			pAct = new selectAction(this) ;
			break;
		case FIGURES:
			pOut->CreateFigureToolBar();
			break;
		case DELETE_FIG:
			pAct = new delete_action(this);
			break;
		case Pick_figure:
			pAct = new pick_figure(this);
			break;
		case Start_Rec:
			pAct = new StartRecAction(this);
			break;
		case Stop_Rec:
			pAct = new StopRecAction(this);
			break;
		case Play_Rec:
			pAct = new PlayRecAction(this);
			break;
		case TO_DRAW:
			pOut->CreateDrawToolBar();
			break;
		case TO_PLAY:
			unhide();
			pOut->CreatePlayToolBar();
			break;
		case BACK_TO_DRAW:
			pOut->CreateDrawToolBar();
			break;
		case TO_PICK:
			pAct = new ActionToPick(this);
			break;
		case CLEAR_ALL:
			pAct = new ClearAllAction(this);
			break;
		case Save_graph:
			pAct = new SaveAction(this);
			break;
		case load_graph:
			pAct = new LoadAction(this);
			break;
		case FILLING:
			pAct = new FillingAction(this);
			break;
		case DRAWING:
			pAct = new DrawingAction(this);
			break;
		case Voice:
			pAct = new VoiceAction(this);
				break;
		case MOVE:
			pAct = new MoveAction(this);
			break;
		case EXIT:
			pAct = new ClearAllAction(this);
			break;
		case STATUS:	//a click on the status bar ==> no action
			return;
	}
	
	//Execute the created action
	if(pAct != NULL)
	{
		pAct->Execute();//Execute
		delete pAct;	//You may need to change this line depending to your implementation
		pAct = NULL;
	}
}
//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//

//Add a figure to the list of figures
void ApplicationManager::AddFigure(CFigure* pFig)
{
	if(FigCount < MaxFigCount )
		FigList[FigCount++] = pFig;	
}
void ApplicationManager::deletefig(CFigure* pFig)
{
	for(int i=0;i<FigCount;i++)
		if (FigList[i] == pFig) {
			delete FigList[i];
			FigList[i] = NULL;
			break;
		}
}
////////////////////////////////////////////////////////////////////////////////////
CFigure *ApplicationManager::GetFigure(int x, int y) const
{
	for (int i = FigCount-1; i >= 0; i--) {
		if(FigList[i] != NULL)
		if(FigList[i]->is_inside(x, y)==1&& !(FigList[i]->Ishidden()) )
			return FigList[i];
	}
	return NULL;
}
int ApplicationManager::getfigcount() { return FigCount; }

void ApplicationManager::de_select() const
{
	for (int i = 0; i < FigCount; i++) {
		if(FigList[i]!=NULL)
		FigList[i]->SetSelected(0);
	}
}
void ApplicationManager::unhide() const
{
	for (int i = 0; i < FigCount; i++) {
		if (FigList[i] != NULL)
			FigList[i]->Sethidden(0);
	}
}
Action** ApplicationManager::GetActionList()
{
	return ActionList;
}

int ApplicationManager::GetActionCount()
{
	return ActionCount;
}

void ApplicationManager::AddAction(Action* pAct)
{
	if (ActionCount < MaxRecActions)
		ActionList[ActionCount++] = pAct;
}

void ApplicationManager::SetIsRec(bool Rec)
{
	Is_Recording = Rec;
}

bool ApplicationManager::GetIsRec()
{
	return Is_Recording;
}


//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{	
	pOut->ClearDrawArea();
	for (int i = 0; i < FigCount; i++) {
		if(FigList[i]!=NULL&&!(FigList[i]->Ishidden()))
		FigList[i]->Draw(pOut);		//Call Draw function (virtual member fn)
	}
}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the input
Input *ApplicationManager::GetInput() const
{	return pIn; }
//Return a pointer to the output
Output *ApplicationManager::GetOutput() const
{	return pOut; }
////////////////////////////////////////////////////////////////////////////////////
//Destructor
ApplicationManager::~ApplicationManager()
{
	for (int i = 0; i < FigCount; i++) {
		if(FigList[i]!=NULL)
		delete FigList[i];
	}
	delete pIn;
	delete pOut;
	
}
