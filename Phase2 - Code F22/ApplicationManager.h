#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "DEFS.h"
#include "Figures\CFigure.h"
#include "GUI\input.h"
#include "GUI\output.h"
#include "Actions\AddRectAction.h"
#include "Actions\AddSqrAction.h"
#include "Actions\AddTriangleAction.h"
#include "Actions\AddCircleAction.h"
#include "Actions\AddHexAction.h"
#include "Actions\SelectAction.h"
#include "Actions\DrawCAction.h"
#include "Actions\FillCAction.h"
#include "Actions\ClearAllAction.h"
#include "Actions\CreatDAction.h"
#include "Actions\CreatFAction.h"
#include "Actions\CreateDToolbarAction.h"
#include "Actions\CreatePToolbarAction.h"
#include "Actions\CreatFigureAction.h"
#include "Actions\DeleteFigureAction.h"
#include "Actions\MoveAction.h"
#include "Actions\SaveAction.h"
#include "Actions\LoadAction.h"

//Main class that manages everything in the application.
class ApplicationManager
{
	enum { MaxFigCount = 200 };	//Max no of figures

private:
	color c1;
	int FigCount, f,ID;		//Actual number of figures
	CFigure* FigList[MaxFigCount];	//List of all figures (Array of pointers)

	CFigure* SelectedFig; //Pointer to the selected figure

	//Pointers to Input and Output classes
	Input *pIn;
	Output *pOut;

public:	
	ApplicationManager(); 
	~ApplicationManager();
	
	// -- Action-Related Functions
	//Reads the input command from the user and returns the corresponding action type
	ActionType GetUserAction() const;
	void ExecuteAction(ActionType) ; //Creates an action and executes it
	
	// -- Figures Management Functions
	void AddFigure(CFigure* pFig);          //Adds a new figure to the FigList
	CFigure* GetFigure(Point p) const; //Search for a figure given a point inside the figure
	void setselectedfigure(CFigure* cf);
	color getcolor();
	void deleteallfigure();
	CFigure* getselectedfigure();
	void deletefigure(CFigure* cf1);
	void MOVEE(Point p) const;
	void SaveAll(ofstream& Fout);
	// -- Interface Management Functions
	Input *GetInput() const; //Return pointer to the input
	Output *GetOutput() const; //Return pointer to the output
	void UpdateInterface() const;	//Redraws all the drawing window	
	string clrtostring(color clr);
};

#endif