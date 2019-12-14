#include "TitleScene.h"
#include "MainScene.h"

USING_NS_CC;

Scene* TitleScene::createScene()
{
	auto scene = Scene::create();
	auto layer = TitleScene::create();
	scene->addChild(layer);
	return scene;
}

TitleScene::TitleScene()
{
}


TitleScene::~TitleScene()
{
}

bool TitleScene::init()
{
	if (!Layer::init())
	{
		return false;
	}

	auto director = Director::getInstance();
	auto winSize = director->getWinSize();

	// add to Background
	auto background = Sprite::create("tmpTitleBackground.jpg");
	background->setPosition(Vec2(winSize.width / 2.3f, winSize.height / 2.0f));
	this->addChild(background);

	// add to image
	// start
	auto start = Sprite::create("start.png");
	start->setPosition(Vec2(winSize.width / 2.0f, 90.0f));
	this->addChild(start);

	// touch to move MainScene
	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = [this](Touch* touch, Event* event)
	{
		this->getEventDispatcher()->removeAllEventListeners();

		auto delay = DelayTime::create(0.0f);

		auto startGame = CallFunc::create([] {
			auto scene = MainScene::createScene();
			auto transition = TransitionPageTurn::create(0.5f, scene, true);
			Director::getInstance()->replaceScene(transition);
		});

		this->runAction(Sequence::create(delay, startGame, NULL));
		return true;
	};

	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);

	return true;
}

void TitleScene::onEnterTransitionDidFinish()
{
	// bgm
}