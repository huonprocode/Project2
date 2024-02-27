#include "GameOver.h"

bool GameOver::init(int diem)
{
	if (!LayerColor::initWithColor(cocos2d::Color4B(0, 0, 0, 128))) {
		return false;
	}

	auto window = Sprite::create("Scene/Window.png");
	window->setScale(0.70f);
	window->setPosition(cocos2d::Director::getInstance()->getVisibleSize() / 2);
	this->addChild(window);

	auto windowSize = window->getContentSize();

	auto menuButton = MenuItemImage::create("Scene/Menu_BTN.png", "Scene/Menu_BTN.png", CC_CALLBACK_1(GameOver::callMainMenu, this));
	auto settingButton = MenuItemImage::create("Scene/Settings_BTN.png", "Scene/Settings_BTN.png", CC_CALLBACK_1(GameOver::callSetingScene, this));
	auto replayButton = MenuItemImage::create("Scene/Replay_BTN.png", "Scene / Replay_BTN.png", CC_CALLBACK_1(GameOver::callMap, this));

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

	auto label = Label::createWithTTF(std::to_string(diem), "fonts/ethnocentric rg.otf", 24);
	label->setPosition(Vec2(tableSize / 2));
	tableSprite->addChild(label);

	/*auto slider = ui::Slider::create();
	slider->loadBarTexture("Scene/Slider_Back.png");
	slider->loadSlidBallTextures("Scene/SliderNode_Normal.png");
	slider->loadProgressBarTexture("Scene/Slider_PressBar.png");
	slider->setPosition(Vec2(windowSize/2));
	slider->setScale(0.75);
	slider->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type) {
		switch (type)
		{
		case ui::Widget::TouchEventType::BEGAN:
			break;
		case ui::Widget::TouchEventType::ENDED:
			std::cout << "slider moved" << std::endl;
			break;
		default:
			break;
		}
		});
	window->addChild(slider);*/

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

void GameOver::callMap(Ref* sender)
{
	Director::getInstance()->replaceScene(GameScene::create("Easy", 1));
}

LayerColor* GameOver::create(int diem)
{
	auto newObject = new GameOver();
	if (newObject != nullptr && newObject->init(diem))
	{
		newObject->autorelease();
		return newObject;
	}

	CC_SAFE_DELETE(newObject);
	return nullptr;
}
