#pragma once

#include <Geode/Bindings.hpp>


namespace more {

class WorldSelectLayerDecomp : public cocos2d::CCLayer, public BoomScrollLayerDelegate, public DynamicScrollDelegate {
public:
    static WorldSelectLayerDecomp* create();
    static cocos2d::CCScene* scene();
    void instantPage(CCObject* sender, int a1);
private:
    bool init() override;
    virtual void keyBackClicked();
    void setupWorlds();

    void onPreva(cocos2d::CCObject* sender);
    void onNext(cocos2d::CCObject* sender);
    void onGarage(cocos2d::CCObject* sender);
    void onPlay(cocos2d::CCObject* sender);
    void onWorldLevel(cocos2d::CCObject* sender);
    void importSheet();
    void createIslands();
    void runParticle();
    void createStars(GJGameLevel* level, CCLayer* layer);
    void playStep2();
    void playStep3();
    void runScroll();
    cocos2d::CCNode* createBackground();
    cocos2d::CCNode* createSideArt();
    cocos2d::CCNode* createArrows();
    void onInfo(CCObject* sender);
    void show2(GJGameLevel* level212);
    /*void updatePageWithObject(CCObject* page, CCObject* object);*/
    void onClose(CCObject*);
    cocos2d::CCNode* m_background;
    BoomScrollLayer* m_sscrollLayer;
    cocos2d::CCArray* m_mainLevels2;
    GJGameLevel* level;
    int m_level;
    CCMenu* menu3;
};

} // namespace more


