#ifndef __SET_SCENE_H__
#define __SET_SCENE_H__

#include "cocos2d.h"
//�������ࣺ�����á�ҳ��
class Set : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    void setCloseCallback(cocos2d::Ref* pSender);
    CREATE_FUNC(Set);
};
#endif
