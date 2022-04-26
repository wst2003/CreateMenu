#include "HelloWorldScene.h"
#include "SetScene.h"
#include "2151792.h"

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

	/*---------------------------------------------2151792 ����----------------------------------------------------------*/
	
	//��ǩ������ 2151792������Ϊ arial����СΪ75
	auto zx_label = Label::createWithSystemFont("2151792", "Fonts/arial.ttf", 75);
	
	//���ݱ�ǩ����һ���˵���Ŀ(�����ִ�� HelloWorld::enterZxScene ��ת����)
	auto zx_menuitem = MenuItemLabel::create(zx_label,CC_CALLBACK_1(HelloWorld::enterZxScene,this));

	//���˵���Ŀ����˵���
	auto zx_menu = Menu::create(zx_menuitem,NULL);

	//ȷ���˵���λ�ã������ origin��ԭ�㣩 �����λ�ã�����ǩλ�õ�ָ������ Ϊ��ǩ�������꣩
	float f_menux = origin.x + visibleSize.width / 2;
	float f_menuy = origin.y + visibleSize.height - (zx_label->getContentSize().height);
	zx_menu->setPosition(Vec2(f_menux, f_menuy));
	
	//�ڲ�����Ӳ˵�
	this->addChild(zx_menu);

/*---------------------------------------------2151792 ���账�����--------------------------------------------------*/
	
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

//2151792 ���� ����ת����
void HelloWorld::enterZxScene(Ref* pSender)
{
	//����Ҫ������³���
	Scene* zx_scene = ZxSecondScene::createScene();

	//ת��С����  ������ʱ��ʱ��0.15s  ��Ч��Ϊ�������������˼��
	TransitionPageTurn* zx_tran = TransitionPageTurn::create(0.3f, zx_scene,true);

	//�����࣬ʵʩת��
	Director::getInstance()->replaceScene(zx_tran);

	return;
}
