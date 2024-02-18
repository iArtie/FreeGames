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

    addChild(node,2);
    importSheet();



    m_background = createBackground();
    CCNode* sideArt = createSideArt();
    CCNode* arrows = createArrows();
   
    addChild(m_background, -1);
    addChild(sideArt);
    addChild(arrows, 5);

    return true;
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
    background->setColor({ 0x33, 0x33, 0x33 });

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

CCNode* WorldSelectLayerDecomp::createArrows() {
    CCMenu* menu = CCMenu::create();

    /// @todo Support controller buttons.

    CCSprite* leftSprite = CCSprite::createWithSpriteFrameName(
        "navArrowBtn_001.png"
    );
    leftSprite->setScale(0.6f);
    leftSprite->setFlipX(true);

    auto m_leftArrow = CCMenuItemSpriteExtra::create(
        leftSprite,
        nullptr,
        this,
        menu_selector(WorldSelectLayerDecomp::onClose)
    );
    menu->addChild(m_leftArrow);

    return menu;
}

void WorldSelectLayerDecomp::keyBackClicked() {
    CCDirector::sharedDirector()->popSceneWithTransition(0.5F, PopTransition::kPopTransitionFade);
}

void WorldSelectLayerDecomp::onClose(CCObject*) {
    keyBackClicked();
}
void WorldSelectLayerDecomp::onPrev(CCObject* sender) {}
void WorldSelectLayerDecomp::onNext(CCObject* sender) {}

} // namespace more