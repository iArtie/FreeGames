//
//  CCLightFlash.h
//  SkullExplodeTest
//
//  Created by Robert Topala on 2/28/12.
//  Copyright 2012 RobTop Games. All rights reserved.
//

#ifndef __CC_LIGHT_FLASH__ 
#define __CC_LIGHT_FLASH__ 
#include "cocos2d.h" 
USING_NS_CC;

#define flashStartDelay     0.8f
#define flashFadeInTime     0.3f
#define flashMidDelay       0.5f
#define flashFadeOutTime    1.5f

class CCLightFlash : public cocos2d::CCNode {
public:
    static CCLightFlash* create(CCPoint origin, ccColor3B color);
    bool init(CCPoint origin, ccColor3B color);

    void showFlash();
    void removeLights();

    void cleanupFlash();

    ~CCLightFlash();

public:

    CCArray* container_;

    CCLayerColor* flashLayer_;

    CC_SYNTHESIZE(CCNode*, flashP_, FlashP);
    CC_SYNTHESIZE(int, flashZ_, FlashZ);
};

class CCLightStrip : public cocos2d::CCNode {
public:
    static CCLightStrip* create(float bW, float tW, float tH, float dur, float delay);
    bool init(float bW, float tW, float tH, float dur, float delay);

    void draw();

    void updateTweenAction(float value, const char* key);

public:

    float bW_;
    float tW_;
    float tH_;
    float dur_;

    CC_SYNTHESIZE(ccColor3B, color_, Color);
    CC_SYNTHESIZE(float, opacity_, Opacity);
    CC_SYNTHESIZE(float, width_, Width);
    CC_SYNTHESIZE(float, height_, Height);
};

#endif