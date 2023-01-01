#pragma once
#include "Action.h"

class ExitAction : public Action
{
private:
	
public:
	ExitAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual bool Execute(bool w = true);
	bool isrecord();
	virtual void undo();
	virtual void redo();
};