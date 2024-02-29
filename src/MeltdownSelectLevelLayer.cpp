#include "MeltdownSelectLevelLayer.h"
//#include "NewLevelPage.h"
#include <Geode/Geode.hpp>
#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>
#include <Geode/modify/LevelSelectLayer.hpp>
#include <Geode/modify/LevelInfoLayer.hpp>
#include <Geode/modify/LevelPage.hpp>
#include <Geode/modify/GJGameLevel.hpp>
#include <Geode/Enums.hpp>
#include "NewLevelSelectLayer.h"
#include <iostream>

using namespace geode::prelude;

ccColor3B colors2[] = {
    {255, 0, 0},    // Rojo
    {0, 255, 0},    // Verde
    {0, 0, 255}     // Azul
};
int numColors2 = sizeof(colors2) / sizeof(colors2[0]);
int currentColorIndex2 = 0;

MeltdownSelectLevelLayer* MeltdownSelectLevelLayer::create(int page) {
    auto ret = new MeltdownSelectLevelLayer();
    if (ret && ret->init(page)) {
        ret->autorelease();
        return ret;
    }
    CC_SAFE_DELETE(ret);
    return nullptr;
};

CCScene* MeltdownSelectLevelLayer::scene(int page) {
    auto layer = MeltdownSelectLevelLayer::create(page);
    auto scene = CCScene::create();
    scene->addChild(layer);
    return scene;
}

bool MeltdownSelectLevelLayer::init(int page) {
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
    m_background->setColor({ 0, 0, 255 });

    m_ground = GJGroundLayer::create(GM->m_loadedGroundID, -1);
    m_ground->setPositionY(std::min(128.f, (winSize.height / 2) - 110.f));


    m_ground->updateGround01Color(GM->colorForIdx(5));
    m_ground->updateGround02Color(GM->colorForIdx(5));
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

  
    //meltdown levels
   /* auto mlevel3 = GJGameLevel::create();
    std::ifstream mt3("./Resources/levels/1003.txt");
    std::string mtext3((std::istreambuf_iterator<char>(mt3)), std::istreambuf_iterator<char>());*/

    GJGameLevel* mlevel3 = GLM->getMainLevel(1003, true);
    mlevel3->m_levelName = "Airborne Robots";
    mlevel3->m_stars = 3;
    mlevel3->m_coins = 3;
    mlevel3->m_audioTrack = 25;
    mlevel3->m_difficulty = GJDifficulty::Hard;
    mlevel3->m_creatorName = "RobTopGames";

   /* auto mlevel2 = GJGameLevel::create();
    std::ifstream mt2("./Resources/levels/1002.txt");
    std::string mtext2((std::istreambuf_iterator<char>(mt2)), std::istreambuf_iterator<char>());*/
    GJGameLevel* mlevel2 = GLM->getMainLevel(1002, true);
    mlevel2->m_levelName = "Viking Arena";
    mlevel2->m_stars = 2;
    mlevel2->m_coins = 3;
    mlevel2->m_audioTrack = 24;
    mlevel2->m_difficulty = GJDifficulty::Normal;
    mlevel2->m_creatorName = "RobTopGames";
   /* auto mlevel1 = GJGameLevel::create();
    std::ifstream mt("./Resources/levels/1001.txt");
    std::string mtext((std::istreambuf_iterator<char>(mt)), std::istreambuf_iterator<char>());*/


    GJGameLevel* mlevel1 = GLM->getMainLevel(1001, true);
    mlevel1->m_levelName = "The Seven Seas";
    mlevel1->m_stars = 1;
    mlevel1->m_coins = 3;
    mlevel1->m_audioTrack = 23;
    mlevel1->m_difficulty = GJDifficulty::Easy;
    mlevel1->m_creatorName = "RobTopGames";
    auto isSubzero = Mod::get()->getSavedValue<int>("onsubzero");
  
        m_mainLevels->addObject(mlevel1);
        m_mainLevels->addObject(mlevel2);
        m_mainLevels->addObject(mlevel3);
    
   
       
      
        m_background->setID("bg-meltdown");
        m_ground->setID("ground-meltdown");
   /* for(int i = 1; i < 23; i++)
        m_mainLevels->addObject(GLM->getMainLevel(i, true));*/
    
    for(size_t i = 0; i < 3; i++)   
        m_levelPages->addObject(LevelPage::create(nullptr));
    
    //GJGameLevel* theTower = GJGameLevel::create();
    //theTower->m_levelID = -2;
    //m_mainLevels->addObject(theTower);

    GJGameLevel* defaultLevel = GJGameLevel::create();
    defaultLevel->m_levelID = -1;
    m_mainLevels->addObject(defaultLevel);

    m_scrollLayer = BoomScrollLayer::create(m_levelPages, 0, true, m_mainLevels, static_cast<DynamicScrollDelegate*>(this));
   
    auto pointer = (CCSpriteBatchNode*)m_scrollLayer->getChildren()->objectAtIndex(1);
    /*pointer->setVisible(false);*/
    pointer->setPositionY(director->getScreenBottom() - 45);
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

    cocos2d::CCMenu* infoMenu = cocos2d::CCMenu::create();
    addChild(infoMenu);

    cocos2d::CCSprite* info = cocos2d::CCSprite::createWithSpriteFrameName("GJ_infoIcon_001.png");
    CCMenuItemSpriteExtra* infoBtn = CCMenuItemSpriteExtra::create(info, this, menu_selector(MeltdownSelectLevelLayer::onInfo));
    infoMenu->addChild(infoBtn);

    infoMenu->setPosition({ director->getScreenRight() - 20.0f, director->getScreenTop() - 20.0f });


    return true;
}

void MeltdownSelectLevelLayer::keyBackClicked() {
    onClose(nullptr);
}

void MeltdownSelectLevelLayer::onClose(CCObject*) {
    auto back = Mod::get()->getSavedValue<int>("onsubzero");
    back = 10;
    Mod::get()->setSavedValue("onsubzero", back);
    CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(0.5, MenuLayer::scene(false)));
}

void MeltdownSelectLevelLayer::onSoundtracks(CCObject*) {
    auto songs = SongsLayer::create();
    songs->enterLayer();
    CCDirector::get()->getRunningScene()->addChild(songs, 2);
}

ccColor3B MeltdownSelectLevelLayer::colorForPage(int page) {
    auto GM = GameManager::sharedState();
	int colIDs[9] = { 5 ,7, 8, 9, 10, 11, 1, 3, 4 };

	return GM->colorForIdx(colIDs[page % 9]);
}


ccColor3B MeltdownSelectLevelLayer::getColorValue(int level1, int level2, float a3)
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

void MeltdownSelectLevelLayer::updatePageWithObject(CCObject* page, CCObject* object) {
    GJGameLevel* level = static_cast<GJGameLevel*>(object);
    static_cast<LevelPage*>(page)->updateDynamicPage(level);
    auto lol = Mod::get()->getSavedValue<int>("meltdownlevel");

    if (level->m_levelID == 1001)
    {
        lol = 1;
    }
 
    if (level->m_levelID == 1002)
    {
        lol = 2;
    }
   
    if (level->m_levelID == 1003)
    {
        lol = 3;
    }
    if (level->m_levelID == -1)
    {
        lol = 4;
    }

    Mod::get()->setSavedValue("meltdownlevel", lol);

    currentColorIndex2 = (currentColorIndex2 + 1) % numColors2;
   /* updateColors();*/
}

void MeltdownSelectLevelLayer::onNext(CCObject*) {
    m_level++;
    m_scrollLayer->moveToPage(m_level);
    currentColorIndex2 = (currentColorIndex2 + 1) % numColors2;
  /*  updateColors();*/
    //scrollLayerMoved({0, 0});
}

void MeltdownSelectLevelLayer::onPrev(CCObject*) {
    m_level--;
    m_scrollLayer->moveToPage(m_level);
    currentColorIndex2 = (currentColorIndex2 - 1 + numColors2) % numColors2;
    //updateColors();
    //scrollLayerMoved({0, 0});
}


void MeltdownSelectLevelLayer::instantPage(CCObject* sender, int a1) {
    
    m_scrollLayer->instantMoveToPage(a1);
    currentColorIndex2 = (currentColorIndex2 - 1 + numColors2) % numColors2;
   /* updateColors();*/
    //scrollLayerMoved({0, 0});
}
void show3(GJGameLevel* level) {

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






void MeltdownSelectLevelLayer::onInfo(CCObject* sender) {


    auto lol = Mod::get()->getSavedValue<int>("meltdownlevel");

    int levellol = 0;
    if (lol == 1)
    {
        levellol = 3;
    }

    if (lol == 2)
    {
        levellol = 0;
    }

    if (lol == 3)
    {
        levellol = 1;
    }

    if (lol == 4)
    {
        levellol = 2;
    }

    std::cout << levellol << std::endl;
    auto levelObject = m_mainLevels->objectAtIndex(levellol);
    // Verificar si el objeto es de tipo GJGameLevel
    if (auto gameLevel = dynamic_cast<GJGameLevel*>(levelObject)) {
        show3(gameLevel);
    }
}
//void MeltdownSelectLevelLayer::updateColors() {
//    ccColor3B color2 = colors2[currentColorIndex2];
//    m_background->setColor(color2);
//    m_ground->updateGround01Color(color2);
//    m_ground->updateGround02Color(color2);
//}
//void MeltdownSelectLevelLayer::pageNumberForPosition(CCPoint point) {
//    log::info("scrollLayerMoved");
//
//    std::cout << "Works!" << std::endl;
//    ccColor3B color = getColorValue(m_level, m_level - 1, 12);
//    m_background->setColor(color);
//    ccColor3B Color1 = color;
//    Color1.r = color.r * 0.8;
//    Color1.g = color.g * 0.8;
//    Color1.b = color.b * 0.8;
//    m_ground->updateGround01Color(Color1);
//
//    ccColor3B Color2 = color;
//    Color2.r = color.r * 0.9;
//    Color2.g = color.g * 0.9;
//    Color2.b = color.b * 0.9;
//    m_ground->updateGround02Color(Color2);
//}