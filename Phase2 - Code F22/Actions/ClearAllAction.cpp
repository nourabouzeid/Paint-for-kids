#include "ClearAllAction.h"
#include "..\ApplicationManager.h"




ClearAllAction::ClearAllAction(ApplicationManager* pApp) :Action(pApp)
{}



void ClearAllAction::ReadActionParameters()
{}




void ClearAllAction::Execute(bool w)
{
	Output* pOut = pManager->GetOutput();
	pOut->ClearDrawArea();
	pManager->clearallfigure();
}

bool ClearAllAction::isrecord()
{
	return false;
}
void ClearAllAction::undo()
{
}
void ClearAllAction::redo()
{
}