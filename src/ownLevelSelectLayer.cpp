#include <Geode/Geode.hpp>
#include "ownLevelSelectLayer.h"
using namespace geode::prelude;


ownLevelSelectLayer* ownLevelSelectLayer::create(int page) {
	auto ret = new ownLevelSelectLayer();
	if (ret && ret->init(page)) {
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
};

CCScene* ownLevelSelectLayer::scene(int page) {
	auto layer = ownLevelSelectLayer::create(page);
	auto scene = CCScene::create();
	scene->addChild(layer);
	return scene;
}

cocos2d::ccColor3B ownLevelSelectLayer::colorForPage(int page)
{
	GameManager* GM = GameManager::sharedState();
	int colIDs[9] = { 5 ,7, 8, 9, 10, 11, 1, 3, 4 }; // GD uses switch statement but this is easier to write

	return GM->colorForIdx(colIDs[page % 9]);
}

bool ownLevelSelectLayer::init(int page)
{
	bool init = cocos2d::CCLayer::init();
	if (init)
	{
		GameManager* GM = GameManager::sharedState();
		GameLevelManager* GLM = GameLevelManager::sharedState();


		setKeypadEnabled(true);
		setKeyboardEnabled(true);

		m_bSecretMenuCoin = AchievementManager::sharedState()->isAchievementEarned("geometry.ach.secret04");
		cocos2d::CCDirector* director = cocos2d::CCDirector::sharedDirector();
		cocos2d::CCSize winSize = director->getWinSize();

		m_pBackground = cocos2d::CCSprite::create("GJ_gradientBG.png");
		m_pBackground->setAnchorPoint({ 0.0f, 0.0f });
		addChild(m_pBackground, -2);

		m_pBackground->setScaleX((winSize.width + 10.f) / m_pBackground->getTextureRect().size.width);
		m_pBackground->setScaleY((winSize.height + 10.f) / m_pBackground->getTextureRect().size.height);
		m_pBackground->setPosition(ccp(-5, -5));
		m_pBackground->setColor({ 0, 0, 255 });

		m_pGround = GJGroundLayer::create(GM->m_loadedGroundID, 1);
		m_pGround->setPositionY(std::min(128.f, (winSize.height / 2) - 110.f));
		addChild(m_pGround, -1);

		CCSprite* topBar = CCSprite::createWithSpriteFrameName("GJ_topBar_001.png");
		topBar->setAnchorPoint({ 0.5f, 1.f });
		topBar->setPosition(ccp(winSize.width / 2, director->getScreenTop() + 1.f));
		addChild(topBar, 1);

		cocos2d::CCSprite* leftArt = cocos2d::CCSprite::createWithSpriteFrameName("GJ_sideArt_001.png");
		leftArt->setAnchorPoint({ 0.0f, 0.0f });
		leftArt->setPosition({ director->getScreenLeft() - 1.0f, director->getScreenBottom() - 1.0f });
		addChild(leftArt, 1);

		cocos2d::CCSprite* rightArt = cocos2d::CCSprite::createWithSpriteFrameName("GJ_sideArt_001.png");
		rightArt->setAnchorPoint({ 1.0f, 0.0f });
		rightArt->setPosition({ director->getScreenRight() + 1.0f, director->getScreenBottom() - 1.0f });
		rightArt->isFlipX();
		addChild(rightArt, 1);

		mainLevels = cocos2d::CCArray::create();
		cocos2d::CCArray* levelPages = cocos2d::CCArray::create();
		for (size_t i = 1; i < 22; i++)
		{
			mainLevels->addObject(GLM->getMainLevel(i, true));
		}
		

		for (size_t i = 1; i < 22; i++)
		{
			levelPages->addObject(LevelPage::create(nullptr));
		}
			

		/*GJGameLevel* defaultLevel = GJGameLevel::create();
		defaultLevel->m_levelID = -1;
		mainLevels->addObject(defaultLevel);*/
	/*	mainLevels->addObject(GLM->getMainLevel(1, true));
		levelPages->addObject(LevelPage::create(nullptr));*/
		m_pBoomScrollLayer = BoomScrollLayer::create(levelPages, 0, true, mainLevels, static_cast<DynamicScrollDelegate*>(this));
		

		//m_pBoomScrollLayer->setPagesIndicatorPosition({ winSize / 2, director->getScreenBottom() + 15.0f });

		//m_fWindowWidth = winSize.width;

		m_pBoomScrollLayer->m_extendedLayer->m_delegate = static_cast<BoomScrollLayerDelegate*>(this);

		if (page)
		{
			if (page == 21)
				m_pBoomScrollLayer->instantMoveToPage(20);
			m_pBoomScrollLayer->instantMoveToPage(page);
		}
		else
		{
			scrollLayerMoved(m_pBoomScrollLayer->getPosition()); //
		}

		addChild(m_pBoomScrollLayer);
		cocos2d::CCLabelBMFont* download = cocos2d::CCLabelBMFont::create("Download the soundtracks", "bigFont.fnt");
		download->setScale(0.5f);

		CCMenuItemSpriteExtra* downloadBtn = CCMenuItemSpriteExtra::create(download, this, menu_selector(ownLevelSelectLayer::onDownload));
		downloadBtn->setSizeMult(2.0f);

		cocos2d::CCMenu* DLMenu = cocos2d::CCMenu::create();
		addChild(DLMenu);

		DLMenu->setPosition(ccp(winSize.width / 2, director->getScreenBottom() + 35.f));
		cocos2d::CCMenu* btnMenu = cocos2d::CCMenu::create();
		addChild(btnMenu, 5);

		bool controller = PlatformToolbox::isControllerConnected();

		cocos2d::CCSprite* left = cocos2d::CCSprite::createWithSpriteFrameName(controller ? "controllerBtn_DPad_Left_001.png" : "navArrowBtn_001.png");
		if (!controller)
			left->isFlipX();

		CCMenuItemSpriteExtra* leftBtn = CCMenuItemSpriteExtra::create(left, this, menu_selector(ownLevelSelectLayer::onPrev));
		btnMenu->addChild(leftBtn);

		leftBtn->setSizeMult(2.0f);
		leftBtn->setPosition(btnMenu->convertToNodeSpace( { director->getScreenLeft() + 25.0f, winSize.height / 2 }));


		cocos2d::CCSprite* right = cocos2d::CCSprite::createWithSpriteFrameName(controller ? "controllerBtn_DPad_Right_001.png" : "navArrowBtn_001.png");

		CCMenuItemSpriteExtra* rightBtn = CCMenuItemSpriteExtra::create(right, this, menu_selector(ownLevelSelectLayer::onNext));
		btnMenu->addChild(rightBtn);

		leftBtn->setSizeMult(2.0f);
		leftBtn->setPosition(btnMenu->convertToNodeSpace(ccp(director->getScreenLeft() + 25.f, winSize.height / 2)));


		cocos2d::CCSprite* back = cocos2d::CCSprite::createWithSpriteFrameName("GJ_arrow_01_001.png");
		CCMenuItemSpriteExtra* backBtn = CCMenuItemSpriteExtra::create(back, this, menu_selector(ownLevelSelectLayer::onBack));
		backBtn->setSizeMult(1.6f);

		cocos2d::CCMenu* backMenu = cocos2d::CCMenu::create();
		addChild(backMenu, 1);

		backMenu->addChild(backBtn);

		backMenu->setPosition({ director->getScreenLeft() + 25.0f, director->getScreenTop() - 22.0f });

		//GM->0x298 = 0;

		cocos2d::CCMenu* infoMenu = cocos2d::CCMenu::create();
		addChild(infoMenu);

		cocos2d::CCSprite* info = cocos2d::CCSprite::createWithSpriteFrameName("GJ_infoIcon_001.png");
		CCMenuItemSpriteExtra* infoBtn = CCMenuItemSpriteExtra::create(info, this, menu_selector(ownLevelSelectLayer::onInfo));
		infoMenu->addChild(infoBtn);

		infoMenu->setPosition({ director->getScreenRight() - 20.0f, director->getScreenTop() - 20.0f });

		if (controller)
			GameToolbox::addBackButton(this, backBtn);

	}	
	return init;
}

cocos2d::ccColor3B ownLevelSelectLayer::getColorValue(int level, int level2, float a3)
{

	float mod = (a3 * (2 / 3)) - 0.2f;
	if (mod < 1.0f)
	{
		if (mod <= 0.0f)
			mod = 0.0f;
	}
	else
		mod = 1.0f;

	ccColor3B col1 = colorForPage(level);
	ccColor3B col2 = colorForPage(level2);

	ccColor3B col3 = {
	static_cast<GLubyte>((col2.r * mod) + col1.r * (1.0f - mod)),
	static_cast<GLubyte>((col2.g * mod) + col1.g * (1.0f - mod)),
	static_cast<GLubyte>((col2.b * mod) + col1.b * (1.0f - mod))
	};
	return col3;
}


void ownLevelSelectLayer::updatePageWithObject(CCObject* page, CCObject*object)
{
	GJGameLevel* level = static_cast<GJGameLevel*>(object);
     static_cast<LevelPage*>(page)->updateDynamicPage(level);
	 log::info("{}", level->m_levelID.value());
}

void ownLevelSelectLayer::onNext(CCObject*) {
	m_nLevel++;
	m_pBoomScrollLayer->moveToPage(m_nLevel);
}

void ownLevelSelectLayer::onPrev(CCObject*) {
	m_nLevel--;
	m_pBoomScrollLayer->moveToPage(m_nLevel);
	//updateColors();
	//scrollLayerMoved({0, 0});
}

void ownLevelSelectLayer::keyBackClicked() {
	onBack(nullptr);
}

void ownLevelSelectLayer::onBack(CCObject*) {
	auto back = Mod::get()->getSavedValue<int>("onsubzero");
	back = 10;
	Mod::get()->setSavedValue("onsubzero", back);
	CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(0.5, MenuLayer::scene(false)));
}

void ownLevelSelectLayer::onDownload(CCObject*) {
	auto songs = SongsLayer::create();
	songs->enterLayer();
	CCDirector::get()->getRunningScene()->addChild(songs, 2);
}


void ownShow(GJGameLevel* level) {

	if (level == nullptr) return;


	if (level->m_levelID == -1) {
		FLAlertLayer::create(nullptr, "It's a secret...", "<cr>Roses are red</c>\n<cl>Violets are blue</c>\n<cg>Welcome to</c>\n<cy>2.2</c>", "OK", nullptr, 360)->show();
		return;
	}

	if (level->m_levelID == -2) {
		FLAlertLayer::create(nullptr, "The Tower", "The path leads to an <cr>old tower</c>. It's been left alone for <cg>years</c>, with little reason to <co>explore</c>.", "OK", nullptr, 360)->show();
		return;
	}


	if (level->m_levelID != -1 && level->m_levelID != -2)
	{
		std::string name = level->m_levelName;
		std::string contentStream =
			"<cy>" + name + "</c>" +
			"\n<cg>Total Attempts</c>: " + std::to_string(level->m_attempts) +
			"\n<cl>Total Jumps</c>: " + std::to_string(level->m_jumps) +
			"\n<cp>Normal</c>: " + std::to_string(level->m_normalPercent) + "%" +
			"\n<co>Practice</c>: " + std::to_string(level->m_practicePercent) + "%";

		FLAlertLayer::create(nullptr, "Level Stats", contentStream, "OK", nullptr, 360)->show();
		return;
	}
}






void ownLevelSelectLayer::onInfo(CCObject* sender) {

	/*std::cout << levellol << std::endl;*/
	auto levelObject = mainLevels->objectAtIndex(m_nLevel);
	// Verificar si el objeto es de tipo GJGameLevel
	if (auto gameLevel = dynamic_cast<GJGameLevel*>(levelObject)) {
		ownShow(gameLevel);
	}
}
bool ownLevelSelectLayer::tryShowAd()
{
	return true;
	/*return GameManager::sharedState()->showInterstitial();*/
}