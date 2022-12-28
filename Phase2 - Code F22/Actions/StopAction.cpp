#include "StopAction.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

StopAction::StopAction(ApplicationManager* pApp) :Action(pApp)
{}

void StopAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();

	pOut->PrintMessage("stop recording");
}

void StopAction::Execute(bool w)
{
	if (w)
    ReadActionParameters();
}

bool StopAction::isrecord()
{
	return false;
}
