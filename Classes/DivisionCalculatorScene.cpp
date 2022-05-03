#include"DivisionCalculatorScene.h"
#include"HelloWorldScene.h"
#include "ui/CocosGUI.h"
#include <string>
#include <iostream>
#include <sstream>

//创建场景
Scene* DivisionScene::createScene()
{
	Scene* scene = Scene::create();
	DivisionScene* layer = DivisionScene::create();
	scene->addChild(layer);
	return scene;
}

//初始化场景
bool DivisionScene::init()
{
	//设置背景
	if (!LayerColor::initWithColor({ 176,196,222 ,255 }))
	{
		return false;
	}
	
	//视窗大小与原点
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	//左文本框及其参数
	auto leftEditBox = ui::EditBox::create(Size(250, 50),"EditBox.png");

	leftEditBox->setPosition(Vec2(origin.x + visibleSize.width / 4, origin.y + visibleSize.height * 3 / 4));
	leftEditBox->setPlaceHolder("Input:");
	leftEditBox->setFontColor(Color4B::BLACK);
	leftEditBox->setInputMode(ui::EditBox::InputMode::DECIMAL);
	leftEditBox->setMaxLength(10);
	leftEditBox-> setTag(10000);

	this->addChild(leftEditBox, 1);

	//右文本框及其参数
	auto rightEditBox = ui::EditBox::create(Size(250, 50), "EditBox.png");

	rightEditBox->setPosition(Vec2(origin.x + visibleSize.width * 3 / 4, origin.y + visibleSize.height * 3 / 4));
	rightEditBox->setPlaceHolder("Input:");
	rightEditBox->setFontColor(Color4B::BLACK);
	rightEditBox->setInputMode(ui::EditBox::InputMode::DECIMAL);
	rightEditBox->setMaxLength(10);
	rightEditBox->setTag(20000);

	this->addChild(rightEditBox, 2);

	//除号
	auto divisionSign = Label::createWithTTF("/", "fonts/Marker Felt.ttf", 40);
	divisionSign->setTextColor(Color4B::BLACK);
	divisionSign->setPosition(origin.x + visibleSize.width / 2, origin.y + visibleSize.height * 3 / 4);

	this->addChild(divisionSign);

	//初始化答案标签
	resultLabel = Label::createWithTTF("result: ", "fonts/Marker Felt.TTF", 40);
	resultLabel->setPosition(Vec2(200.0, 250.0));
	resultLabel->setTextColor(Color4B::BLACK);
	this->addChild(resultLabel, 2);

	//等于按钮
	auto menuItemGetAnswer = MenuItemImage::create("NormalEqualSign.png", "NormalEqualSign.png"
		, CC_CALLBACK_1(DivisionScene::printAnswer, this));

	auto GetAnswer = Menu::create(menuItemGetAnswer, NULL);

	float fBackx = origin.x + visibleSize.width / 2;
	float fBacky = origin.y + visibleSize.height /2;
	GetAnswer->setPosition(Vec2(fBackx, fBacky));

	this->addChild(GetAnswer);
	
	//返回按钮
	//利用现有图片创建菜单条目
	auto menuItemBack = MenuItemImage::create("NormalBack.png", "NormalBack.png",
		CC_CALLBACK_1(DivisionScene::enterFirstScene, this));

	auto menuBack = Menu::create(menuItemBack, NULL);

	fBackx = origin.x + visibleSize.width - menuItemBack->getContentSize().width;
	fBacky = origin.y + menuItemBack->getContentSize().height;
	menuBack->setPosition(Vec2(fBackx, fBacky));

	this->addChild(menuBack,1);


	return true;
}

//回 Halloworld
void DivisionScene::enterFirstScene(Ref* pSender)
{
	//创造要到达的新场景及动画
	Scene* firstScene = HelloWorld::createScene();
	TransitionJumpZoom* divisionTran = TransitionJumpZoom::create(1.0f, firstScene);

	Director::getInstance()->replaceScene(divisionTran);
}

//答案的显示
void DivisionScene::printAnswer(Ref* pSender)
{
	//左右文本框的内容
	auto leftEditBox = dynamic_cast<ui::EditBox*>(this->getChildByTag(10000));
	int leftInput = atoi(leftEditBox->getText());
	divisionCalculate.setLeftNum(leftInput);

	auto rightEditBox = dynamic_cast<ui::EditBox*>(this->getChildByTag(20000));
	int rightInput = atoi(rightEditBox->getText());
	divisionCalculate.setRightNum(rightInput);

	//排除除以0
	if (rightInput == 0)
	{
		this->resultLabel->setString("The right digit can not be 0");
		return;
	}

	//计算、传入与输出
	double dAnswer = this->divisionCalculate.calculate();
	this->divisionCalculate.setResult(3, dAnswer);

	std::string sAnswer;
	std::ostringstream o;
	o << dAnswer;
	sAnswer ="Answer = "+ o.str();

	this->resultLabel->setString( sAnswer);

	return;
}