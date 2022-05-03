#pragma once
#include "cocos2d.h"
#include "Calculator.h"
#include "ui/CocosGUI.h"

USING_NS_CC;

class AllAnswerScene :public LayerColor
{
public:
	static Scene* createScene();

	CREATE_FUNC(AllAnswerScene);

	virtual bool init();

	void enterFirstScene(Ref* pSender);

};