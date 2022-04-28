#include "cocos2d.h"
USING_NS_CC;
class wstAction :public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	CREATE_FUNC(wstAction);
	void wstAction::backMenu(Ref* pSender);
};