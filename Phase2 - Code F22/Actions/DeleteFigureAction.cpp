#include "DeleteFigureAction.h"
#include "..\ApplicationManager.h"




DeleteFigureAction::DeleteFigureAction(ApplicationManager* pApp) :Action(pApp)
{}



void DeleteFigureAction::ReadActionParameters()
{
	cf= pManager->getselectedfigure();
}




void DeleteFigureAction::Execute(bool w)
{
	ReadActionParameters();
	pManager->deletefigure(cf);
}

bool DeleteFigureAction::isrecord()
{
	return true;
}
void DeleteFigureAction::undo()
{
	pManager->AddFigure(cf);
}
void DeleteFigureAction::redo()
{
	pManager->deletefigure(cf);
}