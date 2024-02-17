#pragma once
#include <Geode/Geode.hpp>
//#include "../src/NewLevelSelectLayer.cpp"


class NewLevelSelectLayer : public cocos2d::CCLayer, public BoomScrollLayerDelegate, public DynamicScrollDelegate {
protected:
    GJGroundLayer* m_ground;
    cocos2d::CCSprite* m_background;
    cocos2d::CCArray* m_mainLevels;
    cocos2d::CCArray* m_levelPages;
    BoomScrollLayer* m_scrollLayer;
    int m_level;
public:
    static NewLevelSelectLayer* create(int page);
    static cocos2d::CCScene* scene(int page);
    bool init(int page);
    void onClose(CCObject*);
    void keyBackClicked();
    void updateColors();
    void updatePageWithObject(CCObject* page, CCObject* object) override;
    void scrollLayerMoved(cocos2d::CCPoint) override;
    void onSoundtracks(CCObject*);
    void onNext(CCObject*);
    void onPrev(CCObject*);
    cocos2d::ccColor3B colorForPage(int page);
    cocos2d::ccColor3B getColorValue(int level1, int level2, float a3);
}; 