#include"cocos2d.h"
USING_NS_CC;
//�������������ͷ�ļ�
class ZxSecondScene :public Layer
{
public:
	static Scene* createScene();

	CREATE_FUNC(ZxSecondScene);

	virtual bool init();

	void enterFirstScene(Ref* pSender);

};