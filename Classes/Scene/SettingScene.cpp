#include "SettingScene.h"

bool SettingScene::init()
{
    if (!LayerColor::initWithColor(cocos2d::Color4B(0, 0, 0, 128)))
    {
        return false;
    }

    auto windowSetting = Sprite::create("Scene/WindowPause.png");
    windowSetting->setScale(0.70f);
    windowSetting->setPosition(Director::getInstance()->getVisibleSize() / 2);
    this->addChild(windowSetting);

    auto winSize = windowSetting->getContentSize();

    auto backButton = MenuItemImage::create("Scene/Close_BTN.png", "Scene/Close_BTN.png", CC_CALLBACK_1(SettingScene::callBack, this));
    
    auto menu = Menu::create(backButton, nullptr);
    menu->setPosition(Vec2(winSize.width / 2, winSize.height / 8));
    windowSetting->addChild(menu);

    float musicVolume = UserDefault::getInstance()->getFloatForKey("MusicVolume", AudioManager::getInstance()->getMusicVolume());

    auto slider = ui::Slider::create();
    slider->loadBarTexture("Scene/Slider_Back.png");
    slider->loadSlidBallTextures("Scene/SliderNode_Normal.png");
    slider->loadProgressBarTexture("Scene/Slider_PressBar.png");
    slider->setPosition(Vec2(winSize.width / 2, winSize.height / 1.6));
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
    sliderSFX->setPosition(Vec2(winSize.width / 2, winSize.height / 2.5));
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
    musicLabel->setPosition(Vec2(winSize.width/2, winSize.height/1.4));
    windowSetting->addChild(musicLabel);

    return true;
}



void SettingScene::callBack(Ref* sender)
{
    this->removeFromParent();
}
