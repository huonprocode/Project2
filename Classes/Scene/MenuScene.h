#ifndef __MENU_SCENE_H__
#define __MENU_SCENE_H__

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "GameScene.h"
#include "GameOver.h"
#include "PauseScene.h"
#include "SettingScene.h"
 
USING_NS_CC;

class MenuScene : public Scene
{
public:
	static Scene* createScene();
	virtual bool init();

	void callGameScene(Ref* sender);
	void callSettingScene(Ref* sender);
	void callExit(Ref* sender);
	Sprite* backGround;
	CREATE_FUNC(MenuScene);
};

#endif // !__MENU_SCENE_H__
