#ifndef ADD_HEX_ACTION_H
#define ADD_HEX_ACTION_H

#include "Action.h"
#include "..\Figures\CHex.h"
class AddHexAction : public Action
{
private:
	Point P1; //Rectangle Corners
	GfxInfo RectGfxInfo;
	CFigure* Hex;
public:
	AddHexAction(ApplicationManager* pApp);

	//Reads rectangle parameters
	virtual void ReadActionParameters();

	//Add rectangle to the ApplicationManager
	virtual void Execute(bool w = true);
	bool isrecord();
	virtual void undo();
	virtual void redo();
};
#endif

