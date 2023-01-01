#include "ClearAllAction.h"
#include "..\ApplicationManager.h"




ClearAllAction::ClearAllAction(ApplicationManager* pApp) :Action(pApp)
{
	pManager->setisundo(false);
	pManager->setisredo(false);
}



void ClearAllAction::ReadActionParameters()
{}




bool ClearAllAction::Execute(bool w)
{
	Output* pOut = pManager->GetOutput();
	pOut->ClearDrawArea();
	pManager->clearall();
	if (recordeddd())
		return false;
	else
		return true;
}

bool ClearAllAction::isrecord()
{
	return true;
}
void ClearAllAction::undo()
{
}
void ClearAllAction::redo()
{
}