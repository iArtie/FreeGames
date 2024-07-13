#ifndef OWN_LEVEL_SELECT_LAYER_H
#define OWN_LEVEL_SELECT_LAYER_H

#include "cocos2d.h"


class ownLevelSelectLayer : public cocos2d::CCLayer, public BoomScrollLayerDelegate, public DynamicScrollDelegate
{
public:
    float m_fWindowWidth;
    cocos2d::CCSprite* m_pBackground;
    GJGroundLayer* m_pGround;
    BoomScrollLayer* m_pBoomScrollLayer;
    cocos2d::CCArray* mainLevels;
    int m_nLevel;
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
    void keyBackClicked();
    void scollLayerMoved(cocos2d::CCPoint);
    void keyDown(int);
    static ownLevelSelectLayer* create(int);
    static cocos2d::CCScene* scene(int);
    void updatePageWithObject(CCObject*, CCObject*) override;
};

#endif // OWN_LEVEL_SELECT_LAYER_H
