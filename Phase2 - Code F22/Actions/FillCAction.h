#pragma once
#include "Action.h"

class FillCAction : public Action
{
private:
	color c;
public:
	FillCAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};

