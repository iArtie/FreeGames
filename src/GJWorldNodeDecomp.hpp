#pragma once

#include <Geode/Bindings.hpp>
#include "WorldSelectLayerDecomp.hpp"

namespace more {

class GJWorldNodeDecomp : public cocos2d::CCNode {
public:
    static GJWorldNodeDecomp* create(
        int index,
        WorldSelectLayerDecomp* worldSelectLayer
    );
    
private:
    bool init(
        int index,
        WorldSelectLayerDecomp* worldSelectlayer
    );

    cocos2d::CCSprite* createIsland();

    int m_index;
    WorldSelectLayerDecomp* m_worldSelectLayer;

   
};

} // namespace more