#ifndef __LEVEL_INFO_H__
#define __LEVEL_INFO_H__

#include "cocos2d.h"

USING_NS_CC;

class LevelInfo : public Layer
{
public:
	virtual bool init(std::string level, int boss);
	static Layer* create(std::string level, int boss);

	MenuItemImage* playButton, * backButton;
	Menu* menu;
};
#endif // !__LEVEL_INFO_H__
