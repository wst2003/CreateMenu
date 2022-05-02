#ifndef __MULTIPLY_SCENE_H__
#define __MULTIPLY_SCENE_H__

#include "cocos2d.h"
#include "Calculator.h"

class Multiply : public cocos2d::Layer, cocos2d::TextFieldDelegate {
public:
	static cocos2d::Scene* createScene();
	virtual void onEnter();
	virtual bool init();
	//virtual void onExit();
	void backMenuCallBack(Ref* pSend);
	void multiplyResult(Ref* pSend);
	CREATE_FUNC(Multiply);
private:
	MultiplyCalculator multiplyCalculator;
};

#endif