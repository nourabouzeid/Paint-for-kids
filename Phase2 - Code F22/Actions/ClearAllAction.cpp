#include "ClearAllAction.h"
#include "..\ApplicationManager.h"




ClearAllAction::ClearAllAction(ApplicationManager* pApp) :Action(pApp)
{}



void ClearAllAction::ReadActionParameters()
{}




void ClearAllAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	pOut->ClearDrawArea();
	pManager->deleteallfigure();
}
