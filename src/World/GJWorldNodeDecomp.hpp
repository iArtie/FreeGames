#pragma once

#include <Geode/Bindings.hpp>
#include "ownWorldSelectLayer.h"

namespace more {

class GJWorldNodeDecomp : public cocos2d::CCNode {
public:
    static GJWorldNodeDecomp* create(
        int index,
        ownWorldSelectLayer* worldSelectLayer
    );
    
private:
    bool init(
        int index,
        ownWorldSelectLayer* worldSelectlayer
    );

    cocos2d::CCSprite* createIsland();

    int m_index;
    ownWorldSelectLayer* m_worldSelectLayer;

   
};

} // namespace more