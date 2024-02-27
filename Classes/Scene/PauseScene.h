#ifndef __PAUSE_SCENE_H__
#define __PAUSE_SCENE_H__

#include "cocos2d.h"

USING_NS_CC;

class PauseScene : public LayerColor
{
public:
	virtual bool init(int score);
	static LayerColor* create(int score);

	void callSetingScene(Ref* sender);
	void callMainMenu(Ref* sender);
	void callResume(Ref* sender);

	
};
#endif // !__PAUSE_SCENE__
