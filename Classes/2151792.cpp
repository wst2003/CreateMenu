#include"2151792.h"
#include"HelloWorldScene.h"
//我自己名字下的场景设置
//创建场景
Scene* ZxSecondScene::createScene()
{
	Scene* scene = Scene::create();
	ZxSecondScene* layer = ZxSecondScene::create();
	scene->addChild(layer);
	return scene;
}

//初始化场景
bool ZxSecondScene::init()
{
	if (!Layer::init())
	{
		return false;
	}

	//视窗大小与原点
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	// 用一个精灵图片当背景
	auto sprite = Sprite::create("zx_background.png");

	//获得图片大小
	float f_sizex = sprite->getTextureRect().getMaxX();
	float f_sizey = sprite->getTextureRect().getMaxY();

	//图片位置设置为中心点
	sprite->setPosition(Vec2(origin.x + visibleSize.width / 2, visibleSize.height / 2 + origin.y));

	//对图片大小进行调整，使其总是适应屏幕（该函数参数为缩放倍数）
	sprite->setScaleX(visibleSize.width / f_sizex);
	sprite->setScaleY(visibleSize.height / f_sizey);

	// 将图片加入层
	this->addChild(sprite, 0);


	//标签，内容为需要显示的文字，字体为 Marker Felt ，大小为 50.
	auto movelabel = Label::createWithTTF("Hi,my name is ZhangXiang", "Fonts/Marker Felt.ttf", 50);

	//设置标签位置为视窗下方 (注意标签中心点 为标签坐标）
	movelabel->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y - movelabel->getContentSize().height / 2));
	
	//设置移动方式，从最下方移动到最上方，总时间2.5s
	float f_movex = origin.x + visibleSize.width / 2;
	float f_movey = origin.y + visibleSize.height - movelabel->getContentSize().height / 2;
	MoveTo* move = MoveTo::create(2.5f, Vec2(f_movex, f_movey));
	

	//将移动方式传递给标签，并将标签加入层
	movelabel->runAction(move);
	this->addChild(movelabel);

	//利用现有图片创建菜单条目
	auto menuitem_back = MenuItemImage::create("zx_backward_button.png","zx_backward_button.png", 
												CC_CALLBACK_1(ZxSecondScene::enterFirstScene, this));


	//将菜单条目加入菜单中
	auto menu_back = Menu::create(menuitem_back, NULL);

	//确定菜单的位置，视窗右下角
	float f_backx = origin.x + visibleSize.width - menuitem_back->getContentSize().width;
	float f_backy = origin.y + menuitem_back->getContentSize().height;
	menu_back->setPosition(Vec2(f_backx, f_backy));


	//在层上添加返回菜单
	this->addChild(menu_back);

	return true;
}

void ZxSecondScene::enterFirstScene(Ref* pSender)
{
	//创造要到达的新场景
	Scene* zx_scene = HelloWorld::createScene();

	//转场小动画  ，持续时间时间3s  ，效果为从屏幕跳出
	TransitionJumpZoom* zx_tran = TransitionJumpZoom::create(3.0f, zx_scene);

	//导演类，实施转场
	Director::getInstance()->replaceScene(zx_tran);
}