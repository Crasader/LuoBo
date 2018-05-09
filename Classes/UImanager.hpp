//
//  UImanager.hpp
//  CarrotFantasy
//
//  Created by student on 18/5/7.
//
//

#ifndef UImanager_hpp
#define UImanager_hpp

#include <stdio.h>
#include "UIBaseLayer.hpp"
#include "cocos2d.h"
class UIManager
{
public:
    enum LayerType
    {
        SETLAYER,
        SELECTLAYER
        
    };

        static UIBaseLayer*CreateLayer(LayerType type);
        static void DestroyLayer();
        static UIBaseLayer* m_activeLayer;
        
        
        
        
};




#endif /* UImanager_hpp */
