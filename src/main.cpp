#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>
#include <Geode/modify/LevelSelectLayer.hpp>
#include <Geode/modify/LevelInfoLayer.hpp>
#include <Geode/modify/LevelPage.hpp>
#include <Geode/modify/GJGameLevel.hpp>
#include <Geode/Enums.hpp>
#include "NewLevelSelectLayer.h"
#include "NewLevelSelectLayer.cpp"
using namespace geode::prelude;

#include <iostream>
#include <filesystem> 

//class TestLayer : public CCLayer, BoomScrollLayerDelegate, DynamicScrollDelegate {
//public:
//	static TestLayer* create() {
//		TestLayer* pRet = new TestLayer();
//
//		if (pRet && pRet->init()) {
//			pRet->autorelease();
//		}
//		else {
//			CC_SAFE_DELETE(pRet);
//		}
//
//		return pRet;
//	}
//
//	static CCScene* scene() {
//		CCScene* pScene = CCScene::create();
//		TestLayer* pLayer = TestLayer::create();
//
//		pScene->addChild(pLayer);
//		return pScene;
//	}
//
//	cocos2d::ccColor3B colorForPage(int page)
//	{
//		GameManager* GM = GameManager::sharedState();
//		int colIDs[9] = { 5 ,7, 8, 9, 10, 11, 1, 3, 4 }; // GD uses switch statement but this is easier to write
//
//		return GM->colorForIdx(colIDs[page % 9]);
//	}
//
//	bool init() override {
//		if (!CCLayer::init()) {
//			return false;
//		}
//
//		GameManager* GM = GameManager::sharedState();
//		GameLevelManager* GLM = GameLevelManager::sharedState();
//
//
//		setKeypadEnabled(true);
//		setKeyboardEnabled(true);
//
//
//		cocos2d::CCDirector* director = cocos2d::CCDirector::sharedDirector();
//		cocos2d::CCSize winSize = director->getWinSize();
//
//
//
//		CCArray* pPages = getPages();
//		CCArray* pLevels = getLevels();
//		m_scrollLayer = BoomScrollLayer::create(pPages, 0, true, pLevels, this);
//
//		auto m_pBackground = cocos2d::CCSprite::create("GJ_gradientBG.png");
//		m_pBackground->setAnchorPoint({ 0.0f, 0.0f });
//
//		m_pBackground->setScaleX((winSize.width + 10.0f) / m_pBackground->getTextureRect().size.width);
//		m_pBackground->setScaleX((winSize.height + 10.0f) / m_pBackground->getTextureRect().size.height);
//
//		m_pBackground->setScaleX(m_pBackground->getScaleX() + 42);
//		m_pBackground->setScaleY(m_pBackground->getScaleY() + 1.205);
//		m_pBackground->setPosition({ -5.0f, -5.0f });
//		m_pBackground->setColor({ 0, 0, 255 });
//
//
//		auto pointer = (CCSpriteBatchNode*)m_scrollLayer->getChildren()->objectAtIndex(1);
//		/*pointer->setVisible(false);*/
//		pointer->setPositionY(director->getScreenBottom() - 20);
//
//		auto m_pGround = GJGroundLayer::create(GM->m_loadedGroundID, 1);
//		m_pGround->setPosition(pointer->getPosition());
//		m_pGround->setPositionY(m_pGround->getPositionY() + 70);
//
//		addChild(m_pGround, -1);
//		auto topBar = cocos2d::CCSprite::createWithSpriteFrameName("GJ_topBar_001.png");
//		topBar->setAnchorPoint({ 0.5f, 1.0f });
//		topBar->setPosition({ winSize.width / 2, director->getScreenTop() + 1.0f });
//
//		addChild(topBar, 1);
//
//		cocos2d::CCSprite* leftArt = cocos2d::CCSprite::createWithSpriteFrameName("GJ_sideArt_001.png");
//		leftArt->setAnchorPoint({ 0.0f, 0.0f });
//		leftArt->setPosition({ director->getScreenLeft() - 1.0f, director->getScreenBottom() - 1.0f });
//		addChild(leftArt, 1);
//
//		cocos2d::CCSprite* rightArt = cocos2d::CCSprite::createWithSpriteFrameName("GJ_sideArt_001.png");
//		rightArt->setAnchorPoint({ 1.0f, 0.0f });
//		rightArt->setPosition({ director->getScreenRight() + 1.0f, director->getScreenBottom() - 1.0f });
//		rightArt->isFlipX();
//		rightArt->isFlipY();
//		rightArt->setRotation(-90);
//		rightArt->setPositionY(rightArt->getPositionY() + 71);
//		addChild(rightArt, 1);
//
//		addChild(m_pBackground, -2);
//		addChild(m_scrollLayer);
//
//		auto btnMenu = cocos2d::CCMenu::create();
//		bool controller = PlatformToolbox::isControllerConnected();
//
//		cocos2d::CCSprite* left = cocos2d::CCSprite::createWithSpriteFrameName(controller ? "controllerBtn_DPad_Left_001.png" : "navArrowBtn_001.png");
//		if (!controller)
//			left->isFlipX();
//
//		CCMenuItemSpriteExtra* leftBtn = CCMenuItemSpriteExtra::create(left, this, menu_selector(LevelSelectLayer::onPrev));
//		btnMenu->addChild(leftBtn);
//
//		leftBtn->setSizeMult(2.0f);
//		leftBtn->setPosition(btnMenu->convertToNodeSpace({ director->getScreenLeft() + 25.0f, winSize.height / 2 }));
//
//
//		cocos2d::CCSprite* right = cocos2d::CCSprite::createWithSpriteFrameName(controller ? "controllerBtn_DPad_Right_001.png" : "navArrowBtn_001.png");
//
//		CCMenuItemSpriteExtra* rightBtn = CCMenuItemSpriteExtra::create(right, this, menu_selector(LevelSelectLayer::onNext));
//		btnMenu->addChild(rightBtn);
//
//		leftBtn->setSizeMult(2.0f);
//		leftBtn->setPosition(winSize/2);
//
//
//		cocos2d::CCSprite* back = cocos2d::CCSprite::createWithSpriteFrameName("GJ_arrow_01_001.png");
//		CCMenuItemSpriteExtra* backBtn = CCMenuItemSpriteExtra::create(back, this, menu_selector(LevelSelectLayer::onBack));
//		backBtn->setSizeMult(1.6f);
//
//		cocos2d::CCMenu* backMenu = cocos2d::CCMenu::create();
//		addChild(backMenu, 1);
//
//		backMenu->addChild(backBtn);
//
//		backMenu->setPosition({ director->getScreenLeft() + 25.0f, director->getScreenTop() - 22.0f });
//
//		//GM->0x298 = 0;
//
//		cocos2d::CCMenu* infoMenu = cocos2d::CCMenu::create();
//		addChild(infoMenu);
//
//		cocos2d::CCSprite* info = cocos2d::CCSprite::createWithSpriteFrameName("GJ_infoIcon_001.png");
//		CCMenuItemSpriteExtra* infoBtn = CCMenuItemSpriteExtra::create(info, this, menu_selector(LevelSelectLayer::onInfo));
//		infoMenu->addChild(infoBtn);
//
//		infoMenu->setPosition({ director->getScreenRight() - 20.0f, director->getScreenTop() - 20.0f });
//
//		if (controller)
//		{
//			GameToolbox::addBackButton(this, backBtn);
//
//	}
//		return true;
//	}
//	/*cocos2d::ccColor3B getColorValue (int level1, int level2, float a3) 
//	{
//		float mod = (a3 * (2 / 3)) - 0.2f;
//		if (mod < 1.0f)
//		{
//			if (mod < = 0.0f)
//				mod = 0.0f;
//		}
//		else
//			mod = 1.0f;
//
//		cocos2d::ccColor3B col1 = colorForPage(level1);
//		cocos2d::ccColor3B col2 = colorForPage(level2);
//
//		return ((col2.r * mod) + col1.r * (1.0f - mod)) | (((col2.g * mod) + col1.g * (1.0f - mod)) << 8) | (((col2.b * mod) + col1.b * (1.0f - mod)) << 16);
//	}*/
//
//	void keyBackClicked() override {
//		auto* pScene = MenuLayer::scene(false);
//		auto* pTransition = CCTransitionFade::create(0.5f, pScene);
//
//		CCDirector::sharedDirector()->replaceScene(pTransition);
//	}
//
//	void updatePageWithObject(CCObject* page, CCObject* object) override {
//		static_cast<LevelPage*>(page)->updateDynamicPage(static_cast<GJGameLevel*>(object));
//	}
//
//private:
//	CCArray* getPages() const {
//		CCArray* pPages = CCArray::create();
//		pPages->retain();
//
//		pPages->addObject(LevelPage::create(nullptr));
//		pPages->addObject(LevelPage::create(nullptr));
//		pPages->addObject(LevelPage::create(nullptr));
//
//		return pPages;
//	}
//
//	CCArray* getLevels() const {
//		CCArray* pLevels = CCArray::create();
//		pLevels->retain();
//
//		auto level3 = GJGameLevel::create();
//		std::ifstream t3("./Resources/levels/4003.txt");
//		std::string text3((std::istreambuf_iterator<char>(t3)), std::istreambuf_iterator<char>());
//
//		
//		level3->m_levelName = "Power Trip";
//		level3->m_levelID = 4003;
//		level3->m_levelType = GJLevelType::Local;
//		level3->m_stars = 8;
//		level3->m_levelString = text3;
//		level3->m_coins = 3;
//		level3->m_audioTrack = 39;
//		level3->m_difficulty = GJDifficulty::Harder;
//		level3->m_creatorName = "RobTopGames";
//
//
//		auto level2 = GJGameLevel::create();
//	std::ifstream t2("./Resources/levels/4002.txt");
//	std::string text2((std::istreambuf_iterator<char>(t2)), std::istreambuf_iterator<char>());
//	
//		level2->m_levelName = "Nock Em";
//		level2->m_levelID = 4002;
//		level2->m_levelType = GJLevelType::Local;
//		level2->m_stars = 6;
//		level2->m_levelString = text2;
//		level2->m_coins = 3;
//		level2->m_audioTrack = 38;
//		level2->m_difficulty = GJDifficulty::Hard;
//		level2->m_creatorName = "RobTopGames";
//
//		auto level1 = GJGameLevel::create();
//		std::ifstream t("./Resources/levels/4001.txt");
//		std::string text((std::istreambuf_iterator<char>(t)), std::istreambuf_iterator<char>());
//		if (text != "")
//		{
//
//			std::cout << text << std::endl;
//		}
//		level1->m_levelName = "Press Start";
//		level1->m_levelID = 4001;
//		level1->m_levelType = GJLevelType::Local;
//		level1->m_stars = 4;
//		level1->m_levelString = text;
//		level1->m_coins = 3;
//		level1->m_audioTrack = 37;
//		level1->m_difficulty = GJDifficulty::Normal;
//		level1->m_creatorName = "RobTopGames";
//		/*auto levelPage1 = LevelPage::create(nullptr);
//
//		levelPage1->updateDynamicPage(level);*/
//
//		/*levelPage1->m_level->m_audioTrack = 37;*/
//		pLevels->addObject(level1);
//		pLevels->addObject(level2);
//		pLevels->addObject(level3);
//
//		return pLevels;
//	}
//
//	BoomScrollLayer* m_scrollLayer;
//};
class $modify(MenuLayer) {
	void onMoreGames(CCObject*) {

		
		CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(0.5, NewLevelSelectLayer::scene(0)));
		
        }


	
};




