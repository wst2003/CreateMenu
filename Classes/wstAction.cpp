#include "wstAction.h"
#include "CharEncodingConvert.h"

USING_NS_CC;

Scene* wstAction::createScene()
{
    auto scene = Scene::create();
    auto layer = wstAction::create();
    scene->addChild(layer);
    return scene;
}

bool wstAction::init()
{
    if (!Layer::init())
    {
        return false;
    }

    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    //wst_1:背景添加
    auto bg = Sprite::create("wstbg.jpg");
    auto bgWidth = bg->getContentSize().width;
    auto bgScaleWidth = visibleSize.width / bgWidth;
    bg->setScaleX(bgScaleWidth);
    auto bgHeight = bg->getContentSize().height;
    auto bgScaleHeight = visibleSize.height / bgHeight;
    bg->setScaleY(bgScaleHeight);
    bg->setPosition(visibleSize.width / 2, visibleSize.height / 2);
    this->addChild(bg, 0);

    //wst_2:返回按钮
    auto backMenuButton = MenuItemImage::create("BackwardNormal.png", "BackwardSelected.png",  CC_CALLBACK_1(wstAction::backMenu
        , this));
    auto backMenuMn = Menu::create(backMenuButton, NULL);
    this->addChild(backMenuMn,1);
    backMenuMn->setPosition(Vec2(50, 50));

    //wst_3:文字动画
    std::string wst_label_str = a2u("战无不胜的毛泽东思想万岁！");
    auto myActionLabel = Label::createWithTTF(wst_label_str, "fonts/STXINGKA.TTF",  60);
    myActionLabel->setTextColor(Color4B::RED);
    this->addChild(myActionLabel);
    myActionLabel->setPosition(Vec2(visibleSize.width/2, 80));
    myActionLabel->runAction(MoveTo::create(3, Vec2(visibleSize.width/2, visibleSize.height - 50)));

    return true;
}

void wstAction::backMenu(Ref* pSender)
{
    Director::getInstance()->popScene();
}