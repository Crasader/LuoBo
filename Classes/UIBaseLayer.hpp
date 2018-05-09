//
//  UIBaseLayer.hpp
//  CarrotFantasy
//
//  Created by student on 18/5/7.
//
//

#ifndef UIBaseLayer_hpp
#define UIBaseLayer_hpp

#include <stdio.h>
#include "cocos2d.h"
class UIBaseLayer:public cocos2d::Layer
{
public:
    CREATE_FUNC(UIBaseLayer);
    virtual bool init()override;
    virtual void onEnter()override;
    virtual void onExit()override;
    
    
    virtual void onCreate(){};
    virtual void onActive(){};
    virtual void onDestroy(){};
};

#endif /* UIBaseLayer_hpp */
