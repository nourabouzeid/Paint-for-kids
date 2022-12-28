#include "DeleteFigureAction.h"
#include "..\ApplicationManager.h"




DeleteFigureAction::DeleteFigureAction(ApplicationManager* pApp) :Action(pApp)
{}



void DeleteFigureAction::ReadActionParameters()
{}




void DeleteFigureAction::Execute()
{
	CFigure* cf;
	Output* pOut = pManager->GetOutput();
	pOut->ClearDrawArea();
	cf= pManager->getselectedfigure();
	pManager->deletefigure(cf);
}