#include"DivisionCalculatorScene.h"
#include"HelloWorldScene.h"
#include "ui/CocosGUI.h"
#include "AllAnswer.h"
#include <string>
#include <iostream>
#include <sstream>

USING_NS_CC;

//��������
Scene* AllAnswerScene::createScene()
{
	Scene* scene = Scene::create();
	AllAnswerScene* layer = AllAnswerScene::create();
	scene->addChild(layer);
	return scene;
}


const std::string sFlag[4] = { "+","-","*","/" };

//��ʼ������
bool AllAnswerScene::init()
{
	//���ñ���
	if (!LayerColor::initWithColor({ 176,196,222 ,255 }))
	{
		return false;
	}

	//�Ӵ���С��ԭ��
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	AllAnswer inputAnswer;

	//�𰸱�ǩ,ѭ������4��
	for (int i = 0; i < 4; i++)
	{
		//�õ����
		std::ostringstream o;
		o << inputAnswer.getResult()[i];
		std::string sDigit = o.str();

		//�����
		auto resultLabel = Label::createWithTTF("The result of   " + sFlag[i] + " :      " + sDigit, "fonts/Marker Felt.TTF", 40);
		resultLabel->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height * (7- 2 * i) / 8));
		resultLabel->setTextColor(Color4B::BLACK);

		this->addChild(resultLabel);
	}

	//���ذ�ť
	//��������ͼƬ�����˵���Ŀ
	auto menuItemBack = MenuItemImage::create("NormalBack.png", "NormalBack.png",
		CC_CALLBACK_1(AllAnswerScene::enterFirstScene, this));

	auto menuBack = Menu::create(menuItemBack, NULL);

	float fBackx = origin.x + visibleSize.width - menuItemBack->getContentSize().width;
	float fBacky = origin.y + menuItemBack->getContentSize().height;
	menuBack->setPosition(Vec2(fBackx, fBacky));

	this->addChild(menuBack, 1);
	return true;
}

//�� Halloworld
void AllAnswerScene::enterFirstScene(Ref* pSender)
{
	//����Ҫ������³���������
	Scene* firstScene = HelloWorld::createScene();
	auto answerTran = TransitionSlideInR::create(0.5f, firstScene);

	Director::getInstance()->replaceScene(answerTran);
}