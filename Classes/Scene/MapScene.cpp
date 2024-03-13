#include "MapScene.h"
#include "GameScene.h"
#include "MenuScene.h"
#include "LevelInfo.h"

bool MapScene::init()
{
	if (!Scene::init())
	{
		return false;
	}
	auto visibleSize = Director::getInstance()->getVisibleSize();

	auto backGround = Sprite::create("BackGround/BG.png");
	backGround->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
	this->addChild(backGround, -1);

	auto backButton = MenuItemImage::create("Scene/Close_BTN.png", "Scene/Close_BTN.png", CC_CALLBACK_1(MapScene::callBack, this));
	backButton->setScale(0.5);
	backButton->setAnchorPoint(Vec2::ANCHOR_TOP_RIGHT);
	auto button = Menu::create(backButton, nullptr);
	button->setPosition(Vec2(Director::getInstance()->getVisibleSize()));
	this->addChild(button,1);

	auto level1 = MenuItemLabel::create(Label::createWithTTF("Easy", "fonts/ethnocentric rg.otf", 40), CC_CALLBACK_1(MapScene::level1, this));
	level1->setScale(0.75f);

	auto level2 = MenuItemLabel::create(Label::createWithTTF("Medium", "fonts/ethnocentric rg.otf", 40), CC_CALLBACK_1(MapScene::level2, this));
	level2->setScale(0.75f);

	auto level3 = MenuItemLabel::create(Label::createWithTTF("Hard", "fonts/ethnocentric rg.otf", 40), CC_CALLBACK_1(MapScene::level3, this));
	level3->setScale(0.75f);

	auto menu = Menu::create(level1, level2, level3, nullptr);
	menu->setPosition(visibleSize / 2);
	menu->alignItemsVerticallyWithPadding(visibleSize.height / 20);
	this->addChild(menu, 1);

	return true;
}

void MapScene::level1(Ref* sender)
{
	addChild(LevelInfo::create("Easy", 1), 5);
}

void MapScene::level2(Ref* sender)
{
	addChild(LevelInfo::create("Medium", 2), 5);
}

void MapScene::level3(Ref* sender)
{
	addChild(LevelInfo::create("Hard", 3), 5);
}

void MapScene::callBack(Ref* sender)
{
	Director::getInstance()->replaceScene(MenuScene::create());
}