#ifndef ADD_HEX_ACTION_H
#define ADD_HEX_ACTION_H

#include "Action.h"
#include "..\Figures\CHex.h"
class AddHexAction : public Action
{
private:
	Point P1; //Rectangle Corners
	GfxInfo RectGfxInfo;
public:
	AddHexAction(ApplicationManager* pApp);

	//Reads rectangle parameters
	virtual void ReadActionParameters();

	//Add rectangle to the ApplicationManager
	virtual void Execute();

};
#endif

