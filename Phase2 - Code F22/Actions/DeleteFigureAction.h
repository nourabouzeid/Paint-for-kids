#pragma once
#include "Action.h"
class DeleteFigureAction : public Action
{
private:
public:
	DeleteFigureAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};

