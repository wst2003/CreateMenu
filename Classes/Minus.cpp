/****************************************************************************
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.
 
 http://www.cocos2d-x.org
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#include "Minus.h"
#include"Calculator.h"
USING_NS_CC;

Scene* Minus::createScene()
{
    auto scene = Scene::create();
    auto layer = Minus::create();
    scene->addChild(layer);
    return scene;
}

void  Minus::onEnter()
{
    Layer::onEnter();
    //监听键盘输入
    auto listenerKey = EventListenerKeyboard::create();
    listenerKey->onKeyPressed = [&](EventKeyboard::KeyCode code, Event* event)
    {
        TextFieldTTF* textA = (TextFieldTTF*)this->getChildByTag(2);
        TextFieldTTF* textB = (TextFieldTTF*)this->getChildByTag(3);
        std::string strA = textA->getString();
        std::string strB = textB->getString();
        if (code == EventKeyboard::KeyCode::KEY_ENTER || strA.length() == 10)
            textA->detachWithIME();
        if (code == EventKeyboard::KeyCode::KEY_ENTER || strA.length() == 10)
            textB->detachWithIME();
    };
    //监听鼠标点击
    auto listener = EventListenerTouchOneByOne::create();
    listener->setSwallowTouches(true);
    listener->onTouchBegan = [](Touch* t, Event* event) {log("begin"); return true; };
    listener->onTouchEnded = [&](Touch* touch, Event* event) {
        //鼠标点击上方区域：
        Point posA = touch->getLocation();
        TextFieldTTF* textA = (TextFieldTTF*)this->getChildByTag(2);
        float xA = textA->getPositionX() - textA->getContentSize().width / 2;
        float yA = textA->getPositionY() - textA->getContentSize().height / 2;
        float widthA = textA->getContentSize().width;
        float heightA = textA->getContentSize().height;
        Rect recA = Rect(xA, yA, widthA, heightA);
       
        //鼠标点击下方区域
        Point posB = touch->getLocation();
        TextFieldTTF* textB = (TextFieldTTF*)this->getChildByTag(3);
        float xB = textB->getPositionX() - textB->getContentSize().width / 2;
        float yB = textB->getPositionY() - textB->getContentSize().height / 2;
        float widthB = textB->getContentSize().width;
        float heightB = textB->getContentSize().height;
        Rect recB = Rect(xB, yB, widthB, heightB);

        //被点击时进行操作
        if (recA.containsPoint(posA))
        {
                log("null");
                textA->setString("");
                textA->attachWithIME(); 

        }
        if (recB.containsPoint(posB))
        {
            log("null");
            textB->setString("");
            textB->attachWithIME();
        }
    };

    EventDispatcher* eventDispatcher = Director::getInstance()->getEventDispatcher();
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listenerKey, getChildByTag(2));
    eventDispatcher->addEventListenerWithSceneGraphPriority(listener->clone(), getChildByTag(3));
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listenerKey->clone(), getChildByTag(3));
}


bool Minus::init()
{

    if ( !Layer::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    //背景添加：
    auto bg = Sprite::create("bg.png");
    bg->setPosition(visibleSize.width / 2, visibleSize.height / 2);
    this->addChild(bg, 0);

    //三个文本框的建立
    auto textBoxA = TextFieldTTF::textFieldWithPlaceHolder("0", Size(300, 50), TextHAlignment::LEFT, "Marker Felt", 40);
    textBoxA->setColorSpaceHolder(Color3B::WHITE);
    textBoxA->setPosition(visibleSize.width / 2, visibleSize.height / 2+180);
    textBoxA->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
    textBoxA->setCursorEnabled(true);
    textBoxA->detachWithIME();
    textBoxA->setDelegate(this);
    this->addChild(textBoxA, 0, 2);
  
    auto textBoxB = TextFieldTTF::textFieldWithPlaceHolder("0", Size(300, 50), TextHAlignment::LEFT, "Marker Felt", 40);
    textBoxB->setColorSpaceHolder(Color3B::WHITE);
    textBoxB->setPosition(visibleSize.width / 2, visibleSize.height / 2 + 100);
    textBoxB->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
    textBoxB->setCursorEnabled(true);
    textBoxB->detachWithIME();
    textBoxB->setDelegate(this);
    this->addChild(textBoxB, 0, 3);

    auto textBoxC = TextFieldTTF::textFieldWithPlaceHolder("0", Size(300, 50), TextHAlignment::LEFT, "Marker Felt", 40);
    textBoxC->setColorSpaceHolder(Color3B::WHITE);
    textBoxC->setPosition(visibleSize.width / 2, visibleSize.height / 2 );
    textBoxC->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
    textBoxC->setCursorEnabled(true);
    textBoxC->detachWithIME();
    textBoxC->setDelegate(this);
    this->addChild(textBoxC, 0, 1);
    
    auto textBoxD = TextFieldTTF::textFieldWithPlaceHolder("Get Result", Size(300, 50), TextHAlignment::LEFT, "Marker Felt", 36);
    textBoxD->setColorSpaceHolder(Color3B::WHITE);
    textBoxD->setPosition(visibleSize.width / 2, visibleSize.height-300);
    textBoxD->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
    textBoxD->setCursorEnabled(true);
    textBoxD->detachWithIME();
    textBoxD->setDelegate(this);
    this->addChild(textBoxD, 1);

    auto minusButton = MenuItemImage::create("bar.png","bar.png","bar.png",CC_CALLBACK_1(Minus::minusOperation,this));
    minusButton->setPosition(visibleSize.width / 2-53, visibleSize.height-300);

    auto backMenu = MenuItemImage::create("back.png", "back_selected.png", "back_selected.png", 
        CC_CALLBACK_1(Minus::menuCloseCallback, this));
    backMenu->setPosition(visibleSize.width / 2+300, visibleSize.height - 380);
    auto menu = Menu::create(minusButton, backMenu,NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 0);
    return true;
}


void  Minus::minusOperation(Ref* pSender)
{
    TextFieldTTF* textA = (TextFieldTTF*)this->getChildByTag(2);
    TextFieldTTF* textB = (TextFieldTTF*)this->getChildByTag(3);
    TextFieldTTF* textC = (TextFieldTTF*)this->getChildByTag(1);
    const std::string strA = textA->getString();
    const std::string strB = textB->getString();
    std::stringstream ss;
    int leftNum = atoi(strA.c_str());
    int rightNum = atoi(strB.c_str());
    minusCalculator.setLeftNum(leftNum);
    minusCalculator.setRightNum(rightNum);
    double result = minusCalculator.calculate();
    minusCalculator.setResult(1, result);
    ss << result;
    textC->attachWithIME();
    textC->setString(ss.str());
    textC->detachWithIME();
}
void  Minus::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
