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

	/*---------------------------------------------2151792 张翔----------------------------------------------------------*/
	
	//标签，内容 2151792，字体为 arial，大小为75
	auto zx_label = Label::createWithSystemFont("2151792", "Fonts/arial.ttf", 75);
	
	//根据标签创造一个菜单条目(点击后执行 HelloWorld::enterZxScene 跳转函数)
	auto zx_menuitem = MenuItemLabel::create(zx_label,CC_CALLBACK_1(HelloWorld::enterZxScene,this));

	//将菜单条目加入菜单中
	auto zx_menu = Menu::create(zx_menuitem,NULL);

	//确定菜单的位置（相对于 origin（原点） 的相对位置）（标签位置的指代坐标 为标签中心坐标）
	float f_menux = origin.x + visibleSize.width / 2;
	float f_menuy = origin.y + visibleSize.height - (zx_label->getContentSize().height);
	zx_menu->setPosition(Vec2(f_menux, f_menuy));
	
	//在层上添加菜单
	this->addChild(zx_menu);

/*---------------------------------------------2151792 张翔处理完毕--------------------------------------------------*/
	
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

//2151792 张翔 的跳转函数
void HelloWorld::enterZxScene(Ref* pSender)
{
	//创造要到达的新场景
	Scene* zx_scene = ZxSecondScene::createScene();

	//转场小动画  ，持续时间时间0.15s  ，效果为翻出（翻书的意思）
	TransitionPageTurn* zx_tran = TransitionPageTurn::create(0.3f, zx_scene,true);

	//导演类，实施转场
	Director::getInstance()->replaceScene(zx_tran);

	return;
}
