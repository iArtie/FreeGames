#pragma once

#include <Geode/Geode.hpp>

class WorldLevelPopup : public geode::Popup {
protected:
    bool init(std::string const& value);

public:
    static WorldLevelPopup* create(std::string const& text);
};
