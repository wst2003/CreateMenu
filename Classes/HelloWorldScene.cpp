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
	//��ʼ��������
	_counter = 0;
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	//�������Լ��Ĵ���
	//�ᴺ��
	//����һ�����ð�ť
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
		//λ�������½�
		float x = origin.x + visibleSize.width - setItem->getContentSize().width / 2;
		float y = origin.y + setItem->getContentSize().height / 2;
		setItem->setPosition(Vec2(x, y));
	}
	//����ť���뵽HelloWorld������
	auto menu = Menu::create(setItem, NULL);
	menu->setPosition(Vec2::ANCHOR_MIDDLE);
	this->addChild(menu, 1);

	//����һ���ı���������Menu
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
	//δ��ȫ���
	//Ŀ�꣺HelloWorld�����л���Set��������Set�������κβ������Ա�����
	if (_counter == 1)
		Director::getInstance()->replaceScene(setScene);
	else if (_counter % 2 == 1&&_counter!=1)
		Director::getInstance()->pushScene(setScene);
	else
		Director::getInstance()->popScene();
}
