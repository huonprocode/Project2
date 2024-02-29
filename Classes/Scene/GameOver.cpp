#include "GameOver.h"

Scene* GameOver::create(int score)
{
	auto newObject = new GameOver();
	if (newObject != nullptr && newObject->init(score))
	{
		newObject->autorelease();
		return newObject;
	}

	CC_SAFE_DELETE(newObject);
	return nullptr;
}

bool GameOver::init(int score)
{
	if (!Scene::init()) 
	{
		return false;
	}

	auto window = Sprite::create("Scene/WindowLose.png");
	window->setScale(0.70f);
	window->setPosition(cocos2d::Director::getInstance()->getVisibleSize() / 2);
	this->addChild(window);

	auto windowSize = window->getContentSize();

	auto menuButton = MenuItemImage::create("Scene/Menu_BTN.png", "Scene/Menu_BTN.png", CC_CALLBACK_1(GameOver::callMainMenu, this));
	auto settingButton = MenuItemImage::create("Scene/Settings_BTN.png", "Scene/Settings_BTN.png", CC_CALLBACK_1(GameOver::callSetingScene, this));
	auto replayButton = MenuItemImage::create("Scene/Replay_BTN.png", "Scene / Replay_BTN.png", CC_CALLBACK_1(GameOver::callReplay, this));

	auto menuLoseScene = Menu::create(settingButton, replayButton, menuButton, nullptr);
	menuLoseScene->setPosition(Vec2(windowSize.width / 2, windowSize.height / 8));
	menuLoseScene->alignItemsHorizontallyWithPadding(30);
	window->addChild(menuLoseScene);

	auto scoreSprite = Sprite::create("Scene/Score.png");
	scoreSprite->setPosition(Vec2(windowSize.width / 3, windowSize.height / 1.5));
	window->addChild(scoreSprite);

	auto tableSprite = Sprite::create("Scene/Table.png");
	tableSprite->setPosition(Vec2(windowSize.width / 1.5, windowSize.height / 1.5));
	window->addChild(tableSprite);

	auto tableSize = tableSprite->getContentSize();

	auto label = Label::createWithTTF(std::to_string(score), "fonts/ethnocentric rg.otf", 24);
	label->setPosition(Vec2(tableSize / 2));
	tableSprite->addChild(label);

	return true;
}

void GameOver::callSetingScene(Ref* sender)
{
	auto settingLayer = SettingScene::create();
	this->addChild(settingLayer, INT_MAX);

}

void GameOver::callMainMenu(Ref* sender)
{
	Director::getInstance()->replaceScene(MenuScene::create());
}

void GameOver::callReplay(Ref* sender)
{
	Director::getInstance()->replaceScene(GameScene::create("Easy", 1));
}


