//
//  HeartLayer.hpp
//  CarrotFantasy
//
//  Created by student on 18/5/7.
//
//

#ifndef HeartLayer_hpp
#define HeartLayer_hpp

#include <stdio.h>
#include "UIBaseLayer.hpp"
class HeartLayer:public UIBaseLayer
{
public:
    
    CREATE_FUNC(HeartLayer);
    void UIsetting();
    
    virtual void onCreate()override;
    virtual void onActive()override;
    virtual void onDestroy()override;
    

    
};
#endif /* HeartLayer_hpp */
