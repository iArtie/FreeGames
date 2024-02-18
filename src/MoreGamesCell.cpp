#include "MoreGamesCell.hpp"
#include "Geode/binding/CCMenuItemSpriteExtra.hpp"

using namespace geode::prelude;

namespace more {

MoreGamesCell* MoreGamesCell::create(const CreateArg& arg) {
    MoreGamesCell* ret = new MoreGamesCell();

    if (ret && ret->init(arg)) {
        ret->autorelease();
    } else {
        CC_SAFE_DELETE(ret);
    }

    return ret;
}

bool MoreGamesCell::init(const CreateArg& arg) {
    if (!CCLayer::init()) {
        return false;
    }

    setContentSize(arg.size);

    CCNode* icon = createIcon(arg.iconFrame);
    CCNode* title = createTitle(arg.titleFrame);
    CCNode* playButton = createPlayButton(
        arg.target,
        arg.callback
    );

    addChild(icon);
    addChild(title);
    addChild(playButton);

    return true;
}

CCNode* MoreGamesCell::createIcon(char const* frame) {
    const CCSize container = getContentSize();
    auto* sprite = CCSprite::createWithSpriteFrameName(frame);

    sprite->setScale(0.35f);
    sprite->setPosition({
        container.height / 2.0f,
        container.height / 2.0f,
    });

    return sprite;
}

CCNode* MoreGamesCell::createTitle(char const* frame) {
    const CCSize container = getContentSize();
    auto* sprite = CCSprite::createWithSpriteFrameName(frame);

    sprite->setAnchorPoint({ 0.0f, 0.5f });
    sprite->setPosition({
        (container.height / 2.0f) + 25.0f,
        container.height / 2.0f,
    });
    sprite->setScale(0.9f);

    return sprite;
}

CCNode* MoreGamesCell::createPlayButton(
    CCObject* target,
    SEL_MenuHandler callback
) {
    const CCSize container = getContentSize();

    auto* menu = CCMenu::create();
    menu->setAnchorPoint({ 0.0f, 0.0f });
    menu->setPosition({
        container.width - (container.height / 2.0f) - 5.0f,
        container.height / 2.0f
    });
    menu->setScale(0.6f);

    auto* sprite = CCSprite::createWithSpriteFrameName("GJ_playBtn2_001.png");
    auto* button = CCMenuItemSpriteExtra::create(
        sprite,
        nullptr,
        target,
        callback
    );
    button->setPosition({ 0.0f, 0.0f });
    menu->addChild(button);

    return menu;
}

} // namespace more