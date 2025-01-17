#include <Geode/Geode.hpp>
#include "../Meltdown/MeltdownSelectLayer.h"
#include "../extras/BetterMDPopup.hpp"

using namespace geode::prelude;


void updateGroundColorMeltdown2(CCSpriteBatchNode* batch, const cocos2d::ccColor3B& color)
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


MeltdownSelectLayer* MeltdownSelectLayer::create(int page) {
	auto ret = new MeltdownSelectLayer();
	if (ret && ret->init(page)) {
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
};

	CCScene* MeltdownSelectLayer::scene(int page) {
		auto layer = MeltdownSelectLayer::create(page);
		auto scene = CCScene::create();
		scene->addChild(layer);
		return scene;
	}

bool MeltdownSelectLayer::init(int page)
{
	if (!LevelSelectLayer::init(page)) return false;

	m_scrollLayer->m_dynamicObjects->removeAllObjects();

	auto dotsArray = CCArrayExt<CCSprite*>(m_scrollLayer->m_dots);

	for (CCSprite* dot : dotsArray) {
		dot->removeFromParent();
	}
	m_scrollLayer->m_dots->removeAllObjects();

	// Configurar niveles
	std::vector<std::tuple<int, const char*, int, int, int, GJDifficulty>> levels = {
		{1001, "The Seven Seas", 1, 3, 23, GJDifficulty::Easy},
		{1002, "Viking Arena", 2, 3, 24, GJDifficulty::Normal},
		{1003, "Airborne Robots", 3, 3, 25, GJDifficulty::Hard}
	};


	
	auto GLM = GameLevelManager::sharedState();
	for (auto [id, name, stars, coins, track, difficulty] : levels) {
		auto level = GLM->getMainLevel(id, true);
		
		m_scrollLayer->m_dynamicObjects->addObject(level);
	}

	auto comingSoon = GJGameLevel::create();
	comingSoon->m_levelID = -1;
	m_scrollLayer->m_dynamicObjects->addObject(comingSoon);

	auto batchNode = CCSpriteBatchNode::create("smallDot.png", 29);
	m_scrollLayer->addChild(batchNode, 5);

	for (int i = 0; i < m_scrollLayer->m_dynamicObjects->count(); i++) {
		auto sprite = CCSprite::create("smallDot.png");
		batchNode->addChild(sprite);
		m_scrollLayer->m_dots->addObject(sprite);
	}

	m_scrollLayer->updateDots(0.f);
	m_scrollLayer->updatePages();
	updatePageWithObject(m_scrollLayer->m_pages->objectAtIndex(page % 3),
		m_scrollLayer->m_dynamicObjects->objectAtIndex(page));
	m_scrollLayer->repositionPagesLooped();

	

	
	//for (int i = 1001; i < 1004; i++) {
	//	m_scrollLayer->m_dynamicObjects->addObject(GameLevelManager::get()->getMainLevel(i, true));
	//}

	/*auto commingSoon = GJGameLevel::create();
	comingSoon->m_levelID = -1;*/

	//m_scrollLayer->m_dynamicObjects->addObject(comingSoon);

	//auto batchNode = CCSpriteBatchNode::create("smallDot.png", 29);
	//m_scrollLayer->addChild(batchNode, 5);

	//for (int i = 0; i < m_scrollLayer->m_dynamicObjects->count(); i++) {
	//	auto sprite = CCSprite::create("smallDot.png");
	//	batchNode->addChild(sprite);
	//	m_scrollLayer->m_dots->addObject(sprite);
	//}

	/*m_scrollLayer->updateDots(0.f);
	m_scrollLayer->updatePages();
	this->updatePageWithObject(m_scrollLayer->m_pages->objectAtIndex(page % 3), m_scrollLayer->m_dynamicObjects->objectAtIndex(page));
	this->m_scrollLayer->repositionPagesLooped();*/


	//auto director = CCDirector::sharedDirector();
	//auto winSize = director->getWinSize();
	//auto GM = GameManager::sharedState();
	//auto GLM = GameLevelManager::sharedState();

	//this->setID("MeltdownSelectLayer"_spr);
	//m_pBackground = CCSprite::create("GJ_gradientBG.png");
	//m_pBackground->setAnchorPoint({ 0.f, 0.f });
	//addChild(m_pBackground, -2);

	//m_pBackground->setScaleX((winSize.width + 10.f) / m_pBackground->getTextureRect().size.width);
	//m_pBackground->setScaleY((winSize.height + 10.f) / m_pBackground->getTextureRect().size.height);
	//m_pBackground->setPosition(ccp(-5, -5));
	//m_pBackground->setColor({ 0, 0, 255 });

	//m_pGround = GJGroundLayer::create(GM->m_loadedGroundID, -1);
	//m_pGround->setPositionY(std::min(128.f, (winSize.height / 2) - 110.f));
	//addChild(m_pGround, -1);


	//
	////auto m_pGround01Sprite = m_pGround->getChildByType<CCSpriteBatchNode>(3); // Obtén el hijo por tipo e índice
	////auto m_pGround02Sprite = m_pGround->getChildByType<CCSpriteBatchNode>(4);

	//CCObject* pObj = nullptr;
	//if (Loader::get()->getLoadedMod("bitz.darkmode_v4"))
	//{
	//	CCARRAY_FOREACH(m_pGround->getChildren(), pObj)
	//	{
	//		if (instanceof<CCSpriteBatchNode>(pObj)) {
	//			auto spriteBatchNode = dynamic_cast<CCSpriteBatchNode*>(pObj);
	//			if (spriteBatchNode) {
	//				updateGroundColorMeltdown2(spriteBatchNode, { 40, 40, 40 });
	//			}
	//		}
	//	}
	//}
	//else
	//{
	//	CCARRAY_FOREACH(m_pGround->getChildren(), pObj)
	//	{
	//		if (instanceof<CCSpriteBatchNode>(pObj)) {
	//			auto spriteBatchNode = dynamic_cast<CCSpriteBatchNode*>(pObj);
	//			if (spriteBatchNode) {
	//				updateGroundColorMeltdown2(spriteBatchNode, GM->colorForIdx(5));
	//			}
	//		}
	//	}
	//}
	//CCSprite* topBar = CCSprite::createWithSpriteFrameName("GJ_topBar_001.png");
	//topBar->setAnchorPoint({ 0.5f, 1.f });
	//topBar->setPosition(ccp(winSize.width / 2, director->getScreenTop() + 1.f));
	//addChild(topBar, 1);

	//CCSprite* rightArt = CCSprite::createWithSpriteFrameName("GJ_sideArt_001.png");
	//rightArt->setAnchorPoint({ 1.f, 0.f });
	//rightArt->setPosition(ccp(director->getScreenRight() + 1.f, director->getScreenBottom() - 1.f));
	//rightArt->setFlipX(true);
	//addChild(rightArt, 1);

	//CCSprite* leftArt = CCSprite::createWithSpriteFrameName("GJ_sideArt_001.png");
	//leftArt->setAnchorPoint({ 0.f, 0.f });
	//leftArt->setPosition(ccp(director->getScreenLeft() - 1.f, director->getScreenBottom() - 1.f));
	//addChild(leftArt, 1);

	//mainLevels = CCArray::create();
	//levelPages = CCArray::create();

	//m_nLevel = 0;
	///*for (int i = 1; i < 4; i++)
	//	mainLevels->addObject(GLM->getMainLevel(i, true));*/

	///*for (size_t i = 4; i > 0; i--)*/
	//

	//GJGameLevel* mlevel1 = GLM->getMainLevel(1001, true);
	//GJGameLevel* mlevel2 = GLM->getMainLevel(1002, true);
	//GJGameLevel* mlevel3 = GLM->getMainLevel(1003, true);
	//mlevel1->m_levelName = "The Seven Seas";
	//mlevel1->m_stars = 1;
	//mlevel1->m_coins = 3;
	//mlevel1->m_levelType = GJLevelType::Local;
	//mlevel1->m_audioTrack = 23;
	//mlevel1->m_difficulty = GJDifficulty::Easy;
	//mlevel1->m_creatorName = "RobTopGames";


	//mlevel2->m_levelName = "Viking Arena";
	//mlevel2->m_stars = 2;
	//mlevel2->m_coins = 3;
	//mlevel2->m_levelType = GJLevelType::Local;
	//mlevel2->m_audioTrack = 24;
	//mlevel2->m_difficulty = GJDifficulty::Normal;
	//mlevel2->m_creatorName = "RobTopGames";

	//mlevel3->m_levelName = "Airborne Robots";
	//mlevel3->m_stars = 3;
	//mlevel3->m_coins = 3;
	//mlevel3->m_levelType = GJLevelType::Local;
	//mlevel3->m_audioTrack = 25;
	//mlevel3->m_difficulty = GJDifficulty::Hard;
	//mlevel3->m_creatorName = "RobTopGames";

	//mainLevels->addObject(mlevel1);
	//mainLevels->addObject(mlevel2);
	//mainLevels->addObject(mlevel3);


	//	levelPages->addObject(LevelPage::create(nullptr));
	//	levelPages->addObject(LevelPage::create(nullptr));
	//	levelPages->addObject(LevelPage::create(nullptr));
	////GJGameLevel* theTower = GJGameLevel::create();
	////theTower->m_levelID = -2;
	////m_mainLevels->addObject(theTower);

	//GJGameLevel* defaultLevel = GJGameLevel::create();
	//defaultLevel->m_levelID = -1;
	//mainLevels->addObject(defaultLevel);

	//m_pBoomScrollLayer = BoomScrollLayer::create(levelPages, 0, true, mainLevels, this);

	//auto pointer = (CCSpriteBatchNode*)m_pBoomScrollLayer->getChildren()->objectAtIndex(1);
	///*pointer->setVisible(false);*/
	//pointer->setPositionY(director->getScreenBottom() - 45);
	//m_fWindowWidth = winSize.width;
	//m_pBoomScrollLayer->m_extendedLayer->m_delegate = static_cast<BoomScrollLayerDelegate*>(this);

	//if (page)
	//{
	//	if (page == 21)
	//		m_pBoomScrollLayer->instantMoveToPage(20);
	//	m_pBoomScrollLayer->instantMoveToPage(page);
	//}
	//else
	//{
	//	scrollLayerMoved(m_pBoomScrollLayer->m_extendedLayer->getPosition()); //
	//}

	//addChild(m_pBoomScrollLayer);

	//CCLabelBMFont* downloadLabel = CCLabelBMFont::create("Download the soundtracks", "bigFont.fnt");
	//downloadLabel->setScale(0.5);

	//CCMenuItemSpriteExtra* downloadBtn = CCMenuItemSpriteExtra::create(downloadLabel, this, menu_selector(MeltdownSelectLayer::onDownload));

	//CCMenu* downloadMenu = CCMenu::create();
	//downloadMenu->addChild(downloadBtn);
	//addChild(downloadMenu);

	//downloadMenu->setPosition(ccp(winSize.width / 2, director->getScreenBottom() + 35.f));

	//CCMenu* btnMenu = CCMenu::create();
	//addChild(btnMenu, 5);

	//CCSprite* leftSpr = CCSprite::createWithSpriteFrameName("navArrowBtn_001.png");
	//leftSpr->setFlipX(true);

	//CCMenuItemSpriteExtra* leftBtn = CCMenuItemSpriteExtra::create(leftSpr, this, menu_selector(MeltdownSelectLayer::onPrev));
	//btnMenu->addChild(leftBtn);

	//leftBtn->setPosition(btnMenu->convertToNodeSpace(ccp(director->getScreenLeft() + 25.f, winSize.height / 2)));

	//CCSprite* rightSpr = CCSprite::createWithSpriteFrameName("navArrowBtn_001.png");

	//CCMenuItemSpriteExtra* rightBtn = CCMenuItemSpriteExtra::create(rightSpr, this, menu_selector(MeltdownSelectLayer::onNext));
	//btnMenu->addChild(rightBtn);

	//rightBtn->setPosition(btnMenu->convertToNodeSpace(ccp(director->getScreenRight() - 25.f, winSize.height / 2)));

	//CCSprite* backSpr = CCSprite::createWithSpriteFrameName("GJ_arrow_01_001.png");
	//CCMenuItemSpriteExtra* backBtn = CCMenuItemSpriteExtra::create(backSpr, this, menu_selector(MeltdownSelectLayer::onBack));

	//CCMenu* backMenu = CCMenu::create();
	//backMenu->addChild(backBtn);
	//addChild(backMenu, 1);

	//backMenu->setPosition(ccp(director->getScreenLeft() + 25.f, director->getScreenTop() - 22.f));
	//setKeyboardEnabled(true);
	//setKeypadEnabled(true);

	//cocos2d::CCMenu* infoMenu = cocos2d::CCMenu::create();
	//addChild(infoMenu);

	//cocos2d::CCSprite* info = cocos2d::CCSprite::createWithSpriteFrameName("GJ_infoIcon_001.png");
	//CCMenuItemSpriteExtra* infoBtn = CCMenuItemSpriteExtra::create(info, this, menu_selector(MeltdownSelectLayer::onInfo));
	//infoMenu->addChild(infoBtn);

	//infoMenu->setPosition({ director->getScreenRight() - 20.0f, director->getScreenTop() - 20.0f });


	///*log::info("screen top: {}", director->getScreenTop());*/
	////scrollLayerMoved({0, 0});

	return true;
}

cocos2d::ccColor3B MeltdownSelectLayer::colorForPage(int page)
{
	GameManager* GM = GameManager::sharedState();
	//int colIDs[9] = {1, 3, 5, 4 }; // GD uses switch statement but this is easier to write

	////1 is green
	////5 is blue
	////3 is lightblue

	//return GM->colorForIdx(colIDs[page % 5]);

	return GM->colorForIdx(0);
}


cocos2d::ccColor3B MeltdownSelectLayer::getColorValue(int level, int level2, float a3)
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
//
//
//void MeltdownSelectLayer::updatePageWithObject(CCObject* page, CCObject* object) {
//	if (!page || !object) {
//	/*	std::cerr << "Error: 'updatePageWithObject' is null." << std::endl;*/
//		return;
//	}
//
//	GJGameLevel* level = static_cast<GJGameLevel*>(object);
//	/*std::cout << "LEVELID BEFORE CASTING: " << level->m_levelID << std::endl;*/
//
//	LevelPage* levelPage = dynamic_cast<LevelPage*>(page); 
//
//	if (!levelPage) {
//	/*	std::cerr << "Error: 'page' is not 'LevelPage' type." << std::endl;*/
//		return;
//	}
//	levelPage->updateDynamicPage(level);
//
//	/*std::cout << "LEVELID IN UPDATEPAGEWITHOBJECT: " << level->m_levelID << std::endl;*/
//}

//
//void MeltdownSelectLayer::onNext(CCObject*) {
//	/*	m_nLevel++;*/
//	 m_pBoomScrollLayer->quickUpdate();
//	m_pBoomScrollLayer->moveToPage(m_nLevel +1);
//}
//
//void MeltdownSelectLayer::onPrev(CCObject*) {
//	
//	m_pBoomScrollLayer->quickUpdate();
//	m_pBoomScrollLayer->moveToPage(m_nLevel - 1);
//}
//void MeltdownSelectLayer::scrollLayerMoved(CCPoint point) {
//	const int pageCount = 4; // Obtener el número de páginas dinámicamente
//	const float threshold = 0.7f; // Umbral para determinar cambios significativos de página
//
//	float x = -point.x / this->m_fWindowWidth;
//	while (x < 0.0f) {
//		x += pageCount;
//	}
//
//	int ix = std::floor(x);
//
//	// Calcular el desplazamiento relativo dentro de la página actual
//	float offset = x - ix;
//
//	int firstPage = ix % pageCount;
//
//	int lmao = firstPage + 1;
//	int secondPage = lmao % pageCount;
//
//	m_nLevel = firstPage;
//	
//	if (std::abs(offset) > threshold) {
//
//		ccColor3B color = getColorValue(firstPage, secondPage - 1, 12);
//		m_pBackground->setColor(color);
//
//
//
//		ccColor3B Color1 = color;
//		Color1.r = color.r * 0.8;
//		Color1.g = color.g * 0.8;
//		Color1.b = color.b * 0.8;
//
//		ccColor3B Color2 = color;
//		Color2.r = color.r * 0.9;
//		Color2.g = color.g * 0.9;
//		Color2.b = color.b * 0.9;
//
//
//
//		auto m_pGround01Sprite = static_cast<CCSpriteBatchNode*>(m_pGround->getChildren()->objectAtIndex(0));
//		auto m_pGround02Sprite = static_cast<CCSpriteBatchNode*>(m_pGround->getChildren()->objectAtIndex(1));
//
//		if (Loader::get()->getLoadedMod("bitz.darkmode_v4"))
//		{
//			Color1 = { 40,40,40 };
//			Color2 = { 40,40,40 };
//		}
//		CCArray* children = nullptr;  
//
//		for (int i = 0; i < m_pGround01Sprite->getChildren()->count(); ++i) {
//			if (m_pGround01Sprite != nullptr) {
//				updateGroundColorMeltdown2(m_pGround01Sprite, Color1);
//			}
//			if (m_pGround02Sprite->getChildrenCount() == m_pGround01Sprite->getChildrenCount())
//			{
//				if (m_pGround02Sprite != nullptr) {
//					updateGroundColorMeltdown2(m_pGround02Sprite, Color2);
//				}
//			}
//
//		}
//	}
//}
//	
//
//
//
//void MeltdownSelectLayer::keyBackClicked() {
//	onBack(nullptr);
//}
//
//void MeltdownSelectLayer::onBack(CCObject*) {
//	auto back = Mod::get()->getSavedValue<int>("onsubzero");
//	back = 10;
//	Mod::get()->setSavedValue("onsubzero", back);
//	CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(0.5, MenuLayer::scene(false)));
//}
//
//void MeltdownSelectLayer::onDownload(CCObject*) {
//	auto songs = SongsLayer::create();
//	songs->enterLayer();
//	CCDirector::get()->getRunningScene()->addChild(songs, 2);
//}
//
//
//void ownShow(GJGameLevel* level) {
//
//	if (level == nullptr) return;
//
//
//	if (level->m_levelID == -1) {
//		FLAlertLayer::create(nullptr, "It's a secret...", "<cr>Roses are red</c>\n<cl>Violets are blue</c>\n<cg>Welcome to</c>\n<cy>2.2</c>", "OK", nullptr, 360)->show();
//		return;
//	}
//
//	if (level->m_levelID == -2) {
//		FLAlertLayer::create(nullptr, "The Tower", "The path leads to an <cr>old tower</c>. It's been left alone for <cg>years</c>, with little reason to <co>explore</c>.", "OK", nullptr, 360)->show();
//		return;
//	}
//
//
//	if (level->m_levelID != -1 && level->m_levelID != -2)
//	{
//		std::string name = level->m_levelName;
//		std::string contentStream =
//			"<cy>" + name + "</c>" +
//			"\n<cg>Total Attempts</c>: " + std::to_string(level->m_attempts) +
//			"\n<cl>Total Jumps</c>: " + std::to_string(level->m_jumps) +
//			"\n<cp>Normal</c>: " + std::to_string(level->m_normalPercent) + "%" +
//			"\n<co>Practice</c>: " + std::to_string(level->m_practicePercent) + "%";
//
//		FLAlertLayer::create(nullptr, "Level Stats", contentStream, "OK", nullptr, 360)->show();
//		return;
//	}
//}
//
//
//
//
//
//
//void MeltdownSelectLayer::onInfo(CCObject* sender) {
//
//	/*std::cout << levellol << std::endl;*/
//	auto levelObject = mainLevels->objectAtIndex(m_nLevel);
//	if (auto gameLevel = dynamic_cast<GJGameLevel*>(levelObject)) {
//		ownShow(gameLevel);
//	}
//}
