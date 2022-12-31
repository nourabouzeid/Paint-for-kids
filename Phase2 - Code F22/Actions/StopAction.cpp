#include "StopAction.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

StopAction::StopAction(ApplicationManager* pApp) :Action(pApp)
{}

void StopAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	bool rec = pManager->getrecording();
	if(rec)
	pOut->PrintMessage("stop recording");
	else 
	pOut->PrintMessage("you must start recording first..");
}

void StopAction::Execute(bool w)
{
	if (w)
    ReadActionParameters();
	pManager->setrecording(false);
	pManager->setstop(true);
}

bool StopAction::isrecord()
{
	return false;
}
void StopAction::undo(){}
void StopAction::redo(){}
