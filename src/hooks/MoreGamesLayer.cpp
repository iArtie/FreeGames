
#include "MoreGamesLayer.hpp"
#include <Geode/Bindings.hpp>
#include "Geode/cocos/layers_scenes_transitions_nodes/CCTransition.h"
#include "MoreGamesCell.hpp"
#include "MoreGamesCell.cpp"
#include "../World/ownWorldSelectLayer.h"
//#include "../World/ownWorldSelectLayer.cpp"
#include "../SubZero/SubZeroSelectLayer.h"
#include "../Meltdown/MeltdownSelectLayer.h"
#include "../Meltdown/MeltdownSelectLayer.cpp"
#include "../extras/BetterMDPopup.hpp"
#include "../extras/BetterMDPopup.cpp"
//#include "SubZeroSelectLayer.cpp"

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


    auto discv = Mod::get()->getSavedValue<int>("disclaimervalue");

    if (discv != 2)
    {

        auto disclaimerPopup = BetterMDPopup::create(
            "DISCLAIMER",
            "1. If you have 164 coins or approximately, I recommend <cr>NOT COMPLETING THE LEVELS WITH THE COINS</c> since it probably <cy>won't let you save your data</c> later because you exceed <cl>the coins limit</c>.\n \n 2. If you have already passed the levels in the spinoffs games, <cg>your data should load without any problem</c>, only that the coins <cl>will not be reflected in the levels</c>.\n \n3. Is <cr>HIGHLY RECOMMENDED</c> after passing all the levels to <cy>save your data and reload your account</c>, since this way you do not keep the coins that <cl>the game does not want you to have</c>.",
            "OK",
            nullptr
        );

        disclaimerPopup->show();
        Mod::get()->setSavedValue("disclaimervalue",2);


    }
   
        
    auto* listView = ListView::create(m_games, 72.0f);
    m_listLayer->addChild(listView);
}

CCArray* MoreGamesLayer::getGames() {
    const CCSize cellSize = { 358.0f, 72.0f };
    CCArray* games = CCArray::create();

   /* setKeypadEnabled(true);*/
    auto game1 = MoreGamesCell::create({
           cellSize,
           "meltdownIcon_001.png"_spr,
           "GJ_md_001.png",
           this,
           menu_selector(MoreGamesLayer::onMeltdown)});

    auto gamebg1 = CCSprite::createWithSpriteFrameName("cell1.png"_spr);
    gamebg1->setPosition({ gamebg1->getPositionX() + 179, gamebg1->getPositionY() + 36 });
    gamebg1->setScale(4);
    game1->addChild(gamebg1,-1);
    auto game2 = MoreGamesCell::create({
            cellSize,
            "worldIcon_001.png"_spr,
            "gj_worldLogo_001.png",
            this,
            menu_selector(MoreGamesLayer::onCallback),
        });
    auto gamebg2 = CCSprite::createWithSpriteFrameName("cell3.png"_spr);
    gamebg2->setPosition({ gamebg2->getPositionX() + 179, gamebg2->getPositionY() + 36 });
    gamebg2->setScale(4);
    game2->addChild(gamebg2,-1);
    auto game3 = MoreGamesCell::create({
            cellSize,
            "subzeroIcon_001.png"_spr,
            "gj_subzeroLogo_001.png",
            this,
            menu_selector(MoreGamesLayer::onSubzero),
        });
    auto gamebg3= CCSprite::createWithSpriteFrameName("cell2.png"_spr);


    gamebg3->setPosition({ gamebg3->getPositionX() + 179, gamebg3->getPositionY()+ 36 });
    gamebg3->setScale(4);
    game3->addChild(gamebg3,-1);
    game1->setTag(40);
    game2->setTag(41);
    game3->setTag(42);

    games->addObject(game1);
    games->addObject(game2);
    games->addObject(game3);

    return games;
}

void MoreGamesLayer::onCallback(CCObject* sender) {
    CCScene* scene = ownWorldSelectLayer::scene(0);

#ifdef GEODE_IS_ANDROID

    scene = WorldSelectLayer::scene(0);

#endif
    CCTransitionFade* fade = CCTransitionFade::create(0.5f, scene);
    CCDirector::sharedDirector()->pushScene(fade);
    
}


void MoreGamesLayer::onMeltdown(CCObject* sender) {
    CCScene* scene = MeltdownSelectLayer::scene(0);
    CCTransitionFade* fade = CCTransitionFade::create(0.5f, scene);

    CCDirector::sharedDirector()->pushScene(fade);
}

void MoreGamesLayer::onSubzero(CCObject* sender) {
    CCScene* scene = SubZeroSelectLayer::scene(0);
    CCTransitionFade* fade = CCTransitionFade::create(0.5f, scene);
    CCDirector::sharedDirector()->pushScene(fade);

}

//void MoreGamesLayer::keyBackClicked() {
//    CCDirector::sharedDirector()->popSceneWithTransition(0.5F, PopTransition::kPopTransitionFade);
//}
//
//void MoreGamesLayer::onClose(CCObject*) {
//    keyBackClicked();
//}
} // namespace more
