#ifndef __AUDIO_MANAGER_H__
#define __AUDIO_MANAGER_H__

#include "cocos2d.h"
#include "AudioEngine.h"
USING_NS_CC;

class AudioManager
{
public:
	static AudioManager* getInstance();

	void playMusic(std::string fileName);
	void playSFX(std::string fileName);

	void setMusicVolume(float newVolume);
	void setSFXVolume(float newVolume);

	float getMusicVolume();
	float getSFXVolume();
private:
	static AudioManager* _instance;
	AudioManager();

	float _musicVolume;
	float _sfxVolume;

	int _bgmID;
	int _sfxID;
};


#endif // !__AUDIO_MANAGER_H__
