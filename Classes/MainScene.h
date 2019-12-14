#pragma once

#ifndef __AvoidRain__MainScene__
#define __AvoidRain__MainScene__

#include "cocos2d.h"

class MainScene :public cocos2d::Layer
{
protected:
	MainScene();
	virtual ~MainScene();
	bool init() override;

public:
	static cocos2d::Scene* createScene();

	CREATE_FUNC(MainScene);

};
#endif /* defined__AvoidRain__MainScene__*/
