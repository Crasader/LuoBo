//
//  SettingScene.cpp
//  CarrotFantasy
//
//  Created by Student on 18/5/7.
//
//

#include "SettingScene.hpp"
USING_NS_CC;
#include "CocoStudio.h"
#include "ui/CocosGUI.h"
#include "constant.hpp"
#include "MusicManager.hpp"
#include "SceneManager.hpp"

Scene* SettingScene:: createScene()
{
    return SettingScene::create();
}
bool SettingScene:: init()
{
    if (!Scene::init()) {
        return false;
    }
    this->SettingUI();
    return true;
}

//设置
void SettingScene:: SettingUI()
{
    auto node = CSLoader::createNode(settingLayer);
    node->setTag(1);
    this->addChild(node);
    
    auto btn1 = static_cast<ui::Button*>(node->getChildByName("btn2"));
    btn1->addClickEventListener([=](Ref* sender){
        this->statisticsUI();
        this->removeChildByTag(1);
    });
    
    auto btn2 = static_cast<ui::Button*>(node->getChildByName("btn3"));
    btn2->addClickEventListener([=](Ref* sender){
        this->creditsUI();
        this->removeChildByTag(1);
    });
    
    auto sound = static_cast<ui::CheckBox*>( node->getChildByName("sound"));
    sound->addEventListener([=](Ref* sender,ui::CheckBox::EventType type){
        switch (type) {
            case ui::CheckBox::EventType::SELECTED :
                MusicManager::setEffectFlags(false);
                break;
            case ui::CheckBox::EventType::UNSELECTED :
                MusicManager::setEffectFlags(true);
                break; 
            default:
                break;
        }
    });

    
    
    
    auto music = static_cast<ui::CheckBox*>(node->getChildByName("music"));
    
    if (!MusicManager::getFlags()) {
        music->setSelected(false);
    }
    music->addEventListener([=](Ref* sender,ui::CheckBox::EventType type){
        switch (type) {
            case ui::CheckBox::EventType::SELECTED :
                MusicManager::setFlags(true);
                MusicManager::playBackgroundMusic(bgMusic);
                break;
            case ui::CheckBox::EventType::UNSELECTED :
                MusicManager::setFlags(false);
                MusicManager::stopBackgroundMusic();
                break;
            default:
                break;
        }
    });
    
    auto btn_back = static_cast<ui::Button*>(node->getChildByName("btn_back"));
    btn_back->addClickEventListener([=](Ref* sender){
        SceneMannger::goToStartScene();
//        Director::getInstance()->replaceScene();
    });
}

//数据统计
void SettingScene:: statisticsUI()
{
    auto node = CSLoader::createNode(statisticsLayer);
    node->setTag(2);
    this->addChild(node);
    
    auto btn1 = static_cast<ui::Button*>(node->getChildByName("btn1"));
    btn1->addClickEventListener([=](Ref* sender){
        this->SettingUI();
        this->removeChildByTag(2);
    });
    
    auto btn2 = static_cast<ui::Button*>(node->getChildByName("btn3"));
    btn2->addClickEventListener([=](Ref* sender){
        this->creditsUI();
        this->removeChildByTag(2);
    });
    
    auto btn_back = static_cast<ui::Button*>(node->getChildByName("btn_back"));
    btn_back->addClickEventListener([=](Ref* sender){
        SceneMannger::goToStartScene();
        //        Director::getInstance()->replaceScene();
    });
}

//制作方
void SettingScene:: creditsUI()
{
    auto node = CSLoader::createNode(creditsLayer);
    node->setTag(3);
    this->addChild(node);
    
    auto btn1 = static_cast<ui::Button*>(node->getChildByName("btn1"));
    btn1->addClickEventListener([=](Ref* sender){
        this->SettingUI();
        this->removeChildByTag(3);
    });
    
    auto btn2 = static_cast<ui::Button*>(node->getChildByName("btn2"));
    btn2->addClickEventListener([=](Ref* sender){
        this->statisticsUI();
        this->removeChildByTag(3);
    });
    
    auto btn_back = static_cast<ui::Button*>(node->getChildByName("btn_back"));
    btn_back->addClickEventListener([=](Ref* sender){
        SceneMannger::goToStartScene();
    });
}

void SettingScene:: onEnter()
{
    Scene::onEnter();
    }
void SettingScene:: onExit()
{
    MusicManager::stopBackgroundMusic();
    Scene::onExit();
}


