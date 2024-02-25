#include <Geode/Geode.hpp>
#include "WorldLevel.hpp"
#include <Geode/Geode.hpp>

using namespace geode::prelude;

// specify parameters for the setup function in the Popup<...> template
class WorldLevelPopup : public geode::Popup<std::string const&> {
protected:
    bool setup(std::string const& value) override {
        auto winSize = CCDirector::sharedDirector()->getWinSize();

        // convenience function provided by Popup 
        // for adding/setting a title to the popup
        this->setTitle("");

        auto label = CCLabelBMFont::create(value.c_str(), "bigFont.fnt");
        label->setPosition(winSize / 2);
        this->addChild(label);

        return true;
    }

public:
    static WorldLevelPopup* create(std::string const& text) {
        auto ret = new WorldLevelPopup();
        if (ret && ret->init(300.f, 260.f, text)) {
            ret->autorelease();
            return ret;
        }
        CC_SAFE_DELETE(ret);
        return nullptr;
    }
};
