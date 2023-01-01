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

void ExitAction::Execute(bool w)
{
	remove("PlayMode.txt");
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