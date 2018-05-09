//
//  MusicManager.cpp
//  CarrotFantasy
//
//  Created by Student on 18/5/7.
//
//

#include "MusicManager.hpp"
using namespace cocos2d;

bool MusicManager:: m_musicFlags = false;
bool MusicManager:: m_effectFlags = false;
SimpleAudioEngine* MusicManager:: m_Audio = nullptr;

void MusicManager:: init()
{
    m_Audio = SimpleAudioEngine::getInstance();
    m_musicFlags = UserDefault::getInstance()->getBoolForKey("music", true);
    m_effectFlags = UserDefault::getInstance()->getBoolForKey("effect", true);
}



void MusicManager:: playBackgroundMusic(const char* bgMusic,bool loops)
{
    if (m_musicFlags)
    {
        CCLOG("播放音乐");
        m_Audio->playBackgroundMusic(bgMusic);
    }
}
void MusicManager:: stopBackgroundMusic()
{
    m_Audio->stopBackgroundMusic();
}
void MusicManager:: pauseBackgroundMusic()
{
    m_Audio->pauseBackgroundMusic();
}
void MusicManager:: resumeBackGroungMusic()
{
    m_Audio->resumeBackgroundMusic();
}
void MusicManager:: setFlags(bool flags)
{
    m_musicFlags = flags;
    UserDefault::getInstance()->setBoolForKey("music", flags);
}
bool MusicManager:: getFlags()
{
    return m_musicFlags;
}
void MusicManager:: setEffectFlags(bool flags)
{
    m_effectFlags = flags;
    UserDefault::getInstance()->getBoolForKey("effect", flags);
}
bool MusicManager:: getEffectFlags()
{
    return m_effectFlags;
}

