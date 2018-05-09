//
//  HelpScene.hpp
//  CarrotFantasy
//
//  Created by MAC on 2018/5/7.
//
//

#ifndef HelpScene_hpp
#define HelpScene_hpp

#include <stdio.h>
#include <cocos2d.h>
#include "ui/cocosGUI.h"
USING_NS_CC;
class HelpScene:public cocos2d::Scene
{
public:
    static Scene* createScene();
    bool init()override;
    cocos2d::ui::PageView *pageView;
    Label* label;
    Layer* layer1;
    Layer* layer2;
    Layer* layer3;
    Size visibleSize;
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    void helpUI();
    void guaiWuUI();
    void towerUI();
    void addBottomLabel();
    void addBottomLabel(int num);

    CREATE_FUNC(HelpScene);
};
#endif /* HelpScene_hpp */
