#include "ownWorldSelectLayer.h"
//#include "NewLevelPage.h"
#include <Geode/Geode.hpp>
#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>
#include <Geode/modify/LevelSelectLayer.hpp>
#include <Geode/modify/LevelInfoLayer.hpp>
#include <Geode/modify/LevelPage.hpp>
#include <Geode/modify/GJGameLevel.hpp>
#include <Geode/Enums.hpp>
#include "../Meltdown/MeltdownSelectLayer.h"
#include <iostream>
#include "GJWorldNodeDecomp.hpp"
#include "GJWorldNodeDecomp.cpp"
#include "WorldLevel.hpp"
#include "WorldLevel.cpp"

using namespace geode::prelude;

ccColor3B colors2s[] = {
    {255, 0, 0},    // Rojo
    {0, 255, 0},    // Verde
    {0, 0, 255}     // Azul
};
int numColors2s = sizeof(colors2s) / sizeof(colors2s[0]);
int currentColorIndex2s = 0;

ownWorldSelectLayer* ownWorldSelectLayer::create(int page) {
    auto ret = new ownWorldSelectLayer();
    if (ret && ret->init(page)) {
        ret->autorelease();
        return ret;
    }
    CC_SAFE_DELETE(ret);
    return nullptr;
};

CCScene* ownWorldSelectLayer::scene(int page) {
    auto layer = ownWorldSelectLayer::create(page);
    auto scene = CCScene::create();
    scene->addChild(layer);
    return scene;
}

void ownWorldSelectLayer::importSheet() {
    auto* textureCache = CCTextureCache::sharedTextureCache();
    auto* spriteFrameCache = CCSpriteFrameCache::sharedSpriteFrameCache();

    textureCache->addImage("WorldSheet.png", false);
    spriteFrameCache->addSpriteFramesWithFile("WorldSheet.plist");
}

bool ownWorldSelectLayer::init(int page) {
    if (!CCLayer::init()) return false;


    this->setID("ownWorldSelectLayer"_spr);
    setKeypadEnabled(true);
      auto node = more::GJWorldNodeDecomp::create(1,this);
      auto node2 = more::GJWorldNodeDecomp::create(1, this);
      auto node3 = more::GJWorldNodeDecomp::create(1, this);

    //auto node = CCSprite::createWithSpriteFrameName("GJ_arrow_01_001.png");
    //auto node2 = CCSprite::createWithSpriteFrameName("GJ_arrow_01_001.png");
    //auto node3 = CCSprite::createWithSpriteFrameName("GJ_arrow_01_001.png");
    auto GM = GameManager::sharedState();
    auto GLM = GameLevelManager::sharedState();
    /*addChild(node,2);*/
    importSheet();
   
     CCString* path = CCString::createWithFormat(
         "worldIsland_%02d.png",
         1
     );

     CCSprite* sprite = CCSprite::createWithSpriteFrameName(
         path->getCString()
     );

     CCString* path2 = CCString::createWithFormat(
         "worldIsland_%02d.png",
         2
     );

     CCSprite* sprite2 = CCSprite::createWithSpriteFrameName(
         path2->getCString()
     );


     CCString* path3 = CCString::createWithFormat(
         "worldIsland_%02d.png",
         3
     );

     CCSprite* sprite3 = CCSprite::createWithSpriteFrameName(
         path->getCString()
     );
     /*
      CCString* path = CCString::createWithFormat(
          "worldIsland_%02d.png",
          1
      );*/

   


      CCSprite* backSpr = CCSprite::createWithSpriteFrameName("GJ_arrow_01_001.png");
      CCMenuItemSpriteExtra* backBtn = CCMenuItemSpriteExtra::create(backSpr, this, menu_selector(ownWorldSelectLayer::onClose));

      CCMenu* backMenu = CCMenu::create();
      backMenu->addChild(backBtn);
      addChild(backMenu, 1);

      backMenu->setPosition(ccp(CCDirector::sharedDirector()->getScreenLeft() + 25.f, CCDirector::sharedDirector()->getScreenTop() - 22.f));

    //  /*auto songinfo = SongInfoLayer::create(10);*/
    ///*  SongInfoLayer::create(10)->show();*/
    //  /*addChild(songinfo);*/
    //  /*songinfo->show();*/
      CCSprite* Dashlands = CCSprite::createWithSpriteFrameName("worldLabel_01_001.png");

      CCSprite* ToxicFactory = CCSprite::createWithSpriteFrameName("worldLabel_02_001.png");

      auto CommingSoon = CCLabelBMFont::create("Coming Soon","bigFont.fnt");
    
      auto director = CCDirector::sharedDirector();
      auto winSize = director->getWinSize();

      m_fWindowWidth = winSize.width;

      CCMenu* dashlandsmenu = CCMenu::create();


      CCSprite* unkspr = CCSprite::createWithSpriteFrameName("worldLevelBtn_001.png");
      CCSprite* unkspr1 = CCSprite::createWithSpriteFrameName("worldLevelBtn_001.png");
      CCSprite* unkspr2 = CCSprite::createWithSpriteFrameName("worldLevelBtn_001.png");
      CCSprite* unkspr3 = CCSprite::createWithSpriteFrameName("worldLevelBtn_001.png");
      CCSprite* unkspr4 = CCSprite::createWithSpriteFrameName("worldLevelBtn_001.png");
      CCSprite* unkspr5 = CCSprite::createWithSpriteFrameName("worldLevelBtn_001.png");

      CCSprite* unkspr6 = CCSprite::createWithSpriteFrameName("worldLevelBtn_001.png");
      CCSprite* unkspr7 = CCSprite::createWithSpriteFrameName("worldLevelBtn_001.png");
      CCSprite* unksp8 = CCSprite::createWithSpriteFrameName("worldLevelBtn_001.png");
      CCSprite* unkspr9 = CCSprite::createWithSpriteFrameName("worldLevelBtn_001.png");
      CCSprite* unkspr10 = CCSprite::createWithSpriteFrameName("worldLevelBtn_001.png");

      //locked sprites
      CCSprite* level2 = CCSprite::createWithSpriteFrameName("worldLevelBtn_locked_001.png");
      CCSprite* level3 = CCSprite::createWithSpriteFrameName("worldLevelBtn_locked_001.png");
      CCSprite* level4 = CCSprite::createWithSpriteFrameName("worldLevelBtn_locked_001.png");
      CCSprite* level5 = CCSprite::createWithSpriteFrameName("worldLevelBtn_locked_001.png");
      CCSprite* level6 = CCSprite::createWithSpriteFrameName("worldLevelBtn_locked_001.png");
      CCSprite* level7 = CCSprite::createWithSpriteFrameName("worldLevelBtn_locked_001.png");
      CCSprite* level8 = CCSprite::createWithSpriteFrameName("worldLevelBtn_locked_001.png");
      CCSprite* level9 = CCSprite::createWithSpriteFrameName("worldLevelBtn_locked_001.png");
      CCSprite* level10 = CCSprite::createWithSpriteFrameName("worldLevelBtn_locked_001.png");


      //pointers animation 1
      CCSprite* point1 = CCSprite::createWithSpriteFrameName("uiDot_001.png");
      CCSprite* point2 = CCSprite::createWithSpriteFrameName("uiDot_001.png");
      CCSprite* point3 = CCSprite::createWithSpriteFrameName("uiDot_001.png");
      CCSprite* point4 = CCSprite::createWithSpriteFrameName("uiDot_001.png");
      CCSprite* point5 = CCSprite::createWithSpriteFrameName("uiDot_001.png");

      //pointers animation 2
      CCSprite* Bpoint1 = CCSprite::createWithSpriteFrameName("uiDot_001.png");
      CCSprite* Bpoint2 = CCSprite::createWithSpriteFrameName("uiDot_001.png");
      CCSprite* Bpoint3 = CCSprite::createWithSpriteFrameName("uiDot_001.png");
      CCSprite* Bpoint4 = CCSprite::createWithSpriteFrameName("uiDot_001.png");
      CCSprite* Bpoint5 = CCSprite::createWithSpriteFrameName("uiDot_001.png");

      //pointers animation 3
      CCSprite* Mpoint1 = CCSprite::createWithSpriteFrameName("uiDot_001.png");
      CCSprite* Mpoint2 = CCSprite::createWithSpriteFrameName("uiDot_001.png");
      CCSprite* Mpoint3 = CCSprite::createWithSpriteFrameName("uiDot_001.png");
      CCSprite* Mpoint4 = CCSprite::createWithSpriteFrameName("uiDot_001.png");
      CCSprite* Mpoint5 = CCSprite::createWithSpriteFrameName("uiDot_001.png");

      //pointers animation 4
      CCSprite* Ypoint1 = CCSprite::createWithSpriteFrameName("uiDot_001.png");
      CCSprite* Ypoint2 = CCSprite::createWithSpriteFrameName("uiDot_001.png");
      CCSprite* Ypoint3 = CCSprite::createWithSpriteFrameName("uiDot_001.png");
      CCSprite* Ypoint4 = CCSprite::createWithSpriteFrameName("uiDot_001.png");
      CCSprite* Ypoint5 = CCSprite::createWithSpriteFrameName("uiDot_001.png");

      //pointers animation 5
      CCSprite* Fpoint1 = CCSprite::createWithSpriteFrameName("uiDot_001.png");
      CCSprite* Fpoint2 = CCSprite::createWithSpriteFrameName("uiDot_001.png");
      CCSprite* Fpoint3 = CCSprite::createWithSpriteFrameName("uiDot_001.png");
      CCSprite* Fpoint4 = CCSprite::createWithSpriteFrameName("uiDot_001.png");
      CCSprite* Fpoint5 = CCSprite::createWithSpriteFrameName("uiDot_001.png");

      //pointers animation 6
      CCSprite* SPpoint1 = CCSprite::createWithSpriteFrameName("uiDot_001.png");
      CCSprite* SPpoint2 = CCSprite::createWithSpriteFrameName("uiDot_001.png");
      CCSprite* SPpoint3 = CCSprite::createWithSpriteFrameName("uiDot_001.png");
      CCSprite* SPpoint4 = CCSprite::createWithSpriteFrameName("uiDot_001.png");
      CCSprite* SPpoint5 = CCSprite::createWithSpriteFrameName("uiDot_001.png");

      //pointers animation 7
      CCSprite* Spoint1 = CCSprite::createWithSpriteFrameName("uiDot_001.png");
      CCSprite* Spoint2 = CCSprite::createWithSpriteFrameName("uiDot_001.png");
      CCSprite* Spoint3 = CCSprite::createWithSpriteFrameName("uiDot_001.png");
      CCSprite* Spoint4 = CCSprite::createWithSpriteFrameName("uiDot_001.png");
      CCSprite* Spoint5 = CCSprite::createWithSpriteFrameName("uiDot_001.png");

      //pointers animation 8
      CCSprite* Epoint1 = CCSprite::createWithSpriteFrameName("uiDot_001.png");
      CCSprite* Epoint2 = CCSprite::createWithSpriteFrameName("uiDot_001.png");
      CCSprite* Epoint3 = CCSprite::createWithSpriteFrameName("uiDot_001.png");
      CCSprite* Epoint4 = CCSprite::createWithSpriteFrameName("uiDot_001.png");
      CCSprite* Epoint5 = CCSprite::createWithSpriteFrameName("uiDot_001.png");
      CCSprite* Epoint6 = CCSprite::createWithSpriteFrameName("uiDot_001.png");
      CCSprite* Epoint7 = CCSprite::createWithSpriteFrameName("uiDot_001.png");
      CCSprite* Epoint8 = CCSprite::createWithSpriteFrameName("uiDot_001.png");

      //pointers animation 9
      CCSprite* Rpoint1 = CCSprite::createWithSpriteFrameName("uiDot_001.png");
      CCSprite* Rpoint2 = CCSprite::createWithSpriteFrameName("uiDot_001.png");
      CCSprite* Rpoint3 = CCSprite::createWithSpriteFrameName("uiDot_001.png");
      CCSprite* Rpoint4 = CCSprite::createWithSpriteFrameName("uiDot_001.png");
      CCSprite* Rpoint5 = CCSprite::createWithSpriteFrameName("uiDot_001.png");

      //pointers animation 10
      CCSprite* MDOpoint1 = CCSprite::createWithSpriteFrameName("uiDot_001.png");
      CCSprite* MDOpoint2 = CCSprite::createWithSpriteFrameName("uiDot_001.png");
      CCSprite* MDOpoint3 = CCSprite::createWithSpriteFrameName("uiDot_001.png");
      CCSprite* MDOpoint4 = CCSprite::createWithSpriteFrameName("uiDot_001.png");
      CCSprite* MDOpoint5 = CCSprite::createWithSpriteFrameName("uiDot_001.png");

      dashlandsmenu->addChild(point1);
      dashlandsmenu->addChild(point2);
      dashlandsmenu->addChild(point3);
      dashlandsmenu->addChild(point4);
      dashlandsmenu->addChild(point5);

      dashlandsmenu->addChild(Bpoint1);
      dashlandsmenu->addChild(Bpoint2);
      dashlandsmenu->addChild(Bpoint3);
      dashlandsmenu->addChild(Bpoint4);
      dashlandsmenu->addChild(Bpoint5);

      dashlandsmenu->addChild(Mpoint1);
      dashlandsmenu->addChild(Mpoint2);
      dashlandsmenu->addChild(Mpoint3);
      dashlandsmenu->addChild(Mpoint4);
      dashlandsmenu->addChild(Mpoint5);

      dashlandsmenu->addChild(Ypoint1);
      dashlandsmenu->addChild(Ypoint2);
      dashlandsmenu->addChild(Ypoint3);
      dashlandsmenu->addChild(Ypoint4);
      dashlandsmenu->addChild(Ypoint5);

     
     /* dashlandsmenu->addChild(Fpoint1);
      dashlandsmenu->addChild(Fpoint2);
      dashlandsmenu->addChild(Fpoint3);
      dashlandsmenu->addChild(Fpoint4);
      dashlandsmenu->addChild(Fpoint5);*/

      //dashlandsmenu->addChild(SPpoint1);
      //dashlandsmenu->addChild(SPpoint2);
      //dashlandsmenu->addChild(SPpoint3);
      //dashlandsmenu->addChild(SPpoint4);
      //dashlandsmenu->addChild(SPpoint5);

      //dashlandsmenu->addChild(Spoint1);
      //dashlandsmenu->addChild(Spoint2);
      //dashlandsmenu->addChild(Spoint3);
      //dashlandsmenu->addChild(Spoint4);
      //dashlandsmenu->addChild(Spoint5);

      //dashlandsmenu->addChild(Epoint1);
      //dashlandsmenu->addChild(Epoint2);
      //dashlandsmenu->addChild(Epoint3);
      //dashlandsmenu->addChild(Epoint4);
      //dashlandsmenu->addChild(Epoint5);

      //dashlandsmenu->addChild(Rpoint1);
      //dashlandsmenu->addChild(Rpoint2);
      //dashlandsmenu->addChild(Rpoint3);
      //dashlandsmenu->addChild(Rpoint4);
      //dashlandsmenu->addChild(Rpoint5);

     /* dashlandsmenu->addChild(MDOpoint1);
      dashlandsmenu->addChild(MDOpoint2);
      dashlandsmenu->addChild(MDOpoint3);
      dashlandsmenu->addChild(MDOpoint4);
      dashlandsmenu->addChild(MDOpoint5);*/
      //level buttons
      CCMenuItemSpriteExtra* level1Btn = CCMenuItemSpriteExtra::create(unkspr, this, menu_selector(ownWorldSelectLayer::onWorldLevel));

      level1Btn->setTag(30);
      level1Btn->setPosition(-189, -15);


    /*  level1Btn->setTag(30);
      level1Btn->setPosition(winSize / 2);
      level1Btn->setPositionX(level1Btn->getPositionX() - 380);
      level1Btn->setPositionY(level1Btn->getPositionY() - 215);*/
      //LEVEL 1 POINTS
      //point 1
      point1->setPosition(level1Btn->getPosition());
      point1->setPositionX(point1->getPositionX()+20);
      point1->setPositionY(-20);
      point1->setScale(0.5);
      point1->setScaleX(1);
      //point 2
      point2->setPosition(level1Btn->getPosition());
      point2->setPositionX(point2->getPositionX()+32);
      point2->setPositionY(-25);
      point2->setScale(0.5);
      point2->setScaleX(1);
      //point 3
      point3->setPosition(level1Btn->getPosition());
      point3->setPositionX(point3->getPositionX()+50);
      point3->setPositionY(-22);
      point3->setScale(0.5);
      point3->setScaleX(1);
      //point 4
      point4->setPosition(level1Btn->getPosition());
      point4->setPositionX(point4->getPositionX()+77);
      point4->setPositionY(-22.5);
      point4->setScale(0.5);
      point4->setScaleX(1);
      //point 5
      point5->setPosition(level1Btn->getPosition());
      point5->setPositionX(point5->getPositionX()+89.7);
      point5->setPositionY(-26);
      point5->setScale(0.5);
      point5->setScaleX(1);
      CCMenuItemSpriteExtra* level2Btn = CCMenuItemSpriteExtra::create(unkspr1, this, menu_selector(ownWorldSelectLayer::onWorldLevel));

      level2Btn->setTag(31);
      level2Btn->setPosition(-80, -30);
      level2Btn->setVisible(false);
      level2->setPosition({ -80, -30 });

      //LEVEL 2 POINTS
      //point 1
      Bpoint1->setPosition(level2Btn->getPosition());
      Bpoint1->setPositionX(Bpoint1->getPositionX() + 7);
      Bpoint1->setPositionY(-22);
      Bpoint1->setScale(0.5);
      Bpoint1->setScaleX(1);
      //point 2
      Bpoint2->setPosition(level2Btn->getPosition());
      Bpoint2->setPositionX(Bpoint2->getPositionX() + 13);
      Bpoint2->setPositionY(-15);
      Bpoint2->setScale(0.5);
      Bpoint2->setScaleX(1);
      //point 3
      Bpoint3->setPosition(level2Btn->getPosition());
      Bpoint3->setPositionX(Bpoint3->getPositionX() + 23);
      Bpoint3->setPositionY(-7);
      Bpoint3->setScale(0.5);
      Bpoint3->setScaleX(1);
      //point 4
      Bpoint4->setPosition(level2Btn->getPosition());
      Bpoint4->setPositionX(Bpoint4->getPositionX() + 40);
      Bpoint4->setPositionY(2.5);
      Bpoint4->setScale(0.5);
      Bpoint4->setScaleX(1);
      //point 5
      Bpoint5->setPosition(level2Btn->getPosition());
      Bpoint5->setPositionX(Bpoint5->getPositionX() + 52);
      Bpoint5->setPositionY(5);
      Bpoint5->setScale(0.5);
      Bpoint5->setScaleX(1);

      CCMenuItemSpriteExtra* level3Btn = CCMenuItemSpriteExtra::create(unkspr2, this, menu_selector(ownWorldSelectLayer::onWorldLevel));

      level3Btn->setTag(32);
      level3Btn->setPosition(-10, 10);
      level3Btn->setVisible(false);
      level3->setPosition({ -10, 10 });

      //LEVEL 3 POINTS
      //point 1
      Mpoint1->setPosition(level3Btn->getPosition());
      Mpoint1->setPositionX(Mpoint1->getPositionX() + 13);
      Mpoint1->setPositionY(2);
      Mpoint1->setScale(0.5);
      Mpoint1->setScaleX(1);
      //point 2
      Mpoint2->setPosition(level3Btn->getPosition());
      Mpoint2->setPositionX(Mpoint2->getPositionX() + 17);
      Mpoint2->setPositionY(-11);
      Mpoint2->setScale(0.5);
      Mpoint2->setScaleX(1);
      //point 3
      Mpoint3->setPosition(level3Btn->getPosition());
      Mpoint3->setPositionX(Mpoint3->getPositionX() + 19);
      Mpoint3->setPositionY(-20);
      Mpoint3->setScale(0.5);
      Mpoint3->setScaleX(1);
      //point 4
      Mpoint4->setPosition(level3Btn->getPosition());
      Mpoint4->setPositionX(Mpoint4->getPositionX() + 25);
      Mpoint4->setPositionY(-26);
      Mpoint4->setScale(0.5);
      Mpoint4->setScaleX(1);
      //point 5
      Mpoint5->setPosition(level3Btn->getPosition());
      Mpoint5->setPositionX(Mpoint5->getPositionX() + 42);
      Mpoint5->setPositionY(-28);
      Mpoint5->setScale(0.5);
      Mpoint5->setScaleX(1);

      
      //animation for levels transitions
      auto scaleAction = CCScaleTo::create(0.5,1, 0.5); // Escala al 60% durante 0.5 segundos
      auto scaleAction2 = CCScaleTo::create(0.5, 1);

      auto scaleWithBounce = CCEaseBounceOut::create(scaleAction);
      auto scaleWithBounce2 = CCEaseBounceOut::create(scaleAction2);

     /* auto particle = CCParticleSystemQuad::create("coinPickupEffect.plist", 1);
      particle->retain();

      particle->setPosition(0, 0);
      dashlandsmenu->addChild(particle,2);*/
      
      
    /*  CCParticleSystem* particles = ownParticleCoin::createStarParticles(250);*/
      
     //levels for verify and make the animation
      auto wlevel1 = GLM->getMainLevel(2001, false);


      auto wlevel2 = GLM->getMainLevel(2002, false);


      auto wlevel3 = GLM->getMainLevel(2003, false);


      auto wlevel4 = GLM->getMainLevel(2004, false);


      auto wlevel5 = GLM->getMainLevel(2005, false);


      auto wlevel6 = GLM->getMainLevel(2006, false);


      auto wlevel7 = GLM->getMainLevel(2007, false);


      auto wlevel8 = GLM->getMainLevel(2008, false);


      auto wlevel9 = GLM->getMainLevel(2009, false);


      auto wlevel10 = GLM->getMainLevel(2010, false);

      

      //values for dont repeat the animation when you exit from the layer
      auto level1complete = Mod::get()->getSavedValue<int>("worldlevel1complete");

      auto level2complete = Mod::get()->getSavedValue<int>("worldlevel2complete");

      auto level3complete = Mod::get()->getSavedValue<int>("worldlevel3complete");

      auto level4complete = Mod::get()->getSavedValue<int>("worldlevel4complete");

      auto level5complete = Mod::get()->getSavedValue<int>("worldlevel5complete");

      auto level6complete = Mod::get()->getSavedValue<int>("worldlevel6complete");

      auto level7complete = Mod::get()->getSavedValue<int>("worldlevel7complete");

      auto level8complete = Mod::get()->getSavedValue<int>("worldlevel8complete");

      auto level9complete = Mod::get()->getSavedValue<int>("worldlevel9complete");
      
      auto level10complete = Mod::get()->getSavedValue<int>("worldlevel10complete");


      //level 1 to level 2 animation
      if (wlevel1->m_normalPercent != 100)
      {
          Mod::get()->setSavedValue("worldlevel1complete", 0);
      }
      if (wlevel1->m_normalPercent == 100 && wlevel2->m_normalPercent == 0 && level1complete == 0)
      {
          point1->setScaleY(1.2);
          point2->setScaleY(1.2);
          point3->setScaleY(1.2);
          point4->setScaleY(1.2);
          point5->setScaleY(1.2);

          point1->setScaleX(2);
          point2->setScaleX(2);
          point3->setScaleX(2);
          point4->setScaleX(2);
          point5->setScaleX(2);
          //opacty
          point1->setOpacity(0);
          point2->setOpacity(0);
          point3->setOpacity(0);
          point4->setOpacity(0);
          point5->setOpacity(0);
          level2Btn->setOpacity(0);
        
          point1->runAction(CCSequence::create(CCDelayTime::create(0.3), CCFadeIn::create(0.1), CCEaseBounceOut::create(scaleWithBounce), nullptr));
          point2->runAction(CCSequence::create(CCDelayTime::create(0.6), CCFadeIn::create(0.1), CCEaseBounceOut::create(scaleWithBounce), nullptr));
          point3->runAction(CCSequence::create(CCDelayTime::create(0.9), CCFadeIn::create(0.1), CCEaseBounceOut::create(scaleWithBounce), nullptr));
          point4->runAction(CCSequence::create(CCDelayTime::create(1.2), CCFadeIn::create(0.1), CCEaseBounceOut::create(scaleWithBounce), nullptr));
          point5->runAction(CCSequence::create(CCDelayTime::create(1.5), CCFadeIn::create(0.1), CCEaseBounceOut::create(scaleWithBounce), nullptr));
          
          level2Btn->setScale(1.5);
          level2Btn->setVisible(true);

          Mod::get()->setSavedValue("wlevelunlocked", 1);
          level2Btn->runAction(CCSequence::create(
              CCDelayTime::create(1.8),
              CCCallFunc::create(this, callfunc_selector(ownWorldSelectLayer::runParticle)), // Utilizamos CCCallFunc para llamar a la función runParticle
              CCFadeIn::create(0.1),
              CCEaseBounceOut::create(scaleWithBounce2),
              nullptr
          ));

          Mod::get()->setSavedValue("worldlevel1complete", 1);
      }
      else
      {
          if (wlevel1->m_normalPercent == 100)
          {
              level2Btn->setVisible(true);
          }
          else
          {
              point1->setOpacity(0);
              point2->setOpacity(0);
              point3->setOpacity(0);
              point4->setOpacity(0);
              point5->setOpacity(0);
          }
         
      }

      if (wlevel2->m_normalPercent != 100)
      {
          Mod::get()->setSavedValue("worldlevel2complete", 0);
      }
      if (wlevel2->m_normalPercent == 100 && wlevel3->m_normalPercent == 0 && level2complete == 0)
      {
          //level 2 to level 3 animation
          Bpoint1->setScaleY(1.2);
          Bpoint2->setScaleY(1.2);
          Bpoint3->setScaleY(1.2);
          Bpoint4->setScaleY(1.2);
          Bpoint5->setScaleY(1.2);

          Bpoint1->setScaleX(2);
          Bpoint2->setScaleX(2);
          Bpoint3->setScaleX(2);
          Bpoint4->setScaleX(2);
          Bpoint5->setScaleX(2);
          //opacty
          Bpoint1->setOpacity(0);
          Bpoint2->setOpacity(0);
          Bpoint3->setOpacity(0);
          Bpoint4->setOpacity(0);
          Bpoint5->setOpacity(0);
          level3Btn->setOpacity(0);

          Bpoint1->runAction(CCSequence::create(CCDelayTime::create(0.3), CCFadeIn::create(0.1), CCEaseBounceOut::create(scaleWithBounce), nullptr));
          Bpoint2->runAction(CCSequence::create(CCDelayTime::create(0.6), CCFadeIn::create(0.1), CCEaseBounceOut::create(scaleWithBounce), nullptr));
          Bpoint3->runAction(CCSequence::create(CCDelayTime::create(0.9), CCFadeIn::create(0.1), CCEaseBounceOut::create(scaleWithBounce), nullptr));
          Bpoint4->runAction(CCSequence::create(CCDelayTime::create(1.2), CCFadeIn::create(0.1), CCEaseBounceOut::create(scaleWithBounce), nullptr));
          Bpoint5->runAction(CCSequence::create(CCDelayTime::create(1.5), CCFadeIn::create(0.1), CCEaseBounceOut::create(scaleWithBounce), nullptr));

          level3Btn->setScale(1.5);
          level3Btn->setVisible(true);

          Mod::get()->setSavedValue("wlevelunlocked", 2);
          level3Btn->runAction(CCSequence::create(
              CCDelayTime::create(1.8),
              CCCallFunc::create(this, callfunc_selector(ownWorldSelectLayer::runParticle)), // Utilizamos CCCallFunc para llamar a la función runParticle
              CCFadeIn::create(0.1),
              CCEaseBounceOut::create(scaleWithBounce2),
              nullptr
          ));
          Mod::get()->setSavedValue("worldlevel2complete", 1);
      }
      else
      {
          if (wlevel2->m_normalPercent == 100)
          {
              level3Btn->setVisible(true);
          }
          else
          {
              Bpoint1->setOpacity(0);
              Bpoint2->setOpacity(0);
              Bpoint3->setOpacity(0);
              Bpoint4->setOpacity(0);
              Bpoint5->setOpacity(0);
          }
      }
      /*dashlandsmenu->addChild(particles, 2);*/
      // Establecer la escala inicial como 0 para que estén invisibles
     
      CCMenuItemSpriteExtra* level4Btn = CCMenuItemSpriteExtra::create(unkspr3, this, menu_selector(ownWorldSelectLayer::onWorldLevel));

      level4Btn->setTag(33);
      level4Btn->setPosition(50, -25);
      level4Btn->setVisible(false);
      level4->setPosition({ 50, -25 });

      //LEVEL 4 POINTS
      //point 1
      Ypoint1->setPosition(level4Btn->getPosition());
      Ypoint1->setPositionX(Ypoint1->getPositionX() + 20);
      Ypoint1->setPositionY(-24);
      Ypoint1->setScale(0.5);
      Ypoint1->setScaleX(1);
      //point 2
      Ypoint2->setPosition(level4Btn->getPosition());
      Ypoint2->setPositionX(Ypoint2->getPositionX() + 36);
      Ypoint2->setScale(0.5);
      Ypoint2->setScaleX(1);
      //point 3
      Ypoint3->setPosition(level4Btn->getPosition());
      Ypoint3->setPositionX(Ypoint3->getPositionX() + 51);
      Ypoint3->setPositionY(-22.5);
      Ypoint3->setScale(0.5);
      Ypoint3->setScaleX(1);
      //point 4
      Ypoint4->setPosition(level4Btn->getPosition());
      Ypoint4->setPositionX(Ypoint4->getPositionX() + 72);
      Ypoint4->setPositionY(-25.5);
      Ypoint4->setScale(0.5);
      Ypoint4->setScaleX(1);
      //point 5
      Ypoint5->setPosition(level4Btn->getPosition());
      Ypoint5->setPositionX(Ypoint5->getPositionX() + 88);
      Ypoint5->setPositionY(-20.5);
      Ypoint5->setScale(0.5);
      Ypoint5->setScaleX(1);


      if (wlevel3->m_normalPercent != 100)
      {
          Mod::get()->setSavedValue("worldlevel3complete", 0);
      }
      //level 3 to level 4 animation
      if (wlevel3->m_normalPercent == 100 && wlevel4->m_normalPercent == 0 && level3complete == 0)
      {
          Mpoint1->setScaleY(1.2);
          Mpoint2->setScaleY(1.2);
          Mpoint3->setScaleY(1.2);
          Mpoint4->setScaleY(1.2);
          Mpoint5->setScaleY(1.2);

          Mpoint1->setScaleX(2);
          Mpoint2->setScaleX(2);
          Mpoint3->setScaleX(2);
          Mpoint4->setScaleX(2);
          Mpoint5->setScaleX(2);
          //opacty
          Mpoint1->setOpacity(0);
          Mpoint2->setOpacity(0);
          Mpoint3->setOpacity(0);
          Mpoint4->setOpacity(0);
          Mpoint5->setOpacity(0);
          level4Btn->setOpacity(0);

          Mpoint1->runAction(CCSequence::create(CCDelayTime::create(0.3), CCFadeIn::create(0.1), CCEaseBounceOut::create(scaleWithBounce), nullptr));
          Mpoint2->runAction(CCSequence::create(CCDelayTime::create(0.6), CCFadeIn::create(0.1), CCEaseBounceOut::create(scaleWithBounce), nullptr));
          Mpoint3->runAction(CCSequence::create(CCDelayTime::create(0.9), CCFadeIn::create(0.1), CCEaseBounceOut::create(scaleWithBounce), nullptr));
          Mpoint4->runAction(CCSequence::create(CCDelayTime::create(1.2), CCFadeIn::create(0.1), CCEaseBounceOut::create(scaleWithBounce), nullptr));
          Mpoint5->runAction(CCSequence::create(CCDelayTime::create(1.5), CCFadeIn::create(0.1), CCEaseBounceOut::create(scaleWithBounce), nullptr));

          level4Btn->setScale(1.5);
          level4Btn->setVisible(true);

          Mod::get()->setSavedValue("wlevelunlocked", 3);
          level4Btn->runAction(CCSequence::create(
              CCDelayTime::create(1.8),
              CCCallFunc::create(this, callfunc_selector(ownWorldSelectLayer::runParticle)), // Utilizamos CCCallFunc para llamar a la función runParticle
              CCFadeIn::create(0.1),
              CCEaseBounceOut::create(scaleWithBounce2),
              nullptr
          ));
          Mod::get()->setSavedValue("worldlevel3complete", 1);
      }
      else
      {
          if (wlevel3->m_normalPercent == 100)
          {
              level4Btn->setVisible(true);
          }
          else
          {
              Mpoint1->setOpacity(0);
              Mpoint2->setOpacity(0);
              Mpoint3->setOpacity(0);
              Mpoint4->setOpacity(0);
              Mpoint5->setOpacity(0);
          }
      }
      

      CCMenuItemSpriteExtra* level5Btn = CCMenuItemSpriteExtra::create(unkspr4, this, menu_selector(ownWorldSelectLayer::onWorldLevel));

      level5Btn->setTag(34);
      level5Btn->setPosition(155, -10);
      level5Btn->setVisible(false);
      level5->setPosition({ 155, -10 });


      if (wlevel4->m_normalPercent != 100)
      {
          Mod::get()->setSavedValue("worldlevel4complete", 0);
      }
      //level 4 to level 5 animation
      if (wlevel4->m_normalPercent == 100 && wlevel5->m_normalPercent == 0 && level4complete == 0)
      {
          Ypoint1->setScaleY(1.2);
          Ypoint2->setScaleY(1.2);
          Ypoint3->setScaleY(1.2);
          Ypoint4->setScaleY(1.2);
          Ypoint5->setScaleY(1.2);

          Ypoint1->setScaleX(2);
          Ypoint2->setScaleX(2);
          Ypoint3->setScaleX(2);
          Ypoint4->setScaleX(2);
          Ypoint5->setScaleX(2);
          //opacty
          Ypoint1->setOpacity(0);
          Ypoint2->setOpacity(0);
          Ypoint3->setOpacity(0);
          Ypoint4->setOpacity(0);
          Ypoint5->setOpacity(0);
          level5Btn->setOpacity(0);

          Ypoint1->runAction(CCSequence::create(CCDelayTime::create(0.3), CCFadeIn::create(0.1), CCEaseBounceOut::create(scaleWithBounce), nullptr));
          Ypoint2->runAction(CCSequence::create(CCDelayTime::create(0.6), CCFadeIn::create(0.1), CCEaseBounceOut::create(scaleWithBounce), nullptr));
          Ypoint3->runAction(CCSequence::create(CCDelayTime::create(0.9), CCFadeIn::create(0.1), CCEaseBounceOut::create(scaleWithBounce), nullptr));
          Ypoint4->runAction(CCSequence::create(CCDelayTime::create(1.2), CCFadeIn::create(0.1), CCEaseBounceOut::create(scaleWithBounce), nullptr));
          Ypoint5->runAction(CCSequence::create(CCDelayTime::create(1.5), CCFadeIn::create(0.1), CCEaseBounceOut::create(scaleWithBounce), nullptr));

          level5Btn->setScale(1.5);
          level5Btn->setVisible(true);

          Mod::get()->setSavedValue("wlevelunlocked", 4);
          level5Btn->runAction(CCSequence::create(
              CCDelayTime::create(1.8),
              CCCallFunc::create(this, callfunc_selector(ownWorldSelectLayer::runParticle)), // Utilizamos CCCallFunc para llamar a la función runParticle
              CCFadeIn::create(0.1),
              CCEaseBounceOut::create(scaleWithBounce2),
              nullptr
          ));
          Mod::get()->setSavedValue("worldlevel4complete", 1);
      }
      else
      {
          if (wlevel4->m_normalPercent == 100)
          {
              level5Btn->setVisible(true);
          }
          else
          {
              Ypoint1->setOpacity(0);
              Ypoint2->setOpacity(0);
              Ypoint3->setOpacity(0);
              Ypoint4->setOpacity(0);
              Ypoint5->setOpacity(0);
          }
      }

      auto ToxicFactoryMenu = CCMenu::create();
      CCMenuItemSpriteExtra* level6Btn = CCMenuItemSpriteExtra::create(unkspr5, this, menu_selector(ownWorldSelectLayer::onWorldLevel));

      level6Btn->setTag(35);
      level6Btn->setPosition(-175, -12);
      level6Btn->setVisible(false);
      level6->setPosition(level6Btn->getPosition());

      //LEVEL 6 POINTS
    //point 1
      SPpoint1->setPosition(level6Btn->getPosition());
      SPpoint1->setPositionX(SPpoint1->getPositionX() + 20);
      SPpoint1->setPositionY(-16);
      SPpoint1->setScale(0.5);
      SPpoint1->setScaleX(1);
      //point 2
      SPpoint2->setPosition(level6Btn->getPosition());
      SPpoint2->setPositionX(SPpoint2->getPositionX() + 38);
      SPpoint2->setPositionY(-16.5);
      SPpoint2->setScale(0.5);
      SPpoint2->setScaleX(1);
      //point 3
      SPpoint3->setPosition(level6Btn->getPosition());
      SPpoint3->setPositionX(SPpoint3->getPositionX() + 55);
      SPpoint3->setPositionY(-11);
      SPpoint3->setScale(0.5);
      SPpoint3->setScaleX(1);
      //point 4
      SPpoint4->setPosition(level6Btn->getPosition());
      SPpoint4->setPositionX(SPpoint4->getPositionX() + 72);
      SPpoint4->setPositionY(-12);
      SPpoint4->setScale(0.5);
      SPpoint4->setScaleX(1);
      //point 5
      SPpoint5->setPosition(level6Btn->getPosition());
      SPpoint5->setPositionX(SPpoint5->getPositionX() + 85);
      SPpoint5->setPositionY(-19.5);
      SPpoint5->setScale(0.5);
      SPpoint5->setScaleX(1);


      ToxicFactoryMenu->addChild(SPpoint1,2);
      ToxicFactoryMenu->addChild(SPpoint2, 2);
      ToxicFactoryMenu->addChild(SPpoint3, 2);
      ToxicFactoryMenu->addChild(SPpoint4, 2);
      ToxicFactoryMenu->addChild(SPpoint5, 2);

    
      CCMenuItemSpriteExtra* level7Btn = CCMenuItemSpriteExtra::create(unkspr6, this, menu_selector(ownWorldSelectLayer::onWorldLevel));

      level7Btn->setTag(36);
      level7Btn->setPosition(-73, -28);
      level7Btn->setVisible(false);
      level7->setPosition(level7Btn->getPosition());

      //LEVEL 7 POINTS
     //point 1
      Spoint1->setPosition(level7Btn->getPosition());
      Spoint1->setPositionX(Spoint1->getPositionX() + 10);
      Spoint1->setPositionY(-8);
      Spoint1->setScale(0.5);
      Spoint1->setScaleX(1);
      //point 2
      Spoint2->setPosition(level7Btn->getPosition());
      Spoint2->setPositionX(Spoint2->getPositionX() + 15);
      Spoint2->setPositionY(0);
      Spoint2->setScale(0.5);
      Spoint2->setScaleX(1);
      //point 3
      Spoint3->setPosition(level7Btn->getPosition());
      Spoint3->setPositionX(Spoint3->getPositionX() + 30);
      Spoint3->setPositionY(7);
      Spoint3->setScale(0.5);
      Spoint3->setScaleX(1);
      //point 4
      Spoint4->setPosition(level7Btn->getPosition());
      Spoint4->setPositionX(Spoint4->getPositionX() + 44);
      Spoint4->setPositionY(9.5);
      Spoint4->setScale(0.5);
      Spoint4->setScaleX(1);
      //point 5
      /*Spoint5->setPosition(level2Btn->getPosition());
      Spoint5->setPositionX(Bpoint5->getPositionX() + 52);
      Spoint5->setPositionY(5);
      Spoint5->setScale(0.5);
      Spoint5->setScaleX(1);*/

      ToxicFactoryMenu->addChild(Spoint1, 2);
      ToxicFactoryMenu->addChild(Spoint2, 2);
      ToxicFactoryMenu->addChild(Spoint3, 2);
      ToxicFactoryMenu->addChild(Spoint4, 2);
     /* ToxicFactoryMenu->addChild(Spoint5, 2);*/
      //level 6 to level 7 animation

      if (wlevel6->m_normalPercent != 100)
      {
          Mod::get()->setSavedValue("worldlevel6complete", 0);
      }
      if (wlevel6->m_normalPercent == 100 && wlevel7->m_normalPercent == 0 && level6complete == 0)
      {
          SPpoint1->setScaleY(1.2);
          SPpoint2->setScaleY(1.2);
          SPpoint3->setScaleY(1.2);
          SPpoint4->setScaleY(1.2);
          SPpoint5->setScaleY(1.2);

          SPpoint1->setScaleX(2);
          SPpoint2->setScaleX(2);
          SPpoint3->setScaleX(2);
          SPpoint4->setScaleX(2);
          SPpoint5->setScaleX(2);
          //opacty
          SPpoint1->setOpacity(0);
          SPpoint2->setOpacity(0);
          SPpoint3->setOpacity(0);
          SPpoint4->setOpacity(0);
          SPpoint5->setOpacity(0);
          level7Btn->setOpacity(0);

          SPpoint1->runAction(CCSequence::create(CCDelayTime::create(0.3), CCFadeIn::create(0.1), CCEaseBounceOut::create(scaleWithBounce), nullptr));
          SPpoint2->runAction(CCSequence::create(CCDelayTime::create(0.6), CCFadeIn::create(0.1), CCEaseBounceOut::create(scaleWithBounce), nullptr));
          SPpoint3->runAction(CCSequence::create(CCDelayTime::create(0.9), CCFadeIn::create(0.1), CCEaseBounceOut::create(scaleWithBounce), nullptr));
          SPpoint4->runAction(CCSequence::create(CCDelayTime::create(1.2), CCFadeIn::create(0.1), CCEaseBounceOut::create(scaleWithBounce), nullptr));
          SPpoint5->runAction(CCSequence::create(CCDelayTime::create(1.5), CCFadeIn::create(0.1), CCEaseBounceOut::create(scaleWithBounce), nullptr));

          level7Btn->setScale(1.5);
          level7Btn->setVisible(true);

          Mod::get()->setSavedValue("wlevelunlocked", 6);
          level7Btn->runAction(CCSequence::create(
              CCDelayTime::create(1.8),
              CCCallFunc::create(this, callfunc_selector(ownWorldSelectLayer::runParticle)), // Utilizamos CCCallFunc para llamar a la función runParticle
              CCFadeIn::create(0.1),
              CCEaseBounceOut::create(scaleWithBounce2),
              nullptr
          ));
          Mod::get()->setSavedValue("worldlevel6complete", 1);
      }
      else
      {
          if (wlevel6->m_normalPercent == 100)
          {
              level7Btn->setVisible(true);
          }
          else
          {
              SPpoint1->setOpacity(0);
              SPpoint2->setOpacity(0);
              SPpoint3->setOpacity(0);
              SPpoint4->setOpacity(0);
              SPpoint5->setOpacity(0);
          }
      }

     
      CCMenuItemSpriteExtra* level8Btn = CCMenuItemSpriteExtra::create(unkspr7, this, menu_selector(ownWorldSelectLayer::onWorldLevel));

      level8Btn->setTag(37);
      level8Btn->setPosition(-10, 15);
      level8Btn->setVisible(false);
      level8->setPosition(level8Btn->getPosition());

      //LEVEL 8 POINTS
     //point 1
      Epoint1->setPosition(level8Btn->getPosition());
      Epoint1->setPositionX(Epoint1->getPositionX() + 10);
      Epoint1->setPositionY(3);
      Epoint1->setScale(0.5);
      Epoint1->setScaleX(1);
      //point 2
      Epoint2->setPosition(level8Btn->getPosition());
      Epoint2->setPositionX(Epoint2->getPositionX());
      Epoint2->setPositionY(-7);
      Epoint2->setScale(0.5);
      Epoint2->setScaleX(1);
      //point 3
      Epoint3->setPosition(level8Btn->getPosition());
      Epoint3->setPositionX(Epoint3->getPositionX() - 10);
      Epoint3->setPositionY(-11);
      Epoint3->setScale(0.5);
      Epoint3->setScaleX(1);
      //point 4
      Epoint4->setPosition(level8Btn->getPosition());
      Epoint4->setPositionX(Epoint4->getPositionX() - 15 );
      Epoint4->setPositionY(-20);
      Epoint4->setScale(0.5);
      Epoint4->setScaleX(1);
      //point 5
      Epoint5->setPosition(level8Btn->getPosition());
      Epoint5->setPositionX(Epoint5->getPositionX() - 5);
      Epoint5->setPositionY(-32);
      Epoint5->setScale(0.5);
      Epoint5->setScaleX(1);
      //point 6
      Epoint6->setPosition(level8Btn->getPosition());
      Epoint6->setPositionX(Epoint6->getPositionX() + 17);
      Epoint6->setPositionY(-36.5);
      Epoint6->setScale(0.5);
      Epoint6->setScaleX(1);
      //point 7
      Epoint7->setPosition(level8Btn->getPosition());
      Epoint7->setPositionX(Epoint7->getPositionX() + 41);
      Epoint7->setPositionY(-40);
      Epoint7->setScale(0.5);
      Epoint7->setScaleX(1);
      //point 8
      Epoint8->setPosition(level8Btn->getPosition());
      Epoint8->setPositionX(Epoint8->getPositionX() + 63);
      Epoint8->setPositionY(-40.5);
      Epoint8->setScale(0.5);
      Epoint8->setScaleX(1);


      ToxicFactoryMenu->addChild(Epoint1, 2);
      ToxicFactoryMenu->addChild(Epoint2, 2);
      ToxicFactoryMenu->addChild(Epoint3, 2);
      ToxicFactoryMenu->addChild(Epoint4, 2);
      ToxicFactoryMenu->addChild(Epoint5, 2);
      ToxicFactoryMenu->addChild(Epoint6, 2);
      ToxicFactoryMenu->addChild(Epoint7, 2);
      ToxicFactoryMenu->addChild(Epoint8, 2);
      if (wlevel7->m_normalPercent != 100)
      {
          Mod::get()->setSavedValue("worldlevel7complete", 0);
      }
      ////level 7 to level 8 animation
      if (wlevel7->m_normalPercent == 100 && wlevel8->m_normalPercent == 0 && level7complete == 0)
      {
          Spoint1->setScaleY(1.2);
          Spoint2->setScaleY(1.2);
          Spoint3->setScaleY(1.2);
          Spoint4->setScaleY(1.2);
      

          Spoint1->setScaleX(2);
          Spoint2->setScaleX(2);
          Spoint3->setScaleX(2);
          Spoint4->setScaleX(2);

          //opacty
          Spoint1->setOpacity(0);
          Spoint2->setOpacity(0);
          Spoint3->setOpacity(0);
          Spoint4->setOpacity(0);

          level8Btn->setOpacity(0);

          Spoint1->runAction(CCSequence::create(CCDelayTime::create(0.3), CCFadeIn::create(0.1), CCEaseBounceOut::create(scaleWithBounce), nullptr));
          Spoint2->runAction(CCSequence::create(CCDelayTime::create(0.6), CCFadeIn::create(0.1), CCEaseBounceOut::create(scaleWithBounce), nullptr));
          Spoint3->runAction(CCSequence::create(CCDelayTime::create(0.9), CCFadeIn::create(0.1), CCEaseBounceOut::create(scaleWithBounce), nullptr));
          Spoint4->runAction(CCSequence::create(CCDelayTime::create(1.2), CCFadeIn::create(0.1), CCEaseBounceOut::create(scaleWithBounce), nullptr));
        

          level8Btn->setScale(1.5);
          level8Btn->setVisible(true);

          Mod::get()->setSavedValue("wlevelunlocked", 7);
          level8Btn->runAction(CCSequence::create(
              CCDelayTime::create(1.5),
              CCCallFunc::create(this, callfunc_selector(ownWorldSelectLayer::runParticle)), // Utilizamos CCCallFunc para llamar a la función runParticle
              CCFadeIn::create(0.1),
              CCEaseBounceOut::create(scaleWithBounce2),
              nullptr
          ));
          Mod::get()->setSavedValue("worldlevel7complete", 1);
      }
      else
      {
          if (wlevel7->m_normalPercent == 100)
          {
              level8Btn->setVisible(true);
          }
          else
          {
              Spoint1->setOpacity(0);
              Spoint2->setOpacity(0);
              Spoint3->setOpacity(0);
              Spoint4->setOpacity(0);
              Spoint5->setOpacity(0);
          }
      }

      
      CCMenuItemSpriteExtra* level9Btn = CCMenuItemSpriteExtra::create(unksp8, this, menu_selector(ownWorldSelectLayer::onWorldLevel));

      level9Btn->setTag(38);
      level9Btn->setPosition(80, -38);
      level9Btn->setVisible(false);
      level9->setPosition(level9Btn->getPosition());

      //LEVEL 9 POINTS
     //point 1
      Rpoint1->setPosition(level9Btn->getPosition());
      Rpoint1->setPositionX(Rpoint1->getPositionX() + 16);
      Rpoint1->setPositionY(-34);
      Rpoint1->setScale(0.5);
      Rpoint1->setScaleX(1);
      //point 2
      Rpoint2->setPosition(level9Btn->getPosition());
      Rpoint2->setPositionX(Rpoint2->getPositionX() + 25);
      Rpoint2->setPositionY(-27);
      Rpoint2->setScale(0.5);
      Rpoint2->setScaleX(1);
      //point 3
      Rpoint3->setPosition(level9Btn->getPosition());
      Rpoint3->setPositionX(Rpoint3->getPositionX() + 34);
      Rpoint3->setPositionY(-20.5);
      Rpoint3->setScale(0.5);
      Rpoint3->setScaleX(1);
      //point 4
      Rpoint4->setPosition(level9Btn->getPosition());
      Rpoint4->setPositionX(Rpoint4->getPositionX() + 45);
      Rpoint4->setPositionY(-16);
      Rpoint4->setScale(0.5);
      Rpoint4->setScaleX(1);
      //point 5
      Rpoint5->setPosition(level9Btn->getPosition());
      Rpoint5->setPositionX(Rpoint5->getPositionX() + 67);
      Rpoint5->setPositionY(-12);
      Rpoint5->setScale(0.5);
      Rpoint5->setScaleX(1);


      ToxicFactoryMenu->addChild(Rpoint1, 2);
      ToxicFactoryMenu->addChild(Rpoint2, 2);
      ToxicFactoryMenu->addChild(Rpoint3, 2);
      ToxicFactoryMenu->addChild(Rpoint4, 2);
      ToxicFactoryMenu->addChild(Rpoint5, 2);

      if (wlevel8->m_normalPercent != 100)
      {
          Mod::get()->setSavedValue("worldlevel8complete", 0);
      }
      //level 8 to level 9 animation
      if (wlevel8->m_normalPercent == 100 && wlevel9->m_normalPercent == 0 && level8complete == 0)
      {
          Epoint1->setScaleY(1.2);
          Epoint2->setScaleY(1.2);
          Epoint3->setScaleY(1.2);
          Epoint4->setScaleY(1.2);
          Epoint5->setScaleY(1.2);
          Epoint6->setScaleY(1.2);
          Epoint7->setScaleY(1.2);
          Epoint8->setScaleY(1.2);

          Epoint1->setScaleX(2);
          Epoint2->setScaleX(2);
          Epoint3->setScaleX(2);
          Epoint4->setScaleX(2);
          Epoint5->setScaleX(2);
          Epoint6->setScaleX(2);
          Epoint7->setScaleX(2);
          Epoint8->setScaleX(2);
          //opacty
          Epoint1->setOpacity(0);
          Epoint2->setOpacity(0);
          Epoint3->setOpacity(0);
          Epoint4->setOpacity(0);
          Epoint5->setOpacity(0);
          Epoint6->setOpacity(0);
          Epoint7->setOpacity(0);
          Epoint8->setOpacity(0);
        

          level9Btn->setOpacity(0);

          Epoint1->runAction(CCSequence::create(CCDelayTime::create(0.3), CCFadeIn::create(0.1), CCEaseBounceOut::create(scaleWithBounce), nullptr));
          Epoint2->runAction(CCSequence::create(CCDelayTime::create(0.6), CCFadeIn::create(0.1), CCEaseBounceOut::create(scaleWithBounce), nullptr));
          Epoint3->runAction(CCSequence::create(CCDelayTime::create(0.9), CCFadeIn::create(0.1), CCEaseBounceOut::create(scaleWithBounce), nullptr));
          Epoint4->runAction(CCSequence::create(CCDelayTime::create(1.2), CCFadeIn::create(0.1), CCEaseBounceOut::create(scaleWithBounce), nullptr));
          Epoint5->runAction(CCSequence::create(CCDelayTime::create(1.5), CCFadeIn::create(0.1), CCEaseBounceOut::create(scaleWithBounce), nullptr));
          Epoint6->runAction(CCSequence::create(CCDelayTime::create(1.8), CCFadeIn::create(0.1), CCEaseBounceOut::create(scaleWithBounce), nullptr));
          Epoint7->runAction(CCSequence::create(CCDelayTime::create(2.1), CCFadeIn::create(0.1), CCEaseBounceOut::create(scaleWithBounce), nullptr));
          Epoint8->runAction(CCSequence::create(CCDelayTime::create(2.4), CCFadeIn::create(0.1), CCEaseBounceOut::create(scaleWithBounce), nullptr));

          level9Btn->setScale(1.5);
          level9Btn->setVisible(true);

          Mod::get()->setSavedValue("wlevelunlocked", 8);
          level9Btn->runAction(CCSequence::create(
              CCDelayTime::create(2.7),
              CCCallFunc::create(this, callfunc_selector(ownWorldSelectLayer::runParticle)), // Utilizamos CCCallFunc para llamar a la función runParticle
              CCFadeIn::create(0.1),
              CCEaseBounceOut::create(scaleWithBounce2),
              nullptr
          ));
          Mod::get()->setSavedValue("worldlevel8complete", 1);
      }
      else
      {
          if (wlevel8->m_normalPercent == 100)
          {
              level9Btn->setVisible(true);
          }
          else
          {
              Epoint1->setOpacity(0);
              Epoint2->setOpacity(0);
              Epoint3->setOpacity(0);
              Epoint4->setOpacity(0);
              Epoint5->setOpacity(0);
              Epoint6->setOpacity(0);
              Epoint7->setOpacity(0);
              Epoint8->setOpacity(0);
          }
      }

      CCMenuItemSpriteExtra* level10Btn = CCMenuItemSpriteExtra::create(unkspr9, this, menu_selector(ownWorldSelectLayer::onWorldLevel));

      level10Btn->setTag(39);
      level10Btn->setPosition(170, -10);

      level10Btn->setVisible(false);
      level10->setPosition(level10Btn->getPosition());

      if (wlevel9->m_normalPercent != 100)
      {
          Mod::get()->setSavedValue("worldlevel9complete", 0);
      }
      ////level 9 to level 10 animation
      if (wlevel9->m_normalPercent == 100 && wlevel10->m_normalPercent == 0 && level9complete == 0)
      {
          Rpoint1->setScaleY(1.2);
          Rpoint2->setScaleY(1.2);
          Rpoint3->setScaleY(1.2);
          Rpoint4->setScaleY(1.2);
          Rpoint5->setScaleY(1.2);

          Rpoint1->setScaleX(2);
          Rpoint2->setScaleX(2);
          Rpoint3->setScaleX(2);
          Rpoint4->setScaleX(2);
          Rpoint5->setScaleX(2);

          //opacty
          Rpoint1->setOpacity(0);
          Rpoint2->setOpacity(0);
          Rpoint3->setOpacity(0);
          Rpoint4->setOpacity(0);
          Rpoint5->setOpacity(0);

          level10Btn->setOpacity(0);

          Rpoint1->runAction(CCSequence::create(CCDelayTime::create(0.3), CCFadeIn::create(0.1), CCEaseBounceOut::create(scaleWithBounce), nullptr));
          Rpoint2->runAction(CCSequence::create(CCDelayTime::create(0.6), CCFadeIn::create(0.1), CCEaseBounceOut::create(scaleWithBounce), nullptr));
          Rpoint3->runAction(CCSequence::create(CCDelayTime::create(0.9), CCFadeIn::create(0.1), CCEaseBounceOut::create(scaleWithBounce), nullptr));
          Rpoint4->runAction(CCSequence::create(CCDelayTime::create(1.2), CCFadeIn::create(0.1), CCEaseBounceOut::create(scaleWithBounce), nullptr));
          Rpoint5->runAction(CCSequence::create(CCDelayTime::create(1.5), CCFadeIn::create(0.1), CCEaseBounceOut::create(scaleWithBounce), nullptr));

          level10Btn->setScale(1.5);
          level10Btn->setVisible(true);

          Mod::get()->setSavedValue("wlevelunlocked", 9);
          level10Btn->runAction(CCSequence::create(
              CCDelayTime::create(1.8),
              CCCallFunc::create(this, callfunc_selector(ownWorldSelectLayer::runParticle)), // Utilizamos CCCallFunc para llamar a la función runParticle
              CCFadeIn::create(0.1),
              CCEaseBounceOut::create(scaleWithBounce2),
              nullptr
          ));
          Mod::get()->setSavedValue("worldlevel9complete", 1);
      }
      else
      {
          if (wlevel9->m_normalPercent == 100)
          {
              level10Btn->setVisible(true);
          }
          else
          {
              Rpoint1->setOpacity(0);
              Rpoint2->setOpacity(0);
              Rpoint3->setOpacity(0);
              Rpoint4->setOpacity(0);
              Rpoint5->setOpacity(0);
          }
      }

      if (wlevel10->m_normalPercent != 100)
      {
          Mod::get()->setSavedValue("worldlevel10complete", 0);
      }
      //final dialogue
      if (wlevel10->m_normalPercent == 100 && level10complete == 0)
      {
          CCArray* arr = CCArray::create();
          int colour = 2; //gjsquare thingy

          auto dialog1 = DialogObject::create("The Keymaster", "Well, well, well...<d020> I see you have <cg>completed</c> the <cl>first two</c> islands.", 2 /*dialog icon*/, 1, false, { 255,255,255 });

          auto dialog2 = DialogObject::create("The Keymaster", "Not bad,<d030> not bad at all.\n<d030>I have <co>unlocked</c> <cg>online levels</c> for you.", 2 /*dialog icon*/, 1, false, { 255,255,255 });

          auto dialog3 = DialogObject::create("The Keymaster", "Or maybe, if you were in <cy>Geometry Dash World game</c>, LOL.", 2 /*dialog icon*/, 1, false, { 255,255,255 });

          auto dialog4 = DialogObject::create("The Keymaster", "<cl>Let's see what more you can do<d010>.<d010>.<d010>.</c>", 2 /*dialog icon*/, 1, false, { 255,255,255 });
          arr->addObject(dialog1);

          arr->addObject(dialog2);

          arr->addObject(dialog3);

          arr->addObject(dialog4);




          auto dl = DialogLayer::createDialogLayer(nullptr, arr, colour);
          dl->animateInRandomSide();
          dl->setZOrder(2);

          this->addChild(dl, 3);
          Mod::get()->setSavedValue("worldlevel10complete", 1);
      }
      else
      {
          if (wlevel10->m_normalPercent == 100)
          {
              level10Btn->setVisible(true);
          }
        
      }
      ToxicFactoryMenu->addChild(level6Btn,2);
      ToxicFactoryMenu->addChild(level7Btn, 2);
      ToxicFactoryMenu->addChild(level8Btn,2);
      ToxicFactoryMenu->addChild(level9Btn, 2);
      ToxicFactoryMenu->addChild(level10Btn,2);

      ToxicFactoryMenu->addChild(level6);
      ToxicFactoryMenu->addChild(level7);
      ToxicFactoryMenu->addChild(level8);
      ToxicFactoryMenu->addChild(level9);
      ToxicFactoryMenu->addChild(level10);

     
     
      //LEVEL 5 POINTS
      //point 1
      MDOpoint1->setPosition(level5Btn->getPosition());
      MDOpoint1->setPositionX(MDOpoint1->getPositionX() + 20);
      MDOpoint1->setPositionY(-20);
      MDOpoint1->setScale(0.5);
      MDOpoint1->setScaleX(1);
      //point 2
      MDOpoint2->setPosition(level5Btn->getPosition());
      MDOpoint2->setPositionX(MDOpoint2->getPositionX() + 32);
      MDOpoint2->setPositionY(-25);
      MDOpoint2->setScale(0.5);
      MDOpoint2->setScaleX(1);
      //point 3
      MDOpoint3->setPosition(level5Btn->getPosition());
      MDOpoint3->setPositionX(MDOpoint3->getPositionX() + 50);
      MDOpoint3->setPositionY(-22);
      MDOpoint3->setScale(0.5);
      MDOpoint3->setScaleX(1);
      //point 4
      MDOpoint4->setPosition(level5Btn->getPosition());
      MDOpoint4->setPositionX(MDOpoint4->getPositionX() + 77);
      MDOpoint4->setPositionY(-22.5);
      MDOpoint4->setScale(0.5);
      MDOpoint4->setScaleX(1);
      //point 5
      MDOpoint5->setPosition(level5Btn->getPosition());
      MDOpoint5->setPositionX(MDOpoint5->getPositionX() + 89.7);
      MDOpoint5->setPositionY(-26);
      MDOpoint5->setScale(0.5);
      MDOpoint5->setScaleX(1);
      /*dashlandsmenu->setPositionX(dashlandsmenu->getPositionX() - 59.5);


      dashlandsmenu->setPositionY(dashlandsmenu->getPositionY() - 25);*/

      
      dashlandsmenu->setPosition(winSize / 2);
      dashlandsmenu->setPositionY(dashlandsmenu->getPositionY());
      //button levels
      dashlandsmenu->addChild(level1Btn);
      dashlandsmenu->addChild(level2Btn,1);
      dashlandsmenu->addChild(level3Btn,1);
      dashlandsmenu->addChild(level4Btn,1);
      dashlandsmenu->addChild(level5Btn,1);

      //skull - locked levels
      dashlandsmenu->addChild(level2);
      dashlandsmenu->addChild(level3);
      dashlandsmenu->addChild(level4);
      dashlandsmenu->addChild(level5);
      dashlandsmenu->setZOrder(1);
      /*node->addChild(dashlandsmenu);*/
      node->addChild(sprite);
      node->addChild(dashlandsmenu);
      node->addChild(Dashlands);
      node->setTag(20);

      node2->addChild(sprite2);
      node2->addChild(ToxicFactory);
      node2->addChild(ToxicFactoryMenu);
      node2->setTag(22);

      ToxicFactoryMenu->setPosition(winSize / 2);
      ToxicFactoryMenu->setPositionY(ToxicFactoryMenu->getPositionY());

      node3->addChild(sprite3);
      node3->addChild(CommingSoon);
      node3->setTag(23);





m_mainLevels = CCArray::create();
m_levelPages = CCArray::create();

m_level = 0;

m_levelPages->addObject(node);
m_levelPages->addObject(node2);
m_levelPages->addObject(node3);

//
//m_background->setID("bg-meltdown");
//m_ground->setID("ground-meltdown");
/* for(int i = 1; i < 23; i++)
     m_mainLevels->addObject(GLM->getMainLevel(i, true));*/

//for (size_t i = 0; i < 3; i++)
//    m_levelPages->addObject(LevelPage::create(nullptr));

//GJGameLevel* theTower = GJGameLevel::create();
//theTower->m_levelID = -2;
//m_mainLevels->addObject(theTower);



m_scrollLayer = BoomScrollLayer::create(m_levelPages, 0, false, nullptr, static_cast<DynamicScrollDelegate*>(this));

m_scrollLayer->m_extendedLayer->m_delegate = static_cast<BoomScrollLayerDelegate*>(this);

if (page)
{
    if (page == 21)
        m_scrollLayer->instantMoveToPage(20);
    m_scrollLayer->instantMoveToPage(page);
}
else
{
    scrollLayerMoved(m_scrollLayer->m_extendedLayer->getPosition()); //
}

addChild(m_scrollLayer);
auto pointer = (CCSpriteBatchNode*)m_scrollLayer->getChildren()->objectAtIndex(1);
/*pointer->setVisible(false);*/
pointer->setPositionY(director->getScreenBottom() - 45);
addChild(m_scrollLayer);


    //  //level 5 to level 6 animation
      if (wlevel5->m_normalPercent != 100)
      {
          Mod::get()->setSavedValue("worldlevel5complete", 0);
      }
      if (wlevel5->m_normalPercent == 100 && wlevel6->m_normalPercent == 0 && level5complete == 0)
      {
          //opacty

          level6Btn->setOpacity(0);

          level6Btn->setScale(1.5);
          level6Btn->setVisible(true);

          Mod::get()->setSavedValue("wlevelunlocked", 5);

          m_scrollLayer->moveToPage(1);
          level6Btn->runAction(CCSequence::create(
              CCDelayTime::create(1.2),
              CCCallFunc::create(this, callfunc_selector(ownWorldSelectLayer::runParticle)), // Utilizamos CCCallFunc para llamar a la función runParticle
              CCFadeIn::create(0.1),
              CCEaseBounceOut::create(scaleWithBounce2),
              nullptr
          ));

          Mod::get()->setSavedValue("worldlevel5complete", 1);
      }
      else
      {
          if (wlevel5->m_normalPercent == 100)
          {
              level6Btn->setVisible(true);
          }
          else
          {
              Fpoint1->setOpacity(0);
              Fpoint2->setOpacity(0);
              Fpoint3->setOpacity(0);
              Fpoint4->setOpacity(0);
              Fpoint5->setOpacity(0);
          }

      }

    
      sprite->setPosition(winSize / 2);
      sprite->setPositionY(sprite->getPositionY() - 30);
      /*sprite->setPositionX(sprite->getPositionX() + 279);
      sprite->setPositionY(sprite->getPositionY() + 130);*/


      Dashlands->setPositionX(sprite->getPositionX());
      Dashlands->setPositionY(sprite->getPositionY() + 150);
      Dashlands->setScale(0.8);

      

      sprite2->setPosition(winSize / 2);
      sprite2->setPositionY(sprite2->getPositionY() - 30);

      sprite3->setPosition(winSize / 2);
      sprite3->setPositionY(sprite3->getPositionY() - 30);

      ToxicFactory->setPositionX(sprite2->getPositionX());
      ToxicFactory->setPositionY(sprite2->getPositionY() + 150);
      ToxicFactory->setScale(0.8);

      CommingSoon->setPositionX(sprite3->getPositionX());
      CommingSoon->setPositionY(sprite3->getPositionY() + 150);
      CommingSoon->setScale(0.8);
      

      //start arrow animation
      auto moveUp = CCMoveBy::create(0.5f, ccp(0, 5)); 
      auto moveDown = CCMoveBy::create(0.5f, ccp(0, -5));

     /* auto moveUp1 = CCMoveBy::create(0.5f, ccp(0, 5));
      auto moveDown1 = moveUp->reverse();*/

      auto easeOutUp = CCEaseInOut::create(moveUp,1.5f);   
      auto easeInDown = CCEaseInOut::create(moveDown, 1.5f);

      /*auto easeOutDown = CCEaseOut::create(moveDown1, 1.5f);
      auto easeInUp = CCEaseIn::create(moveUp1, 1.5f); */
      auto moveSequence = CCSequence::create(easeOutUp, easeInDown, nullptr);

      auto repeatAction = CCRepeatForever::create(moveSequence);

      //island 1 loop
      
      auto moveUp21 = CCMoveBy::create(1.0f, ccp(0, 1));
      auto moveDown21 = moveUp21->reverse();

      auto moveUp121 = CCMoveBy::create(1.0f, ccp(0, 1));
      auto moveDown121 = moveUp121->reverse();

      auto easeOutUp21 = CCEaseOut::create(moveUp21, 1.5f);
      auto easeInDown21 = CCEaseIn::create(moveDown21, 1.5f);

      auto easeOutDown21 = CCEaseOut::create(moveDown121, 1.5f);
      auto easeInUp21 = CCEaseIn::create(moveUp121, 1.5f);
      auto moveSequence21 = CCSequence::create(easeOutUp21, easeInDown21, easeOutDown21, easeInUp21, nullptr);

      auto repeatAction21 = CCRepeatForever::create(moveSequence21);
      //island 2 loop
      auto moveUp2 = CCMoveBy::create(1.0f, ccp(0, 1)); 
      auto moveDown2 = moveUp2->reverse(); 

      auto moveUp12 = CCMoveBy::create(1.0f, ccp(0, 1)); 
      auto moveDown12 = moveUp2->reverse();

      auto easeOutUp2 = CCEaseOut::create(moveUp2, 1.5f); 
      auto easeInDown2 = CCEaseIn::create(moveDown2, 1.5f); 

      auto easeOutDown2 = CCEaseOut::create(moveDown12, 1.5f); 
      auto easeInUp2 = CCEaseIn::create(moveUp12, 1.5f); 
      auto moveSequence2 = CCSequence::create(easeOutUp2, easeInDown2, easeOutDown2, easeInUp2, nullptr);

      auto repeatAction2 = CCRepeatForever::create(moveSequence2);

     /* sprite->runAction(repeatAction);*/
      node->runAction(repeatAction21);

      node2->runAction(repeatAction2);


     
      if (wlevel1->m_normalPercent != 100)
      {
          auto level1arrow = CCSprite::createWithSpriteFrameName("GJ_arrow_02_001.png");

          level1arrow->setPosition(level1Btn->getPosition());

          level1arrow->setPositionY(level1arrow->getPositionY() + 40);
          level1arrow->setRotation(-90);
          level1arrow->setScale(0.6);
          dashlandsmenu->addChild(level1arrow);
          level1arrow->runAction(repeatAction);
      }
     /* auto pointer = (CCSpriteBatchNode*)m_scrollLayer->getChildren()->objectAtIndex(1);

      pointer->setPositionY(CCDirector::sharedDirector()->getScreenBottom() - 45);*/

      m_background = CCSprite::create("GJ_gradientBG.png");
      m_background->setAnchorPoint({ 0.f, 0.f });
      addChild(m_background, -4);

      m_background->setScaleX((winSize.width + 10.f) / m_background->getTextureRect().size.width);
      m_background->setScaleY((winSize.height + 10.f) / m_background->getTextureRect().size.height);
      m_background->setPosition(ccp(-5, -5));
      m_background->setColor(GM->colorForIdx(4));
      m_background->setTag(120);
      auto mm_background = CCSprite::create("GJ_gradientBG.png");
      mm_background->setAnchorPoint({ 0.f, 0.f });
     addChild(mm_background, -1);

      mm_background->setScaleX((winSize.width + 10.f) / mm_background->getTextureRect().size.width);
      mm_background->setScaleY((winSize.height + 10.f) / mm_background->getTextureRect().size.height);
      mm_background->setPosition(ccp(-5, -5));
      mm_background->setColor(GM->colorForIdx(4));
      mm_background->setTag(121);

      mm_background->setVisible(false);

      auto mm_background2 = CCSprite::create("GJ_gradientBG.png");
      mm_background2->setAnchorPoint({ 0.f, 0.f });
      addChild(mm_background2, -2);

      mm_background2->setScaleX((winSize.width + 10.f) / mm_background2->getTextureRect().size.width);
      mm_background2->setScaleY((winSize.height + 10.f) / mm_background2->getTextureRect().size.height);
      mm_background2->setPosition(ccp(-5, -5));
      mm_background2->setColor(GM->colorForIdx(17));
      mm_background2->setTag(122);

      auto mm_background3 = CCSprite::create("GJ_gradientBG.png");
      mm_background3->setAnchorPoint({ 0.f, 0.f });
      addChild(mm_background3, -3);
      mm_background2->setVisible(false);

      m_background->setZOrder(-4);
      mm_background3->setScaleX((winSize.width + 10.f) / mm_background3->getTextureRect().size.width);
      mm_background3->setScaleY((winSize.height + 10.f) / mm_background3->getTextureRect().size.height);
      mm_background3->setPosition(ccp(-5, -5));
      mm_background3->setColor(GM->colorForIdx(6));
      mm_background3->setVisible(false);
      mm_background3->setTag(123);
      sprite3->setColor(ccBLACK);
      sprite3->setOpacity(40);
    menu3 = CCMenu::create();
    menu3->setPosition(CCDirector::sharedDirector()->getScreenRight() - 50,
        CCDirector::sharedDirector()->getScreenTop() - 30);
    auto btn3 = CCSprite::createWithSpriteFrameName("garageRope_001.png");
    btn3->setScale(1);
    auto myButton3 = CCMenuItemSpriteExtra::create(
        btn3,
        this,
        menu_selector(ownWorldSelectLayer::onGarage));
    menu3->setTouchEnabled(false);
    auto delay = CCDelayTime::create(0.6f); // Crear una acción de retraso de 2 segundos
    auto callFunc = CCCallFunc::create(this, callfunc_selector(ownWorldSelectLayer::runScroll)); // Crear una acción que llame a la función deseada
  
    auto sequence = CCSequence::create(delay, callFunc,nullptr); // Crear una secuencia de acciones


    this->runAction(sequence); // Ejecutar la secuencia en un nodo o capa apropiada
    myButton3->setSizeMult(1);
    myButton3->m_animationType = MenuAnimationType{ 1 };
    myButton3->m_startPosition = btn3->getPosition();
    myButton3->m_offset = CCPoint{ 0, -5.f };
   /* myButton3->m_animationType = MenuAnimationType::Move;*/
    menu3->addChild(myButton3);
    addChild(menu3,2);
      m_background->setColor({ 0, 125, 255 });
        CCNode* sideArt = createSideArt();
    

        addChild(menu3,2);


        addChild(m_background, -1);
        addChild(sideArt);
        /*addChild(arrows, 5);*/

    return true;
}

void ownWorldSelectLayer::runScroll()
{
    Mod::get()->setSavedValue("onsubzero", 3);
     menu3->setTouchEnabled(true);
}
void ownWorldSelectLayer::runParticle()
{
    auto winSize = CCDirector::sharedDirector()->getWinSize();
    auto particles = CCParticleSystemQuad::create("coinPickupEffect.plist", 1);

    auto levelunlocked = Mod::get()->getSavedValue<int>("wlevelunlocked");

    auto extendedLayer = (ExtendedLayer*)m_scrollLayer->getChildren()->objectAtIndex(0);

    auto levelsnode1 = (more::GJWorldNodeDecomp*)extendedLayer->getChildren()->objectAtIndex(0);

    auto levelsmenu1 = (CCMenu*)levelsnode1->getChildren()->objectAtIndex(2);


    auto levelsnode2 = (more::GJWorldNodeDecomp*)extendedLayer->getChildren()->objectAtIndex(1);

    auto levelsmenu2 = (CCMenu*)levelsnode2->getChildren()->objectAtIndex(2);

   /* particles->setPosition({ ((winSize.width / 2) - 118) + 100, 136 });*/
    particles->setAnchorPoint({ 0.5f, 0.5f });
    particles->setScale(0.5f);
    particles->setZOrder(3);

  
    auto circlewave = CCCircleWave::create(16.0, 30, 0.3, 0,1);
    circlewave->setAnchorPoint({ 0.5f, 0.5f });
    circlewave->setScale(0.5f);
    circlewave->setZOrder(3);

    auto circlewave2 = CCCircleWave::create(16, 80, 0.3, 1, 1);
    circlewave2->setAnchorPoint({ 0.5f, 0.5f });
    circlewave2->setScale(0.5f);
    circlewave->setZOrder(3);
    if (levelunlocked == 1)
    {
        particles->setPosition({ -80, -30 });
      /*  circlewave->setPositionY(particles->getPositionY() - 100);
        circlewave2->setPositionY(particles->getPositionY() - 100);*/
    }

    if (levelunlocked == 2)
    {
        particles->setPosition({ -10, 10 });
      /*  circlewave->setPositionY(particles->getPositionY() - 150);
        circlewave2->setPositionY(particles->getPositionY() - 150);*/
    }
    if (levelunlocked == 3)
    {
        particles->setPosition({ 50, -25 });
       /* circlewave->setPositionY(particles->getPositionY() - 150);
        circlewave2->setPositionY(particles->getPositionY() - 150);*/
    }
    if (levelunlocked == 4)
    {
        particles->setPosition({ 155, -10 });
       /* circlewave->setPositionY(particles->getPositionY() - 150);
        circlewave2->setPositionY(particles->getPositionY() - 150);*/
    }
    if (levelunlocked == 5)
    {
        particles->setPosition({ -175, -12 });
      /*  circlewave->setPositionY(particles->getPositionY() - 150);
        circlewave2->setPositionY(particles->getPositionY() - 150);*/
    }
    if (levelunlocked == 6)
    {
        particles->setPosition({ -73, -28 });
       /* circlewave->setPositionY(particles->getPositionY() - 150);
        circlewave2->setPositionY(particles->getPositionY() - 150);*/
    }
    if (levelunlocked == 7)
    {
        particles->setPosition({ -10, 15 });
       /* circlewave->setPositionY(particles->getPositionY() - 150);
        circlewave2->setPositionY(particles->getPositionY() - 150);*/
    }
    if (levelunlocked == 8)
    {
        particles->setPosition({ 80, -38 });
      /*  circlewave->setPositionY(particles->getPositionY() - 150);
        circlewave2->setPositionY(particles->getPositionY() - 150);*/
    }
    if (levelunlocked == 9)
    {
        particles->setPosition({ 170, -10 });
      /*  circlewave->setPositionY(particles->getPositionY() - 150);
        circlewave2->setPositionY(particles->getPositionY() - 150);*/
    }
 /*   circlewave->setPositionX(particles->getPositionX()+50);
    circlewave2->setPositionX(particles->getPositionX() + 50);*/
    
    /*CCCircleWave::create(0LL, 4.0, 40.0, 0.3, 1);*/
    //203.5 - 130

    particles->init();

 /*   addChild(particles, 2);*/
    if (levelunlocked >= 1 && levelunlocked <= 4) {
        levelsmenu1->addChild(particles, 2);
   
    }
    else if (levelunlocked >= 5 && levelunlocked <= 9) {
        levelsmenu2->addChild(particles, 2);
    }
    particles->addChild(circlewave, 2);
    particles->addChild(circlewave2, 2);
}


//void WorldSelectLayerDecomp::createIslands() {
//  /*  CCString* path = CCString::createWithFormat(
//        "worldIsland_%02d.png",
//        m_index
//    );
//
//    CCSprite* sprite = CCSprite::createWithSpriteFrameName(
//        path->getCString()
//    );
//
//    return sprite;*/
//}
//void WorldSelectLayerDecomp::setupWorlds() {
//    /// @todo
//}

//void ownWorldSelectLayer::updatePageWithObject(CCObject* page, CCObject* object) {
//    GJGameLevel* level = static_cast<GJGameLevel*>(object);
//    static_cast<LevelPage*>(page)->updateDynamicPage(level);
//    auto lol = Mod::get()->getSavedValue<int>("meltdownlevel");
//
//    /* updateColors();*/
//}

//CCSprite* ownWorldSelectLayer::createBackground() {
//   
//
//    return background;
//}

CCNode* ownWorldSelectLayer::createSideArt() {
    CCNode* sideArt = CCNode::create();

    CCDirector* director = CCDirector::sharedDirector();
    const float screenLeft = director->getScreenLeft();
    const float screenRight = director->getScreenRight();
    const float screenBottom = director->getScreenBottom();

    CCSprite* left = CCSprite::createWithSpriteFrameName(
        "GJ_sideArt_001.png"
    );
    left->setAnchorPoint({ 0.0f, 0.0f });
    left->setPosition({ screenLeft - 1.0f, screenBottom - 1.0f });
    sideArt->addChild(left);

    CCSprite* right = CCSprite::createWithSpriteFrameName(
        "GJ_sideArt_001.png"
    );
    right->setAnchorPoint({ 1.0f, 0.0f });
    right->setPosition({ screenRight + 1.0f, screenBottom - 1.0f });
    right->setFlipX(true);
    sideArt->addChild(right);


    return sideArt;


}


//void WorldSelectLayerDecomp::updatePageWithObject(CCObject* page, CCObject* object) {
//    GJGameLevel* level = static_cast<GJGameLevel*>(object);
//    static_cast<LevelPage*>(page)->updateDynamicPage(level);
//    
//  /*  std::cout << page << std::endl;*/
//   /* auto lol = Mod::get()->getSavedValue<int>("subzerolevellol");*/
//  /*  if (level->m_levelID == 4001)
//    {
//        lol = 1;
//    }
//
//    if (level->m_levelID == 4002)
//    {
//        lol = 2;
//    }
//
//    if (level->m_levelID == 4003)
//    {
//        lol = 3;
//    }
//    if (level->m_levelID == -1)
//    {
//        lol = 4;
//    }*/
//
//   /* Mod::get()->setSavedValue("subzerolevellol", lol);*/
//    /* updateColors();*/
//}
//
//CCNode* WorldSelectLayerDecomp::createArrows() {
//    CCMenu* btnMenu = CCMenu::create();
//   
//    auto director = CCDirector::sharedDirector();
//    auto winSize = director->getWinSize();
//    CCSprite* leftSpr = CCSprite::createWithSpriteFrameName("navArrowBtn_001.png");
//    leftSpr->setFlipX(true);
//
//    CCMenuItemSpriteExtra* leftBtn = CCMenuItemSpriteExtra::create(leftSpr, this, menu_selector(LevelInfoLayer::onGarage));
//    btnMenu->addChild(leftBtn);
//
//
//    leftBtn->setPosition(btnMenu->convertToNodeSpace(ccp(director->getScreenLeft() + 25.f, winSize.height / 2)));
//    leftBtn->setScale(0.7);
//
//
//    CCSprite* rightSpr = CCSprite::createWithSpriteFrameName("navArrowBtn_001.png");
//
//    CCMenuItemSpriteExtra* rightBtn = CCMenuItemSpriteExtra::create(rightSpr, this, menu_selector(WorldSelectLayerDecomp::onNext));
//    
//    btnMenu->addChild(rightBtn);
//
//    rightBtn->setPosition(btnMenu->convertToNodeSpace(ccp(director->getScreenRight() - 25.f, winSize.height / 2)));
//    rightBtn->setScale(0.7);
//
//    return btnMenu;
//}

void ownWorldSelectLayer::keyBackClicked() {
    auto back = Mod::get()->getSavedValue<int>("onsubzero");
    back = 10;
    Mod::get()->setSavedValue("onsubzero", back);
    Mod::get()->setSavedValue("onworldpages", back);
    //Mod::get()->getSavedValue<int>("onworldpages");
    CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(0.5, MenuLayer::scene(false)));
}

void ownWorldSelectLayer::onWorldLevel(CCObject* sender) {

    CCMenuItemSpriteExtra* button = (CCMenuItemSpriteExtra*)sender;
    auto GLM = GameLevelManager::sharedState();
    auto level1popup = WorldLevelPopup::create("");
    auto Layer = (CCLayer*)level1popup->getChildren()->objectAtIndex(0);

    auto BG = (CCScale9Sprite*)Layer->getChildren()->objectAtIndex(0);
    auto m_buttonMenu = CCMenu::create();
    auto corner1 = CCSprite::createWithSpriteFrameName("dailyLevelCorner_001.png");
    auto director = CCDirector::sharedDirector();
    auto winSize = director->getWinSize();
    corner1->setPosition(BG->getPosition());
    corner1->setRotation(180);
    Layer->addChild(corner1);

    auto corner2 = CCSprite::createWithSpriteFrameName("dailyLevelCorner_001.png");
    corner2->setPosition(BG->getPosition());
    corner2->setRotation(90);
    Layer->addChild(corner2);

    auto corner3 = CCSprite::createWithSpriteFrameName("dailyLevelCorner_001.png");
    corner3->setPosition(BG->getPosition());
    corner3->setRotation(270);
    Layer->addChild(corner3);

    auto corner4 = CCSprite::createWithSpriteFrameName("dailyLevelCorner_001.png");
    corner4->setPosition(BG->getPosition());
    //corner 1 = right + up
    corner1->setPositionX(corner1->getPositionX() + 125.45);
    corner1->setPositionY(corner1->getPositionY() + 105.1);
    //corner 2 = left + up
    corner2->setPositionX(corner2->getPositionX() - 125.45);
    corner2->setPositionY(corner2->getPositionY() + 105.1);
    //corner 3 = right + down
    corner3->setPositionX(corner3->getPositionX() + 125.45);
    corner3->setPositionY(corner3->getPositionY() - 105.1);
    //corner 4 =  left + down
    corner4->setPositionX(corner4->getPositionX() - 125.45);
    corner4->setPositionY(corner4->getPositionY() - 105.1);

    cocos2d::CCMenu* infoMenu = cocos2d::CCMenu::create();
    cocos2d::CCSprite* info = cocos2d::CCSprite::createWithSpriteFrameName("GJ_infoIcon_001.png");
    CCMenuItemSpriteExtra* infoBtn = CCMenuItemSpriteExtra::create(info, this, menu_selector(ownWorldSelectLayer::onInfo));

    infoBtn->setTag(button->getTag());
    infoMenu->addChild(infoBtn);
    infoMenu->setPosition(BG->getPosition());
    infoMenu->setPositionX(infoMenu->getPositionX() + 146.5);
    infoMenu->setPositionY(infoMenu->getPositionY() + 126.1);
    info->setTag(button->getTag());
    infoMenu->setTag(button->getTag());
    Layer->addChild(infoMenu, 2);
    Layer->addChild(corner4);

    Layer->addChild(m_buttonMenu);


   
    if (button->getTag() == 30)
    {
     /*   std::string dir = geode::Mod::get()->getResourcesDir().string();
        std::ifstream mt(dir + "/2001.txt");
        std::string mtext((std::istreambuf_iterator<char>(mt)), std::istreambuf_iterator<char>());*/
        level = GLM->getMainLevel(2001, true);
        level->m_levelName = "Payload";
        level->m_stars = 2;
        level->m_levelString = LocalLevelManager::sharedState()->getMainLevelString(2001);
        level->m_audioTrack = 27;
        level->m_difficulty = GJDifficulty::Easy;
        level->m_creatorName = "RobTopGames";
        level->m_requiredCoins = 0;
        level->m_coins = 0;
    }
    if (button->getTag() == 31)
    {
    /*    std::string dir = geode::Mod::get()->getResourcesDir().string();
        std::ifstream mt(dir + "/2002.txt");
        std::string mtext((std::istreambuf_iterator<char>(mt)), std::istreambuf_iterator<char>());*/
        level = GLM->getMainLevel(2002, false);
        level->m_levelName = "Beast Mode";
        level->m_stars = 2;
        level->m_levelString = LocalLevelManager::sharedState()->getMainLevelString(2002);
        level->m_audioTrack = 28;
        level->m_difficulty = GJDifficulty::Easy;
        level->m_creatorName = "RobTopGames";
        level->m_requiredCoins = 0;
        level->m_coins = 0;
    }
    if (button->getTag() == 32)
    {
     /*   std::string dir = geode::Mod::get()->getResourcesDir().string();
        std::ifstream mt(dir + "/2003.txt");
        std::string mtext((std::istreambuf_iterator<char>(mt)), std::istreambuf_iterator<char>());*/
        level = GLM->getMainLevel(2003, false);
        level->m_levelName = "Machina";
        level->m_stars = 3;
        level->m_levelString = LocalLevelManager::sharedState()->getMainLevelString(2003);
        level->m_audioTrack = 29;
        level->m_difficulty = GJDifficulty::Normal;
        level->m_creatorName = "RobTopGames";
        level->m_requiredCoins = 0;
        level->m_coins = 0;
    }
    if (button->getTag() == 33)
    {
      /*  std::string dir = geode::Mod::get()->getResourcesDir().string();
        std::ifstream mt(dir + "/2004.txt");

        std::string mtext((std::istreambuf_iterator<char>(mt)), std::istreambuf_iterator<char>());*/
        level = GLM->getMainLevel(2004, false);
        level->m_levelName = "Years";
        level->m_stars = 3;
        level->m_levelString = LocalLevelManager::sharedState()->getMainLevelString(2004);
        level->m_audioTrack = 30;
        level->m_difficulty = GJDifficulty::Normal;
        level->m_creatorName = "RobTopGames";
        level->m_requiredCoins = 0;
        level->m_coins = 0;
    }
    if (button->getTag() == 34)
    {
        /*std::string dir = geode::Mod::get()->getResourcesDir().string();
        std::ifstream mt(dir + "/2005.txt");

        std::string mtext((std::istreambuf_iterator<char>(mt)), std::istreambuf_iterator<char>());*/
        level = GLM->getMainLevel(2005, false);
        level->m_levelName = "Frontlines";
        level->m_stars = 3;
        level->m_levelString = LocalLevelManager::sharedState()->getMainLevelString(2005);
        level->m_audioTrack = 31;
        level->m_difficulty = GJDifficulty::Normal;
        level->m_creatorName = "RobTopGames";
        level->m_requiredCoins = 0;
        level->m_coins = 0;
    }
    if (button->getTag() == 35)
    {
     /*   std::string dir = geode::Mod::get()->getResourcesDir().string();
        std::ifstream mt(dir + "/2006.txt");
        std::string mtext((std::istreambuf_iterator<char>(mt)), std::istreambuf_iterator<char>());*/
        level = GLM->getMainLevel(2006, false);
        level->m_levelName = "Space Pirates";
        level->m_stars = 3;
        level->m_levelString = LocalLevelManager::sharedState()->getMainLevelString(2006);
        level->m_audioTrack = 32;
        level->m_difficulty = GJDifficulty::Normal;
        level->m_creatorName = "RobTopGames";
        level->m_requiredCoins = 0;
        level->m_coins = 0;
    }
    if (button->getTag() == 36)
    {
       /* std::string dir = geode::Mod::get()->getResourcesDir().string();
        std::ifstream mt(dir + "/2007.txt");
        std::string mtext((std::istreambuf_iterator<char>(mt)), std::istreambuf_iterator<char>());*/
        level = GLM->getMainLevel(2007, false);
        level->m_levelName = "Striker";
        level->m_stars = 3;
        level->m_levelString = LocalLevelManager::sharedState()->getMainLevelString(2007);
        level->m_audioTrack = 33;
        level->m_difficulty = GJDifficulty::Normal;
        level->m_creatorName = "RobTopGames";
        level->m_requiredCoins = 0;
        level->m_coins = 0;
    }
    if (button->getTag() == 37)
    {
     /*   std::string dir = geode::Mod::get()->getResourcesDir().string();
        std::ifstream mt(dir + "/2008.txt");
        std::string mtext((std::istreambuf_iterator<char>(mt)), std::istreambuf_iterator<char>());*/
        level = GLM->getMainLevel(2008, false);
        level->m_levelName = "Embers";
        level->m_stars = 3;
        level->m_levelString = LocalLevelManager::sharedState()->getMainLevelString(2008);
        level->m_audioTrack = 34;
        level->m_difficulty = GJDifficulty::Normal;
        level->m_creatorName = "RobTopGames";
        level->m_requiredCoins = 0;
        level->m_coins = 0;
    }
    if (button->getTag() == 38)
    {
       /* std::string dir = geode::Mod::get()->getResourcesDir().string();
        std::ifstream mt(dir + "/2009.txt");
        std::string mtext((std::istreambuf_iterator<char>(mt)), std::istreambuf_iterator<char>());*/
        level = GLM->getMainLevel(2009, false);
        level->m_levelName = "Round 1";
        level->m_stars = 3;
        level->m_levelString = LocalLevelManager::sharedState()->getMainLevelString(2009);
        level->m_audioTrack = 35;
        level->m_difficulty = GJDifficulty::Normal;
        level->m_creatorName = "RobTopGames";
        level->m_requiredCoins = 0;
        level->m_coins = 0;
    }
    if (button->getTag() == 39)
    {
        //std::string dir = geode::Mod::get()->getResourcesDir().string();
        //std::ifstream mt(dir + "/2010.txt");
        //std::string mtext((std::istreambuf_iterator<char>(mt)), std::istreambuf_iterator<char>());
        level = GLM->getMainLevel(2010, false);
        level->m_levelName = "Monster Dance Off";
        level->m_stars = 3;
        level->m_levelString = LocalLevelManager::sharedState()->getMainLevelString(2010);
        level->m_audioTrack = 36;
        level->m_difficulty = GJDifficulty::Normal;
        level->m_creatorName = "RobTopGames";
        level->m_requiredCoins = 0;
        level->m_coins = 0;
    }

    auto playBtn = CCMenuItemSpriteExtra::create(CCSprite::createWithSpriteFrameName("GJ_playBtn2_001.png"), this, menu_selector(ownWorldSelectLayer::onPlay));
    
    m_buttonMenu->addChild(playBtn);
    m_buttonMenu->setPositionX(BG->getPositionX());
    m_buttonMenu->setPositionY(BG->getPositionY()+35);
    Mod::get()->setSavedValue("worldpopuptag", button->getTag());
    std::string title = level->m_levelName;

    const char* font = "goldFont.fnt";
    float scale = .7f;
    float offset = 80.f;
    auto m_title = cocos2d::CCLabelBMFont::create(title.c_str(), font);
    m_title->setScale(0.9);
    /*auto winSize = cocos2d::CCDirector::get()->getWinSize();*/

    //Normal mode progress bar
    int per = 100;
    std::vector<int> normalPer(per, 0);

    /*std::cout << level->m_normalPercent << std::endl;*/
    std::vector<int> completePer(level->m_normalPercent, 100);

    auto levelVector = normalPer;
    auto completedVector = completePer;

    //progress bar
    auto bar = CCSprite::create("GJ_progressBar_001.png");
    bar->setScale(0.7f);
    bar->setPosition(BG->getPosition());
    bar->setPositionX(bar->getPositionX());
    bar->setPositionY(bar->getPositionY() - 153.5);
    bar->setColor({ 0, 0, 0 });
    bar->setOpacity(125);
    bar->setZOrder(1);
    bar->setID("progress-bar-normal"_spr);

    Layer->addChild(bar);

    float size = (float)completedVector.size() / (float)levelVector.size();

    auto status = CCLabelBMFont::create(fmt::format("{}%", completedVector.size(), levelVector.size()).c_str(), "bigFont.fnt");
    status->setPosition({ bar->getPosition() });
    status->limitLabelWidth(170, .7f, .3f);
    status->setScale(0.4f);
    status->setZOrder(2);
    status->setID("status"_spr);
    status->setPositionY(status->getPositionY() + 108);
    Layer->addChild(status);


    auto normal = CCLabelBMFont::create("Normal Mode", "bigFont.fnt");
    normal->setPosition(status->getPosition());
    normal->setID("normal"_spr);

    normal->setPositionY(normal->getPositionY() + 20);
    normal->setScale(0.4f);
    Layer->addChild(normal);

    auto progress = CCSprite::create("GJ_progressBar_001.png");
    progress->setColor({ 0,255,0 });
    //progress->setColor({0,255,0});
    progress->setScaleX(0.985f);
    progress->setScaleY(0.860f);
    progress->setOpacity(255);
    bar->addChild(progress);
    bar->setPositionY(bar->getPositionY() + 108);
    progress->setAnchorPoint({ 0.f,0.5f });
    progress->setPosition({ 2.5f, 10.f });
    progress->setID("progress-bar-internal"_spr);

    CCRect progressRect = progress->getTextureRect();
    progressRect.size.width *= size;
    progress->setTextureRect(progressRect);

    //practice progress bar

    int pper = 100;
    std::vector<int> pnormalPer(pper, 0);

    /*std::cout << level->m_normalPercent << std::endl;*/
    std::vector<int> pcompletePer(level->m_practicePercent, 100);

    auto plevelVector = pnormalPer;
    auto pcompletedVector = pcompletePer;

    //progress bar
    auto pbar = CCSprite::create("GJ_progressBar_001.png");
    pbar->setScale(0.7f);
    pbar->setPosition(BG->getPosition());

    pbar->setPositionX(pbar->getPositionX());
    pbar->setPositionY(pbar->getPositionY() - 150.5);
    pbar->setColor({ 0, 0, 0 });
    pbar->setOpacity(125);
    pbar->setZOrder(1);
    pbar->setID("progress-bar"_spr);

    Layer->addChild(pbar);

    float psize = (float)pcompletedVector.size() / (float)plevelVector.size();

    auto pstatus = CCLabelBMFont::create(fmt::format("{}%", pcompletedVector.size(), plevelVector.size()).c_str(), "bigFont.fnt");
    pstatus->setPosition({ pbar->getPosition() });
    pstatus->limitLabelWidth(170, .7f, .3f);
    pstatus->setScale(0.4f);
    pstatus->setZOrder(2);
    pstatus->setID("practice status"_spr);
    pstatus->setPositionY(pstatus->getPositionY() + 58);
    Layer->addChild(pstatus);


    auto practice = CCLabelBMFont::create("Practice Mode", "bigFont.fnt");
    practice->setPosition(pstatus->getPosition());
    practice->setID("practice"_spr);

    practice->setPositionY(practice->getPositionY() + 20);
    practice->setScale(0.4f);
    Layer->addChild(practice);

    auto pprogress = CCSprite::create("GJ_progressBar_001.png");
    pprogress->setColor({ 0,255,255 });
    //progress->setColor({0,255,0});
    pprogress->setScaleX(0.985f);
    pprogress->setScaleY(0.860f);
    pprogress->setOpacity(255);
    pbar->addChild(pprogress);
    pbar->setPositionY(pbar->getPositionY() + 58);
    pprogress->setAnchorPoint({ 0.f,0.5f });
    pprogress->setPosition({ 2.5f, 10.f });
    pprogress->setID("progress-bar-internal"_spr);

    CCRect pprogressRect = pprogress->getTextureRect();
    pprogressRect.size.width *= psize;
    pprogress->setTextureRect(pprogressRect);
    m_title->setPosition(BG->getPosition());
    m_title->setPositionY(m_title->getPositionY() + 110);
    Layer->addChild(m_title);

    createStars(level, Layer);
    /* m_title->setPositionY()*/
  /*  level1popup->addChild(m_title);*/
   /* level1popup->setContentSize({290,200});*/
    level1popup->show();

}

//void ownWorldSelectLayer::instantPage(CCObject* sender, int a1) {
//
//    if (a1 == 1)
//    {
//        auto GM = GameManager::sharedState();
//        CCSprite* BG = (CCSprite*)m_background;
//        /* BG->setColor(GM->colorForIdx(6));*/
//        auto extendedLayer = (ExtendedLayer*)m_scrollLayer->getChildren()->objectAtIndex(0);
//
//        /* extendedLayer->setPositionX(-569);*/
//        m_scrollLayer->instantMoveToPage(0);
//    }
//    if (a1 == 2)
//    {
//        auto GM = GameManager::sharedState();
//        CCSprite* BG = (CCSprite*)m_background;
//        BG->setColor(GM->colorForIdx(6));
//        auto extendedLayer = (ExtendedLayer*)m_scrollLayer->getChildren()->objectAtIndex(0);
//
//        /* extendedLayer->setPositionX(-569);*/
//        m_scrollLayer->instantMoveToPage(1);
//    }
//    if (a1 == 3)
//    {
//        auto GM = GameManager::sharedState();
//        CCSprite* BG = (CCSprite*)m_background;
//        BG->setColor(GM->colorForIdx(17));
//        auto extendedLayer = (ExtendedLayer*)m_scrollLayer->getChildren()->objectAtIndex(0);
//
//        /* extendedLayer->setPositionX(-569);*/
//        m_scrollLayer->instantMoveToPage(1);
//    }
//    if (a1 == 3)
//    {
//        auto GM = GameManager::sharedState();
//        CCSprite* BG = (CCSprite*)m_background;
//        /*BG->setColor(GM->colorForIdx(6));*/
//        auto extendedLayer = (ExtendedLayer*)m_scrollLayer->getChildren()->objectAtIndex(0);
//
//        /* extendedLayer->setPositionX(-569);*/
//        m_scrollLayer->instantMoveToPage(2);
//    }
//    /*m_sscrollLayer->instantMoveToPage(a1);*/
//    /*m_scrollLayer->moveToPage(a1);*/
//    /*  currentColorIndex = (currentColorIndex - 1 + numColors) % numColors;*/
//      /*  updateColors();*/
// /*   scrollLayerMoved({ 0, 0 });*/
//}
void ownWorldSelectLayer::onPlay(CCObject* sender) {
	auto currentScene = CCDirector::sharedDirector()->getRunningScene();

    CCMenuItemSpriteExtra* button = (CCMenuItemSpriteExtra*)sender;
    button->setEnabled(false);
    auto GLM = GameLevelManager::sharedState();
    auto playLayer = PlayLayer::scene(level, false, false);
    FMODAudioEngine::sharedEngine()->playEffect("playSound_01.ogg");
   /* std::cout << "level string:" << level->m_levelString.c_str() << std::endl;*/
    

    CCDirector::get()->replaceScene(CCTransitionFade::create(0.5f, playLayer));

}



cocos2d::ccColor3B ownWorldSelectLayer::colorForPage(int page)
{
    auto GM = GameManager::sharedState();
    int colIDs[9] = { 6 ,17, 4, 9, 3, 11, 1, 3, 4 };

    return GM->colorForIdx(colIDs[page % 5]);
}

cocos2d::ccColor3B ownWorldSelectLayer::getColorValue(int level, int level2, float a3)
{

    float mod = (a3 * (2 / 3)) - 0.2f;
    if (mod < 1.0f)
    {
        if (mod <= 0.0f)
            mod = 0.0f;
    }
    else
        mod = 1.0f;

    ccColor3B col1 = colorForPage(level);
    ccColor3B col2 = colorForPage(level2);

    ccColor3B col3 = {
    static_cast<GLubyte>((col2.r * mod) + col1.r * (1.0f - mod)),
    static_cast<GLubyte>((col2.g * mod) + col1.g * (1.0f - mod)),
    static_cast<GLubyte>((col2.b * mod) + col1.b * (1.0f - mod))
    };
    return col3;
}

void ownWorldSelectLayer::scrollLayerMoved(CCPoint point) {
    const int pageCount = 3; 
    const float threshold = 0.7f; 

    float x = -point.x / this->m_fWindowWidth;
    while (x < 0.0f) {
        x += pageCount;
    }

    int ix = std::floor(x);

   
    float offset = x - ix;

    int firstPage = ix % pageCount;

    int lmao = firstPage + 1;
    int secondPage = lmao % pageCount;

    m_level = firstPage;

    if (std::abs(offset) > threshold) {

        ccColor3B color = getColorValue(firstPage, secondPage - 1, 12);
        m_background->setColor(color);



        ccColor3B Color1 = color;
        Color1.r = color.r * 0.8;
        Color1.g = color.g * 0.8;
        Color1.b = color.b * 0.8;

        ccColor3B Color2 = color;
        Color2.r = color.r * 0.9;
        Color2.g = color.g * 0.9;
        Color2.b = color.b * 0.9;


    }
}

void ownWorldSelectLayer::onGarage(CCObject* sender) {

    auto transition = CCTransitionMoveInT::create(0.5f, GJGarageLayer::scene());

    Mod::get()->setSavedValue("onsubzero", 10);
    Mod::get()->setSavedValue("onworldpages", this->m_scrollLayer->m_page+1);
    CCDirector::sharedDirector()->pushScene(transition);

}
void ownWorldSelectLayer::createStars(GJGameLevel* level, CCLayer* layer) {
    int totalstars = level->m_stars;
    float screenWidth = CCDirector::sharedDirector()->getWinSize().width;
    auto BG = (CCScale9Sprite*)layer->getChildren()->objectAtIndex(0);
    auto director = CCDirector::sharedDirector();
    auto winSize = director->getWinSize();

    std::string starspr = "";

    if (level->m_normalPercent == 100)
    {
        starspr = "GJ_starsIcon_001.png";
    }
    else
    {
        starspr = "GJ_starsIcon_gray_001.png";
    }



    float starWidth = 0;
    float spaceBetweenStars = 35.0f;


    float totalWidth = totalstars * (starWidth * 0.65) + (totalstars - 1) * spaceBetweenStars;

  
    float startX = BG->getPositionX() - totalWidth / 2;

   
    float startY = (BG->getPositionY()) - 113;

   
    float currentX = startX;


    for (int i = 0; i < totalstars; ++i) {
        auto star = CCSprite::createWithSpriteFrameName(starspr.c_str());

        star->setPosition({ currentX, startY });
        star->setScale(0.65);

        layer->addChild(star);

        currentX += (starWidth * 0.65) + spaceBetweenStars;
    }
}

void ownWorldSelectLayer::onClose(CCObject*) {
    keyBackClicked();
}

void ownWorldSelectLayer::updatePageWithObject(CCObject* page, CCObject* object) {
    if (!page || !object) {
        // Maneja el caso de punteros nulos
        std::cerr << "Error: 'updatePageWithObject' is null." << std::endl;
        return;
    }

    GJGameLevel* level = static_cast<GJGameLevel*>(object);
    std::cout << "LEVELID BEFORE CASTING: " << level->m_levelID << std::endl;

    LevelPage* levelPage = dynamic_cast<LevelPage*>(page);

    if (!levelPage) {

        std::cerr << "Error: 'page' is not 'LevelPage' type." << std::endl;
        return;
    }

    levelPage->updateDynamicPage(level);

    std::cout << "LEVELID IN UPDATEPAGEWITHOBJECT: " << level->m_levelID << std::endl;
}


void ownWorldSelectLayer::onNext(CCObject*) {
    /*	m_nLevel++;*/
    m_scrollLayer->quickUpdate();
    m_scrollLayer->moveToPage(m_level + 1);
}

void ownWorldSelectLayer::onPrev(CCObject*) {

    m_scrollLayer->quickUpdate();
    m_scrollLayer->moveToPage(m_level - 1);
}

void sLOLwshow2(GJGameLevel* level212) {

    if (level212 == nullptr) return;


    if (level212->m_levelID == -1) {
        FLAlertLayer::create(nullptr, "It's a secret...", "<cr>Roses are red</c>\n<cl>Violets are blue</c>\n<cg>Welcome to</c>\n<cy>2.2</c>", "OK", nullptr, 360)->show();
        return;
    }

    if (level212->m_levelID == -2) {
        FLAlertLayer::create(nullptr, "The Tower", "The path leads to an <cr>old tower</c>. It's been left alone for <cg>years</c>, with little reason to <co>explore</c>.", "OK", nullptr, 360)->show();
        return;
    }


    if (level212->m_levelID != -1 && level212->m_levelID != -2)
    {
        std::string name = level212->m_levelName;
        std::string contentStream =
            "<cy>" + name + "</c>" +
            "\n<cg>Total Attempts</c>: " + std::to_string(level212->m_attempts) +
            "\n<cl>Total Jumps</c>: " + std::to_string(level212->m_jumps) +
            "\n<cp>Normal</c>: " + std::to_string(level212->m_normalPercent) + "%" +
            "\n<co>Practice</c>: " + std::to_string(level212->m_practicePercent) + "%";

        FLAlertLayer::create(nullptr, "Level Stats", contentStream, "OK", nullptr, 360)->show();
        return;
    }
}

void ownWorldSelectLayer::onInfo(CCObject* sender) {

    /*Mod::get()->setSavedValue("subzerolevels", subzero);*/
    auto lol = Mod::get()->getSavedValue<int>("worldpopuptag");
    auto GLM = GameLevelManager::sharedState();

    auto level21 = GJGameLevel::create();
    int levellol = 0;
    if (lol == 30)
    {
       /* std::string dir = geode::Mod::get()->getResourcesDir().string();
        std::ifstream mt(dir + "/2001.txt");
        std::string mtext((std::istreambuf_iterator<char>(mt)), std::istreambuf_iterator<char>());*/
        level21 = GLM->getMainLevel(2001, true);
     /*   level21->m_levelName = "Payload";
        level21->m_levelType = GJLevelType::Local;
        level21->m_stars = 2;
        level21->m_levelString = mtext;
        level21->m_audioTrack = 27;
        level21->m_difficulty = GJDifficulty::Normal;
        level21->m_creatorName = "RobTopGames";
        level21->m_requiredCoins = 0;
        level21->m_coins = 0;*/
    }

    if (lol == 31)
    {
       /* std::string dir = geode::Mod::get()->getResourcesDir().string();
        std::ifstream mt(dir + "/2002.txt");
        std::string mtext((std::istreambuf_iterator<char>(mt)), std::istreambuf_iterator<char>());*/

        level21 = GLM->getMainLevel(2002, true);
       /* level21->m_levelName = "Beast Mode";
        level21->m_stars = 2;
        level21->m_levelType = GJLevelType::Local;
        level21->m_levelString = mtext;
        level21->m_audioTrack = 28;
        level21->m_difficulty = GJDifficulty::Normal;
        level21->m_creatorName = "RobTopGames";
        level21->m_requiredCoins = 0;
        level21->m_coins = 0;*/
    }

    if (lol == 32)
    {
        /*std::string dir = geode::Mod::get()->getResourcesDir().string();
        std::ifstream mt(dir + "/2003.txt");
        std::string mtext((std::istreambuf_iterator<char>(mt)), std::istreambuf_iterator<char>());*/

        level21 = GLM->getMainLevel(2003, true);
     /*   level21->m_levelName = "Machina";
        level21->m_stars = 3;
        level21->m_levelType = GJLevelType::Local;
        level21->m_levelString = mtext;
        level21->m_audioTrack = 29;
        level21->m_difficulty = GJDifficulty::Normal;
        level21->m_creatorName = "RobTopGames";
        level21->m_requiredCoins = 0;
        level21->m_coins = 0;*/
    }

    if (lol == 33)
    {
       /* std::string dir = geode::Mod::get()->getResourcesDir().string();
        std::ifstream mt(dir + "/2004.txt");
        std::string mtext((std::istreambuf_iterator<char>(mt)), std::istreambuf_iterator<char>());*/

        level21 = GLM->getMainLevel(2004, true);
    /*    level21->m_levelName = "Years";
        level21->m_stars = 3;
        level21->m_levelType = GJLevelType::Local;
        level21->m_levelString = mtext;
        level21->m_audioTrack = 30;
        level21->m_difficulty = GJDifficulty::Normal;
        level21->m_creatorName = "RobTopGames";
        level21->m_requiredCoins = 0;
        level21->m_coins = 0;*/
    }
    if (lol == 34)
    {
      /*  std::string dir = geode::Mod::get()->getResourcesDir().string();
        std::ifstream mt(dir + "/2005.txt");
        std::string mtext((std::istreambuf_iterator<char>(mt)), std::istreambuf_iterator<char>());*/


        level21 = GLM->getMainLevel(2005, true);
      /*  level21->m_levelName = "Frontlines";
        level21->m_stars = 3;
        level21->m_levelType = GJLevelType::Local;
        level21->m_levelString = mtext;
        level21->m_audioTrack = 31;
        level21->m_difficulty = GJDifficulty::Normal;
        level21->m_creatorName = "RobTopGames";
        level21->m_requiredCoins = 0;
        level21->m_coins = 0;*/
    }
    if (lol == 35)
    {
       /* std::string dir = geode::Mod::get()->getResourcesDir().string();
        std::ifstream mt(dir + "/2006.txt");
        std::string mtext((std::istreambuf_iterator<char>(mt)), std::istreambuf_iterator<char>());*/

        level21 = GLM->getMainLevel(2006, true);
      /*  level21->m_levelName = "Space Pirates";
        level21->m_stars = 3;
        level21->m_levelType = GJLevelType::Local;
        level21->m_levelString = mtext;
        level21->m_audioTrack = 32;
        level21->m_difficulty = GJDifficulty::Normal;
        level21->m_creatorName = "RobTopGames";
        level21->m_requiredCoins = 0;
        level21->m_coins = 0;*/
    }
    if (lol == 36)
    {
      /*  std::string dir = geode::Mod::get()->getResourcesDir().string();
        std::ifstream mt(dir + "/2007.txt");
        std::string mtext((std::istreambuf_iterator<char>(mt)), std::istreambuf_iterator<char>());*/

        level21 = GLM->getMainLevel(2007, true);
       /* level21->m_levelName = "Striker";
        level21->m_stars = 3;
        level21->m_levelType = GJLevelType::Local;
        level21->m_levelString = mtext;
        level21->m_audioTrack = 33;
        level21->m_difficulty = GJDifficulty::Normal;
        level21->m_creatorName = "RobTopGames";
        level21->m_requiredCoins = 0;
        level21->m_coins = 0;*/
    }
    if (lol == 37)
    {
       /* std::string dir = geode::Mod::get()->getResourcesDir().string();
        std::ifstream mt(dir + "/2008.txt");
        std::string mtext((std::istreambuf_iterator<char>(mt)), std::istreambuf_iterator<char>());*/

        level21 = GLM->getMainLevel(2008, true);
       /* level21->m_levelName = "Embers";
        level21->m_stars = 3;
        level21->m_levelType = GJLevelType::Local;
        level21->m_levelString = mtext;
        level21->m_audioTrack = 34;
        level21->m_difficulty = GJDifficulty::Normal;
        level21->m_creatorName = "RobTopGames";
        level21->m_requiredCoins = 0;
        level21->m_coins = 0;*/
    }
    if (lol == 38)
    {
      /*  std::string dir = geode::Mod::get()->getResourcesDir().string();
        std::ifstream mt(dir + "/2009.txt");
        std::string mtext((std::istreambuf_iterator<char>(mt)), std::istreambuf_iterator<char>());*/

        level21 = GLM->getMainLevel(2009, true);
        //level21->m_levelName = "Round 1";
        //level21->m_stars = 3;
        //level21->m_levelType = GJLevelType::Local;
        //level21->m_levelString = mtext;
        //level21->m_audioTrack = 35;
        //level21->m_difficulty = GJDifficulty::Normal;
        //level21->m_creatorName = "RobTopGames";
        //level21->m_requiredCoins = 0;
        //level21->m_coins = 0;
    }
    if (lol == 39)
    {
     /*   std::string dir = geode::Mod::get()->getResourcesDir().string();
        std::ifstream mt(dir + "/2010.txt");
        std::string mtext((std::istreambuf_iterator<char>(mt)), std::istreambuf_iterator<char>());*/

        level21 = GLM->getMainLevel(2010, true);
      /*  level21->m_levelName = "Monster Dance Off";
        level21->m_stars = 3;
        level21->m_levelType = GJLevelType::Local;
        level21->m_levelString = mtext;
        level21->m_audioTrack = 36;
        level21->m_difficulty = GJDifficulty::Normal;
        level21->m_creatorName = "RobTopGames";
        level21->m_requiredCoins = 0;
        level21->m_coins = 0;*/
    }

    /*std::cout << levellol << std::endl;*/

    sLOLwshow2(level21);
}






//void MeltdownSelectLevelLayer::updateColors() {
//    ccColor3B color2 = colors2[currentColorIndex2];
//    m_background->setColor(color2);
//    m_ground->updateGround01Color(color2);
//    m_ground->updateGround02Color(color2);
//}
//void MeltdownSelectLevelLayer::pageNumberForPosition(CCPoint point) {
//    log::info("scrollLayerMoved");
//
//    std::cout << "Works!" << std::endl;
//    ccColor3B color = getColorValue(m_level, m_level - 1, 12);
//    m_background->setColor(color);
//    ccColor3B Color1 = color;
//    Color1.r = color.r * 0.8;
//    Color1.g = color.g * 0.8;
//    Color1.b = color.b * 0.8;
//    m_ground->updateGround01Color(Color1);
//
//    ccColor3B Color2 = color;
//    Color2.r = color.r * 0.9;
//    Color2.g = color.g * 0.9;
//    Color2.b = color.b * 0.9;
//    m_ground->updateGround02Color(Color2);
//}