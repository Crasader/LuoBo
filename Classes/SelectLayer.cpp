//
//  SelectLayer.cpp
//  CarrotFantasy
//
//  Created by student on 18/5/9.
//
//

#include "SelectLayer.hpp"
#include "CocoStudio.h"
#include "ui/cocosGUI.h"
#include "SceneManager.hpp"

#include "ui/UIText.h"
USING_NS_CC;
void SelectLayer::onCreate()
{
    this->UIsetting();
}
void SelectLayer::UIsetting()
{
    FileUtils::getInstance()->addSearchPath("Studio");
    node1=CSLoader::createNode("Layer.csb");
    this->addChild(node1);
    auto btn1=node1->getChildByName("Button_1");
    (static_cast<ui::Button*>(btn1))->addClickEventListener([=](Ref* sender)
    {

        CCLOG("测试按钮");
       
        SceneMannger::goToStartScene();//需要修改成main

    });
    auto btn2=node1->getChildByName("Button_2");
    (static_cast<ui::Button*>(btn2))->addClickEventListener([=](Ref* sender)
    {
        
        CCLOG("测试按钮");
        
        SceneMannger::goToHelpScene();
        
    });
    
    //选择关卡
    auto label1 = ui::Text::create();
    label1->setString("选择关卡");
    label1->setFontSize(15);
    label1->setColor(Color3B(255, 255, 255));
    label1->setPosition(Vec2(this->getContentSize().width/2,this->getContentSize().height/2));
    this->addChild(label1,2);
    auto visibleSize = Director::getInstance()->getVisibleSize();
    //底部白云
    auto sp2 = Sprite::create("ss_cloud.png");
    sp2->setScale(0.77, 0.5);
    sp2->cocos2d::Node::setAnchorPoint(Vec2(0.5, 0));
    sp2->setPosition(Vec2(visibleSize.width/2, 0));
    this->addChild(sp2,2);
    
    auto sp = Sprite::create("ss_towers_01.png");
    sp->setPosition(Vec2(visibleSize.width/2, 83));
    this->addChild(sp,4);
    
    //下部开始游戏
    auto startBtn = cocos2d::ui::Button::create("ss_play_normal_CN.png","ss_play_pressed_CN.png","ss_locked_CN.png");
    startBtn->setPosition(Vec2(visibleSize.width/2, 40));
    startBtn->setScale(0.8, 0.8);
    this->addChild(startBtn, 2);
    startBtn->addClickEventListener([=](Ref* sender)
    {
        
        CCLOG("开始");
    });
    //上部怪物波数
    auto waves = Sprite::create("ss_waves_15.png");
    waves->setAnchorPoint(Vec2(0, 0));
    waves->setPosition(Vec2(visibleSize.width/2, visibleSize.height-80));
    this->addChild(waves,2);



    
}
void SelectLayer::onActive()
{
    CCLOG("激活 －－> 准备刷新UI");
  }
void SelectLayer::onDestroy()
{
    CCLOG("销毁 －－> 准备保存各种设置");
  }
