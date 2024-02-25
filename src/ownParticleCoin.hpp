#ifndef OWNPARTICLECOIN_H
#define OWNPARTICLECOIN_H

#include <Geode/Geode.hpp>

using namespace geode::prelude;

class ownParticleCoin {
public:

    static CCParticleSystemQuad* createStarParticles(int maxParticles) {

        auto dict = CCDictionary::createWithContentsOfFileThreadSafe("dragEffect.plist");

        dict->setObject(CCString::create("0"), "emitterType");
        dict->setObject(CCString::create("0.05"), "duration");
        dict->setObject(CCString::createWithFormat("%i", maxParticles), "maxParticles");
        dict->setObject(CCString::create("0.6"), "particleLifespan");
        dict->setObject(CCString::create("0"), "angle");
        dict->setObject(CCString::create("360"), "angleVariance");
        dict->setObject(CCString::create("100"), "maxRadius");
        dict->setObject(CCString::create("0"), "minRadius");
        dict->setObject(CCString::create("310.619"), "sourcePositionx");
        dict->setObject(CCString::create("223.657"), "sourcePositiony");
        dict->setObject(CCString::create("10"), "sourcePositionVariancex");
        dict->setObject(CCString::create("10"), "sourcePositionVariancey");
        dict->setObject(CCString::create("5"), "startParticleSize");
        dict->setObject(CCString::create("2"), "finishParticleSize");
        dict->setObject(CCString::create("2"), "startParticleSizeVariance");
        dict->setObject(CCString::create("1"), "startColorRed");
        dict->setObject(CCString::create("1"), "startColorGreen");
        dict->setObject(CCString::create("0"), "startColorBlue");
        dict->setObject(CCString::create("1"), "startColorAlpha");
        dict->setObject(CCString::create("0"), "startColorVarianceRed");
        dict->setObject(CCString::create("0"), "startColorVarianceBlue");
        dict->setObject(CCString::create("0"), "startColorVarianceGreen");
        dict->setObject(CCString::create("0"), "startColorVarianceAlpha");
        dict->setObject(CCString::create("1"), "finishColorRed");
        dict->setObject(CCString::create("0"), "finishColorGreen");
        dict->setObject(CCString::create("0"), "finishColorBlue");
        dict->setObject(CCString::create("0"), "finishColorAlpha");
        dict->setObject(CCString::create("0"), "finishColorVarianceRed");
        dict->setObject(CCString::create("0"), "finishColorVarianceBlue");
        dict->setObject(CCString::create("0"), "finishColorVarianceGreen");
        dict->setObject(CCString::create("0"), "finishColorVarianceAlpha");

        auto p = CCParticleSystemQuad::create();
        p->initWithDictionary(dict, "square.png");

        return p;
    }
};

#endif