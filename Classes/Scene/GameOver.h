#ifndef __GAME_OVER_H__
#define __GAME_OVER_H__

#include "cocos2d.h"
#include "MenuScene.h"
#include "ui/CocosGUI.h"

USING_NS_CC;

class GameOver : public LayerColor
{
public:
	virtual bool init() override;

	void callSetingScene(Ref* sender);
	void callMainMenu(Ref* sender);
	void callMap(Ref* sender);

	CREATE_FUNC(GameOver);
};
#endif // !__GAME_OVER_H__
