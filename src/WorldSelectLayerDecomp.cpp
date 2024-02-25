#include "WorldSelectLayerDecomp.hpp"
#include <Geode/Bindings.hpp>
#include "GJWorldNodeDecomp.hpp"
#include "Geode/cocos/menu_nodes/CCMenuItem.h"
#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>
#include <Geode/modify/GJGameLevel.hpp>
#include <Geode/Enums.hpp>
#include "NewLevelSelectLayer.h"
#include <iostream>
#include <windows.h>
#include "GJWorldNodeDecomp.cpp"
#include "GJWorldNodeDecomp.hpp"
#include "ownWorldLevelPage.hpp"
#include "WorldLevel.cpp"
#include "ownParticleCoin.hpp"
//#include "WorldLevelPage.cpp"

using namespace geode::prelude;

namespace more {

WorldSelectLayerDecomp* WorldSelectLayerDecomp::create() {
    WorldSelectLayerDecomp* ret = new WorldSelectLayerDecomp();

    if (ret && ret->init()) {
        ret->autorelease();
    } else {
        CC_SAFE_DELETE(ret);
    }

    return ret;
}

CCScene* WorldSelectLayerDecomp::scene() {
    CCScene* scene = CCScene::create();
    WorldSelectLayerDecomp* layer = WorldSelectLayerDecomp::create();

    scene->addChild(layer);
    return scene;
}

void WorldSelectLayerDecomp::importSheet() {
    auto* textureCache = CCTextureCache::sharedTextureCache();
    auto* spriteFrameCache = CCSpriteFrameCache::sharedSpriteFrameCache();

    textureCache->addImage("WorldSheet.png", false);
    spriteFrameCache->addSpriteFramesWithFile("WorldSheet.plist");
}

bool WorldSelectLayerDecomp::init() {
    if (!CCLayer::init()) {
        return false;
    }
    setKeypadEnabled(true);
    auto node = GJWorldNodeDecomp::create(1,this);
    auto node2 = GJWorldNodeDecomp::create(1, this);
    auto node3 = GJWorldNodeDecomp::create(1, this);

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
    

    CCSprite* backSpr = CCSprite::createWithSpriteFrameName("GJ_arrow_01_001.png");
    CCMenuItemSpriteExtra* backBtn = CCMenuItemSpriteExtra::create(backSpr, this, menu_selector(WorldSelectLayerDecomp::onClose));

    CCMenu* backMenu = CCMenu::create();
    backMenu->addChild(backBtn);
    addChild(backMenu, 1);

    backMenu->setPosition(ccp(CCDirector::sharedDirector()->getScreenLeft() + 25.f, CCDirector::sharedDirector()->getScreenTop() - 22.f));

    /*auto songinfo = SongInfoLayer::create(10);*/
  /*  SongInfoLayer::create(10)->show();*/
    /*addChild(songinfo);*/
    /*songinfo->show();*/
    CCSprite* Dashlands = CCSprite::createWithSpriteFrameName("worldLabel_01_001.png");

    CCSprite* ToxicFactory = CCSprite::createWithSpriteFrameName("worldLabel_02_001.png");

    auto CommingSoon = CCLabelBMFont::create("Coming Soon","bigFont.fnt");
    auto m_levelPages = CCArray::create();
    auto m_mainLevels = CCArray::create();


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

    auto director = CCDirector::sharedDirector();
    auto winSize = director->getWinSize();
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
    CCMenuItemSpriteExtra* level1Btn = CCMenuItemSpriteExtra::create(unkspr, this, menu_selector(WorldSelectLayerDecomp::onWorldLevel));

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
    CCMenuItemSpriteExtra* level2Btn = CCMenuItemSpriteExtra::create(unkspr1, this, menu_selector(WorldSelectLayerDecomp::onWorldLevel));

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

    CCMenuItemSpriteExtra* level3Btn = CCMenuItemSpriteExtra::create(unkspr2, this, menu_selector(WorldSelectLayerDecomp::onWorldLevel));

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
            CCCallFunc::create(this, callfunc_selector(WorldSelectLayerDecomp::runParticle)), // Utilizamos CCCallFunc para llamar a la función runParticle
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
            CCCallFunc::create(this, callfunc_selector(WorldSelectLayerDecomp::runParticle)), // Utilizamos CCCallFunc para llamar a la función runParticle
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
   
    CCMenuItemSpriteExtra* level4Btn = CCMenuItemSpriteExtra::create(unkspr3, this, menu_selector(WorldSelectLayerDecomp::onWorldLevel));

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
            CCCallFunc::create(this, callfunc_selector(WorldSelectLayerDecomp::runParticle)), // Utilizamos CCCallFunc para llamar a la función runParticle
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
    

    CCMenuItemSpriteExtra* level5Btn = CCMenuItemSpriteExtra::create(unkspr4, this, menu_selector(WorldSelectLayerDecomp::onWorldLevel));

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
            CCCallFunc::create(this, callfunc_selector(WorldSelectLayerDecomp::runParticle)), // Utilizamos CCCallFunc para llamar a la función runParticle
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
 

    CCMenuItemSpriteExtra* level6Btn = CCMenuItemSpriteExtra::create(unkspr5, this, menu_selector(WorldSelectLayerDecomp::onWorldLevel));

    level6Btn->setTag(35);
    level6Btn->setPosition(-189, -13);

    CCMenuItemSpriteExtra* level7Btn = CCMenuItemSpriteExtra::create(unkspr6, this, menu_selector(WorldSelectLayerDecomp::onWorldLevel));

    level7Btn->setTag(36);
    level7Btn->setPosition(-80, -30);
    level7Btn->setVisible(false);
    /*level2->setPosition({ -80, -30 });*/

    CCMenuItemSpriteExtra* level8Btn = CCMenuItemSpriteExtra::create(unkspr7, this, menu_selector(WorldSelectLayerDecomp::onWorldLevel));

    level8Btn->setTag(37);
    level8Btn->setPosition(-10, 10);
    level8Btn->setVisible(false);
   /* level3->setPosition({ -10, 10 });*/

    CCMenuItemSpriteExtra* level9Btn = CCMenuItemSpriteExtra::create(unksp8, this, menu_selector(WorldSelectLayerDecomp::onWorldLevel));

    level9Btn->setTag(38);
    level9Btn->setPosition(50, -25);
    level9Btn->setVisible(false);
   /* level4->setPosition({ 50, -25 });*/

    CCMenuItemSpriteExtra* level10Btn = CCMenuItemSpriteExtra::create(unkspr9, this, menu_selector(WorldSelectLayerDecomp::onWorldLevel));

    level10Btn->setTag(39);
    level10Btn->setPosition(155, -10);
    level10Btn->setVisible(false);
    /*level5->setPosition({ 155, -10 });*/


    //level 1 to level 2 animation
    if (wlevel5->m_normalPercent != 100)
    {
        Mod::get()->setSavedValue("worldlevel5complete", 0);
    }
    if (wlevel5->m_normalPercent == 100 && wlevel6->m_normalPercent == 0 && level5complete == 0)
    {
        //opacty
      
        level5Btn->setOpacity(0);

        level5Btn->setScale(1.5);
        level5Btn->setVisible(true);

        Mod::get()->setSavedValue("wlevelunlocked", 1);
        level6Btn->runAction(CCSequence::create(
            CCDelayTime::create(1.8),
            CCCallFunc::create(this, callfunc_selector(WorldSelectLayerDecomp::runParticle)), // Utilizamos CCCallFunc para llamar a la función runParticle
            CCFadeIn::create(0.1),
            CCEaseBounceOut::create(scaleWithBounce2),
            nullptr
        ));

        Mod::get()->setSavedValue("worldlevel5complete", 1);
    }
    else
    {
        if (wlevel4->m_normalPercent == 100)
        {
            level5Btn->setVisible(true);
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
    node2->setTag(22);


    node3->addChild(sprite3);
    node3->addChild(CommingSoon);
    node3->setTag(23);

    m_levelPages->addObject(node);
    m_levelPages->addObject(node2);
    m_levelPages->addObject(node3);
    sprite3->setColor(ccBLACK);
    sprite3->setOpacity(40);

    auto m_scrollLayer = BoomScrollLayer::create(m_levelPages, 0, true, nullptr, static_cast<DynamicScrollDelegate*>(this));

    m_sscrollLayer = m_scrollLayer;
   

    addChild(m_scrollLayer);

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
    //island 1 loop
    auto moveUp = CCMoveBy::create(1.0f, ccp(0, 1)); 
    auto moveDown = moveUp->reverse(); 

    auto moveUp1 = CCMoveBy::create(1.0f, ccp(0, 1));
    auto moveDown1 = moveUp->reverse();

    auto easeOutUp = CCEaseOut::create(moveUp, 1.0f);   
    auto easeInDown = CCEaseIn::create(moveDown, 1.0f); 

    auto easeOutDown = CCEaseOut::create(moveDown1, 1.0f);
    auto easeInUp = CCEaseIn::create(moveUp1, 1.0f); 
    auto moveSequence = CCSequence::create(easeOutUp, easeInDown, easeOutDown, easeInUp, nullptr);

    auto repeatAction = CCRepeatForever::create(moveSequence);

    //buttons loop
    
    auto moveUp21 = CCMoveBy::create(1.0f, ccp(0, 1));
    auto moveDown21 = moveUp21->reverse();

    auto moveUp121 = CCMoveBy::create(1.0f, ccp(0, 1));
    auto moveDown121 = moveUp121->reverse();

    auto easeOutUp21 = CCEaseOut::create(moveUp21, 1.0f);
    auto easeInDown21 = CCEaseIn::create(moveDown21, 1.0f);

    auto easeOutDown21 = CCEaseOut::create(moveDown121, 1.0f);
    auto easeInUp21 = CCEaseIn::create(moveUp1, 1.0f);
    auto moveSequence21 = CCSequence::create(easeOutUp21, easeInDown21, easeOutDown21, easeInUp21, nullptr);

    auto repeatAction21 = CCRepeatForever::create(moveSequence21);
    //island 2 loop
    auto moveUp2 = CCMoveBy::create(1.0f, ccp(0, 1)); 
    auto moveDown2 = moveUp2->reverse(); 

    auto moveUp12 = CCMoveBy::create(1.0f, ccp(0, 1)); 
    auto moveDown12 = moveUp2->reverse();

    auto easeOutUp2 = CCEaseOut::create(moveUp2, 1.0f); 
    auto easeInDown2 = CCEaseIn::create(moveDown2, 1.0f); 

    auto easeOutDown2 = CCEaseOut::create(moveDown12, 1.0f); 
    auto easeInUp2 = CCEaseIn::create(moveUp12, 1.0f); 
    auto moveSequence2 = CCSequence::create(easeOutUp2, easeInDown2, easeOutDown2, easeInUp2, nullptr);

    auto repeatAction2 = CCRepeatForever::create(moveSequence2);

   /* sprite->runAction(repeatAction);*/
    node->runAction(repeatAction21);

    sprite2->runAction(repeatAction2);

    
    auto pointer = (CCSpriteBatchNode*)m_scrollLayer->getChildren()->objectAtIndex(1);
  
    pointer->setPositionY(CCDirector::sharedDirector()->getScreenBottom() - 45);

    m_background = createBackground();
    CCSprite* background = (CCSprite*) m_background;
    background->setColor({ 0, 125, 255 });
    CCNode* sideArt = createSideArt();
    /*CCNode* arrows = createArrows();*/


   
    auto menu3 = CCMenu::create();
    menu3->setPosition(CCDirector::sharedDirector()->getScreenRight() - 50,
        CCDirector::sharedDirector()->getScreenTop() - 30);
    auto btn3 = CCSprite::createWithSpriteFrameName("garageRope_001.png");
    btn3->setScale(1);
    auto myButton3 = CCMenuItemSpriteExtra::create(
        btn3,
        this,
        menu_selector(WorldSelectLayerDecomp::onGarage));

   
    myButton3->setSizeMult(1);
    myButton3->m_animationType = MenuAnimationType{ 1 };
    myButton3->m_startPosition = btn3->getPosition();
    myButton3->m_destPosition = CCPoint{ 0, -5.f };
   /* myButton3->m_animationType = MenuAnimationType::Move;*/
    menu3->addChild(myButton3);
    addChild(menu3,2);


    addChild(m_background, -1);
    addChild(sideArt);
    /*addChild(arrows, 5);*/

    return true;
}

void WorldSelectLayerDecomp::runParticle()
{
    auto winSize = CCDirector::sharedDirector()->getWinSize();
    auto particles = CCParticleSystemQuad::create("coinPickupEffect.plist", 1);

    auto levelunlocked = Mod::get()->getSavedValue<int>("wlevelunlocked");
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
        particles->setPosition({ 203.5,130 });
        circlewave->setPositionY(particles->getPositionY() - 100);
        circlewave2->setPositionY(particles->getPositionY() - 100);
    }

    if (levelunlocked == 2)
    {
        particles->setPosition({ 274.5,170 });
        circlewave->setPositionY(particles->getPositionY() - 150);
        circlewave2->setPositionY(particles->getPositionY() - 150);
    }
    if (levelunlocked == 3)
    {
        particles->setPosition({ 332.5,136 });
        circlewave->setPositionY(particles->getPositionY() - 150);
        circlewave2->setPositionY(particles->getPositionY() - 150);
    }
    if (levelunlocked == 4)
    {
        particles->setPosition({ 439.5,153 });
        circlewave->setPositionY(particles->getPositionY() - 150);
        circlewave2->setPositionY(particles->getPositionY() - 150);
    }
    
 /*   circlewave->setPositionX(particles->getPositionX()+50);
    circlewave2->setPositionX(particles->getPositionX() + 50);*/
    
    /*CCCircleWave::create(0LL, 4.0, 40.0, 0.3, 1);*/
    //203.5 - 130

    particles->init();
    addChild(particles, 2);
    particles->addChild(circlewave, 2);
    particles->addChild(circlewave2, 2);
}
void WorldSelectLayerDecomp::createIslands() {
  /*  CCString* path = CCString::createWithFormat(
        "worldIsland_%02d.png",
        m_index
    );

    CCSprite* sprite = CCSprite::createWithSpriteFrameName(
        path->getCString()
    );

    return sprite;*/
}
void WorldSelectLayerDecomp::setupWorlds() {
    /// @todo
}

CCNode* WorldSelectLayerDecomp::createBackground() {
    CCSprite* background = CCSprite::create("GJ_gradientBG.png");

    const CCSize winSize = CCDirector::sharedDirector()->getWinSize();
    const CCSize contentSize = background->getContentSize();
    
    background->setAnchorPoint({ 0.0f, 0.0f });
    background->setScaleX((winSize.width + 10.0f) / contentSize.width);
    background->setScaleY((winSize.height + 10.0f) / contentSize.height);
    background->setPosition({ -5.0f, -5.0f });
   

    return background;
}

CCNode* WorldSelectLayerDecomp::createSideArt() {
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

CCNode* WorldSelectLayerDecomp::createArrows() {
    CCMenu* btnMenu = CCMenu::create();
   
    auto director = CCDirector::sharedDirector();
    auto winSize = director->getWinSize();
    CCSprite* leftSpr = CCSprite::createWithSpriteFrameName("navArrowBtn_001.png");
    leftSpr->setFlipX(true);

    CCMenuItemSpriteExtra* leftBtn = CCMenuItemSpriteExtra::create(leftSpr, this, menu_selector(LevelInfoLayer::onGarage));
    btnMenu->addChild(leftBtn);


    leftBtn->setPosition(btnMenu->convertToNodeSpace(ccp(director->getScreenLeft() + 25.f, winSize.height / 2)));
    leftBtn->setScale(0.7);


    CCSprite* rightSpr = CCSprite::createWithSpriteFrameName("navArrowBtn_001.png");

    CCMenuItemSpriteExtra* rightBtn = CCMenuItemSpriteExtra::create(rightSpr, this, menu_selector(WorldSelectLayerDecomp::onNext));
    
    btnMenu->addChild(rightBtn);

    rightBtn->setPosition(btnMenu->convertToNodeSpace(ccp(director->getScreenRight() - 25.f, winSize.height / 2)));
    rightBtn->setScale(0.7);

    return btnMenu;
}

void WorldSelectLayerDecomp::keyBackClicked() {
    auto back = Mod::get()->getSavedValue<int>("onsubzero");
    back = 10;
    Mod::get()->setSavedValue("onsubzero", back);
    CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(0.5, MenuLayer::scene(false)));
}

void WorldSelectLayerDecomp::onWorldLevel(CCObject* sender) {

    CCMenuItemSpriteExtra* button = (CCMenuItemSpriteExtra*)sender;
    auto GLM = GameLevelManager::sharedState();
    auto level1popup = WorldLevelPopup::create("");
    auto Layer = (CCLayer*)level1popup->getChildren()->objectAtIndex(0);
    auto m_buttonMenu = CCMenu::create();
    auto corner1 = CCSprite::createWithSpriteFrameName("dailyLevelCorner_001.png");
    auto director = CCDirector::sharedDirector();
    auto winSize = director->getWinSize();
    corner1->setPosition({ winSize/2});
    corner1->setRotation(180);
    Layer->addChild(corner1);

    auto corner2 = CCSprite::createWithSpriteFrameName("dailyLevelCorner_001.png");
    corner2->setPosition({ winSize / 2 });
    corner2->setRotation(90);
    Layer->addChild(corner2);

    auto corner3 = CCSprite::createWithSpriteFrameName("dailyLevelCorner_001.png");
    corner3->setPosition({ winSize / 2 });
    corner3->setRotation(270);
    Layer->addChild(corner3);

    auto corner4 = CCSprite::createWithSpriteFrameName("dailyLevelCorner_001.png");
    corner4->setPosition({ winSize / 2 });
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
    Layer->addChild(corner4);

    Layer->addChild(m_buttonMenu);

    
    auto playBtn = CCMenuItemSpriteExtra::create(CCSprite::createWithSpriteFrameName("GJ_playBtn2_001.png"), this, menu_selector(WorldSelectLayerDecomp::onPlay));
    playBtn->setPositionY(40);
    m_buttonMenu->addChild(playBtn);
    if(button->getTag() == 30)
    { 
        std::ifstream mt("./Resources/levels/2001.txt");
        std::string mtext((std::istreambuf_iterator<char>(mt)), std::istreambuf_iterator<char>());
        level = GLM->getMainLevel(2001, false);
        level->m_levelName = "Payload";
        level->m_stars = 2;
        level->m_levelString = mtext;
        level->m_audioTrack = 27;
        level->m_difficulty = GJDifficulty::Easy;
        level->m_creatorName = "RobTopGames";
        level->m_requiredCoins = 0;
        level->m_coins = 0;
    }
    if (button->getTag() == 31)
    {
        std::ifstream mt("./Resources/levels/2002.txt");
        std::string mtext((std::istreambuf_iterator<char>(mt)), std::istreambuf_iterator<char>());
        level = GLM->getMainLevel(2002, false);
        level->m_levelName = "Beast Mode";
        level->m_stars = 2;
        level->m_levelString = mtext;
        level->m_audioTrack = 28;
        level->m_difficulty = GJDifficulty::Easy;
        level->m_creatorName = "RobTopGames";
        level->m_requiredCoins = 0;
        level->m_coins = 0;
    }
    if (button->getTag() == 32)
    {
        std::ifstream mt("./Resources/levels/2003.txt");
        std::string mtext((std::istreambuf_iterator<char>(mt)), std::istreambuf_iterator<char>());
        level = GLM->getMainLevel(2003, false);
        level->m_levelName = "Machina";
        level->m_stars = 3;
        level->m_levelString = mtext;
        level->m_audioTrack = 29;
        level->m_difficulty = GJDifficulty::Normal;
        level->m_creatorName = "RobTopGames";
        level->m_requiredCoins = 0;
        level->m_coins = 0;
    }
    if (button->getTag() == 33)
    {
        std::ifstream mt("./Resources/levels/2004.txt");
        std::string mtext((std::istreambuf_iterator<char>(mt)), std::istreambuf_iterator<char>());
        level = GLM->getMainLevel(2004, false);
        level->m_levelName = "Years";
        level->m_stars = 3;
        level->m_levelString = mtext;
        level->m_audioTrack = 30;
        level->m_difficulty = GJDifficulty::Normal;
        level->m_creatorName = "RobTopGames";
        level->m_requiredCoins = 0;
        level->m_coins = 0;
    }
    if (button->getTag() == 34)
    {
        std::ifstream mt("./Resources/levels/2005.txt");
        std::string mtext((std::istreambuf_iterator<char>(mt)), std::istreambuf_iterator<char>());
        level = GLM->getMainLevel(2005, false);
        level->m_levelName = "Frontlines";
        level->m_stars = 3;
        level->m_levelString = mtext;
        level->m_audioTrack = 31;
        level->m_difficulty = GJDifficulty::Normal;
        level->m_creatorName = "RobTopGames";
        level->m_requiredCoins = 0;
        level->m_coins = 0;
    }
    if (button->getTag() == 35)
    {
        std::ifstream mt("./Resources/levels/2006.txt");
        std::string mtext((std::istreambuf_iterator<char>(mt)), std::istreambuf_iterator<char>());
        level = GLM->getMainLevel(2006, false);
        level->m_levelName = "Space Pirates";
        level->m_stars = 3;
        level->m_levelString = mtext;
        level->m_audioTrack = 32;
        level->m_difficulty = GJDifficulty::Normal;
        level->m_creatorName = "RobTopGames";
        level->m_requiredCoins = 0;
        level->m_coins = 0;
    }
    if (button->getTag() == 36)
    {
        std::ifstream mt("./Resources/levels/2007.txt");
        std::string mtext((std::istreambuf_iterator<char>(mt)), std::istreambuf_iterator<char>());
        level = GLM->getMainLevel(2007, false);
        level->m_levelName = "Striker";
        level->m_stars = 3;
        level->m_levelString = mtext;
        level->m_audioTrack = 33;
        level->m_difficulty = GJDifficulty::Normal;
        level->m_creatorName = "RobTopGames";
        level->m_requiredCoins = 0;
        level->m_coins = 0;
    }
    if (button->getTag() == 37)
    {
        std::ifstream mt("./Resources/levels/2008.txt");
        std::string mtext((std::istreambuf_iterator<char>(mt)), std::istreambuf_iterator<char>());
        level = GLM->getMainLevel(2008, false);
        level->m_levelName = "Embers";
        level->m_stars = 3;
        level->m_levelString = mtext;
        level->m_audioTrack = 34;
        level->m_difficulty = GJDifficulty::Normal;
        level->m_creatorName = "RobTopGames";
        level->m_requiredCoins = 0;
        level->m_coins = 0;
    }
    if (button->getTag() == 38)
    {
        std::ifstream mt("./Resources/levels/2009.txt");
        std::string mtext((std::istreambuf_iterator<char>(mt)), std::istreambuf_iterator<char>());
        level = GLM->getMainLevel(2009, false);
        level->m_levelName = "Round 1";
        level->m_stars = 2;
        level->m_levelString = mtext;
        level->m_audioTrack = 35;
        level->m_difficulty = GJDifficulty::Normal;
        level->m_creatorName = "RobTopGames";
        level->m_requiredCoins = 0;
        level->m_coins = 0;
    }
    if (button->getTag() == 39)
    {
        std::ifstream mt("./Resources/levels/2010.txt");
        std::string mtext((std::istreambuf_iterator<char>(mt)), std::istreambuf_iterator<char>());
        level = GLM->getMainLevel(2010, false);
        level->m_levelName = "Monster Dance Off";
        level->m_stars = 3;
        level->m_levelString = mtext;
        level->m_audioTrack = 36;
        level->m_difficulty = GJDifficulty::Normal;
        level->m_creatorName = "RobTopGames";
        level->m_requiredCoins = 0;
        level->m_coins = 0;
    }

    std::string title = level->m_levelName;

    const char* font = "goldFont.fnt";
    float scale = .7f;
    float offset = 80.f;
    auto m_title = cocos2d::CCLabelBMFont::create(title.c_str(), font);
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
    bar->setPosition(winSize / 2);
    bar->setPositionX(bar->getPositionX());
    bar->setPositionY(bar->getPositionY() - 153.5);
    bar->setColor({ 0, 0, 0 });
    bar->setOpacity(125);
    bar->setZOrder(1);
    bar->setID("progress-bar-normal"_spr);

    Layer->addChild(bar);

    float size = (float)completedVector.size() / (float)levelVector.size();

    auto status = CCLabelBMFont::create(fmt::format("{}%", completedVector.size(), levelVector.size()).c_str(), "bigFont.fnt");
    status->setPosition({bar->getPosition()});
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
    pbar->setPosition({ winSize / 2 });

    pbar->setPositionX( pbar->getPositionX());
    pbar->setPositionY(pbar->getPositionY() - 150.5);
    pbar->setColor({ 0, 0, 0 });
    pbar->setOpacity(125);
    pbar->setZOrder(1);
    pbar->setID("progress-bar"_spr);

    Layer->addChild(pbar);

    float psize = (float)pcompletedVector.size() / (float)plevelVector.size();

    auto pstatus = CCLabelBMFont::create(fmt::format("{}%", pcompletedVector.size(), plevelVector.size()).c_str(), "bigFont.fnt");
    pstatus->setPosition({ pbar->getPosition()});
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
    m_title->setPosition({ winSize / 2 });
    m_title->setPositionY(m_title->getPositionY() + 110);
    Layer->addChild(m_title);

    createStars(level, Layer);
    /* m_title->setPositionY()*/
  /*  level1popup->addChild(m_title);*/
   /* level1popup->setContentSize({290,200});*/
    level1popup->show();

}

void WorldSelectLayerDecomp::instantPage(CCObject* sender, int a1) {

    if (a1 == 2)
    {
        auto GM = GameManager::sharedState();
        CCSprite* BG = (CCSprite*)m_background;
        BG->setColor(GM->colorForIdx(6));
        auto extendedLayer = (ExtendedLayer*)m_sscrollLayer->getChildren()->objectAtIndex(0);

       /* extendedLayer->setPositionX(-569);*/
        m_sscrollLayer->instantMoveToPage(1);
    }
    
    /*m_sscrollLayer->instantMoveToPage(a1);*/
    //m_sscrollLayer->moveToPage(a1);
  /*  currentColorIndex = (currentColorIndex - 1 + numColors) % numColors;*/
    /*  updateColors();*/
      //scrollLayerMoved({0, 0});
}
void WorldSelectLayerDecomp::onPlay(CCObject* sender) {
    auto GLM = GameLevelManager::sharedState();
    auto playLayer = PlayLayer::create(level, false, false);
    FMODAudioEngine::sharedEngine()->playEffect("playSound_01.ogg");
    std::cout << "level string:" << level->m_levelString.c_str() << std::endl;
    CCScene* scene = CCScene::create();
  
    scene->addChild(playLayer);
  
    CCTransitionFade* fade = CCTransitionFade::create(0.5f, scene);
  
    /*playLayer->startGameDelayed();*/
    CCDirector::sharedDirector()->pushScene(fade);
}

//void WorldSelectLayerDecomp::playStep2()
//{
//    FMODAudioEngine::sharedEngine()->playMusic(level->getAudioFileName(), 0, 1);
//
//    cocos2d::CCDelayTime* delay = cocos2d::CCDelayTime::create(0.0f);
//    cocos2d::CCCallFunc* func = cocos2d::CCCallFunc::create(this, WorldSelectLayerDecomp::playStep3);
//    runAction(cocos2d::CCSequence::create(delay, func, 0));
//}

//void WorldSelectLayerDecomp::playStep3()
//{
//   /* GameManager::sharedState()->scene = 9;*/
//    level->m_levelString = LocalLevelManager::sharedState()->getMainLevelString(1001);
//}
void WorldSelectLayerDecomp::onGarage(CCObject* sender) {

    auto transition = CCTransitionMoveInT::create(0.5f, GJGarageLayer::scene());

    // Establecer un valor guardado
    Mod::get()->setSavedValue("onsubzero", 10);

    // Reemplazar la escena actual con la nueva escena usando la transición
    CCDirector::sharedDirector()->replaceScene(transition);
 
}
void WorldSelectLayerDecomp::createStars(GJGameLevel* level, CCLayer* layer) {
    int totalstars = level->m_stars;
    float screenWidth = CCDirector::sharedDirector()->getWinSize().width;

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


    float totalWidth = totalstars * starWidth + (totalstars - 1) * spaceBetweenStars;


    float startX = (screenWidth - totalWidth) / 2;

    float startY = (winSize.height/2)-113;

    float currentX = startX;


    for (int i = 0; i < totalstars; ++i) {
        auto star = CCSprite::createWithSpriteFrameName(starspr.c_str());

        
        star->setPosition({ currentX, startY });
        star->setScale(0.65);

       
        layer->addChild(star);

        
        currentX += starWidth + spaceBetweenStars; 
    }
}

void WorldSelectLayerDecomp::onClose(CCObject*) {
    keyBackClicked();
}
void WorldSelectLayerDecomp::onPreva(CCObject* sender) {

    auto pointer = Mod::get()->getSavedValue<int>("worldpages");
    /*Mod::get()->setSavedValue("worldpages", );*/
    /*m_level = 0;*/

    std::cout << pointer << std::endl;
    if (pointer < 3) {
        pointer = pointer - 1;
        m_sscrollLayer->moveToPage(pointer);
    }
    std::cout << m_level << std::endl;
}
void WorldSelectLayerDecomp::onNext(CCObject* sender) {

    m_level = m_level+ 1;
    m_sscrollLayer->moveToPage(m_level);
}

} // namespace more