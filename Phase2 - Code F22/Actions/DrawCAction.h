#pragma once
#include "Action.h"

class DrawCAction : public Action
{
private:
	color c;
public:
	DrawCAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};

