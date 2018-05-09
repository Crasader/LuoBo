//
//  SettingScene.hpp
//  CarrotFantasy
//
//  Created by Student on 18/5/7.
//
//

#ifndef SettingScene_hpp
#define SettingScene_hpp

#include <stdio.h>
#include "cocos2d.h"

class SettingScene:public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();
    bool init()override;
    CREATE_FUNC(SettingScene);
    void SettingUI();
    void statisticsUI();
    void creditsUI();
    virtual void onEnter()override;
    virtual void onExit()override;
};





#endif /* SettingScene_hpp */
