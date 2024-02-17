#include "NewLevelSelectLayer.h"
#include "../Pages/NewLevelPage.h"
#include <Geode/Geode.hpp>
#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>
#include <Geode/modify/LevelSelectLayer.hpp>
#include <Geode/modify/LevelInfoLayer.hpp>
#include <Geode/modify/LevelPage.hpp>
#include <Geode/modify/GJGameLevel.hpp>
#include <Geode/Enums.hpp>
#include "../src/NewLevelSelectLayer.h"

using namespace geode::prelude;

NewLevelSelectLayer* NewLevelSelectLayer::create(int page) {
    auto ret = new NewLevelSelectLayer();
    if (ret && ret->init(page)) {
        ret->autorelease();
        return ret;
    }
    CC_SAFE_DELETE(ret);
    return nullptr;
};

CCScene* NewLevelSelectLayer::scene(int page) {
    auto layer = NewLevelSelectLayer::create(page);
    auto scene = CCScene::create();
    scene->addChild(layer);
    return scene;
}

bool NewLevelSelectLayer::init(int page) {
    if(!CCLayer::init()) return false;

    auto director = CCDirector::sharedDirector();
    auto winSize = director->getWinSize();
    auto GM = GameManager::sharedState();
    auto GLM = GameLevelManager::sharedState();

    m_background = CCSprite::create("GJ_gradientBG.png");
    m_background->setAnchorPoint({ 0.f, 0.f });
    addChild(m_background, -2);

    m_background->setScaleX((winSize.width + 10.f) / m_background->getTextureRect().size.width);
    m_background->setScaleY((winSize.height + 10.f) / m_background->getTextureRect().size.height);
    m_background->setPosition(ccp(-5, -5));
    m_background->setColor({ 40, 125, 255 });

    m_ground = GJGroundLayer::create(GM->m_loadedGroundID, -1);
    m_ground->setPositionY(std::min(128.f, (winSize.height / 2) - 110.f));
    addChild(m_ground ,-1);

    CCSprite* topBar = CCSprite::createWithSpriteFrameName("GJ_topBar_001.png");
    topBar->setAnchorPoint({ 0.5f, 1.f });
    topBar->setPosition(ccp(winSize.width / 2, director->getScreenTop() + 1.f));
    addChild(topBar, 1);

    CCSprite* rightArt = CCSprite::createWithSpriteFrameName("GJ_sideArt_001.png");
    rightArt->setAnchorPoint({ 1.f, 0.f });
    rightArt->setPosition(ccp(director->getScreenRight() + 1.f, director->getScreenBottom() - 1.f));
    rightArt->setFlipX(true);
    addChild(rightArt, 1);

    CCSprite* leftArt = CCSprite::createWithSpriteFrameName("GJ_sideArt_001.png");
    leftArt->setAnchorPoint({ 0.f, 0.f });
    leftArt->setPosition(ccp(director->getScreenLeft() - 1.f, director->getScreenBottom() - 1.f));
    addChild(leftArt, 1);

    m_mainLevels = CCArray::create();
    m_levelPages = CCArray::create();

    m_level = 0;
    for(int i = 1; i < 23; i++)
        m_mainLevels->addObject(GLM->getMainLevel(i, true));
    
    for(size_t i = 0; i < 3; i++)   
        m_levelPages->addObject(LevelPage::create(nullptr));
    
    //GJGameLevel* theTower = GJGameLevel::create();
    //theTower->m_levelID = -2;
    //m_mainLevels->addObject(theTower);

    GJGameLevel* defaultLevel = GJGameLevel::create();
    defaultLevel->m_levelID = -1;
    m_mainLevels->addObject(defaultLevel);

    m_scrollLayer = BoomScrollLayer::create(m_levelPages, 0, true, m_mainLevels, static_cast<DynamicScrollDelegate*>(this));
    addChild(m_scrollLayer);

    CCLabelBMFont* downloadLabel = CCLabelBMFont::create("Download the soundtracks", "bigFont.fnt");
    downloadLabel->setScale(0.5);

    CCMenuItemSpriteExtra* downloadBtn = CCMenuItemSpriteExtra::create(downloadLabel, this, menu_selector(NewLevelSelectLayer::onSoundtracks));

    CCMenu* downloadMenu = CCMenu::create();
    downloadMenu->addChild(downloadBtn);
    addChild(downloadMenu);

    downloadMenu->setPosition(ccp(winSize.width / 2, director->getScreenBottom() + 35.f));

    CCMenu* btnMenu = CCMenu::create();
    addChild(btnMenu, 5);

    CCSprite* leftSpr = CCSprite::createWithSpriteFrameName("navArrowBtn_001.png");
    leftSpr->setFlipX(true);

    CCMenuItemSpriteExtra* leftBtn = CCMenuItemSpriteExtra::create(leftSpr, this, menu_selector(NewLevelSelectLayer::onPrev));
    btnMenu->addChild(leftBtn);

    leftBtn->setPosition(btnMenu->convertToNodeSpace(ccp(director->getScreenLeft() + 25.f, winSize.height / 2)));

    CCSprite* rightSpr = CCSprite::createWithSpriteFrameName("navArrowBtn_001.png");

    CCMenuItemSpriteExtra* rightBtn = CCMenuItemSpriteExtra::create(rightSpr, this, menu_selector(NewLevelSelectLayer::onNext));
    btnMenu->addChild(rightBtn);

    rightBtn->setPosition(btnMenu->convertToNodeSpace(ccp(director->getScreenRight() - 25.f, winSize.height / 2)));

    CCSprite* backSpr = CCSprite::createWithSpriteFrameName("GJ_arrow_01_001.png");
    CCMenuItemSpriteExtra* backBtn = CCMenuItemSpriteExtra::create(backSpr, this, menu_selector(NewLevelSelectLayer::onClose));

    CCMenu* backMenu = CCMenu::create();
    backMenu->addChild(backBtn);
    addChild(backMenu, 1);

    backMenu->setPosition(ccp(director->getScreenLeft() + 25.f, director->getScreenTop() - 22.f));
    setKeyboardEnabled(true);
    setKeypadEnabled(true);
    log::info("screen top: {}", director->getScreenTop());
    //scrollLayerMoved({0, 0});

    return true;
}

void NewLevelSelectLayer::keyBackClicked() {
    onClose(nullptr);
}

void NewLevelSelectLayer::onClose(CCObject*) {
    CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(0.5, MenuLayer::scene(false)));
}

void NewLevelSelectLayer::onSoundtracks(CCObject*) {
    auto songs = SongsLayer::create();
    songs->enterLayer();
    CCDirector::get()->getRunningScene()->addChild(songs, 2);
}

ccColor3B NewLevelSelectLayer::colorForPage(int page) {
    auto GM = GameManager::sharedState();
	int colIDs[9] = { 5 ,7, 8, 9, 10, 11, 1, 3, 4 };

	return GM->colorForIdx(colIDs[page % 9]);
}


ccColor3B NewLevelSelectLayer::getColorValue(int level1, int level2, float a3)
{
	float mod = (a3 * (2 / 3)) - 0.2f;
	if (mod < 1.0f)
	{
		if (mod <= 0.0f)
			mod = 0.0f;
	}
	else
		mod = 1.0f;

	ccColor3B col1 = colorForPage(level1);
	ccColor3B col2 = colorForPage(level2);

    ccColor3B col3 = {((col2.r * mod) + col1.r * (1.0f - mod)), (((col2.g * mod) + col1.g * (1.0f - mod))), (((col2.b * mod) + col1.b * (1.0f - mod)))};
    return col3;
}

void NewLevelSelectLayer::updatePageWithObject(CCObject* page, CCObject* object) {
    GJGameLevel* level = static_cast<GJGameLevel*>(object);
    static_cast<LevelPage*>(page)->updateDynamicPage(level);
}

void NewLevelSelectLayer::onNext(CCObject*) {
    m_level++;
    m_scrollLayer->moveToPage(m_level);
    //scrollLayerMoved({0, 0});
}

void NewLevelSelectLayer::onPrev(CCObject*) {
    m_level--;
    m_scrollLayer->moveToPage(m_level);
    //scrollLayerMoved({0, 0});
}

void NewLevelSelectLayer::scrollLayerMoved(CCPoint point) {
    log::info("scrollLayerMoved");
    ccColor3B color = getColorValue(m_level, m_level - 1, 12);
    m_background->setColor(color);
    ccColor3B Color1 = color;
    Color1.r = color.r * 0.8;
    Color1.g = color.g * 0.8;
    Color1.b = color.b * 0.8;
    m_ground->updateGround01Color(Color1);

    ccColor3B Color2 = color;
    Color2.r = color.r * 0.9;
    Color2.g = color.g * 0.9;
    Color2.b = color.b * 0.9;
    m_ground->updateGround02Color(Color2);
}