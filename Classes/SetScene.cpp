#include "SetScene.h"
#include "HelloWorldScene.h"
USING_NS_CC;

Scene* Set::createScene()
{
	return Set::create();
}

static void problemLoading(const char* filename)
{
	printf("Error while loading: %s\n", filename);
	printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

bool Set::init()
{
	if (!Scene::init())
	{
		return false;
	}
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	//创建返回按钮
	auto setItem = MenuItemImage::create(
		"BackwardNormal.png",
		"BackwardSelected.png",
		CC_CALLBACK_1(Set::setCloseCallback, this));
	if (setItem == nullptr ||
		setItem->getContentSize().width <= 0 ||
		setItem->getContentSize().height <= 0)
	{
		problemLoading("'BackwardNormal.png' and 'BackwardSelected.png'");
	}
	else
	{
		//按钮位置在左下角
		float x = setItem->getContentSize().width / 2;
		float y = setItem->getContentSize().height / 2;
		setItem->setPosition(Vec2(x, y));
	}
	//将按钮加入到Set场景中
	auto menu = Menu::create(setItem, NULL);
	menu->setPosition(Vec2::ANCHOR_BOTTOM_LEFT);
	this->addChild(menu, 1);

	//创建音乐开关
	auto unselected = Sprite::create("sound-on.png");
	auto selected = Sprite::create("sound-off.png");
	auto unselectedSpriteItem = MenuItemSprite::create(unselected, unselected);
	auto selectedSpriteItem = MenuItemSprite::create(selected, selected);
	auto toggleItem = MenuItemToggle::createWithCallback([&](Ref* ref) {
		//声音开关控制，未完成
		auto item = dynamic_cast<MenuItemToggle*>(ref);
		if (item) {
			if (item->getSelectedIndex() == 0) {
				CCLOG("play");

			}
			else if (item->getSelectedIndex() ==1) {
				CCLOG("silence");
			}
		}
		}, unselectedSpriteItem, selectedSpriteItem, NULL);
	//开关位置设在窗口中间偏左
	toggleItem->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	toggleItem->setPosition(Vec2(visibleSize / 2)+Vec2(-140,0));

	//创建文本框（内容：Music）
	auto label = Label::createWithTTF("Music", "fonts/Marker Felt.ttf", 72);
	auto labelItem = MenuItemLabel::create(label, NULL);
	//文本位置设在窗口中间
	labelItem->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	label->setPosition(Vec2(visibleSize / 2));

	//将开关和文本加入到Set场景中
	menu = Menu::create(toggleItem, labelItem, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu);

	return true;
}

void Set::setCloseCallback(cocos2d::Ref* pSender)
{
	//返回主菜单
	auto scene = HelloWorld::createScene();
	Director::getInstance()->pushScene(scene);
}