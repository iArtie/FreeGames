#ifndef MELTDOWN_SELECT_LAYER_H
#define MELTDOWN_SELECT_LAYER_H

#include "cocos2d.h"

//
//class MeltdownSelectLayer : public cocos2d::CCLayer, public BoomScrollLayerDelegate, public DynamicScrollDelegate

class MeltdownSelectLayer : public LevelSelectLayer
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
    cocos2d::CCSprite* m_secretDoor;
public:
    bool init(int);
    static MeltdownSelectLayer* create(int);
    static cocos2d::CCScene* scene(int);
    
};

#endif // MELTDOWN_SELECT_LAYER_H
