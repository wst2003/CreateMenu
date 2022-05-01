#include "HelloWorldScene.h"
#include "CharEncodingConvert.h"
#include "Calculator.h"
#include "AddCalculatorScene.h"

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
	MenuItemFont::setFontSize(70);
	auto addMenuItem = MenuItemFont::create(menuItemString, CC_CALLBACK_1(HelloWorld::addMenuItemCallBack,this));
	
	auto addMenu = Menu::create(addMenuItem, NULL);
	addMenu->setPosition(Vec2(visibleSize.width / 2, visibleSize.height - 100));
	addChild(addMenu);

	return true;
}

void HelloWorld::addMenuItemCallBack(Ref* pSender)
{
	auto addCalculatorScene = AddCalculatorScene::createScene();
	Director::getInstance()->pushScene(addCalculatorScene);
}