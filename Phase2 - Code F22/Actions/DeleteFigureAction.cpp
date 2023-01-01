#include "DeleteFigureAction.h"
#include "..\ApplicationManager.h"




DeleteFigureAction::DeleteFigureAction(ApplicationManager* pApp) :Action(pApp)
{
	pManager->setisundo(true);
	pManager->setisredo(false);
}



void DeleteFigureAction::ReadActionParameters()
{
	cf= pManager->getselectedfigure();
}




bool DeleteFigureAction::Execute(bool w)
{
	ReadActionParameters();
	cpycf=cf;
	pManager->deletefigure(cf);
	return false;
}

bool DeleteFigureAction::isrecord()
{
	return true;
}
void DeleteFigureAction::undo()
{
	pManager->AddFigure(cpycf);
}
void DeleteFigureAction::redo()
{
	pManager->deletefigure(cf);
}