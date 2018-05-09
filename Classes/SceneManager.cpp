//
//  SceneManager.cpp
//  CarrotFantasy
//
//  Created by student on 18/5/7.
//
//

#include "SceneManager.hpp"
#include "HelpScene.hpp"
#include "StartScene.hpp"
#include "SettingScene.hpp"
USING_NS_CC;
void SceneMannger::goToStartScene()
{
    auto startscene = StartScene::createScene();
    //    auto scene = TransitionRotoZoom::create(1,startscene);
    auto scene=TransitionJumpZoom::create(1,startscene);
    Director::getInstance()->replaceScene(scene);
}
void SceneMannger::goToHelpScene()
{
    auto mainmenu = HelpScene::createScene();
    //    auto scene = TransitionRotoZoom::create(1,mainmenu);
    auto scene=TransitionFadeTR::create(1, mainmenu);
    Director::getInstance()->replaceScene(scene);
}
void SceneMannger::goToSettingScene()
{
    
    auto gamescene = SettingScene::createScene();
    auto scene = TransitionRotoZoom::create(1,gamescene);
    Director::getInstance()->replaceScene(scene);
    
}