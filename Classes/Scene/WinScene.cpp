#include "WinScene.h"

bool WinScene::init()
{
	if (!LayerColor::initWithColor(cocos2d::Color4B(0, 0, 0, 128))) {
		return false;
	}

	auto window = Sprite::create("Scene/WindowWin.png");
	window->setScale(0.70f);
	window->setPosition(cocos2d::Director::getInstance()->getVisibleSize() / 2);
	this->addChild(window);

	auto windowSize = window->getContentSize();

	auto nextButton = MenuItemImage::create("Scene/Next_BTN.png", "Scene/Next_BTN.png", CC_CALLBACK_1(WinScene::callNext, this));
	auto settingButton = MenuItemImage::create("Scene/Settings_BTN.png", "Scene/Settings_BTN.png", CC_CALLBACK_1(WinScene::callSetingScene, this));
	auto replayButton = MenuItemImage::create("Scene/Replay_BTN.png", "Scene / Replay_BTN.png", CC_CALLBACK_1(WinScene::callReplay, this));

	auto menuWinScene = Menu::create(settingButton, replayButton, nextButton, nullptr);
	menuWinScene->setPosition(Vec2(windowSize.width / 2, windowSize.height / 8));
	menuWinScene->alignItemsHorizontallyWithPadding(30);
	window->addChild(menuWinScene);

	auto scoreSprite = Sprite::create("Scene/Score.png");
	scoreSprite->setPosition(Vec2(windowSize.width / 3, windowSize.height / 1.5));
	window->addChild(scoreSprite);

	auto tableSprite = Sprite::create("Scene/Table.png");
	tableSprite->setPosition(Vec2(windowSize.width / 1.5, windowSize.height / 1.5));
	window->addChild(tableSprite);

	auto tableSize = tableSprite->getContentSize();

	auto label = Label::createWithTTF("10000", "fonts/ethnocentric rg.otf", 24);
	label->setPosition(Vec2(tableSize / 2));
	tableSprite->addChild(label);

	return true;
}

void WinScene::callSetingScene(Ref* sender)
{
	auto settingLayer = SettingScene::create();
	this->addChild(settingLayer, INT_MAX);
}

void WinScene::callReplay(Ref* sender)
{

}

void WinScene::callNext(Ref* sender)
{

}
