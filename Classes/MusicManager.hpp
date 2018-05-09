//
//  MusicManager.hpp
//  CarrotFantasy
//
//  Created by Student on 18/5/7.
//
//

#ifndef MusicManager_hpp
#define MusicManager_hpp

#include <stdio.h>
#include "cocos2d.h"
#include "audio/include/SimpleAudioEngine.h"
using namespace CocosDenshion;

class MusicManager
{
public:
    static void init();
    static void playBackgroundMusic(const char* bgMusic,bool loops = false);
    static void stopBackgroundMusic();
    static void pauseBackgroundMusic();
    static void resumeBackGroungMusic();
    static void setFlags(bool flags);
    static bool getFlags();
    static void setEffectFlags(bool flags);
    static bool getEffectFlags();
    
    
    
private:
    static bool m_musicFlags;
    static bool m_effectFlags;
    static SimpleAudioEngine* m_Audio;
};


#endif /* MusicManager_hpp */
