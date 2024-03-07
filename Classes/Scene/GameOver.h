#ifndef __GAME_OVER_H__
#define __GAME_OVER_H__

#include "cocos2d.h"
#include "MenuScene.h"
#include "ui/CocosGUI.h"

USING_NS_CC;

class GameOver : public Scene
{
public:
	virtual bool init(int score, std::string level, int boss);
	static Scene* create(int score, std::string level, int boss);

	void callSetingScene(Ref* sender);
	void callMainMenu(Ref* sender);

};
#endif // !__GAME_OVER_H__
