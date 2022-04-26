#ifndef __SET_SCENE_H__
#define __SET_SCENE_H__

#include "cocos2d.h"
//场景子类：“设置”页面
class Set : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    void setCloseCallback(cocos2d::Ref* pSender);
    CREATE_FUNC(Set);
};
#endif
