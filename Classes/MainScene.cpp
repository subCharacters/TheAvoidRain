#include "MainScene.h"
#include "TitleScene.h"

USING_NS_CC;

#include "cocos2d.h"

Scene* MainScene::createScene()
{
	auto scene = Scene::create();
	auto layer = MainScene::create();
	scene->addChild(layer);
	return scene;
}

MainScene::MainScene()
{

}

MainScene::~MainScene()
{

}

bool MainScene::init()
{
	if (!Layer::init()) {
		return false;
	}

	auto director = Director::getInstance();

	auto size = director->getWinSize();

	auto background = Sprite::create("tmpMain.jpg");

	background->setPosition(Vec2(size.width / 2.0, size.height / 2.0));

	this->addChild(background);
}