#include"DivisionCalculatorScene.h"
#include"HelloWorldScene.h"
#include "ui/CocosGUI.h"
#include "AllAnswer.h"
#include <string>
#include <iostream>
#include <sstream>

USING_NS_CC;

//创建场景
Scene* AllAnswerScene::createScene()
{
	Scene* scene = Scene::create();
	AllAnswerScene* layer = AllAnswerScene::create();
	scene->addChild(layer);
	return scene;
}


const std::string sFlag[4] = { "+","-","*","/" };

//初始化场景
bool AllAnswerScene::init()
{
	//设置背景
	if (!LayerColor::initWithColor({ 176,196,222 ,255 }))
	{
		return false;
	}

	//视窗大小与原点
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	AllAnswer inputAnswer;

	//答案标签,循环创造4个
	for (int i = 0; i < 4; i++)
	{
		//得到结果
		std::ostringstream o;
		o << inputAnswer.getResult()[i];
		std::string sDigit = o.str();

		//输出答案
		auto resultLabel = Label::createWithTTF("The result of   " + sFlag[i] + " :      " + sDigit, "fonts/Marker Felt.TTF", 40);
		resultLabel->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height * (7- 2 * i) / 8));
		resultLabel->setTextColor(Color4B::BLACK);

		this->addChild(resultLabel);
	}

	//返回按钮
	//利用现有图片创建菜单条目
	auto menuItemBack = MenuItemImage::create("NormalBack.png", "NormalBack.png",
		CC_CALLBACK_1(AllAnswerScene::enterFirstScene, this));

	auto menuBack = Menu::create(menuItemBack, NULL);

	float fBackx = origin.x + visibleSize.width - menuItemBack->getContentSize().width;
	float fBacky = origin.y + menuItemBack->getContentSize().height;
	menuBack->setPosition(Vec2(fBackx, fBacky));

	this->addChild(menuBack, 1);
	return true;
}

//回 Halloworld
void AllAnswerScene::enterFirstScene(Ref* pSender)
{
	//创造要到达的新场景及动画
	Scene* firstScene = HelloWorld::createScene();
	auto answerTran = TransitionSlideInR::create(0.5f, firstScene);

	Director::getInstance()->replaceScene(answerTran);
}