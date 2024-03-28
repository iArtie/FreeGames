#include "GJWorldNodeDecomp.hpp"
#include "WorldSelectLayerDecomp.hpp"

using namespace geode::prelude;

namespace more {

GJWorldNodeDecomp* GJWorldNodeDecomp::create(
    int index,
    ownWorldSelectLayer* worldSelectLayer
) {
    GJWorldNodeDecomp* ret = new GJWorldNodeDecomp();

    if (ret && ret->init(index, worldSelectLayer)) {
        ret->autorelease();
    } else {
        CC_SAFE_DELETE(ret);
    }

    return ret;
}

bool GJWorldNodeDecomp::init(
    int index,
    ownWorldSelectLayer* worldSelectLayer
) {
    if (!CCNode::init()) {
        return false;
    }

    m_index = index;

  /*  std::cout << index << std::endl;*/
    m_worldSelectLayer = worldSelectLayer;
   

    return true;
}

CCSprite* GJWorldNodeDecomp::createIsland() {
    CCString* path = CCString::createWithFormat(
        "worldIsland_%02d.png",
        m_index
    );

    CCSprite* sprite = CCSprite::createWithSpriteFrameName(
        path->getCString()
    );

    return sprite;
}

} // namespace more