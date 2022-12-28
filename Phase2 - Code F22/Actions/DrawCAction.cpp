#include "DrawCAction.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

DrawCAction::DrawCAction(ApplicationManager* pApp) :Action(pApp)
{}


void DrawCAction::ReadActionParameters()
{
}

void DrawCAction::Execute()
{
	CFigure* cf1;
	c = pManager->getcolor();
	cf1=pManager->getselectedfigure();
	if(cf1)
	cf1->ChngDrawClr(c);
}