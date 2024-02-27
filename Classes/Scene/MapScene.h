#ifndef __MAP_SCENE_H__
#define __MAP_SCENE_H__

#include "cocos2d.h"

USING_NS_CC;

class MapScene : public Scene
{
public:

	virtual bool init() override;

	void level1(Ref* sender);
	void level2(Ref* sender);
	void level3(Ref* sender);

	CREATE_FUNC(MapScene);
};
#endif // !__MAP_SCENE_H__
