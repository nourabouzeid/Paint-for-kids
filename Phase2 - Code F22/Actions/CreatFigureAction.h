#pragma once
#include "Action.h"
class CreatFigureAction : public Action
{
private:
public:
	CreatFigureAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};

