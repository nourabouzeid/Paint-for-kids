#include "PlayRecordAction.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

PlayRecordAction::PlayRecordAction(ApplicationManager* pApp) :Action(pApp)
{}

void PlayRecordAction::ReadActionParameters()
{
}

void PlayRecordAction::Execute(bool w)
{
	Output* pOut = pManager->GetOutput();
	pOut->ClearDrawArea();
	pManager->deleteallfigure();
	pManager->excuteplayactions();
}

bool PlayRecordAction::isrecord()
{
	return false;
}

