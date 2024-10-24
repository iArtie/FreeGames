//
//  CCLightStrip.m
//  SkullExplodeTest
//
//  Created by Robert Topala on 2/28/12.
//  Copyright 2012 RobTop Games. All rights reserved.
//

#include "CCLightFlash.h"
#include "MathHelper.h"

// Implementation CCLightFlash

STATIC_CONSTRUCTOR2(CCLightFlash, (CCPoint origin, ccColor3B color), (origin, color))

bool CCLightFlash::init(CCPoint origin, ccColor3B color)
{
    container_ = CCArray::create();
    container_->retain();

    for (int i = 0; i < 7; i++) {
        CCLightStrip* light = CCLightStrip::create(1, 10 + CCRANDOM_0_1() * 20, 480, 0.15f + CCRANDOM_MINUS1_1() * 0.1f, i * 0.1f + CCRANDOM_0_1() * 0.1f);
        this->addChild(light, 1);
        light->setPosition(origin);
        light->setRotation(CCRANDOM_0_1() * 360);
        light->setOpacity(randRange(150, 255));
        light->setColor(color);
        container_->addObject(light);
    }

    CCDelayTime* delay = CCDelayTime::create(flashStartDelay);
    CCCallFunc* callfunc = CCCallFunc::create(this, callfunc_selector(CCLightFlash::showFlash));
    CCFiniteTimeAction* seq = CCSequence::create(delay, callfunc, NULL);
    this->runAction(seq);

    return true;
}

void CCLightFlash::showFlash()
{
    if (!flashP_) flashP_ = this;

    flashLayer_ = CCLayerColor::create(ccc4(255, 255, 255, 0));
    flashLayer_->setBlendFunc((ccBlendFunc) { GL_SRC_ALPHA, GL_ONE });
    flashP_->addChild(flashLayer_, flashZ_);

    CCFadeIn* fadeIn = CCFadeIn::create(flashFadeInTime);
    fadeIn = (CCFadeIn*)CCEaseIn::create(fadeIn, 2.0f);
    CCCallFunc* callfunc = CCCallFunc::create(this, callfunc_selector(CCLightFlash::removeLights));
    CCDelayTime* delay = CCDelayTime::create(flashMidDelay);
    CCFadeOut* fadeOut = CCFadeOut::create(flashFadeOutTime);
    fadeOut = (CCFadeOut*)CCEaseInOut::create(fadeOut, 2.0f);

    CCCallFunc* remove = CCCallFunc::create(this, callfunc_selector(CCLightFlash::cleanupFlash));

    CCFiniteTimeAction* seq = CCSequence::create(fadeIn, callfunc, delay, fadeOut, remove, NULL);
    flashLayer_->runAction(seq);
}

void CCLightFlash::removeLights()
{
    for (int i = 0; i < container_->count(); i++) {
        ((CCNode*)container_->objectAtIndex(i))->removeFromParentAndCleanup(true);
    }
}

void CCLightFlash::cleanupFlash()
{
    flashLayer_->removeFromParentAndCleanup(true);
    this->removeFromParentAndCleanup(true);
}

// on "dealloc" you need to release all your retained objects
CCLightFlash::~CCLightFlash()
{
    CC_SAFE_RELEASE(container_);
}

// Implementation CCLightStrip

STATIC_CONSTRUCTOR2(CCLightStrip, (float bW, float tW, float tH, float dur, float delay), (bW, tW, tH, dur, delay))

bool CCLightStrip::init(float bW, float tW, float tH, float dur, float delay)
{
    bW_ = bW;
    tW_ = tW;
    tH_ = tH;
    dur_ = dur;

    width_ = bW;
    height_ = 1.0f;

    opacity_ = 255;

    this->setVisible(false);

    // Create the actions
    CCDelayTime* delayAction = CCDelayTime::create(delay);

    CCShow* show = CCShow::create();

    CCActionTween* hAction = CCActionTween::create(dur, "height", height_, tH);
    hAction = (CCActionTween*)CCEaseOut::create(hAction, 2.0f);
    CCActionTween* wAction = CCActionTween::create(dur, "width", width_, tW_);
    wAction = (CCActionTween*)CCEaseOut::create(wAction, 2.0f);

    CCFiniteTimeAction* spawn = CCSpawn::create(hAction, wAction, NULL);

    CCFiniteTimeAction* seq = CCSequence::create(delayAction, show, spawn, NULL);

    AManager->addAction(seq, this, false);

    return true;
}

void CCLightStrip::draw()
{
    if (!this->isVisible()) return;

    glBlendFunc(GL_SRC_ALPHA, GL_ONE);

    ccDrawColor4B(color_.r, color_.g, color_.b, opacity_);

    float bW = (bW_ + (width_ - bW_) / 4.0f);

    float width = (width_);
    float height = (height_);

    CCPoint vertices2[] = { ccp(-bW / 2.0f,0), ccp(bW / 2.0f,0), ccp(width / 2.0f,height), ccp(-width / 2.0f,height) };
    ccColor4F col = ccc4FFromccc3B(color_);
    col.a = opacity_ / 255.0f;

    ccDrawSolidPoly(vertices2, 4, col);

    glBlendFunc(CC_BLEND_SRC, CC_BLEND_DST);
}

void CCLightStrip::updateTweenAction(float value, const char* key)
{
    if (stringEqualToString(key, "height")) height_ = value;
    else if (stringEqualToString(key, "width")) width_ = value;
}