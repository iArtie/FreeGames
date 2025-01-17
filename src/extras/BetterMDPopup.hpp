#pragma once

#include <Geode/Geode.hpp>

//Thanks doggo for the popup
using namespace geode::prelude;

class BetterMDPopup : public FLAlertLayer
{
    public:
        bool init(FLAlertLayerProtocol* delegate, char const* title, gd::string desc, char const* btn1, char const* btn2, float width, bool scroll, float height, float textScale);

        static BetterMDPopup* create(FLAlertLayerProtocol* delegate, char const* title, gd::string desc, char const* btn1, char const* btn2, float width, bool scroll, float height, float textScale);
        static BetterMDPopup* create(char const* title, gd::string desc, char const* btn1, char const* btn2);
};