#include "AddCircleAction.h"


#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddCircleAction::AddCircleAction(ApplicationManager* pApp) :Action(pApp)
{
	pManager->setisundo(true);
	pManager->setisredo(false);
}

void AddCircleAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Circle: Click at midd");

	//Read 1st corner and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);

	pOut->PrintMessage("New Circle: Click at radius");

	//Read 2nd corner and store in point P2
	pIn->GetPointClicked(P2.x, P2.y);

	RectGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	RectGfxInfo.DrawClr = pOut->getCrntDrawColor();
	RectGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

//Execute the action
void AddCircleAction::Execute(bool w)
{
	if(pManager->getsound())
		PlaySound("Circle.wav",NULL,SND_SYNC);
	//This action needs to read some parameters first
	if(w)
	ReadActionParameters();

	//Create a rectangle with the parameters read from the user
	R = new CCircle(P1, P2, RectGfxInfo);

	//Add the rectangle to the list of figures
	pManager->AddFigure(R);
}

bool AddCircleAction::isrecord()
{
	return true;
}
void AddCircleAction::undo()
{
	cpyR=R;
	pManager->deletefigure(R);
}
void AddCircleAction::redo()
{
	pManager->AddFigure(cpyR);
}