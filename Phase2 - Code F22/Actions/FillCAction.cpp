#include "FillCAction.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

FillCAction::FillCAction(ApplicationManager* pApp) :Action(pApp)
{}


void FillCAction::ReadActionParameters()
{
	c = pManager->getcolor();
	cf1 = pManager->getselectedfigure();
	isfill=cf1->getGfxInfo().isFilled;
	if(isfill)
		oldc=cf1->getGfxInfo().FillClr;
}

void FillCAction::Execute(bool w)
{
	if (w)
		ReadActionParameters();
	if(cf1)
	cf1->ChngFillClr(c);
}

bool FillCAction::isrecord()
{
	return true;
}
void FillCAction::undo()
{
	if(isfill)
		cf1->ChngFillClr(oldc);
	else 
		cf1->setisfilled(false);
}
void FillCAction::redo()
{
	if(isfill)
		cf1->ChngFillClr(c);
	else 
		cf1->setisfilled(false);
}