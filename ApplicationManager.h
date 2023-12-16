#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "DEFS.h"
#include "Figures\CFigure.h"
#include "GUI\input.h"
#include "GUI\output.h"
#include "Actions\Action.h"
//Main class that manages everything in the application.
class ApplicationManager
{
	enum { MaxFigCount = 200, MaxRecActions = 20 };	//Max no of figures

private:
	int FigCount;		//Actual number of figures
	CFigure* FigList[MaxFigCount];	//List of all figures (Array of pointers)
	CFigure* SelectedFig; //Pointer to the selected figure
	//Pointers to Input and Output classes
	Input* pIn;
	Output* pOut;
	Action* ActionList[MaxRecActions]; // list for all action(for the recording)
	int ActionCount;
	bool Is_Recording;
public:	
	ApplicationManager(); 
	~ApplicationManager();
	
	// -- Action-Related Functions
	//Reads the input command from the user and returns the corresponding action type
	void Clearall();
	int getfigcount();
	ActionType GetUserAction() const;
	void ExecuteAction(ActionType) ; //Creates an action and executes it
	void de_select() const; //deselect all figure
	void unhide() const;//unhide all figures
	// -- Figures Management Functions
	void AddFigure(CFigure* pFig);          //Adds a new figure to the FigList
	CFigure *GetFigure(int x, int y) const; //Search for a figure given a point inside the figure
	void set_selected(CFigure* pFig);
	CFigure* Get_selected() const; //get selected figure
	void deletefig(CFigure* pFig);
	int count_fig(char Fig_t);
	int count_fig(char Fig_t, color c);
	int count_fig(color c);
	void SaveAll(ofstream &);
	int GetFigCount();
	// -- Interface Management Functions
	Input *GetInput() const; //Return pointer to the input
	Output *GetOutput() const; //Return pointer to the output
	void UpdateInterface() const;	//Redraws all the drawing window	
	Action** GetActionList();
	int  GetActionCount();
	void AddAction(Action* pAct);
	void SetIsRec(bool Rec);
	bool GetIsRec();
};

#endif