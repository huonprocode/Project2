#include "LevelInfo.h"
#include "GameScene.h"

Layer* LevelInfo::create(std::string level, int boss)
{
    auto newLayer = new LevelInfo();
	if (newLayer != nullptr && newLayer->init(level, boss))
	{
		newLayer->autorelease();
		return newLayer;
	}

	CC_SAFE_DELETE(newLayer);
    return nullptr;
}

bool LevelInfo::init(std::string level, int boss)
{
	if (!Layer::init())
	{
		return false;
	}

	auto overlayLayer = LayerColor::create(Color4B(0, 0, 0, 128));
	overlayLayer->setContentSize(Director::getInstance()->getVisibleSize());
	overlayLayer->setPosition(Vec2::ZERO);
	this->addChild(overlayLayer, -1);

	auto touchListener = EventListenerTouchOneByOne::create();
	touchListener->setSwallowTouches(true);
	touchListener->onTouchBegan = [](Touch* touch, Event* event) -> bool {
		return true;
		};
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchListener, overlayLayer);

	auto window = Sprite::create("Scene/Window.png");
	window->setScale(0.70f);
	window->setPosition(Director::getInstance()->getVisibleSize() / 2);
	this->addChild(window);

	Size windowSize = window->getContentSize();

	playButton = MenuItemImage::create("Scene/Play_BTN.png", "Scene/Play_BTN.png",
		[=](Ref* sender)
		{
			Director::getInstance()->replaceScene(GameScene::create(level, boss));
			this->removeFromParent();
		});
	backButton = MenuItemImage::create("Scene/Close_BTN.png", "Scene/Close_BTN.png",
		[&](Ref* sender)
		{
			this->removeFromParent();
		});
	 menu = Menu::create(backButton, playButton, nullptr);
	 menu->setPosition(Vec2(windowSize.width / 2, windowSize.height / 8));
	 menu->alignItemsHorizontallyWithPadding(30);
	 window->addChild(menu);

	 auto recordSprite = Sprite::create("Scene/Record.png");
	 recordSprite->setPosition(Vec2(windowSize.width / 3, windowSize.height / 1.5));
	 window->addChild(recordSprite);

	 auto tableSprite = Sprite::create("Scene/Table.png");
	 tableSprite->setPosition(Vec2(windowSize.width / 1.5, windowSize.height / 1.5));
	 window->addChild(tableSprite);

	 Size tableSize = tableSprite->getContentSize();

	 auto levelLabel = Label::createWithTTF("LEVEL " + std::to_string(boss), "fonts/ethnocentric rg.otf", 40);
	 levelLabel->setPosition(Vec2(windowSize.width / 2, windowSize.height /1.05));
	 window->addChild(levelLabel);

	 auto label = Label::createWithTTF("1000000", "fonts/ethnocentric rg.otf", 24);
	 label->setPosition(Vec2(tableSize / 2));
	 tableSprite->addChild(label);

	return true;
}


