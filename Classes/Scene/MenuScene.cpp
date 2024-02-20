#include "MenuScene.h"

USING_NS_CC;
Scene* MenuScene::createScene()
{
	return MenuScene::create();
}

bool MenuScene::init()
{
	if (!Scene::init())
	{
		return false;
	}
	auto visibleSize = Director::getInstance()->getVisibleSize();


	auto backGround = Sprite::create("BackGround/BGHard.png");
	backGround->setPosition(Vec2(visibleSize.width / 2, visibleSize.height/2));
	this->addChild(backGround, 0);

	auto gameScene = MenuItemImage::create("Scene/Start.png","Scene/Start1.png", CC_CALLBACK_1(MenuScene::callGameScene, this));
	gameScene->setScale(0.75f);

	auto setting = MenuItemImage::create("Scene/SettingBT.png", "Scene/SettingBT1.png", CC_CALLBACK_1(MenuScene::callSettingScene, this));
	setting->setScale(0.75f);

	auto exitGame = MenuItemImage::create("Scene/Exit.png", "Scene/Exit1.png", CC_CALLBACK_1(MenuScene::callExit, this));
	exitGame->setScale(0.75f);



	auto menu = Menu::create(gameScene, setting, exitGame, nullptr);
	menu->setPosition(visibleSize / 2);
	menu->alignItemsVerticallyWithPadding(visibleSize.height/30);
	this->addChild(menu, 1);

	return true;
}

void MenuScene::callGameScene(Ref* sender)
{
	
	Director::getInstance()->replaceScene(GameScene::create("Easy", 1));
	Director::getInstance()->resume();
}

void MenuScene::callSettingScene(Ref* sender)
{
	auto setting = SettingScene::create();
	addChild(setting, INT_MAX);
	
}

void MenuScene::callExit(Ref* sender)
{
	Director::getInstance()->end();
}
