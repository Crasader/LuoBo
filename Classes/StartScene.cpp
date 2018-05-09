//
//  StartScene.cpp
//  CarrotFantasy
//
//  Created by student on 18/5/7.
//
//

#include "StartScene.hpp"
#include "CocoStudio.h"
#include "ui/cocosGUI.h"
#include "UImanager.hpp"
#include "HelpScene.hpp"
#include "SceneManager.hpp"
#include "MusicManager.hpp"
#include "Constant.hpp"
USING_NS_CC;
Scene* StartScene:: createScene()
{
    return StartScene::create();
}
bool StartScene::init()
{
    if (!cocos2d::Scene::init())
    {
        return false;
    }
    this->initUI();
    this->setBtn();
    return true;
}
void StartScene::initUI()
{
    FileUtils::getInstance()->addSearchPath("Studio");
    node=CSLoader::createNode("StartScene.csb");
    this->addChild(node);
    
}
void StartScene::setDH()
{
    auto s1=node->getChildByName("bird");
    
    auto s2=node->getChildByTag(77);
    auto pos=Vec2(462,264);
    
    auto s3=node->getChildByTag(78);
    auto pos1=Vec2(416,240);
    
    auto s4=node->getChildByTag(58);
    auto s5=node->getChildByTag(59);

    auto moveby=MoveBy::create(2, Vec2(0,-70));
    auto moveby1=MoveBy::create(2, Vec2(0,70));
    auto moveby2=MoveBy::create(5, Vec2(-500,0));
    auto delay=DelayTime::create(0.5);
    
    
    auto moveby3=MoveBy::create(5, Vec2(-480,0));
    auto delay1=DelayTime::create(0.5);

    
    
    
    auto rota=RotateBy::create(2, 25);
    auto rota1=RotateBy::create(2, -25);
    
    
    
    
    auto rota2=RotateBy::create(2, -25);
    auto rota3=RotateBy::create(2, 25);
    
    
    auto seq1=Sequence::create(moveby,moveby1, NULL);
    auto seq2=Sequence::create(moveby2,delay, NULL);
    auto seq3=Sequence::create(rota,rota1, NULL);
    
    
    
    auto seq4=Sequence::create(rota2,rota3, NULL);
    auto seq5=Sequence::create(moveby3,delay1, NULL);
    
    s1->runAction(seq1);
    
    s2->runAction(seq2);
    s2->setPosition(pos);
    
    s3->runAction(seq5);
    s3->setPosition(pos1);
    
    s4->runAction(seq3);
    s5->runAction(seq4);
   
    
}
void StartScene::setBtn()
{
    auto btn=node->getChildByName("heart");

    auto btn1=static_cast<ui::Button*>(btn);
    btn1->addClickEventListener([=](Ref* sender)
    {
        CCLOG("点击按钮");
        auto layer=UIManager::CreateLayer(UIManager::LayerType::SETLAYER);
        
        this->addChild(layer);
    
    });
    auto btn2=node->getChildByName("Button_2");
    auto btn3=static_cast<ui::Button*>(btn2);
    btn3->addClickEventListener([=](Ref* sender)
    {
        
        CCLOG("帮助按钮");
        SceneMannger::goToHelpScene();

    });
    auto btn4=node->getChildByName("Button_1");
    auto btn5=static_cast<ui::Button*>(btn4);
    btn5->addClickEventListener([=](Ref* sender)
    {
        CCLOG("设置按钮");
        SceneMannger::goToSettingScene();
    
    
    });
    
    auto btn6=node->getChildByName("Button_4");
    (static_cast<ui::Button*>(btn6))->addClickEventListener([=](Ref* sender)
    {
    
        CCLOG("测试按钮");
        auto layer=UIManager::CreateLayer(UIManager::LayerType::SELECTLAYER);
        
        this->addChild(layer);
        
    });
    
    
}
void StartScene::onEnter()
{
    Scene::onEnter();
    MusicManager::playBackgroundMusic(bgMusic);

    this->schedule([=](float dt)
       {
           this->setDH();
           
       },4,CC_REPEAT_FOREVER,0,"key");
    
}
void StartScene:: onExit()
{
    this->unschedule("key");
    Scene::onExit();
}
