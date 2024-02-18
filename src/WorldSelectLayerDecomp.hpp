#pragma once

#include <Geode/Bindings.hpp>


namespace more {

class WorldSelectLayerDecomp : public cocos2d::CCLayer  {
public:
    static WorldSelectLayerDecomp* create();
    static cocos2d::CCScene* scene();
    
private:
    bool init() override;
    virtual void keyBackClicked();
    void setupWorlds();

    void onPrev(cocos2d::CCObject* sender);
    void onNext(cocos2d::CCObject* sender);

    void importSheet();
    cocos2d::CCNode* createBackground();
    cocos2d::CCNode* createSideArt();
    cocos2d::CCNode* createArrows();
    
    void onClose(CCObject*);
    cocos2d::CCNode* m_background;
};

} // namespace more
