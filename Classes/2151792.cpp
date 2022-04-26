#include"2151792.h"
#include"HelloWorldScene.h"
//���Լ������µĳ�������
//��������
Scene* ZxSecondScene::createScene()
{
	Scene* scene = Scene::create();
	ZxSecondScene* layer = ZxSecondScene::create();
	scene->addChild(layer);
	return scene;
}

//��ʼ������
bool ZxSecondScene::init()
{
	if (!Layer::init())
	{
		return false;
	}

	//�Ӵ���С��ԭ��
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	// ��һ������ͼƬ������
	auto sprite = Sprite::create("zx_background.png");

	//���ͼƬ��С
	float f_sizex = sprite->getTextureRect().getMaxX();
	float f_sizey = sprite->getTextureRect().getMaxY();

	//ͼƬλ������Ϊ���ĵ�
	sprite->setPosition(Vec2(origin.x + visibleSize.width / 2, visibleSize.height / 2 + origin.y));

	//��ͼƬ��С���е�����ʹ��������Ӧ��Ļ���ú�������Ϊ���ű�����
	sprite->setScaleX(visibleSize.width / f_sizex);
	sprite->setScaleY(visibleSize.height / f_sizey);

	// ��ͼƬ�����
	this->addChild(sprite, 0);


	//��ǩ������Ϊ��Ҫ��ʾ�����֣�����Ϊ Marker Felt ����СΪ 50.
	auto movelabel = Label::createWithTTF("Hi,my name is ZhangXiang", "Fonts/Marker Felt.ttf", 50);

	//���ñ�ǩλ��Ϊ�Ӵ��·� (ע���ǩ���ĵ� Ϊ��ǩ���꣩
	movelabel->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y - movelabel->getContentSize().height / 2));
	
	//�����ƶ���ʽ�������·��ƶ������Ϸ�����ʱ��2.5s
	float f_movex = origin.x + visibleSize.width / 2;
	float f_movey = origin.y + visibleSize.height - movelabel->getContentSize().height / 2;
	MoveTo* move = MoveTo::create(2.5f, Vec2(f_movex, f_movey));
	

	//���ƶ���ʽ���ݸ���ǩ��������ǩ�����
	movelabel->runAction(move);
	this->addChild(movelabel);

	//��������ͼƬ�����˵���Ŀ
	auto menuitem_back = MenuItemImage::create("zx_backward_button.png","zx_backward_button.png", 
												CC_CALLBACK_1(ZxSecondScene::enterFirstScene, this));


	//���˵���Ŀ����˵���
	auto menu_back = Menu::create(menuitem_back, NULL);

	//ȷ���˵���λ�ã��Ӵ����½�
	float f_backx = origin.x + visibleSize.width - menuitem_back->getContentSize().width;
	float f_backy = origin.y + menuitem_back->getContentSize().height;
	menu_back->setPosition(Vec2(f_backx, f_backy));


	//�ڲ�����ӷ��ز˵�
	this->addChild(menu_back);

	return true;
}

void ZxSecondScene::enterFirstScene(Ref* pSender)
{
	//����Ҫ������³���
	Scene* zx_scene = HelloWorld::createScene();

	//ת��С����  ������ʱ��ʱ��3s  ��Ч��Ϊ����Ļ����
	TransitionJumpZoom* zx_tran = TransitionJumpZoom::create(3.0f, zx_scene);

	//�����࣬ʵʩת��
	Director::getInstance()->replaceScene(zx_tran);
}