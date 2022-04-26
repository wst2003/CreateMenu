#include "HelloWorldScene.h"
#include "SetScene.h"
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

static void problemLoading(const char* filename)
{
	printf("Error while loading: %s\n", filename);
	printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
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
	//俞春先
	//创建一个设置按钮
	auto setItem = MenuItemImage::create(
		"SetNormal.png",
		"SetSelected.png",
		CC_CALLBACK_1(HelloWorld::menuSetCallback, this));
	if (setItem == nullptr ||
		setItem->getContentSize().width <= 0 ||
		setItem->getContentSize().height <= 0)
	{
		problemLoading("'SetNormal.png' and 'SetSelected.png'");
	}
	else
	{
		//位置在右下角
		float x = origin.x + visibleSize.width - setItem->getContentSize().width / 2;
		float y = origin.y + setItem->getContentSize().height / 2;
		setItem->setPosition(Vec2(x, y));
	}
	//将按钮加入到HelloWorld场景中
	auto menu = Menu::create(setItem, NULL);
	menu->setPosition(Vec2::ANCHOR_MIDDLE);
	this->addChild(menu, 1);

	//创建一个文本框，内容是Menu
	auto label = Label::createWithTTF("Menu", "fonts/Marker Felt.ttf", 72);
	label->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	label->setPosition(Vec2(visibleSize / 2));
	this->addChild(label, 1);
	return true;
}
void HelloWorld::menuSetCallback(Ref* pSender)
{
	_counter++;
	auto setScene = Set::createScene();
	//未完全完成
	//目标：HelloWorld场景切换到Set场景后，在Set场景的任何操作可以被保存
	if (_counter == 1)
		Director::getInstance()->replaceScene(setScene);
	else if (_counter % 2 == 1&&_counter!=1)
		Director::getInstance()->pushScene(setScene);
	else
		Director::getInstance()->popScene();
}
