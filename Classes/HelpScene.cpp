//
//  HelpScene.cpp
//  CarrotFantasy
//
//  Created by MAC on 2018/5/7.
//
//

#include "HelpScene.hpp"
#include "CocoStudio.h"
#include "ui/cocosGUI.h"
#include "string.h"
#include "StartScene.hpp"
#include "SceneManager.hpp"
USING_NS_CC;
using namespace ui;
Scene* HelpScene::createScene()
{
    return HelpScene::create();
}
bool HelpScene::init()
{
    if (!Scene::init())
    {
        return false;
    }
    FileUtils::getInstance()->addSearchPath("Resources");
//    auto node=CSLoader::createNode("HelpScene.csb");
//    this->addChild(node);
    
    visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    //    背景
    auto bg = Sprite::create("help_bg.png");
    bg->setPosition(Vec2(visibleSize.width/2,visibleSize.height/2));
    bg->setScale(visibleSize.width/bg->getContentSize().width, visibleSize.height/bg->getContentSize().height);
    this->addChild(bg);
    //    创建返回按钮
    auto bt = Button::create("help_home_normal.png","help_home_pressed.png");
    bt->setPosition(Vec2(bt->getContentSize().width/2,visibleSize.height-bt->getContentSize().height/2));
    bt->addClickEventListener([=](Ref* sender){
        SceneMannger::goToStartScene();
    });
    this->addChild(bt);
    //    创建帮助、怪物、炮塔Checkbox
    auto towerbt = CheckBox::create("tower_normal_CN.png","tower_selected_CN.png","tower_selected_CN.png","tower_selected_CN.png","tower_selected_CN.png");
    auto guaiwubt = CheckBox::create("monster_normal_CN.png","monster_selected_CN.png","monster_selected_CN.png","monster_selected_CN.png","monster_selected_CN.png");
    auto helpbt = CheckBox::create("tips_normal_CN.png","tips_selected_CN.png","tips_selected_CN.png","tips_selected_CN.png","tips_selected_CN.png");
    
    addBottomLabel();//底部标签
    helpUI();//创建帮助的pageView
    //    帮助CheckBox设置
    helpbt->setSelected(true);
    helpbt->setPosition(Vec2(160,295));
    helpbt->setScale(0.7);
    this->addChild(helpbt);
    helpbt->addEventListener([=](Ref *sender,CheckBox::EventType type)
     {
         //        实现单选框显示
         if(type == CheckBox::EventType::UNSELECTED)
         helpbt->setSelected(true);
         guaiwubt->setSelected(false);
         towerbt->setSelected(false);
         if (this->getChildByTag(2)) {
             this->removeChildByTag(2);
         }
         if (this->getChildByTag(3)) {
             this->removeChildByTag(3);
         }
//         guaiwubt->setVisible(false);
         //        跳转到该界面
//         layer->removeAllChildren();//移除旧pageView
         helpUI();
     });
    //    怪物CheckBox设置
    guaiwubt->setPosition(Vec2(visibleSize.width/2,295));
    guaiwubt->setScale(0.7);
    this->addChild(guaiwubt);
    guaiwubt->addEventListener([=](Ref *sender,CheckBox::EventType type)
       {
           //实现单选框显示
           if(type == CheckBox::EventType::UNSELECTED)
           guaiwubt->setSelected(true);
           helpbt->setSelected(false);
           towerbt->setSelected(false);
           
           if (this->getChildByTag(1)) {
               this->removeChildByTag(1);
           }
           if (this->getChildByTag(3)) {
               this->removeChildByTag(3);
           }
           
           guaiWuUI();
       });
    //    炮塔CheckBox设置
    towerbt->setPosition(Vec2(320,295));
    towerbt->setScale(0.7);
    this->addChild(towerbt);
    towerbt->addEventListener([=](Ref *sender,CheckBox::EventType type)
      {
          //实现单选框显示
          if(type == CheckBox::EventType::UNSELECTED)
              towerbt->setSelected(true);
          guaiwubt->setSelected(false);
          helpbt->setSelected(false);
          if (this->getChildByTag(1)) {
              this->removeChildByTag(1);
          }
          if (this->getChildByTag(2)) {
              this->removeChildByTag(2);
          }
          towerUI();
      });
    
    return true;
}

//创建帮助界面
void HelpScene::helpUI()
{
    layer1 = Layer::create();
    layer1->setTag(1);
    //
    pageView = PageView::create();
    pageView->setContentSize(Size(440,225));
    pageView->setPosition(Vec2(30,60));
    layer1->addChild(pageView);
    this->addChild(layer1);
    int count=4;
    for (int i=1; i<=count; i++) {
        auto layer=ui::Layout::create();
        layer->setContentSize(Size(240.0f, 160.0f));
        
        
        auto cache = cocos2d::SpriteFrameCache::getInstance();
        cache->addSpriteFramesWithFile("help_3-hd.plist");
        char str[20];
        sprintf(str,"tips_%d.png",i);

        auto spriteFrame = cache->getSpriteFrameByName(str);
        auto sprite = Sprite::createWithSpriteFrame(spriteFrame);
        sprite->setScale(0.8);
        sprite->setPosition(Vec2(layer->getContentSize().width/2+100,layer->getContentSize().height/2+10));
        layer->addChild(sprite);
        pageView->addChild(layer);
    }

    pageView->addEventListener([=](Ref* sender,PageView::EventType type)
   {
       switch(type)
       {
           case PageView::EventType::TURNING:
           {
               label->removeFromParent();
               addBottomLabel(4);
           }
               break;
           default:
               break;
       }
   });
    //移除数字标签
    if(this->getChildByTag(4))
        this->removeChildByTag(4);
    //底部数字标签
    addBottomLabel(4);
}

//创建怪物界面
void HelpScene::guaiWuUI()
{
    layer2 = Layer::create();
    layer2->setTag(2);
    //创建layout
    auto sp = Sprite::create("help_monster.png");
    auto sp1 = Sprite::create("help_monster_CN.png");
    sp->setPosition(Vec2(visibleSize.width/2,visibleSize.height/2-15));
    sp1->setPosition(Vec2(visibleSize.width/2-10,visibleSize.height/2-55));
    sp->setScale(0.75);
    sp1->setScale(0.75);
    layer2->addChild(sp);
    layer2->addChild(sp1);
    this->addChild(layer2);
}
//创建炮塔界面
void HelpScene::towerUI()
{
    layer3 = Layer::create();
    layer3->setTag(3);
    pageView = PageView::create();
    pageView->setContentSize(Size(440,225));
    pageView->setPosition(Vec2(20,40));
    for(int i = 1;i <= 18; i++)
    {
        //layout
        Layout* layout = Layout::create();
        layout->setContentSize(Size(440,225));
        //图片精灵
        auto str = StringUtils::format("tower_%02d.png",i);
        auto sprite = Sprite::create(str);
        sprite->setScale(0.7);
        sprite->setPosition(Vec2(layout->getContentSize().width/2,layout->getContentSize().height/2));
        layout->addChild(sprite);
        //道具名标签精灵
        auto str1 = StringUtils::format("tower_%02d_CN.png",i);
        auto daojuName = Sprite::create(str1);
        daojuName->setPosition(Vec2(visibleSize.width/2-16,82));
        daojuName->setScale(0.7);
        layout->addChild(daojuName);
        pageView->addChild(layout);
    }
    layer3->addChild(pageView);
    this->addChild(layer3);
    pageView->addEventListener([=](Ref* sender,PageView::EventType type)
       {
           switch(type)
           {
               case PageView::EventType::TURNING:
               {
//                   SimpleAudioEngine::getInstance()->playEffect("TowerSelect.mp3");
                   if(this->getChildByTag(4))
                       this->removeChildByTag(4);
                   //添加底部数字标签
                   addBottomLabel(18);
               }
                   break;
               default:
                   break;
           }
       });
    //移除之前底部数字标签
    if(this->getChildByTag(4))
        this->removeChildByTag(4);
    //添加底部数字标签
    addBottomLabel(18);
    //添加底部数字标签背景
    auto bottomsp = Sprite::create("bottom.png");
    bottomsp->setPosition(Vec2(visibleSize.width/2+7,23));
    bottomsp->setScale(0.75);
    layer3->addChild(bottomsp);
    
}
//添加底部数字标签
void HelpScene::addBottomLabel(int num)
{
    auto str = StringUtils::format("%ld/%d",pageView->getCurPageIndex()+1,num);
    label = Label::createWithSystemFont(str,"fonts/Marker Felt.ttf",15);
    label->setTag(4);
    label->setColor(Color3B(0,230,0));
    label->setPosition(Vec2(visibleSize.width/2,28));
    this->addChild(label);
}
//添加底部数字标签
void HelpScene::addBottomLabel()
{
    auto str = StringUtils::format("1/4");
    label = Label::createWithSystemFont(str,"fonts/Marker Felt.ttf",15);
    label->setTag(4);
    label->setColor(Color3B(0,230,0));
    label->setPosition(Vec2(visibleSize.width/2,28));
    this->addChild(label,2);
    
}
void HelpScene::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
