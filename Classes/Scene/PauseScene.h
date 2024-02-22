#ifndef __PAUSE_SCENE_H__
#define __PAUSE_SCENE_H__

#include "cocos2d.h"
#include "MenuScene.h"
#include "GameScene.h"

USING_NS_CC;

class PauseScene : public LayerColor
{
public:
	virtual bool init() override;

	void callSetingScene(Ref* sender);
	void callMainMenu(Ref* sender);
	void callResume(Ref* sender);

	CREATE_FUNC(PauseScene);
};
#endif // !__PAUSE_SCENE__
