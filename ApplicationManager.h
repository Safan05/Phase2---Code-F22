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
	enum { MaxFigCount = 200, MaxRecActions = 20 , MaxUndoActions = 5, MaxRedoFiglist = 5, MaxRedoActions = 5
	};	//Max no of figures


private:
	int FigCount;		//Actual number of figures
	CFigure* FigList[MaxFigCount];	//List of all figures (Array of pointers)
	CFigure* SelectedFig; //Pointer to the selected figure
	//Pointers to Input and Output classes
	Input* pIn;
	Output* pOut;
	CFigure* RECFigList[MaxRecActions];
	Action* UndoactionList[MaxUndoActions];
	Action* RedoactionList[MaxRedoActions];
	CFigure* RedoFiglist[MaxRedoFiglist];
	CFigure* numofmoved[10];
	CFigure* numofchanged[10];//array of pointers to figures stored the changed color figures
	Point pointmove[5];
	color fillcolor[10];
	color drawcolor[10];
	CFigure* figdel[5];
	bool filled;
	int UndoCount;
	int Redocount;
	int ActionCount;
	int SelectedfigM;
	int SelectedfigC;
	int numofpoints;
	int numofdraw;
	int numoffill;
	int redofigcount;
	int RecFIGCount;
	int undoactioncount;
	int figdell;
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
	void Updatefigure(CFigure * Fig) const;
	CFigure** GetRECFigList();
	int  GetRecFIGCount();
	void AddRECFig(CFigure* pFig);
	void SetIsRec(bool Rec);
	bool GetIsRec();
	int GetUndoCount();
	void AddUndoAction(Action* pAct);
	void AddRedoAction(Action* p);
	void deleteRedoAction();
	Action* GetfirstRedoAction();
	int GetRedoCount();
	void AddRedofiglist(CFigure* f);
	CFigure* GetlastRedoFig();
	void deletelastfig();
	CFigure* Getlastfig();
	Action* GetlastUndo();
	void AddfigselectedM(CFigure* f);
	CFigure* GetfigselectedM();
	void AddfigselectedC(CFigure* f);
	CFigure* GetfigSelectedC();
	void Addpoint(Point p);
	Point Getpoint();
	void Addfillcolor(color g);
	color Getfillcolor();
	void Adddrawcolor(color g);
	color Getdrawcolor();
	void defill();
	int Getnumoffill();
	int Getnumofdraw();
	void deldraw();
	void delUndocount();
	void delRedoAction();
	void delfigredo();
	void SetFilled(bool f);
	bool GetFilled();
	color GetfillRedo();
	color GetdrawRedo();
	void Incrementfill();
	void Incrementdraw();
	Point GetpointRedo();
	Action** GetUndoAction();
	Action** GetRedoAction();
	CFigure** GetRedofig();
	int Getredofigcount();
	void Setundocount();
	int Getundocount();
	void AddFigdel(CFigure* f);
	CFigure* Getfigdel();
};

#endif