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

	return true;
}

void HelloWorld::addMenuItemCallBack(Ref* pSender)
{
	auto addCalculatorScene = AddCalculatorScene::createScene();
	Director::getInstance()->pushScene(addCalculatorScene);
}