#ifndef __GAME_OVER_H__
#define __GAME_OVER_H__

#include "cocos2d.h"
#include "MenuScene.h"
#include "ui/CocosGUI.h"

USING_NS_CC;

class GameOver : public LayerColor
{
public:
	virtual bool init(int diem);

	void callSetingScene(Ref* sender);
	void callMainMenu(Ref* sender);
	void callMap(Ref* sender);

	static LayerColor* create(int diem);
	// chuyen diem thanh chuoi xong gan vao label la duoc
};
#endif // !__GAME_OVER_H__
