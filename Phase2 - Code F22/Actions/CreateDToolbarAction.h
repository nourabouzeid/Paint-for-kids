#pragma once
#include "Action.h"
class CreateDToolbarAction :   public Action
{
private:
public:
	CreateDToolbarAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};

