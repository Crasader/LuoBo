//
//  SelectLayer.hpp
//  CarrotFantasy
//
//  Created by student on 18/5/9.
//
//

#ifndef SelectLayer_hpp
#define SelectLayer_hpp

#include <stdio.h>
#include "UIBaseLayer.hpp"
class SelectLayer:public UIBaseLayer
{
public:
    CREATE_FUNC(SelectLayer);
    void UIsetting();
    void addTouchListener();
    
    virtual void onCreate()override;
    virtual void onActive()override;
    virtual void onDestroy()override;
private:
    cocos2d::Node* node1;

    
};
#endif /* SelectLayer_hpp */
