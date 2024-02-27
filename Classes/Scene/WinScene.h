#ifndef __WIN_SCENE_H__
#define __WIN_SCENE_H__

#include "cocos2d.h"
#include "SettingScene.h"
 
USING_NS_CC;

class WinScene : public LayerColor
{
public:
	virtual bool init() override;

	void callSetingScene(Ref* sender);
	void callReplay(Ref* sender);
	void callNext(Ref* sender);

	CREATE_FUNC(WinScene);
};

#endif // !__WIN_SCENE_H__
