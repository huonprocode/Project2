#include "WinScene.h"

Scene* WinScene::create(int score, std::string level, int boss)
{
	auto newObject = new WinScene();
	if (newObject != nullptr && newObject->init(score, level, boss))
	{
		newObject->autorelease();
		return newObject;
	}

	CC_SAFE_DELETE(newObject);
	return nullptr;
}

bool WinScene::init(int score, std::string level, int boss)
{
	if (!Scene::init()) {
		return false;
	}

	Sprite* background = Sprite::create("BackGround/BG" + level + ".png");
	background->setPosition(Vec2(Director::getInstance()->getVisibleSize() / 2));
	this->addChild(background, -1);

	auto windowWin = Sprite::create("Scene/WindowWin.png");
	windowWin->setScale(0.70f);
	windowWin->setPosition(cocos2d::Director::getInstance()->getVisibleSize() / 2);
	this->addChild(windowWin);

	Size windowWinSize = windowWin->getContentSize();

	auto nextButton = MenuItemImage::create("Scene/Next_BTN.png", "Scene/Next_BTN.png", CC_CALLBACK_1(WinScene::callBack, this));
	auto settingButton = MenuItemImage::create("Scene/Settings_BTN.png", "Scene/Settings_BTN.png", CC_CALLBACK_1(WinScene::callSetingScene, this));
	auto replayButton = MenuItemImage::create("Scene/Replay_BTN.png", "Scene / Replay_BTN.png",
		[=](Ref* sender)
		{
			Director::getInstance()->replaceScene(GameScene::create(level, boss));
		});

	auto menuWinScene = Menu::create(settingButton, replayButton, nextButton, nullptr);
	menuWinScene->setPosition(Vec2(windowWinSize.width / 2, windowWinSize.height / 8));
	menuWinScene->alignItemsHorizontallyWithPadding(30);
	windowWin->addChild(menuWinScene);

	auto scoreSprite = Sprite::create("Scene/Score.png");
	scoreSprite->setPosition(Vec2(windowWinSize.width / 3, windowWinSize.height / 1.5));
	windowWin->addChild(scoreSprite);

	auto tableSprite = Sprite::create("Scene/Table.png");
	tableSprite->setPosition(Vec2(windowWinSize.width / 1.5, windowWinSize.height / 1.5));
	windowWin->addChild(tableSprite);

	Size tableSize = tableSprite->getContentSize();

	auto label = Label::createWithTTF(std::to_string(score), "fonts/ethnocentric rg.otf", 24);
	label->setPosition(Vec2(tableSize / 2));
	tableSprite->addChild(label);

	return true;
}

void WinScene::callSetingScene(Ref* sender)
{
	auto settingLayer = SettingScene::create();
	this->addChild(settingLayer, INT_MAX);
}

void WinScene::callBack(Ref* sender)
{
	Director::getInstance()->replaceScene(MenuScene::create());
}
