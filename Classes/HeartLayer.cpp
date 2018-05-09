//
//  HeartLayer.cpp
//  CarrotFantasy
//
//  Created by student on 18/5/7.
//
//

#include "HeartLayer.hpp"
#include "Constant.hpp"
#include "VisibleRect.hpp"
#include "ui/cocosGUI.h"
#include "UImanager.hpp"
USING_NS_CC;
void HeartLayer::onCreate()
{
    this->UIsetting();
}
void HeartLayer::UIsetting()
{
    auto Bg=Sprite::create(checkbg);
    Bg->setPosition(VisibleRect::center());
    Bg->setScale(0.5);
    this->addChild(Bg);
    
    auto btn=ui::Button::create(x1);
    btn->setPosition(Vec2(VisibleRect::center().x+190,VisibleRect::center().y+90));
    Bg->addChild(btn);
    btn->addClickEventListener([=](Ref* sender)
    {
        UIManager::DestroyLayer();
    });
    
    auto label=Label::createWithSystemFont("帅琛", "", 50);
    label->setColor(Color3B::BLACK);
    label->setPosition(Vec2(VisibleRect::center()));
    Bg->addChild(label,2);
}
void HeartLayer::onActive()
{
    CCLOG("激活心形－－> 准备刷新UI");
}
void HeartLayer::onDestroy()
{
    CCLOG("销毁心形 －－> 准备保存各种设置");
    
}
