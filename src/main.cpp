#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>
#include <Geode/modify/LevelSelectLayer.hpp>
#include <Geode/modify/LevelInfoLayer.hpp>
#include <Geode/modify/LevelPage.hpp>
#include <Geode/modify/GJGameLevel.hpp>
#include <Geode/modify/BoomScrollLayer.hpp>
#include <Geode/modify/PauseLayer.hpp>
#include <Geode/modify/PlayLayer.hpp>
#include <Geode/modify/EndLevelLayer.hpp>
#include <Geode/modify/GJGarageLayer.hpp>
#include <Geode/modify/LoadingLayer.hpp>
#include <Geode/modify/SecretLayer4.hpp>
#include <Geode/Enums.hpp>
#include "NewLevelSelectLayer.h"
#include "NewLevelSelectLayer.cpp"
#include "MoreGamesLayer.hpp"
#include "MoreGamesLayer.cpp"
#include "ownWorldLevelPage.hpp"
#include "MeltdownSelectLevelLayer.h"
#include "WorldSelectLayerDecomp.hpp"
//#include "WorldSelectLayerDecomp.cpp"

//#include "ownWorldLevelPage.cpp"

using namespace geode::prelude;

#include <iostream>
#include <filesystem> 
using namespace more;

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
#include <Geode/utils/web.hpp>
class $modify(LoadingLayer)
{
	void loadAssets()
	{
		
		LoadingLayer::loadAssets();


		std::string zipFilePath;
			
		
		std::string unzipDir;
		

#ifdef GEODE_IS_WINDOWS


		zipFilePath = geode::Mod::get()->getResourcesDir().string() + "\\" + "SpinOffGames.zip";

		unzipDir = geode::Mod::get()->getResourcesDir().string() + "\\" + "SpinOffGames";

#endif
#ifdef GEODE_IS_ANDROID


		zipFilePath = geode::Mod::get()->getResourcesDir().string() + "/" + "SpinOffGames.zip";

		unzipDir = geode::Mod::get()->getResourcesDir().string() + "/" + "SpinOffGames";

#endif
		auto result = geode::utils::file::Unzip::intoDir(zipFilePath, unzipDir);
		
		CCFileUtils::get()->addTexturePack(CCTexturePack{
		  .m_id = this->getID(),
		  .m_paths = { unzipDir }
			});

		auto* textureCache = CCTextureCache::sharedTextureCache();
		auto* spriteFrameCache = CCSpriteFrameCache::sharedSpriteFrameCache();

		textureCache->addImage("WorldSheet.png", false);
		spriteFrameCache->addSpriteFramesWithFile("WorldSheet.plist");
		}

	
	
};
class $modify(MenuLayer) {
	void onMoreGames(CCObject*) {

		/*auto leveltest = GJGameLevel::create();
		leveltest->m_levelName = "Press Start";
		leveltest->m_levelID = 4001;
		leveltest->m_levelType = GJLevelType::Local;
		leveltest->m_stars = 4;
		leveltest->m_levelString = "";
		leveltest->m_coins = 3;
		leveltest->m_audioTrack = 37;
		leveltest->m_difficulty = GJDifficulty::Normal;
		leveltest->m_creatorName = "RobTopGames";
		auto page = ownWorldLevelPage::create(leveltest);

		addChild(page);*/

		auto* layer = more::MoreGamesLayer::create();

		addChild(layer, 100);
		layer->showLayer(false);
		
		//CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(0.5, NewLevelSelectLayer::scene(0)));
		
        }


	
};

class $modify(SecretLayer4)
{
	void onBack(CCObject * sender)
	{
		auto scene = CCScene::create();

		auto isSubzero = Mod::get()->getSavedValue<int>("onsubzero");
		auto SubZeroScene = NewLevelSelectLayer::create(4);
		auto MeltdownScene = MeltdownSelectLevelLayer::create(4);
		auto dashlandScene = ownWorldSelectLayer::create();

		if (isSubzero == 1)
		{
			scene->addChild(SubZeroScene);
			CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(0.5, scene));
			SecretLayer4::onBack(sender);
		}else
		if (isSubzero == 2)
		{
			scene->addChild(MeltdownScene);
			CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(0.5, scene));
			SecretLayer4::onBack(sender);
		}
		else
		if (isSubzero == 3)
			{
			SecretLayer4::onBack(sender);
			}
		else
		{
			SecretLayer4::onBack(sender);
		}


		
		
	}
};
class $modify(GJGarageLayer) {
	bool init() {
		auto back = Mod::get()->getSavedValue<int>("onsubzero");
		back = 10;
		Mod::get()->setSavedValue("onsubzero", back);
		return GJGarageLayer::init();
	}

	void onBack(cocos2d::CCObject* sender)
	{
		auto pages = Mod::get()->getSavedValue<int>("onworldpages");

		auto World = ownWorldSelectLayer::create();
		auto scene = CCScene::create();

		scene->addChild(World);
		
		if (pages != 0 && pages != 10)
		{
			auto transitionScene = CCScene::create(); // Creamos una escena para la transición

			// Mover la escena actual hacia arriba (salida)
			CCSize winSize = CCDirector::sharedDirector()->getWinSize();
			CCActionInterval* moveUp = CCMoveBy::create(0.23f, ccp(0, winSize.height));
			this->runAction(moveUp);

			if (pages == 1) {
				World->instantPage(sender, 1);
			}
			else if (pages == 2) {
				World->instantPage(sender, 2);
			}
			else if (pages == 3) {
				// World->instantPage(sender, 3);
			}

			auto transition = CCTransitionMoveInB::create(0.31f, scene);

			// Mover la nueva escena hacia abajo (entrada)
			CCActionInterval* moveDown = CCMoveBy::create(0.5f, ccp(0, -winSize.height));
			transitionScene->runAction(moveDown);

			scene->setZOrder(1);
			this->setZOrder(2);
			transition->setZOrder(1);
			transitionScene->setZOrder(2);
			CCDirector::sharedDirector()->pushScene(transitionScene);
			CCDirector::sharedDirector()->pushScene(transition);
		}
		
		else
		{
			GJGarageLayer::onBack(sender);
		}
		
		
	}

};
class $modify(PauseLayer) {
	void onQuit(CCObject* sender) {

		auto scene = CCScene::create();

		auto isSubzero = Mod::get()->getSavedValue<int>("onsubzero");
		auto SubZeroScene = NewLevelSelectLayer::create(0);
		auto MeltdownScene = MeltdownSelectLevelLayer::create(0);
		auto dashlandScene = ownWorldSelectLayer::create();
		
		if (isSubzero == 1)
		{
			scene->addChild(SubZeroScene);
		}
		
		if (isSubzero == 2)
		{
			scene->addChild(MeltdownScene);
		}

		if (isSubzero == 3)
		{
			scene->addChild(dashlandScene);
		}
		int page = 0;
		auto subzero = Mod::get()->getSavedValue<int>("subzerolevels");
		auto BG = (CCSprite*)dashlandScene->getChildren()->objectAtIndex(0);
		switch (subzero) {
		case 1:
			std::cout << "on PressStart" << std::endl;
			page = 0;
			if (isSubzero == 1)
			{
				SubZeroScene->instantPage(sender, 0);
			}
			if (isSubzero == 2)
			{
				MeltdownScene->instantPage(sender, 0);
			}
			if (isSubzero == 3)
			{
				dashlandScene->instantPage(sender, 1);
			}
			break;
		case 2:
			std::cout << "on Nock Em" << std::endl;
			page = 1;
			if (isSubzero == 1)
			{
				SubZeroScene->instantPage(sender, 1);
			}
			if (isSubzero == 2)
			{
				MeltdownScene->instantPage(sender, 1);
			}
			if (isSubzero == 3)
			{
				dashlandScene->instantPage(sender, 1);
			}
			break;
		case 3:
			std::cout << "on Power Trip" << std::endl;
			page = 2;
			if (isSubzero == 1)
			{
				SubZeroScene->instantPage(sender, 2);
			}
			if (isSubzero == 2)
			{
				MeltdownScene->instantPage(sender, 2);
			}
			if (isSubzero == 3)
			{
				dashlandScene->instantPage(sender, 1);
			}
			
			
			break;
		case 4:
			
			page = 3;
			if (isSubzero == 1)
			{
				SubZeroScene->instantPage(sender, 2);
			}
			if (isSubzero == 2)
			{
				MeltdownScene->instantPage(sender, 2);
			}
			if (isSubzero == 3)
			{
				dashlandScene->instantPage(sender, 1);
			}
			break;
		case 5:
			std::cout << "on FrontLines" << std::endl;
			page = 4;
			/*MeltdownScene->instantPage(sender, 2);*/
			if (isSubzero == 1)
			{
				SubZeroScene->instantPage(sender, 2);
			}
			if (isSubzero == 2)
			{
				MeltdownScene->instantPage(sender, 2);
			}
			if (isSubzero == 3)
			{
				dashlandScene->instantPage(sender, 1);
			}
			
			
		/*	BG->setColor({ 125, 0, 255 });*/
			break;
		case 6:
		
			page = 5;
			dashlandScene->instantPage(sender, 2);
			break;
		case 7:
	
			page = 6;
			dashlandScene->instantPage(sender, 2);
			break;
		case 8:
	
			page = 7;
			dashlandScene->instantPage(sender, 2);
			break;
		case 9:
	
			page = 8;
			dashlandScene->instantPage(sender, 2);
			break;
		case 10:
		
			page = 9;
			dashlandScene->instantPage(sender, 2);
			break;
		default:
			std::cout << "on a common level" << std::endl;
			page = 10;
			break;
		}

		if (page != 10) {
			CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(0.5, scene));
			PauseLayer::onQuit(sender);
		}
		else {
			PauseLayer::onQuit(sender);
		}

	}

	void onEdit(cocos2d::CCObject* sender)
	{
		Mod::get()->setSavedValue("onsubzero", 25);
		PauseLayer::onEdit(sender);
	}

};


class $modify(EndLevelLayer) {
	void onMenu(CCObject * sender) {
	
		auto scene = CCScene::create();

		auto isSubzero = Mod::get()->getSavedValue<int>("onsubzero");
		auto SubZeroScene = NewLevelSelectLayer::create(0);
		auto MeltdownScene = MeltdownSelectLevelLayer::create(0);

		
		auto dashlandScene = ownWorldSelectLayer::create();
		if (isSubzero == 1)
		{
			scene->addChild(SubZeroScene);
		}

		if (isSubzero == 2)
		{
			scene->addChild(MeltdownScene);
		}

		if (isSubzero == 3)
		{
			scene->addChild(dashlandScene);
		}
		int page = 0;
		auto subzero = Mod::get()->getSavedValue<int>("subzerolevels");

		switch (subzero) {
		case 1:
			std::cout << "on PressStart" << std::endl;
			page = 0;
			if (isSubzero == 1)
			{
				SubZeroScene->instantPage(sender, 0);
			}
			if (isSubzero == 2)
			{
				MeltdownScene->instantPage(sender, 0);
			}
			if (isSubzero == 3)
			{
				dashlandScene->instantPage(sender, 1);
			}
			break;
		case 2:
			std::cout << "on Nock Em" << std::endl;
			page = 1;
			if (isSubzero == 1)
			{
				SubZeroScene->instantPage(sender, 1);
			}
			if (isSubzero == 2)
			{
				MeltdownScene->instantPage(sender, 1);
			}
			if (isSubzero == 3)
			{
				dashlandScene->instantPage(sender, 1);
			}
			break;
		case 3:
			std::cout << "on Power Trip" << std::endl;
			page = 2;
			if (isSubzero == 1)
			{
				SubZeroScene->instantPage(sender, 2);
			}
			if (isSubzero == 2)
			{
				MeltdownScene->instantPage(sender, 2);
			}
			if (isSubzero == 3)
			{
				dashlandScene->instantPage(sender, 1);
			}
			break;
		case 4:

			page = 3;
			if (isSubzero == 1)
			{
				SubZeroScene->instantPage(sender, 2);
			}
			if (isSubzero == 2)
			{
				MeltdownScene->instantPage(sender, 2);
			}
			if (isSubzero == 3)
			{
				dashlandScene->instantPage(sender, 1);
			}
			break;
		case 5:
			std::cout << "on FrontLines" << std::endl;
			page = 4;
			/*MeltdownScene->instantPage(sender, 2);*/
			if (isSubzero == 1)
			{
				SubZeroScene->instantPage(sender, 2);
			}
			if (isSubzero == 2)
			{
				MeltdownScene->instantPage(sender, 2);
			}
			if (isSubzero == 3)
			{
				dashlandScene->instantPage(sender, 1);
			}



		/*	BG->setColor({ 125, 0, 255 });*/
			break;
		case 6:

			page = 5;
			dashlandScene->instantPage(sender, 2);
			break;
		case 7:

			page = 6;
			dashlandScene->instantPage(sender, 2);
			break;
		case 8:

			page = 7;
			dashlandScene->instantPage(sender, 2);
			break;
		case 9:

			page = 8;
			dashlandScene->instantPage(sender, 2);
			break;
		case 10:

			page = 9;
			dashlandScene->instantPage(sender, 2);
			break;
		default:
			std::cout << "on a common level" << std::endl;
			page = 10;
			break;
		}

		if (page != 10) {
			CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(0.5, scene));
			EndLevelLayer::onMenu(sender);
		}
		else {
			EndLevelLayer::onMenu(sender);
		}

	}



};
class $modify(PlayLayer) {
	bool init(GJGameLevel * level, bool useReplay, bool dontCreateObjects){

		std::cout << level->m_levelID << std::endl;

		std::cout << level->m_levelString.c_str() << std::endl;
		auto isSubzero = Mod::get()->getSavedValue<int>("onsubzero");
		int subzero = 0;

		if (isSubzero == 1)
		{
			if (level->m_levelID == 4001) {
				subzero = 1;
			}
			else if (level->m_levelID == 4002) {
				subzero = 2;
			}
			else if (level->m_levelID == 4003) {
				subzero = 3;
			}
		}
		if (isSubzero == 2)
		{
			if (level->m_levelID == 1001) {
				subzero = 1;
			}
			else if (level->m_levelID == 1002) {
				subzero = 2;
			}
			else if (level->m_levelID == 1003) {
				subzero = 3;
			}
		}
		
		if (isSubzero == 3)
		{
			if (level->m_levelID == 2001) {
				subzero = 1;
			}
			else if (level->m_levelID == 2002) {
				subzero = 2;
			}
			else if (level->m_levelID == 2003) {
				subzero = 3;
			}
			else if (level->m_levelID == 2004) {
				subzero = 4;
			}
			else if (level->m_levelID == 2005) {
				subzero = 5;
			}
			else if (level->m_levelID == 2006) {
				subzero = 6;
			}
			else if (level->m_levelID == 2007) {
				subzero = 7;
			}
			else if (level->m_levelID == 2008) {
				subzero = 8;
			}
			else if (level->m_levelID == 2009) {
				subzero = 9;
			}
			else if (level->m_levelID == 2010) {
				subzero = 10;
			}
		}
		Mod::get()->setSavedValue("subzerolevels", subzero);

		return PlayLayer::init(level, useReplay, dontCreateObjects);
		
	}
//
//	int getCurrentPercentInt()
//	{
//		//Subzero percentage levels
//
//		if (this->m_level->m_levelID == 4001) {
//			int currentPercent = Mod::get()->getSavedValue<int>(this->m_isPracticeMode ? "psPracticeMode" : "psNormalMode");
//			if (PlayLayer::getCurrentPercentInt() > currentPercent) {
//				if (this->m_isPracticeMode) {
//					Mod::get()->setSavedValue("psPracticeMode", PlayLayer::getCurrentPercentInt());
//				}
//				else {
//					Mod::get()->setSavedValue("psNormalMode", PlayLayer::getCurrentPercentInt());
//				}
//			}
//		}
//		else if (this->m_level->m_levelID == 4002) {
//			int currentPercent = Mod::get()->getSavedValue<int>(this->m_isPracticeMode ? "nePracticeMode" : "neNormalMode");
//			if (PlayLayer::getCurrentPercentInt() > currentPercent) {
//				if (this->m_isPracticeMode) {
//					Mod::get()->setSavedValue("nePracticeMode", PlayLayer::getCurrentPercentInt());
//				}
//				else {
//					Mod::get()->setSavedValue("neNormalMode", PlayLayer::getCurrentPercentInt());
//				}
//			}
//		}
//		else if (this->m_level->m_levelID == 4003) {
//			int currentPercent = Mod::get()->getSavedValue<int>(this->m_isPracticeMode ? "ptPracticeMode" : "ptNormalMode");
//			if (PlayLayer::getCurrentPercentInt() > currentPercent) {
//				if (this->m_isPracticeMode) {
//					Mod::get()->setSavedValue("ptPracticeMode", PlayLayer::getCurrentPercentInt());
//				}
//				else {
//					Mod::get()->setSavedValue("ptNormalMode", PlayLayer::getCurrentPercentInt());
//				}
//			}
//		}
//
//		//meltdown percenttage levels
//		if (this->m_level->m_levelID == 1001) {
//			int currentPercent = Mod::get()->getSavedValue<int>(this->m_isPracticeMode ? "tsPracticeMode" : "tsNormalMode");
//			if (PlayLayer::getCurrentPercentInt() > currentPercent) {
//				if (this->m_isPracticeMode) {
//					Mod::get()->setSavedValue("tsPracticeMode", PlayLayer::getCurrentPercentInt());
//				}
//				else {
//					Mod::get()->setSavedValue("tsNormalMode", PlayLayer::getCurrentPercentInt());
//				}
//			}
//		}
//		else if (this->m_level->m_levelID == 1002) {
//			int currentPercent = Mod::get()->getSavedValue<int>(this->m_isPracticeMode ? "vaPracticeMode" : "vaNormalMode");
//			if (PlayLayer::getCurrentPercentInt() > currentPercent) {
//				if (this->m_isPracticeMode) {
//					Mod::get()->setSavedValue("vaPracticeMode", PlayLayer::getCurrentPercentInt());
//				}
//				else {
//					Mod::get()->setSavedValue("vaNormalMode", PlayLayer::getCurrentPercentInt());
//				}
//			}
//		}
//		else if (this->m_level->m_levelID == 1003) {
//			int currentPercent = Mod::get()->getSavedValue<int>(this->m_isPracticeMode ? "abPracticeMode" : "abNormalMode");
//			if (PlayLayer::getCurrentPercentInt() > currentPercent) {
//				if (this->m_isPracticeMode) {
//					Mod::get()->setSavedValue("abPracticeMode", PlayLayer::getCurrentPercentInt());
//				}
//				else {
//					Mod::get()->setSavedValue("abNormalMode", PlayLayer::getCurrentPercentInt());
//				}
//			}
//		}
//		return PlayLayer::getCurrentPercentInt();
//		
//	}
//
};


ccColor3B colorForPage(int page) {
	auto GM = GameManager::sharedState();
	int colIDs[9] = { 1 ,3, 5, 0, 9, 11, 1, 3, 4 };

	return GM->colorForIdx(colIDs[page % 5]);
}

ccColor3B getColorValue(int level1, int level2, float a3)
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

	ccColor3B col3 = {
	static_cast<GLubyte>((col2.r * mod) + col1.r * (1.0f - mod)),
	static_cast<GLubyte>((col2.g * mod) + col1.g * (1.0f - mod)),
	static_cast<GLubyte>((col2.b * mod) + col1.b * (1.0f - mod))
	};
	return col3;
}
ccColor3B colorForPage2(int page) {
	auto GM = GameManager::sharedState();
	int colIDs[9] = { 4 ,6, 17, 3, 9, 11, 1, 3, 4 };

	return GM->colorForIdx(colIDs[page % 5]);
}

ccColor3B getColorValue2(int level1, int level2, float a3)
{
	float mod = (a3 * (2 / 3)) - 0.2f;
	if (mod < 1.0f)
	{
		if (mod <= 0.0f)
			mod = 0.0f;
	}
	else
		mod = 1.0f;

	ccColor3B col1 = colorForPage2(level1);
	ccColor3B col2 = colorForPage2(level2);

	ccColor3B col3 = {
	static_cast<GLubyte>((col2.r * mod) + col1.r * (1.0f - mod)),
	static_cast<GLubyte>((col2.g * mod) + col1.g * (1.0f - mod)),
	static_cast<GLubyte>((col2.b * mod) + col1.b * (1.0f - mod))
	};
	return col3;
}

class $modify(BoomScrollLayer) {
	TodoReturn pageNumberForPosition(cocos2d::CCPoint a1) {
		
		auto lol = this->getParent();
		auto meltdown = Mod::get()->getSavedValue<int>("onsubzero");
		auto GM = GameManager::sharedState();

		
		int m_level = 0;
		if (meltdown == 2 || meltdown == 1)
		{
			if (meltdown == 2)
			{
				m_level = Mod::get()->getSavedValue<int>("meltdownlevel");
			}
			if (meltdown == 1)
			{
				m_level = Mod::get()->getSavedValue<int>("subzerolevellol");
			}
		
			auto m_background = (CCSprite*)lol->getChildren()->objectAtIndex(0);
			auto m_ground = (GJGroundLayer*)lol->getChildren()->objectAtIndex(1);
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

		if (meltdown == 3)
		{
			auto extendedlayer = (CCSpriteBatchNode*)this->getChildren()->objectAtIndex(1);
			
			auto point1 = (CCSprite*)extendedlayer->getChildren()->objectAtIndex(0);
			auto point2 = (CCSprite*)extendedlayer->getChildren()->objectAtIndex(1);
			auto point3 = (CCSprite*)extendedlayer->getChildren()->objectAtIndex(2);
			auto bg = (CCNode*)lol->getChildren()->objectAtIndex(0);
			auto director = CCDirector::sharedDirector();
			auto winSize = director->getWinSize();

			
			CCSprite* m_background = (CCSprite*)bg;
			
			
			auto shitbg = (CCSprite*)lol->getChildByTag(120);

			auto mm_background = (CCSprite*)lol->getChildByTag(121);

			auto mm_background2 = (CCSprite*)lol->getChildByTag(122);

			auto mm_background3 = (CCSprite*)lol->getChildByTag(123);
			shitbg->setZOrder(-4);
			/*std::cout << page1->getTag() << std::endl;*/
			
			/*m_background->setColor(color);*/
			if (point1->getColor() == ccWHITE && point1->isVisible() && point1->getPositionX() != 0)
			{
				/*std::cout << "pagina 1" << std::endl;*/

				
				/*	m_background->setColor(GM->colorForIdx(4));*/
					
				this->setVisible(true);
				shitbg->setVisible(true);
				mm_background->setVisible(true);
			/*	mm_background2->setVisible(false);
				mm_background3->setVisible(false);*/
				Mod::get()->setSavedValue("onworldpages",1);
				Mod::get()->setSavedValue("worldpages", 0);
			}

			/*if (levelsas <= 5)
			{
				m_background->setColor({ 0, 125, 255 });
			}
			else
			{
				m_background->setColor({ 125, 0, 255 });
			}*/
			if (point2->getColor() == ccWHITE && point2->getPositionX() != 0)
			{
				/*std::cout << "pagina 2" << std::endl;*/
				this->setVisible(true);
				shitbg->setVisible(false);
				mm_background->setVisible(false);
				mm_background2->setVisible(false);
				mm_background3->setVisible(true);
				Mod::get()->setSavedValue("onworldpages", 2);
				Mod::get()->setSavedValue("worldpages", 1);
			
			}
			if (point3->getColor() == ccWHITE && point3->getPositionX() != 0)
			{
			/*	std::cout << "pagina 3" << std::endl;*/
				this->setVisible(true);
				shitbg->setVisible(false);
				mm_background->setVisible(false);
				mm_background2->setVisible(true);
				mm_background3->setVisible(false);
				Mod::get()->setSavedValue("onworldpages", 3);
				Mod::get()->setSavedValue("worldpages", 2);
				
			}
			
			
		
			
		}
		BoomScrollLayer::pageNumberForPosition(a1);
	}
};


