#include "TitleScene.h"
#include "MainScene.h"
#include "SimpleAudioEngine.h"

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
	auto delay = DelayTime::create(0.5f);
	auto startButton = MenuItemImage::create("start.png", "start.png", [](Ref* ref) {
		auto scene = MainScene::createScene();
		auto transition = TransitionCrossFade::create(1.0f, scene);
		
		auto audioEngine = CocosDenshion::SimpleAudioEngine::getInstance();
		audioEngine->playEffect("huh_.mp3");

		Director::getInstance()->replaceScene(transition);

	});
		this->runAction(Sequence::create(delay, startButton, NULL));

	// 메뉴 작성
	auto menu = Menu::create(startButton, NULL);
	menu->alignItemsVerticallyWithPadding(30);
	menu->setPosition(Vec2(winSize.width / 2.0f, winSize.height / 2.0f));
	this->addChild(menu);



	return true;
}

void TitleScene::onEnterTransitionDidFinish()
{
	// bgm
}