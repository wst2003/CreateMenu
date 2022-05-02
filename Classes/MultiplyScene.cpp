#include "MultiplyScene.h"
#include <stdlib.h>
USING_NS_CC;

Scene* Multiply::createScene()
{
	auto scene = Scene::create();
	auto layer = Multiply::create();
	scene->addChild(layer);
	return scene;
}

void Multiply::onEnter()
{
	Layer::onEnter();
	auto listenerKey = EventListenerKeyboard::create();
	listenerKey->onKeyPressed = [&](EventKeyboard::KeyCode code, Event* event)
	{
		TextFieldTTF* textA = (TextFieldTTF*)this->getChildByTag(1);
		std::string strA = textA->getString();
		TextFieldTTF* textB = (TextFieldTTF*)this->getChildByTag(2);
		std::string strB = textB->getString();
		if (code == EventKeyboard::KeyCode::KEY_ENTER || strA.length() == 10)
			textA->detachWithIME();
		if (code == EventKeyboard::KeyCode::KEY_ENTER || strB.length() == 10)
			textB->detachWithIME();
	};

	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = [](Touch* t, Event* event) {log("begin"); return true; };
	listener->onTouchEnded = [&](Touch* t, Event* event) {
		log("end");
		//鼠标点击到左文本框区域内
		Point posA = t->getLocation();
		TextFieldTTF* textA = (TextFieldTTF*)this->getChildByTag(1);
		float xA = textA->getPositionX() - textA->getContentSize().width / 2;
		float yA = textA->getPositionY() - textA->getContentSize().height / 2;
		float widthA = textA->getContentSize().width;
		float heightA = textA->getContentSize().height;
		Rect recA = Rect(xA, yA, widthA, heightA);
		//鼠标点击到右文本框区域内
		Point posB = t->getLocation();
		TextFieldTTF* textB = (TextFieldTTF*)this->getChildByTag(2);
		float xB = textB->getPositionX() - textB->getContentSize().width / 2;
		float yB = textB->getPositionY() - textB->getContentSize().height / 2;
		float widthB = textB->getContentSize().width;
		float heightB = textB->getContentSize().height;
		Rect recB = Rect(xB, yB, widthB, heightB);

		if (recA.containsPoint(posA)) {
			log("input");
			textA->enableShadow(Color4B::BLACK);
			textA->setString("");
			textA->attachWithIME();
		}
		if (recB.containsPoint(posB)) {
			log("input");
			textB->enableShadow(Color4B::BLACK);
			textB->setString("");
			textB->attachWithIME();
		}
		return true; };
	listener->onTouchMoved = [](Touch* t, Event* event) {return true; };

	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, getChildByTag(1));
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listenerKey, getChildByTag(1));
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener->clone(), getChildByTag(2));
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listenerKey->clone(), getChildByTag(2));

}

bool Multiply::init()
{
	if (!Layer::init())
	{
		return false;
	}
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	//左文本框
	auto inputBar1 = Sprite::create("bar.png");
	inputBar1->setPosition(visibleSize.width / 2-200, visibleSize.height / 2 + 50);
	inputBar1->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	this->addChild(inputBar1);
	auto textBoxA = TextFieldTTF::textFieldWithPlaceHolder("Please input",Size(300,50),TextHAlignment::LEFT, "Marker Felt", 36);
	textBoxA->setColorSpaceHolder(Color3B::WHITE);
	textBoxA->setPosition(visibleSize.width / 2-200, visibleSize.height / 2 + 50);
	textBoxA->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	textBoxA->setCursorEnabled(true);
	this->addChild(textBoxA,0,1);
	textBoxA->setDelegate(this);
	//乘法符号
	auto multiplySign = Label::createWithSystemFont("X", "Time New Roman", 40);
	multiplySign->setTextColor(Color4B::WHITE);
	multiplySign->setPosition(visibleSize.width / 2, visibleSize.height / 2+50);
	this->addChild(multiplySign);
	//右文本框
	auto inputBar2 = Sprite::create("bar.png");
	inputBar2->setPosition(visibleSize.width / 2+200, visibleSize.height / 2 + 50);
	inputBar2->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	this->addChild(inputBar2);
	auto textBoxB = TextFieldTTF::textFieldWithPlaceHolder("Please input", Size(300, 50), TextHAlignment::LEFT, "Marker Felt", 36);
	textBoxB->setColorSpaceHolder(Color3B::WHITE);
	textBoxB->setPosition(visibleSize.width / 2+200, visibleSize.height / 2 + 50);
	textBoxB->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	textBoxB->setCursorEnabled(true);
	this->addChild(textBoxB, 0, 2);
	textBoxB->setDelegate(this);
	//左下角的返回键
	auto backMenuItem = MenuItemImage::create("NormalBack.png", "SelectedBack.png", CC_CALLBACK_1(Multiply::backMenuCallBack, this));
	auto backMenu = Menu::create(backMenuItem, NULL);
	backMenu->setPosition(backMenuItem->getContentSize().width / 2, backMenuItem->getContentSize().height / 2);
	this->addChild(backMenu);
	//等号键
	auto equalSignMenuItem = MenuItemImage::create("NormalEqualSign.png", "SelectedEqualSign.png", CC_CALLBACK_1(Multiply::multiplyResult, this));
	auto equalSign = Menu::create(equalSignMenuItem, NULL);
	equalSign->setPosition(200,200);
	this->addChild(equalSign);
	//输出结果的标签
	Label*  resultLabel = Label::createWithSystemFont("", "Time New Roman", 60);
	resultLabel->setPosition(Vec2(300, 200));
	resultLabel->setAnchorPoint(Vec2::ANCHOR_MIDDLE_LEFT);
	resultLabel->setTextColor(Color4B::WHITE);
	resultLabel->setTag(3);
	this->addChild(resultLabel, 2);

	return true;
}

void Multiply::backMenuCallBack(Ref* pSend)
{
	Director::getInstance()->popScene();
}

void Multiply::multiplyResult(Ref* pSend)
{
	TextFieldTTF* textA = (TextFieldTTF*)this->getChildByTag(1);
	TextFieldTTF* textB = (TextFieldTTF*)this->getChildByTag(2);
	std::string strA = textA->getString();
	std::string strB = textB->getString();
	int numA = stoi(strA);
	int numB = stoi(strB);
	multiplyCalculator.setLeftNum(numA);
	multiplyCalculator.setRightNum(numB);

	double result = this->multiplyCalculator.calculate();
	MultiplyCalculator::setResult(2, result);
	char res[100];
	_gcvt_s(res, result, 32);
	std::string resultString = res;
	Label* resultLabel =(Label *) this->getChildByTag(3);
	resultLabel->setString("" + resultString);
}