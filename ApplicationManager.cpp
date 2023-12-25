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
#include "Actions\Pick_color.h"
#include "Actions\pick_both.h"
#include "Actions\ResizeAction.h"
#include "Figures/CCirc.h"
#include "Figures/CHexa.h"
#include "Figures/CRectangle.h"
#include "Figures/CSquare.h"
#include "Figures/CTri.h"
#include "Actions\StartRecAction.h"
#include "Actions\StopRecAction.h"
#include "Actions\PlayRecAction.h"
#include "Actions/MoveAction.h"
#include "Actions/MoveByDrag.h"
#include <fstream>
#include "Actions/ExitAction.h"
#include "Actions/ToPlayAction.h"
#include "Actions/ToDrawAction.h"
#include "Actions/ToFiguresAction.h"
#include "Actions/UndoAction.h"
#include "Actions/RedoAction.h"
//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	Is_Recording=false;
	
	pOut = new Output;
	pIn = pOut->CreateInput();
	FigCount = 0;
	RecFIGCount = 0;
	UndoCount = 0;
	redofigcount = 0;
	Redocount = 0;
	SelectedfigM = 0;
	SelectedfigC = 0;
	numofpoints = 0;
	numoffill = 0;
	numofdraw = 0;
	filled = false;
	//Create an array of figure pointers and set them to NULL		
	for(int i=0; i<MaxFigCount; i++)
		FigList[i] = NULL;	
	for (int i = 0; i < MaxRecActions; i++)
		RECFigList[i] = NULL;
	SelectedFig = NULL;
	for (int i = 0; i < MaxUndoActions; i++)
		UndoactionList[i] = NULL;
	for (int i = 0; i < MaxRedoActions; i++)
		RedoactionList[i] = NULL;
	for (int i = 0; i < MaxRedoFiglist; i++)
		RedoFiglist[i] = NULL;
	for (int i = 0; i < 5; i++)
		numofmoved[i] = NULL;
	for (int i = 0; i < 5; i++)
		numofchanged[i] = NULL;
}
int ApplicationManager::count_fig(char Fig_t) {
	int count = 0;
		for (int i = 0; i < FigCount; i++) {
			if (FigList[i]->type()==Fig_t)
				count++;
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
int ApplicationManager::count_fig(char Fig_t, color col) {
	int count = 0;
	for (int i = 0; i < FigCount; i++) {
		if (FigList[i]->type() == Fig_t&&FigList[i]->get_color()==col)
			count++;
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
			pAct = new ToFiguresAction(this);
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
			pAct = new ToDrawAction(this);
			break;
		case TO_PLAY:
			pAct = new ToPlayAction(this);
			break;
		case BACK_TO_DRAW:
			pAct = new ToDrawAction(this);
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
		case MOVEBYDRAG:
			pAct = new MoveByDrag(this);
			break;
		case RESIZE:
			pAct = new ResizeAction(this);
			break;
		case EXIT:
			pAct = new ExitAction(this);
			break;
		case PickColor:
			pAct = new Pick_color(this);
			break;
		case Pick_both:
			pAct = new pick_both(this);
			break;
		case UNDO:
			pAct = new UndoAction(this);
			 
			break;
		case REDO:
			pAct = new RedoAction(this);
			break;
		case STATUS:	//a click on the status bar ==> no action
			return;
	}
	
	//Execute the created action
	if (pAct != NULL)
	{
		pAct->Execute();//Execute
		if (dynamic_cast<selectAction*>(pAct) || dynamic_cast<RedoAction*>(pAct) || dynamic_cast<UndoAction*>(pAct) || dynamic_cast<ClearAllAction*>(pAct) || dynamic_cast<VoiceAction*>(pAct) || dynamic_cast<pick_figure*>(pAct) || dynamic_cast<StartRecAction*>(pAct) || dynamic_cast<StopRecAction*>(pAct) || dynamic_cast<PlayRecAction*>(pAct) || dynamic_cast<ActionToPick*>(pAct) || dynamic_cast<ClearAllAction*>(pAct) || dynamic_cast<SaveAction*>(pAct) || dynamic_cast<LoadAction*>(pAct))
		{
			delete pAct;
			pAct = NULL;
		}

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

void ApplicationManager::unhide() const
{
	for (int i = 0; i < FigCount; i++) {
		if (FigList[i] != NULL)
			FigList[i]->Sethidden(0);
	}
}

CFigure** ApplicationManager::GetRECFigList()
{
	return RECFigList;
}

int ApplicationManager::GetRecFIGCount()
{
	return RecFIGCount;
}

void ApplicationManager::AddRECFig(CFigure* pFig)
{
	if (RecFIGCount < MaxRecActions)
		RECFigList[RecFIGCount++] = pFig;

}


void ApplicationManager::SetIsRec(bool Rec)
{
	Is_Recording = Rec;
}

bool ApplicationManager::GetIsRec()
{
	return Is_Recording;
}

void ApplicationManager::Setundocount()
{
	UndoCount = 0;
}

int ApplicationManager::GetUndoCount()
{
	return UndoCount;
}

void ApplicationManager::AddUndoAction(Action* pAct)
{
	if (UndoCount < MaxUndoActions)
	{
		UndoactionList[UndoCount++] = pAct;
	}
	else
	{
		delete UndoactionList[0];
		UndoactionList[0] = NULL;
		for (int i = 0; i < (MaxUndoActions - 1); i++)
		{
			UndoactionList[i] = UndoactionList[i + 1];
		}
		UndoactionList[4] = pAct;
	}
}



void ApplicationManager::deletelastfig()
{
	if (FigList[FigCount - 1] != NULL)
	{
		AddRedofiglist(FigList[FigCount - 1]);
		FigList[FigCount - 1] = NULL;
		FigCount--;
	}
}

CFigure* ApplicationManager::Getlastfig()
{
	return FigList[FigCount - 1];
}

void ApplicationManager::AddRedofiglist(CFigure* f)
{
	//	if (RedoFiglist[redofigcount++]!=NULL)
	RedoFiglist[redofigcount++] = f;
}

Action* ApplicationManager::GetfirstRedoAction()
{
	if (RedoactionList[GetRedoCount() - 1])
		return RedoactionList[GetRedoCount() - 1];
}

CFigure* ApplicationManager::GetlastRedoFig()
{
	return RedoFiglist[redofigcount - 1];
}

int ApplicationManager::GetRedoCount()
{
	return Redocount;
}

CFigure* ApplicationManager::GetfigselectedM()
{
	return numofmoved[SelectedfigM - 1];
}

void ApplicationManager::deleteRedoAction()
{
	if (RedoactionList[GetRedoCount() - 1])
	{
		delete RedoactionList[GetRedoCount() - 1];
		RedoactionList[GetRedoCount() - 1] = NULL;
		Redocount--;
	}
}

void ApplicationManager::Addpoint(Point p)
{
	pointmove[numofpoints++] = p;
}

Point ApplicationManager::Getpoint()
{
	return pointmove[numofpoints - 1];
}

void ApplicationManager::Addfillcolor(color g)
{
	fillcolor[numoffill++] = g;
}

color ApplicationManager::Getfillcolor()
{
	return fillcolor[numoffill - 2];
}

void ApplicationManager::Adddrawcolor(color g)
{
	drawcolor[numofdraw++] = g;
}

void ApplicationManager::deldraw()
{
	numofdraw--;
}

void ApplicationManager::delUndocount()
{
	UndoCount--;
}

void ApplicationManager::delRedoAction()
{
	if (RedoactionList[Redocount - 1])
	{
		delete RedoactionList[Redocount - 1];
		RedoactionList[Redocount - 1] = NULL;
		Redocount--;
	}
}

void ApplicationManager::delfigredo()
{
	if (RedoFiglist[redofigcount - 1] != NULL)
	{
		//delete RedoFiglist[redofigcount - 1];
		//RedoFiglist[redofigcount - 1] = NULL;
		redofigcount--;
	}
}

void ApplicationManager::SetFilled(bool f)
{
	filled = f;
}

bool ApplicationManager::GetFilled()
{
	return filled;
}

color ApplicationManager::GetfillRedo()
{
	return fillcolor[numoffill - 1];
}

color ApplicationManager::GetdrawRedo()
{
	return drawcolor[numofdraw - 1];
}

void ApplicationManager::Incrementfill()
{
	numoffill++;
}

void ApplicationManager::Incrementdraw()
{
	numofdraw++;
}

Point ApplicationManager::GetpointRedo()
{
	return pointmove[numofpoints - 2];
}

Action** ApplicationManager::GetUndoAction()
{
	return UndoactionList;
}

Action** ApplicationManager::GetRedoAction()
{
	return RedoactionList;
}

CFigure** ApplicationManager::GetRedofig()
{
	return RedoFiglist;
}

int ApplicationManager::Getredofigcount()
{
	return redofigcount;
}

color ApplicationManager::Getdrawcolor()
{
	return drawcolor[numofdraw - 2];
}

void ApplicationManager::defill()
{
	numoffill--;
}

int ApplicationManager::Getnumoffill()
{
	return numoffill;
}

int ApplicationManager::Getnumofdraw()
{
	return numofdraw;
}

CFigure* ApplicationManager::GetfigSelectedC()
{
	return numofchanged[SelectedfigC - 1];
}


void ApplicationManager::AddfigselectedC(CFigure* f)
{
	numofchanged[SelectedfigC++] = f;
}

void ApplicationManager::AddfigselectedM(CFigure* f)
{
	numofmoved[SelectedfigM++] = f;
}

Action* ApplicationManager::GetlastUndo()
{

	if (UndoactionList[(GetUndoCount() - 1)])
		return UndoactionList[(GetUndoCount() - 1)];
}

void ApplicationManager::AddRedoAction(Action* p)
{
	if (Redocount < MaxRedoActions)
	{
		RedoactionList[Redocount++] = p;
	}
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
	pOut->Updatebuffer();
}
void ApplicationManager::Updatefigure(CFigure* Fig) const
{
	for (int i = 0; i < FigCount; i++) {
		if (FigList[i] != NULL && !(FigList[i]->Ishidden())&&FigList[i]->IsSelected())		//under development
			FigList[i]->Draw(pOut);
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
