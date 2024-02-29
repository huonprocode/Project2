#ifndef __WIN_SCENE_H__
#define __WIN_SCENE_H__

#include "cocos2d.h"
#include "SettingScene.h"
 
USING_NS_CC;

class WinScene : public Scene
{
public:
	virtual bool init(int score);
	static Scene* create(int score);

	void callSetingScene(Ref* sender);
	void callReplay(Ref* sender);
	void callBack(Ref* sender);

};

#endif // !__WIN_SCENE_H__
