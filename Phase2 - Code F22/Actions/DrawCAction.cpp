#include "DrawCAction.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

DrawCAction::DrawCAction(ApplicationManager* pApp) :Action(pApp)
{}


void DrawCAction::ReadActionParameters()
{
	c = pManager->getcolor();
}

void DrawCAction::Execute(bool w)
{
	if(w)
	ReadActionParameters();
	CFigure* cf1;
	cf1=pManager->getselectedfigure();
	if(cf1)
	cf1->ChngDrawClr(c);
}

bool DrawCAction::isrecord()
{
	return true;
}
