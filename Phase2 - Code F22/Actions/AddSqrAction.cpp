#include "AddSqrAction.h"


#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddSqrAction::AddSqrAction(ApplicationManager* pApp) :Action(pApp)
{}

void AddSqrAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Square: Click at midd");

	//Read 1st corner and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);


	RectGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	RectGfxInfo.DrawClr = pOut->getCrntDrawColor();
	RectGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

//Execute the action
void AddSqrAction::Execute(bool w)
{
	if(pManager->getsound())
		PlaySound("Square.wav",NULL,SND_SYNC);
	//This action needs to read some parameters first
	if(w)
	ReadActionParameters();

	//Create a rectangle with the parameters read from the user
	Squr=new CSquare(P1, RectGfxInfo);
	//Add the rectangle to the list of figures
	pManager->AddFigure(Squr);
}

bool AddSqrAction::isrecord()
{
	return true;
}
void AddSqrAction::undo() 
{
	Output* pOut = pManager->GetOutput();
	pOut->ClearDrawArea();
	pManager->deletefigure(Squr);
	pManager->UpdateInterface();
	pManager->GetOutput()->PrintMessage("Undo Drawing Square");
}

void AddSqrAction::redo() 
{
	Output* pOut = pManager->GetOutput();
	pOut->ClearDrawArea();
	pManager->AddFigure(Squr);
	pManager->UpdateInterface();
	pManager->GetOutput()->PrintMessage("Redo Drawing Square");
}

