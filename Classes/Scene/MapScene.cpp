#include "MapScene.h"
#include "GameScene.h"

bool MapScene::init()
{
	if (!Scene::init())
	{
		return false;
	}
	auto visibleSize = Director::getInstance()->getVisibleSize();

	auto backGround = Sprite::create("BackGround/BGHard.png");
	backGround->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
	this->addChild(backGround, -1);

	auto level1 = MenuItemImage::create("Scene/Level1_BTN.png", "Scene/Level1_BTN.png", CC_CALLBACK_1(MapScene::level1, this));
	level1->setScale(0.75f);

	auto level2 = MenuItemImage::create("Scene/Level2_BTN.png", "Scene/Level2_BTN.png", CC_CALLBACK_1(MapScene::level2, this));
	level2->setScale(0.75f);

	auto level3 = MenuItemImage::create("Scene/Level3_BTN.png", "Scene/Level3_BTN.png", CC_CALLBACK_1(MapScene::level3, this));
	level3->setScale(0.75f);

	auto menu = Menu::create(level1, level2, level3, nullptr);
	menu->setPosition(visibleSize / 2);
	menu->alignItemsVerticallyWithPadding(visibleSize.height / 30);
	this->addChild(menu, 1);
	return true;
}

void MapScene::level1(Ref* sender)
{
	Director::getInstance()->replaceScene(GameScene::create("Easy", 1));
}

void MapScene::level2(Ref* sender)
{
	Director::getInstance()->replaceScene(GameScene::create("Medium", 2));
}

void MapScene::level3(Ref* sender)
{
	Director::getInstance()->replaceScene(GameScene::create("Hard", 3));
}
