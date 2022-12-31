#include "DeleteFigureAction.h"
#include "..\ApplicationManager.h"




DeleteFigureAction::DeleteFigureAction(ApplicationManager* pApp) :Action(pApp)
{}



void DeleteFigureAction::ReadActionParameters()
{}




void DeleteFigureAction::Execute(bool w)
{
	Output* pOut = pManager->GetOutput();
	pOut->ClearDrawArea();
	Fig= pManager->getselectedfigure();
	pManager->deletefigure(Fig);
}

bool DeleteFigureAction::isrecord()
{
	return true;
}
 void DeleteFigureAction::undo()
 {	
 }
 void DeleteFigureAction::redo(){}