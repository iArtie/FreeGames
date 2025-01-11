#include <Geode/Geode.hpp>
#include "../SubZero/SubZeroSelectLayer.h"
#include "../extras/BetterMDPopup.hpp"

using namespace geode::prelude;

void updateGroundColorSubZero(CCSpriteBatchNode* batch, const cocos2d::ccColor3B& color)
{
	if (!batch) return;

	auto children = batch->getChildren();
	if (!children) return;

	for (int i = 0; i < children->count(); ++i) {
		auto sprite = dynamic_cast<CCSprite*>(children->objectAtIndex(i));
		if (!sprite) continue;

		sprite->setColor(color);

		auto spriteChildren = sprite->getChildren();
		if (!spriteChildren) continue;

		for (int o = 0; o < spriteChildren->count(); ++o) {
			auto spriteChild = dynamic_cast<CCSprite*>(spriteChildren->objectAtIndex(o));
			if (!spriteChild) continue;

			spriteChild->setColor(color);
		}
	}
}

SubZeroSelectLayer* SubZeroSelectLayer::create(int page) {
	auto ret = new SubZeroSelectLayer();
	if (ret && ret->init(page)) {
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
};

CCScene* SubZeroSelectLayer::scene(int page) {
	auto layer = SubZeroSelectLayer::create(page);
	auto scene = CCScene::create();
	scene->addChild(layer);
	return scene;
}

bool SubZeroSelectLayer::init(int page)
{
	if (!CCLayer::init()) return false;

	auto director = CCDirector::sharedDirector();
	auto winSize = director->getWinSize();
	auto GM = GameManager::sharedState();
	auto GLM = GameLevelManager::sharedState();

	this->setID("SubZeroSelectLayer"_spr);
	m_pBackground = CCSprite::create("GJ_gradientBG.png");
	m_pBackground->setAnchorPoint({ 0.f, 0.f });
	addChild(m_pBackground, -2);

	m_pBackground->setScaleX((winSize.width + 10.f) / m_pBackground->getTextureRect().size.width);
	m_pBackground->setScaleY((winSize.height + 10.f) / m_pBackground->getTextureRect().size.height);
	m_pBackground->setPosition(ccp(-5, -5));
	m_pBackground->setColor({ 0, 0, 255 });

	m_pGround = GJGroundLayer::create(GM->m_loadedGroundID, -1);
	m_pGround->setPositionY(std::min(128.f, (winSize.height / 2) - 110.f));
	addChild(m_pGround, -1);

	auto m_pGround01Sprite = static_cast<CCSpriteBatchNode*>(m_pGround->getChildren()->objectAtIndex(3));
   auto m_pGround02Sprite = static_cast<CCSpriteBatchNode*>(m_pGround->getChildren()->objectAtIndex(4));


   CCArray* children = nullptr;  // Inicializamos children a nullptr


   CCObject* pObj = nullptr;
   if (Loader::get()->getLoadedMod("bitz.darkmode_v4"))
   {
	   CCARRAY_FOREACH(m_pGround->getChildren(), pObj)
	   {
		   if (instanceof<CCSpriteBatchNode>(pObj)) {
			   auto spriteBatchNode = dynamic_cast<CCSpriteBatchNode*>(pObj);
			   if (spriteBatchNode) {
				   updateGroundColorSubZero(spriteBatchNode, { 40, 40, 40 });
			   }
		   }
	   }
   }
   else
   {
	   CCARRAY_FOREACH(m_pGround->getChildren(), pObj)
	   {
		   if (instanceof<CCSpriteBatchNode>(pObj)) {
			   auto spriteBatchNode = dynamic_cast<CCSpriteBatchNode*>(pObj);
			   if (spriteBatchNode) {
				   updateGroundColorSubZero(spriteBatchNode, GM->colorForIdx(5));
			   }
		   }
	   }
   }
  
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

	mainLevels = CCArray::create();
	levelPages = CCArray::create();

	m_nLevel = 0;
	/*for (int i = 1; i < 4; i++)
		mainLevels->addObject(GLM->getMainLevel(i, true));*/

	/*for (size_t i = 4; i > 0; i--)*/
	


	GJGameLevel* level3 = GLM->getMainLevel(4003, true);
	level3->m_levelName = "Power Trip";
	level3->m_levelID = 4003;
	level3->m_levelType = GJLevelType::Local;
	level3->m_stars = 8;
	level3->m_coins = 3;
	level3->m_audioTrack = 39;
	level3->m_difficulty = GJDifficulty::Harder;
	level3->m_creatorName = "RobTopGames";


	GJGameLevel* level2 = GLM->getMainLevel(4002, true);
	level2->m_levelName = "Nock Em";
	level2->m_levelType = GJLevelType::Local;
	level2->m_stars = 6;
	level2->m_coins = 3;
	level2->m_audioTrack = 38;
	level2->m_difficulty = GJDifficulty::Hard;
	level2->m_creatorName = "RobTopGames";



	GJGameLevel* level1 = GLM->getMainLevel(4001, true);
	
   
	 level1->m_levelName = "Press Start";
	 level1->m_levelID = 4001;
	 level1->m_levelType = GJLevelType::Local;
	 level1->m_stars = 4;
	 level1->m_coins = 3;
	 level1->m_audioTrack = 37;
	 level1->m_difficulty = GJDifficulty::Normal;
	 level1->m_creatorName = "RobTopGames";


	mainLevels->addObject(level1);
	mainLevels->addObject(level2);
	mainLevels->addObject(level3);


		levelPages->addObject(LevelPage::create(nullptr));
		levelPages->addObject(LevelPage::create(nullptr));
		levelPages->addObject(LevelPage::create(nullptr));
	//GJGameLevel* theTower = GJGameLevel::create();
	//theTower->m_levelID = -2;
	//m_mainLevels->addObject(theTower);

	GJGameLevel* defaultLevel = GJGameLevel::create();
	defaultLevel->m_levelID = -1;
	mainLevels->addObject(defaultLevel);

	m_pBoomScrollLayer = BoomScrollLayer::create(levelPages, 0, true, mainLevels, this);

	auto pointer = (CCSpriteBatchNode*)m_pBoomScrollLayer->getChildren()->objectAtIndex(1);
	/*pointer->setVisible(false);*/
	pointer->setPositionY(director->getScreenBottom() - 45);
	m_fWindowWidth = winSize.width;
	m_pBoomScrollLayer->m_extendedLayer->m_delegate = static_cast<BoomScrollLayerDelegate*>(this);

	if (page)
	{
		if (page == 21)
			m_pBoomScrollLayer->instantMoveToPage(20);
		m_pBoomScrollLayer->instantMoveToPage(page);
	}
	else
	{
		scrollLayerMoved(m_pBoomScrollLayer->m_extendedLayer->getPosition()); //
	}

	addChild(m_pBoomScrollLayer);

	CCLabelBMFont* downloadLabel = CCLabelBMFont::create("Download the soundtracks", "bigFont.fnt");
	downloadLabel->setScale(0.5);

	CCMenuItemSpriteExtra* downloadBtn = CCMenuItemSpriteExtra::create(downloadLabel, this, menu_selector(SubZeroSelectLayer::onDownload));

	CCMenu* downloadMenu = CCMenu::create();
	downloadMenu->addChild(downloadBtn);
	addChild(downloadMenu);

	downloadMenu->setPosition(ccp(winSize.width / 2, director->getScreenBottom() + 35.f));

	CCMenu* btnMenu = CCMenu::create();
	addChild(btnMenu, 5);

	CCSprite* leftSpr = CCSprite::createWithSpriteFrameName("navArrowBtn_001.png");
	leftSpr->setFlipX(true);

	CCMenuItemSpriteExtra* leftBtn = CCMenuItemSpriteExtra::create(leftSpr, this, menu_selector(SubZeroSelectLayer::onPrev));
	btnMenu->addChild(leftBtn);

	leftBtn->setPosition(btnMenu->convertToNodeSpace(ccp(director->getScreenLeft() + 25.f, winSize.height / 2)));

	CCSprite* rightSpr = CCSprite::createWithSpriteFrameName("navArrowBtn_001.png");

	CCMenuItemSpriteExtra* rightBtn = CCMenuItemSpriteExtra::create(rightSpr, this, menu_selector(SubZeroSelectLayer::onNext));
	btnMenu->addChild(rightBtn);

	rightBtn->setPosition(btnMenu->convertToNodeSpace(ccp(director->getScreenRight() - 25.f, winSize.height / 2)));

	CCSprite* backSpr = CCSprite::createWithSpriteFrameName("GJ_arrow_01_001.png");
	CCMenuItemSpriteExtra* backBtn = CCMenuItemSpriteExtra::create(backSpr, this, menu_selector(SubZeroSelectLayer::onBack));

	CCMenu* backMenu = CCMenu::create();
	backMenu->addChild(backBtn);
	addChild(backMenu, 1);

	backMenu->setPosition(ccp(director->getScreenLeft() + 25.f, director->getScreenTop() - 22.f));
	setKeyboardEnabled(true);
	setKeypadEnabled(true);

	cocos2d::CCMenu* infoMenu = cocos2d::CCMenu::create();
	addChild(infoMenu);

	cocos2d::CCSprite* info = cocos2d::CCSprite::createWithSpriteFrameName("GJ_infoIcon_001.png");
	CCMenuItemSpriteExtra* infoBtn = CCMenuItemSpriteExtra::create(info, this, menu_selector(SubZeroSelectLayer::onInfo));
	infoMenu->addChild(infoBtn);

	infoMenu->setPosition({ director->getScreenRight() - 20.0f, director->getScreenTop() - 20.0f });


	/*log::info("screen top: {}", director->getScreenTop());*/
	//scrollLayerMoved({0, 0});

	return true;
}

cocos2d::ccColor3B SubZeroSelectLayer::colorForPage(int page)
{
	GameManager* GM = GameManager::sharedState();
	int colIDs[9] = { 9 ,1, 3, 5, 4, 11, 1, 3, 0 }; // GD uses switch statement but this is easier to write

	//1 is green
	//5 is blue
	//3 is lightblue

	return GM->colorForIdx(colIDs[page % 5]);
}

cocos2d::ccColor3B SubZeroSelectLayer::getColorValue(int level, int level2, float a3)
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


void SubZeroSelectLayer::updatePageWithObject(CCObject* page, CCObject* object) {
	if (!page || !object) {
		/*std::cerr << "Error: 'updatePageWithObject' is null." << std::endl;*/
		return;
	}
	GJGameLevel* level = static_cast<GJGameLevel*>(object);
	/*std::cout << "LEVELID BEFORE CASTING: " << level->m_levelID << std::endl;*/
	LevelPage* levelPage = dynamic_cast<LevelPage*>(page); 
	if (!levelPage) {
		/*	std::cerr << "Error: 'page' is not 'LevelPage' type." << std::endl;*/
		return;
	}
	levelPage->updateDynamicPage(level);
	/*std::cout << "LEVELID IN UPDATEPAGEWITHOBJECT: " << level->m_levelID << std::endl;*/
}


void SubZeroSelectLayer::onNext(CCObject*) {
	/*	m_nLevel++;*/
	 m_pBoomScrollLayer->quickUpdate();
	m_pBoomScrollLayer->moveToPage(m_nLevel +1);
}

void SubZeroSelectLayer::onPrev(CCObject*) {
	
	m_pBoomScrollLayer->quickUpdate();
	m_pBoomScrollLayer->moveToPage(m_nLevel - 1);
}
void SubZeroSelectLayer::scrollLayerMoved(CCPoint point) {
	const int pageCount = 4; 
	const float threshold = 0.7f; 

	float x = -point.x / this->m_fWindowWidth;
	while (x < 0.0f) {
		x += pageCount;
	}

	int ix = std::floor(x);


	float offset = x - ix;

	int firstPage = ix % pageCount;

	int lmao = firstPage + 1;
	int secondPage = lmao % pageCount;

	m_nLevel = firstPage;
	
	if (std::abs(offset) > threshold) {
	
		ccColor3B color = getColorValue(firstPage, secondPage - 1, 12);
		m_pBackground->setColor(color);



		ccColor3B Color1 = color;
		Color1.r = color.r * 0.8;
		Color1.g = color.g * 0.8;
		Color1.b = color.b * 0.8;

		ccColor3B Color2 = color;
		Color2.r = color.r * 0.9;
		Color2.g = color.g * 0.9;
		Color2.b = color.b * 0.9;



		auto m_pGround01Sprite = static_cast<CCSpriteBatchNode*>(m_pGround->getChildren()->objectAtIndex(0));
		auto m_pGround02Sprite = static_cast<CCSpriteBatchNode*>(m_pGround->getChildren()->objectAtIndex(1));

		if (Loader::get()->getLoadedMod("bitz.darkmode_v4"))
		{
			Color1 = { 40,40,40 };
			Color2 = { 40,40,40 };
		}
		
		CCArray* children = nullptr; 

		for (int i = 0; i < m_pGround01Sprite->getChildren()->count(); ++i) {
			if (m_pGround01Sprite != nullptr) {
				updateGroundColorSubZero(m_pGround01Sprite, Color1);
			}
			if (m_pGround02Sprite->getChildrenCount() == m_pGround01Sprite->getChildrenCount())
			{
				if (m_pGround02Sprite != nullptr) {
					updateGroundColorSubZero(m_pGround02Sprite, Color2);
				}
			}

		}
	}
}
	



void SubZeroSelectLayer::keyBackClicked() {
	onBack(nullptr);
}

void SubZeroSelectLayer::onBack(CCObject*) {
	auto back = Mod::get()->getSavedValue<int>("onsubzero");
	back = 10;
	Mod::get()->setSavedValue("onsubzero", back);
	CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(0.5, MenuLayer::scene(false)));
}

void SubZeroSelectLayer::onDownload(CCObject*) {
	auto songs = SongsLayer::create();
	songs->enterLayer();
	CCDirector::get()->getRunningScene()->addChild(songs, 2);
}


void ownShowSubZero(GJGameLevel* level) {

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






void SubZeroSelectLayer::onInfo(CCObject* sender) {

	/*std::cout << levellol << std::endl;*/
	auto levelObject = mainLevels->objectAtIndex(m_nLevel);
	if (auto gameLevel = dynamic_cast<GJGameLevel*>(levelObject)) {
		ownShowSubZero(gameLevel);
	}
}
