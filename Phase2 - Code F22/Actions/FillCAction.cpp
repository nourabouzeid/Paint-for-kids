#include "FillCAction.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

FillCAction::FillCAction(ApplicationManager* pApp) :Action(pApp)
{}


void FillCAction::ReadActionParameters()
{
	c = pManager->getcolor();
}

void FillCAction::Execute(bool w)
{
	if (w)
		ReadActionParameters();
	CFigure* cf1;
	cf1 = pManager->getselectedfigure();
	if(cf1)
	cf1->ChngFillClr(c);
}

bool FillCAction::isrecord()
{
	return true;
}
