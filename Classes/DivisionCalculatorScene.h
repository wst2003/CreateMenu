#pragma once
#include "cocos2d.h"
#include "Calculator.h"
#include "ui/CocosGUI.h"

USING_NS_CC;

class DivisionScene :public LayerColor
{
public:
	static Scene* createScene();

	CREATE_FUNC(DivisionScene);

	virtual bool init();

	void enterFirstScene(Ref* pSender);
	void printAnswer(Ref* pSender);
	
private:
	Label* resultLabel;
	DivisionCalculator divisionCalculate;
};