#include <Geode/Geode.hpp>
#include "WorldLevel.hpp"
#include <Geode/Geode.hpp>

using namespace geode::prelude;


class WorldLevelPopup : public geode::Popup {
protected:
    bool init(std::string const& value)  {
          if (!Popup::init(320.f, 160.f))
            return false;
        
        auto winSize = CCDirector::sharedDirector()->getWinSize();
        this->setID("worldLevelPopup"_spr);
    
        this->setTitle("");

        auto label = CCLabelBMFont::create(value.c_str(), "bigFont.fnt");
        label->setPosition(winSize / 2);
        
        this->addChild(label);

        return true;
    }

public:
    static WorldLevelPopup* create(std::string const& text) {
        auto ret = new WorldLevelPopup();
         
        
        if (ret && ret->init(text)) {
            ret->autorelease();
            return ret;
        }
        CC_SAFE_DELETE(ret);
        return nullptr;
    }
};
