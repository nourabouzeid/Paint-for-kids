#include "SelectAction.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

SelectAction::SelectAction(ApplicationManager* pApp):Action(pApp)
{}

void SelectAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("please Click inside a figure");

	//Read 1st corner and store in point P1
	pIn->GetPointClicked(p.x, p.y);

	pOut->ClearStatusBar();
}

void SelectAction::Execute()
{
	CFigure* cf1;
	CFigure* cf2;
	ReadActionParameters();
	cf2= pManager->getselectedfigure();
	cf1= pManager->GetFigure(p);
	if (cf1)
	{
		if (cf1->IsSelected())
		{
			cf1->SetSelected(false);
			pManager->setselectedfigure(NULL);
		}
		else
		{
			if(cf2)
			cf2->SetSelected(false);
			cf1->SetSelected(true);
			pManager->setselectedfigure(cf1);
		}
	}
}
