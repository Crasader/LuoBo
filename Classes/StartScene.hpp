//
//  StartScene.hpp
//  CarrotFantasy
//
//  Created by student on 18/5/7.
//
//

#ifndef StartScene_hpp
#define StartScene_hpp

#include <stdio.h>
#include "cocos2d.h"
class StartScene:public cocos2d::Scene
{
    
public:
    static Scene* createScene();
    virtual bool init()override;
    CREATE_FUNC(StartScene);
    void initUI();
    void setDH();
    void setBtn();
    void onEnter()override;
    void onExit()override;
private:
    cocos2d::Node* node;
    
};
#endif /* StartScene_hpp */
