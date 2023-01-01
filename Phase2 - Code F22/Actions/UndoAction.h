#pragma once
#include "Action.h"
class UndoAction :public Action
{
private:
	Action* undoaction;
	
public:
	UndoAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual bool Execute(bool w=true);
	bool isrecord();
	virtual void undo();
	virtual void redo();
	
};

