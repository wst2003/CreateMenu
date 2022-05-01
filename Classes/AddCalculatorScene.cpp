#include "HelloWorldScene.h"
#include "CharEncodingConvert.h"
#include "AddCalculatorScene.h"
#include <stdlib.h>
#include "ui/CocosGUI.h"

USING_NS_CC;

Scene* AddCalculatorScene::createScene()
{
	auto scene = Scene::create();
	auto layer = AddCalculatorScene::create();
	scene->addChild(layer);

	return scene;
}

void AddCalculatorScene::onEnter()
{
	Layer::onEnter();
	auto buttonListener = EventListenerMouse::create();
	buttonListener->onMouseDown = CC_CALLBACK_1(AddCalculatorScene::mouseDownButton,this);

	EventDispatcher * eventDispatcher = Director::getInstance()->getEventDispatcher();
	eventDispatcher->addEventListenerWithSceneGraphPriority(buttonListener, getChildByTag(50));

}
bool AddCalculatorScene::init()
{
	if (!Layer::init())
	{
		return false;
	}
	//初始化计数器
	_counter = 0;
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	//背景
	auto bg = Sprite::create("BackGround.png");
	bg->setScaleX(visibleSize.width / bg->getContentSize().width);
	bg->setScaleY(visibleSize.height / bg->getContentSize().height);
	bg->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
	this->addChild(bg);

	auto addCalculatorLabel = Label::createWithTTF(a2u("加法计算器"), "fonts/STXINGKA.TTF", 50);
	addCalculatorLabel->setPosition(Vec2(200,visibleSize.height-100));
	addCalculatorLabel->setTextColor(Color4B::BLACK);
	this->addChild(addCalculatorLabel,0);

	
	//左文本框
	auto leftEditBox = ui::EditBox::create(Size(200, 50), "EditBox.png");
	leftEditBox->setPlaceHolder("Enter");
	leftEditBox->setMaxLength(10);
	leftEditBox->setPosition(Vec2(200, 400));
	this->addChild(leftEditBox, 1);
	leftEditBox->setTag(101);
	leftEditBox->setDelegate(this);
	leftEditBox->setInputMode(cocos2d::ui::EditBox::InputMode::NUMERIC);

	//右文本框
	auto rightEditBox = ui::EditBox::create(Size(200, 50), "EditBox.png");
	rightEditBox->setPlaceHolder("Enter");
	rightEditBox->setMaxLength(10);
	rightEditBox->setPosition(Vec2(500, 400));
	this->addChild(rightEditBox, 1);
	rightEditBox->setTag(102);
	rightEditBox->setDelegate(this);
	rightEditBox->setInputMode(cocos2d::ui::EditBox::InputMode::NUMERIC);

	//加号
	auto addSign = Label::createWithTTF("+", "fonts/STXINGKA.TTF", 40);
	addSign->setTextColor(Color4B::BLACK);
	addSign->setPosition(Vec2(350, 400));
	this->addChild(addSign,2);

	//结果显示标签
	resultLabel = Label::createWithTTF("result: ", "fonts/Marker Felt.TTF", 40);
	resultLabel->setPosition(Vec2(200, 250));
	resultLabel->setTextColor(Color4B::BLACK);
	this->addChild(resultLabel, 2);

	//计算按钮
	calculateButton = Sprite::create("wstButton.png");
	calculateButton->setPosition(Vec2(400, 250));
	calculateButton->setTag(50);
	this->addChild(calculateButton, 2);

	//返回键
	auto backMenuItem = MenuItemImage::create("Back-up.png", "Back-down.png",CC_CALLBACK_1(AddCalculatorScene::backMenuCallBack,this));
	auto backMenu = Menu::create(backMenuItem, NULL);
	backMenu->setPosition(90, 30);
	this->addChild(backMenu);

	return true;
}

void AddCalculatorScene::editBoxTextChanged(cocos2d::ui::EditBox* editBox, const std::string& text)
{
	/*响应编辑框的改变*/
	switch (editBox->getTag()) {
	case 101: {
		auto leftStr = editBox->getText();
		int leftNum = atoi(leftStr);
		addCalculator.setLeftNum(leftNum);
		break; }
	case 102: {
		auto rightStr = editBox->getText();
		int rightNum = atoi(rightStr);
		addCalculator.setRightNum(rightNum);
		break; }
	}
};
void AddCalculatorScene::mouseDownButton(EventMouse* event)
{
	/*相应鼠标*/
	if (event->getMouseButton() == EventMouse::MouseButton::BUTTON_LEFT) {
		if (this->calculateButton->getBoundingBox().containsPoint(event->getLocationInView())) {
			double result = this->addCalculator.calculate();
			AddCalculator::setResult(0, result);
			char res[10];
			_gcvt_s(res, result, 5);
			std::string resultString = res;
			this->resultLabel->setString("result: " + resultString);
		}
	}
}

void AddCalculatorScene::backMenuCallBack(Ref* pSender)
{
	Director::getInstance()->popScene();
}
