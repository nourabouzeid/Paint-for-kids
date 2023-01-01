#include "ExitAction.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

ExitAction::ExitAction(ApplicationManager* pApp) :Action(pApp)
{
	pManager->setisundo(false);
	pManager->setisredo(false);
}


void ExitAction::ReadActionParameters()
{
}

bool ExitAction::Execute(bool w)
{
	remove("PlayMode.txt");
	pManager->clearall();
	return true;
}

bool ExitAction::isrecord()
{
	return false;
}
void ExitAction::undo()
{
}
void ExitAction::redo()
{
}