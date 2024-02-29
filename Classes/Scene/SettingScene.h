#ifndef __SETTING_SCENE_H__
#define	__SETTING_SCENE_H__

#include "cocos2d.h"
#include "Audio/AudioManager.h"
#include "Scene/MenuScene.h"
#include "ui/CocosGUI.h"

USING_NS_CC;

class SettingScene : public Layer
{
public:
	virtual bool init() override;

	void callBack(Ref* sender);

	CREATE_FUNC(SettingScene);
};



#endif // !__SETTING_SCENE_H__
