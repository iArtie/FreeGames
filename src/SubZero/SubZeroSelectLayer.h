#ifndef SUBZERO_SELECT_LAYER_H
#define SUBZERO_SELECT_LAYER_H

#include "cocos2d.h"

//
//class SubZeroSelectLayer : public cocos2d::CCLayer, public BoomScrollLayerDelegate, public DynamicScrollDelegate

class SubZeroSelectLayer : public LevelSelectLayer

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
    bool init(int);
    static SubZeroSelectLayer* create(int);
    static cocos2d::CCScene* scene(int);
    
};

#endif // SUBZERO_SELECT_LAYER_H
