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

	//�������ذ�ť
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
		//��ťλ�������½�
		float x = setItem->getContentSize().width / 2;
		float y = setItem->getContentSize().height / 2;
		setItem->setPosition(Vec2(x, y));
	}
	//����ť���뵽Set������
	auto menu = Menu::create(setItem, NULL);
	menu->setPosition(Vec2::ANCHOR_BOTTOM_LEFT);
	this->addChild(menu, 1);

	//�������ֿ���
	auto unselected = Sprite::create("sound-on.png");
	auto selected = Sprite::create("sound-off.png");
	auto unselectedSpriteItem = MenuItemSprite::create(unselected, unselected);
	auto selectedSpriteItem = MenuItemSprite::create(selected, selected);
	auto toggleItem = MenuItemToggle::createWithCallback([&](Ref* ref) {
		//�������ؿ��ƣ�δ���
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
	//����λ�����ڴ����м�ƫ��
	toggleItem->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	toggleItem->setPosition(Vec2(visibleSize / 2)+Vec2(-140,0));

	//�����ı������ݣ�Music��
	auto label = Label::createWithTTF("Music", "fonts/Marker Felt.ttf", 72);
	auto labelItem = MenuItemLabel::create(label, NULL);
	//�ı�λ�����ڴ����м�
	labelItem->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	label->setPosition(Vec2(visibleSize / 2));

	//�����غ��ı����뵽Set������
	menu = Menu::create(toggleItem, labelItem, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu);

	return true;
}

void Set::setCloseCallback(cocos2d::Ref* pSender)
{
	//�������˵�
	auto scene = HelloWorld::createScene();
	Director::getInstance()->pushScene(scene);
}