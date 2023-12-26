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
	enum { MaxFigCount = 200, MaxRecActions = 20, MaxUndoRedo = 5 };	//Max no of figures


private:
	int FigCount;		//Actual number of figures
	CFigure* FigList[MaxFigCount];	//List of all figures (Array of pointers)
	CFigure* SelectedFig; //Pointer to the selected figure
	//Pointers to Input and Output classes
	Input* pIn;
	Output* pOut;
	CFigure* RECFigList[MaxRecActions];
	CFigure* Undo[MaxUndoRedo];
	CFigure* Redo[MaxUndoRedo];
	int RecFIGCount;
	int UndoCount;
	int RedoCount;
	bool Is_Recording;

public:
	ApplicationManager();
	~ApplicationManager();
	// -- Action-Related Functions
	//Reads the input command from the user and returns the corresponding action type
	void Clearall();
	int getfigcount();
	ActionType GetUserAction() const;
	void ExecuteAction(ActionType); //Creates an action and executes it
	void unhide() const;//unhide all figures
	// -- Figures Management Functions
	void AddFigure(CFigure* pFig);          //Adds a new figure to the FigList
	CFigure* GetFigure(int x, int y) const; //Search for a figure given a point inside the figure
	void set_selected(CFigure* pFig);
	CFigure* Get_selected() const; //get selected figure
	CFigure* GetFigBy_id(int id) const; //get selected figure
	void deletefig(CFigure* pFig); // delete a specific figure using it's pointer
	void replacefig(CFigure* pFig,CFigure* x); //replace a figure pFig with another one x
	int count_fig(char Fig_t); //count figures of specific shapes
	int count_fig(char Fig_t, color c); //count figures of both specific shapes and colors
	int count_fig(color c); //count figures of specific colors
	void SaveAll(ofstream&);
	int GetFigCount();
	// -- Interface Management Functions
	Input* GetInput() const; //Return pointer to the input
	Output* GetOutput() const; //Return pointer to the output
	void UpdateInterface() const;	//Redraws all the drawing window	
	CFigure** GetRECFigList();
	int  GetRecFIGCount();
	void AddRECFig(CFigure* pFig);
	void SetIsRec(bool Rec);
	bool GetIsRec();
	int GetUndoCount();
	int GetRedoCount();
	void decrementUndoCount();//decreasing the undo actions by 1
	void setUndo_RedoCount(int u);
	void decrementRedoCount();//decreasing the redo actions by 1
	CFigure** GetUndo();// returning the undo figlist
	CFigure** GetRedo();// returning the redo figlist
	void AddUndo(CFigure* pFig);//adding a figure to undo list
	void AddRedo(CFigure* pFig);//adding a figure to redo list
};

#endif