#include <Geode/Geode.hpp>
#include "WorldLevel.hpp"

using namespace geode::prelude;

bool WorldLevelPopup::init(std::string const& value) {
    if (!geode::Popup::init(300.f, 260.f))
        return false;

    this->setTitle("");

    auto label = CCLabelBMFont::create(value.c_str(), "bigFont.fnt");
    label->setPosition(this->getContentSize() / 2);
    this->addChild(label);

    return true;
}

WorldLevelPopup* WorldLevelPopup::create(std::string const& text) {
    auto ret = new WorldLevelPopup();

    if (ret && ret->init(text)) {
        ret->autorelease();
        return ret;
    }

    delete ret;
    return nullptr;
}
