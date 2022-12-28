#include "FillCAction.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

FillCAction::FillCAction(ApplicationManager* pApp) :Action(pApp)
{}


void FillCAction::ReadActionParameters()
{}

void FillCAction::Execute(bool w)
{
	CFigure* cf1;
	c = pManager->getcolor();
	cf1 = pManager->getselectedfigure();
	if(cf1)
	cf1->ChngFillClr(c);
}

bool FillCAction::isrecord()
{
	return true;
}
