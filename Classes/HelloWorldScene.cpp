#include "HelloWorldScene.h"
#include "CharEncodingConvert.h"
#include "Calculator.h"
#include "AddCalculatorScene.h"
#include "MultiplyScene.h"

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
	//��ʼ��������
	_counter = 0;
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	//�������Լ��Ĵ���
	/*��ʫ�ڵļӷ�������ѡ��*/
	std::string menuItemString = a2u("�ӷ�������");
	MenuItemFont::setFontName("����");
	MenuItemFont::setFontSize(70);
	auto addMenuItem = MenuItemFont::create(menuItemString, CC_CALLBACK_1(HelloWorld::addMenuItemCallBack,this));
	
	auto addMenu = Menu::create(addMenuItem, NULL);
	addMenu->setPosition(Vec2(visibleSize.width / 2, visibleSize.height - 100));
	addChild(addMenu);

	/*�ᴺ�ȵĳ˷�������*/
	MenuItemFont::setFontName("Times New Roman");
	MenuItemFont::setFontSize(60);
	MenuItemFont* multiplicationMenuItem = MenuItemFont::create("multiply",
		CC_CALLBACK_1(HelloWorld::multiplyMenuItemCallBack, this));
	Menu* menu = Menu::create(multiplicationMenuItem, NULL);
	menu->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2));
	this->addChild(menu);

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