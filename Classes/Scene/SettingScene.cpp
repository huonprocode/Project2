#include "SettingScene.h"

bool SettingScene::init()
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

    auto windowSetting = Sprite::create("Scene/WindowPause.png");
    windowSetting->setScale(0.70f);
    windowSetting->setPosition(Director::getInstance()->getVisibleSize() / 2);
    this->addChild(windowSetting);

    Size winSettingSize = windowSetting->getContentSize();

    auto backButton = MenuItemImage::create("Scene/Close_BTN.png", "Scene/Close_BTN.png", CC_CALLBACK_1(SettingScene::callBack, this));
    
    auto menu = Menu::create(backButton, nullptr);
    menu->setPosition(Vec2(winSettingSize.width / 2, winSettingSize.height / 8));
    windowSetting->addChild(menu);

    float musicVolume = UserDefault::getInstance()->getFloatForKey("MusicVolume", AudioManager::getInstance()->getMusicVolume());

    auto slider = ui::Slider::create();
    slider->loadBarTexture("Scene/Slider_Back.png");
    slider->loadSlidBallTextures("Scene/SliderNode_Normal.png");
    slider->loadProgressBarTexture("Scene/Slider_PressBar.png");
    slider->setPosition(Vec2(winSettingSize.width / 2, winSettingSize.height / 1.6));
    slider->setScale(0.75);
    slider->setPercent(musicVolume * 100);
    slider->addEventListener([&](Ref* sender, ui::Slider::EventType type) {
        if (type == ui::Slider::EventType::ON_PERCENTAGE_CHANGED)
        {
            auto s = dynamic_cast<ui::Slider*> (sender);
            if (s) {
                float volume = (float)s->getPercent() / 100;
                AudioManager::getInstance()->setMusicVolume(volume);

                UserDefault::getInstance()->setFloatForKey("MusicVolume", volume);
                UserDefault::getInstance()->flush();
            }
        }
        });
    windowSetting->addChild(slider);

    float sfxVolume = UserDefault::getInstance()->getFloatForKey("SfxVolume", AudioManager::getInstance()->getSFXVolume());

    auto sliderSFX = ui::Slider::create();
    sliderSFX->loadBarTexture("Scene/Slider_Back.png");
    sliderSFX->loadSlidBallTextures("Scene/SliderNode_Normal.png");
    sliderSFX->loadProgressBarTexture("Scene/Slider_PressBar.png");
    sliderSFX->setPosition(Vec2(winSettingSize.width / 2, winSettingSize.height / 2.5));
    sliderSFX->setScale(0.75);
    sliderSFX->setPercent(sfxVolume * 100);
    sliderSFX->addEventListener([&](Ref* sender, ui::Slider::EventType type) {
        if (type == ui::Slider::EventType::ON_PERCENTAGE_CHANGED)
        {
            auto sfx = dynamic_cast<ui::Slider*> (sender);
            if (sfx) {
                float volumesfx = (float)sfx->getPercent() / 100;
                AudioManager::getInstance()->setSFXVolume(volumesfx);

                UserDefault::getInstance()->setFloatForKey("SfxVolume", volumesfx);
                UserDefault::getInstance()->flush();
            }
        }
        });
    windowSetting->addChild(sliderSFX);

    auto musicLabel = Label::createWithTTF("Music", "fonts/ethnocentric rg.otf", 30);
    musicLabel->setPosition(Vec2(winSettingSize.width/2, winSettingSize.height/1.4));
    windowSetting->addChild(musicLabel);

    auto sfxLabel = Label::createWithTTF("SFX", "fonts/ethnocentric rg.otf", 30);
    sfxLabel->setPosition(Vec2(winSettingSize.width / 2, winSettingSize.height / 2));
    windowSetting->addChild(sfxLabel);

    return true;
}


void SettingScene::callBack(Ref* sender)
{
    this->removeFromParent();
}
