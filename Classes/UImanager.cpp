//
//  UImanager.cpp
//  CarrotFantasy
//
//  Created by student on 18/5/7.
//
//

#include "UImanager.hpp"
#include "HeartLayer.hpp"
#include "SelectLayer.hpp"
#define BACKGROUNDZORDER 10
#define SETLAYERZORDER 20

UIBaseLayer* UIManager::m_activeLayer = nullptr;

UIBaseLayer* UIManager::CreateLayer(UIManager::LayerType type)
{
    m_activeLayer = nullptr;
    switch (type) {
        case SETLAYER:
        {
            m_activeLayer = HeartLayer::create();
            m_activeLayer->setLocalZOrder(SETLAYERZORDER);
            break;
        }
        case SELECTLAYER:
        {
            m_activeLayer = SelectLayer::create();
            m_activeLayer->setLocalZOrder(BACKGROUNDZORDER);
            break;
        }
            
        default:
            break;
    }
    return m_activeLayer;
}
void UIManager::DestroyLayer()
{
    if (m_activeLayer)
    {
        m_activeLayer->removeFromParent();
        m_activeLayer = nullptr;
    }
}