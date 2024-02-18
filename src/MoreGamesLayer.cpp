
#include "MoreGamesLayer.hpp"
#include <Geode/Bindings.hpp>
#include "Geode/cocos/layers_scenes_transitions_nodes/CCTransition.h"
#include "MoreGamesCell.hpp"
#include "MoreGamesCell.cpp"
#include "WorldSelectLayerDecomp.hpp"
#include "WorldSelectLayerDecomp.cpp"
#include "MeltdownSelectLevelLayer.h"
#include "../src/NewLevelSelectLayer.h"



using namespace geode::prelude;

namespace more {

MoreGamesLayer* MoreGamesLayer::create() {
    auto* ret = new MoreGamesLayer();

    if (ret && ret->init("More Games")) {
        ret->autorelease();   
    } else {
        CC_SAFE_DELETE(ret);
    }

    return ret;
}

void MoreGamesLayer::customSetup() {
    m_games = getGames();
    m_games->retain();

    auto* listView = ListView::create(m_games, 60.0f);
    m_listLayer->addChild(listView);
}

CCArray* MoreGamesLayer::getGames() {
    const CCSize cellSize = { 358.0f, 60.0f };
    CCArray* games = CCArray::create();


    auto game1 = MoreGamesCell::create({
           cellSize,
           "meltdownIcon_001.png"_spr,
           "GJ_md_001.png",
           this,
           menu_selector(MoreGamesLayer::onMeltdown)});
    auto game2 = MoreGamesCell::create({
            cellSize,
            "worldIcon_001.png"_spr,
            "gj_worldLogo_001.png",
            this,
            menu_selector(MoreGamesLayer::onCallback),
        });

    auto game3 = MoreGamesCell::create({
            cellSize,
            "subzeroIcon_001.png"_spr,
            "gj_subzeroLogo_001.png",
            this,
            menu_selector(MoreGamesLayer::onSubzero),
        });

    game1->setTag(40);
    game2->setTag(41);
    game3->setTag(42);

    games->addObject(game1);
    games->addObject(game2);
    games->addObject(game3);

    return games;
}

void MoreGamesLayer::onCallback(CCObject* sender) {
    CCScene* scene = WorldSelectLayerDecomp::scene();
    CCTransitionFade* fade = CCTransitionFade::create(0.5f, scene);

    CCDirector::sharedDirector()->pushScene(fade);
}


void MoreGamesLayer::onMeltdown(CCObject* sender) {
    CCScene* scene = MeltdownSelectLevelLayer::scene(0);
    Mod::get()->setSavedValue("onsubzero", 2);
    CCTransitionFade* fade = CCTransitionFade::create(0.5f, scene);

    CCDirector::sharedDirector()->pushScene(fade);
}

void MoreGamesLayer::onSubzero(CCObject* sender) {

    Mod::get()->setSavedValue("onsubzero", 1);
    CCScene* scene = NewLevelSelectLayer::scene(0);
    CCTransitionFade* fade = CCTransitionFade::create(0.5f, scene);

    CCDirector::sharedDirector()->pushScene(fade);
}
} // namespace more
