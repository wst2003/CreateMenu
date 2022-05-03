#include "HelloWorldScene.h"
#include "CharEncodingConvert.h"
#include "Calculator.h"
#include "AddCalculatorScene.h"
#include "MultiplyScene.h"
#include "DivisionCalculatorScene.h"
#include "AllAnswer.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = HelloWorld::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}


bool HelloWorld::init()
{
	if (!Layer::init())
	{
		return false;
	}
	//初始化计数器
	_counter = 0;
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	//以下是自己的代码
	/*王诗腾的加法计算器选项*/
	std::string menuItemString = a2u("加法计算器");
	MenuItemFont::setFontName("宋体");
	MenuItemFont::setFontSize(60);
	auto addMenuItem = MenuItemFont::create(menuItemString, CC_CALLBACK_1(HelloWorld::addMenuItemCallBack,this));
	
	auto addMenu = Menu::create(addMenuItem, NULL);
	addMenu->setPosition(Vec2(visibleSize.width / 2, visibleSize.height*9/10));
	addChild(addMenu);

	/*俞春先的乘法计算器*/
	MenuItemFont::setFontName("Times New Roman");
	MenuItemFont::setFontSize(60);
	MenuItemFont* multiplicationMenuItem = MenuItemFont::create("multiply",
		CC_CALLBACK_1(HelloWorld::multiplyMenuItemCallBack, this));
	Menu* menu = Menu::create(multiplicationMenuItem, NULL);
	menu->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2));
	this->addChild(menu);

	//张翔除法
	auto menuItemDivision = MenuItemFont::create(a2u("除法计算器"), CC_CALLBACK_1(HelloWorld::enterDivisionScene, this));

	auto menuToDivision = Menu::create(menuItemDivision, NULL);

	float fBackx = origin.x + visibleSize.width/2;
	float fBacky = origin.y + visibleSize.height * 7 / 10;
	menuToDivision->setPosition(Vec2(fBackx, fBacky));

	this->addChild(menuToDivision);

	//所有结果
	auto menuItemAllAnswer = MenuItemFont::create("All Answer", CC_CALLBACK_1(HelloWorld::enterAnswerScene, this));

	auto menuToAnswer = Menu::create(menuItemAllAnswer, NULL);

	fBackx = origin.x + visibleSize.width / 2;
	fBacky = origin.y + visibleSize.height / 10;
	menuToAnswer->setPosition(Vec2(fBackx, fBacky));

	this->addChild(menuToAnswer);
	return true;
}

void HelloWorld::addMenuItemCallBack(Ref* pSender)
{
	auto addCalculatorScene = AddCalculatorScene::createScene();
	Director::getInstance()->pushScene(addCalculatorScene);
}

void HelloWorld::multiplyMenuItemCallBack(Ref* pSender)
{
	auto multiplyScene = Multiply::createScene();
	auto actionScene = TransitionSlideInR::create(0.5f, multiplyScene);
	Director::getInstance()->pushScene(actionScene);
}

//除法计算器
void HelloWorld::enterDivisionScene(Ref* pSender)
{
	//创造要到达的新场景及动画
	Scene* divisionScene = DivisionScene::createScene();
	TransitionJumpZoom* divisionTran = TransitionJumpZoom::create(1.0f, divisionScene);

	Director::getInstance()->replaceScene(divisionTran);
}

//结果界面
void HelloWorld::enterAnswerScene(Ref* pSender)
{
	//创造要到达的新场景及动画
	Scene* answerScene = AllAnswerScene::createScene();
	auto answerTran = TransitionSlideInR::create(0.5f, answerScene);

	Director::getInstance()->replaceScene(answerTran);
}