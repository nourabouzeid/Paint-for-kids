#include "StartAction.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

StartAction::StartAction(ApplicationManager* pApp) :Action(pApp)
{}

void StartAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();

	pOut->PrintMessage(" recording......");
}

void StartAction::Execute(bool w)
{
	if (w)
	ReadActionParameters();
	Action* acttype;
	acttype = pManager->getlastaction();
	if ((acttype->isrecord()))
		pManager->setlastaction(acttype);
}

bool StartAction::isrecord()
{
	return false;
}

