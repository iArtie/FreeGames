#ifndef SUBZERO_SELECT_LAYER_H
#define SUBZERO_SELECT_LAYER_H

#include "cocos2d.h"


class SubZeroSelectLayer : public cocos2d::CCLayer, public BoomScrollLayerDelegate, public DynamicScrollDelegate
{
public:
    float m_fWindowWidth;
    cocos2d::CCSprite* m_pBackground;
    GJGroundLayer* m_pGround;
    BoomScrollLayer* m_pBoomScrollLayer;
    cocos2d::CCArray* mainLevels = nullptr;
    cocos2d::CCArray* levelPages = nullptr;
    int m_nLevel = 0;
    bool m_bSecretMenuCoin;

public:
    cocos2d::ccColor3B colorForPage(int);
    cocos2d::ccColor3B getColorValue(int, int, float);
    bool init(int);
    bool tryShowAd();
    void onPrev(cocos2d::CCObject*);
    void onNext(cocos2d::CCObject*);
    void onDownload(cocos2d::CCObject*);
    void onInfo(cocos2d::CCObject*);
    void onBack(cocos2d::CCObject*);
    void updatePageWithObject(CCObject*, CCObject*) override;
    void keyBackClicked();
    void scrollLayerMoved(cocos2d::CCPoint) override;
    void keyDown(int);
    static SubZeroSelectLayer* create(int);
    static cocos2d::CCScene* scene(int);
    
};

#endif // SUBZERO_SELECT_LAYER_H
