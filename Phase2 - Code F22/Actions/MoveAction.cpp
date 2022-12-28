#include "MoveAction.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"



MoveAction::MoveAction(ApplicationManager* pApp) : Action(pApp)
{}



void MoveAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("please Click a point you want to move there");

	//Read 1st corner and store in point P1
	pIn->GetPointClicked(p.x, p.y);

	pOut->ClearStatusBar();
	pOut->ClearDrawArea();
}




void MoveAction::Execute()
{
	ReadActionParameters();
	pManager->MOVEE(p);
}
