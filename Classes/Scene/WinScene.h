#ifndef __WIN_SCENE_H__
#define __WIN_SCENE_H__

#include "cocos2d.h"
#include "SettingScene.h"
 
USING_NS_CC;

class WinScene : public Scene
{
public:
	virtual bool init(int score, std::string level, int boss);
	static Scene* create(int score, std::string level, int boss);

	void callSetingScene(Ref* sender);
	void callBack(Ref* sender);
};

#endif // !__WIN_SCENE_H__
