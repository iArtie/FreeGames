#pragma once

#include <Geode/binding/GJDropDownLayer.hpp>

namespace more {

/// @brief Game selection layer.
class MoreGamesLayer : public GJDropDownLayer {
public:
    static MoreGamesLayer* create();
    ~MoreGamesLayer() override {}

    void customSetup() override;

private:
    cocos2d::CCArray* getGames();

    void onCallback(cocos2d::CCObject* sender);
    void onMeltdown(cocos2d::CCObject* sender);
    void onSubzero(cocos2d::CCObject* sender);
    cocos2d::CCArray* m_games;
};

} // namespace more
