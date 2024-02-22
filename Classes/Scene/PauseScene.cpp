#include "PauseScene.h"

bool PauseScene::init()
{
	if (!LayerColor::initWithColor(cocos2d::Color4B(0, 0, 0, 128))) {
		return false;
	}
	auto windowPause = Sprite::create("Scene/WindowPause.png");
	windowPause->setScale(0.70f);
	windowPause->setPosition(cocos2d::Director::getInstance()->getVisibleSize() / 2);
	this->addChild(windowPause);

	auto windowSize = windowPause->getContentSize();

	auto menuButton = MenuItemImage::create("Scene/Menu_BTN.png", "Scene/Menu_BTN.png", CC_CALLBACK_1(PauseScene::callMainMenu, this));
	auto settingButton = MenuItemImage::create("Scene/Settings_BTN.png", "Scene/Settings_BTN.png", CC_CALLBACK_1(PauseScene::callSetingScene, this));
	auto resumeButton = MenuItemImage::create("Scene/Play_BTN.png", "Scene /Play_BTN.png", CC_CALLBACK_1(PauseScene::callResume, this));

	auto menuLoseScene = Menu::create(settingButton, resumeButton, menuButton, nullptr);
	menuLoseScene->setPosition(Vec2(windowSize.width / 2, windowSize.height / 8));
	menuLoseScene->alignItemsHorizontallyWithPadding(30);
	windowPause->addChild(menuLoseScene);

	auto scoreSprite = Sprite::create("Scene/Score.png");
	scoreSprite->setPosition(Vec2(windowSize.width / 3, windowSize.height / 1.5));
	windowPause->addChild(scoreSprite);

	auto tableSprite = Sprite::create("Scene/Table.png");
	tableSprite->setPosition(Vec2(windowSize.width / 1.5, windowSize.height / 1.5));
	windowPause->addChild(tableSprite);

	auto tableSize = tableSprite->getContentSize();

	auto label = Label::createWithTTF("10000", "fonts/ethnocentric rg.otf", 24);
	label->setPosition(Vec2(tableSize / 2));
	tableSprite->addChild(label);
	return true;
}

void PauseScene::callSetingScene(Ref* sender)
{

}

void PauseScene::callMainMenu(Ref* sender)
{
	Director::getInstance()->resume();
	this->removeFromParent();
	Director::getInstance()->replaceScene(MenuScene::createScene());
}

void PauseScene::callResume(Ref* sender)
{
	Director::getInstance()->resume();
	
	this->removeFromParent();
}
