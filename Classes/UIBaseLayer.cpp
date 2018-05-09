//
//  UIBaseLayer.cpp
//  CarrotFantasy
//
//  Created by student on 18/5/7.
//
//

#include "UIBaseLayer.hpp"
bool UIBaseLayer::init()
{
    if (!Layer::init())
    {
        return false;
    }
    this->onCreate();
    return true;
}
void UIBaseLayer::onEnter()
{
    Layer::onEnter();
    this->onActive();
}
void UIBaseLayer::onExit()
{
    this->onDestroy();
    Layer::onExit();
}