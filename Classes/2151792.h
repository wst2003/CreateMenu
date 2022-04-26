#include"cocos2d.h"
USING_NS_CC;
//场景设置所需的头文件
class ZxSecondScene :public Layer
{
public:
	static Scene* createScene();

	CREATE_FUNC(ZxSecondScene);

	virtual bool init();

	void enterFirstScene(Ref* pSender);

};