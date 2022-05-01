#pragma once
#include "cocos2d.h"
#include "Calculator.h"
#include "ui/CocosGUI.h"


USING_NS_CC;
using namespace ui;
class AddCalculatorScene : public cocos2d::Layer ,public cocos2d::ui::EditBoxDelegate
{
public:
    static cocos2d::Scene* createScene();

    virtual void onEnter();
    virtual bool init();

    virtual void editBoxEditingDidEndWithAction(EditBox* editbox, EditBoxEndAction) {};
    virtual void editBoxEditingDidBegin(cocos2d::ui::EditBox* editBox) {};
    virtual void editBoxTextChanged(cocos2d::ui::EditBox* editBox, const std::string& text);
    virtual void editBoxReturn(cocos2d::ui::EditBox* editBox) {};

    void mouseDownButton(EventMouse* event);
    void backMenuCallBack(Ref* r);
    CREATE_FUNC(AddCalculatorScene);
private:
    //HelloWorld场景被点击次数
    int _counter;
    AddCalculator addCalculator;
    Label *resultLabel;
    Sprite* calculateButton;
};

