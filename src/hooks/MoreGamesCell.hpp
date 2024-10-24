#pragma once

#include <Geode/Bindings.hpp>

namespace more {

class MoreGamesCell : public cocos2d::CCLayer {
public:
    struct CreateArg {
        cocos2d::CCSize size;

        char const* iconFrame;
        char const* titleFrame;
        
        cocos2d::CCObject* target;
        cocos2d::SEL_MenuHandler callback;
    };

    static MoreGamesCell* create(const CreateArg& arg);

private:
    bool init(const CreateArg& arg);

    cocos2d::CCNode* createIcon(char const* frame);
    cocos2d::CCNode* createTitle(char const* frame);
    cocos2d::CCNode* createPlayButton(
        cocos2d::CCObject* target,
        cocos2d::SEL_MenuHandler callback
    );
};

} // namespace more