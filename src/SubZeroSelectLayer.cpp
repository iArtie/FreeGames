#include "SubZeroSelectLayer.h"
//#include "NewLevelPage.h"
#include <Geode/Geode.hpp>
#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>
#include <Geode/modify/LevelSelectLayer.hpp>
#include <Geode/modify/LevelInfoLayer.hpp>
#include <Geode/modify/LevelPage.hpp>
#include <Geode/modify/GJGameLevel.hpp>
#include <Geode/Enums.hpp>
#include "SubZeroSelectLayer.h"
#include <iostream>

using namespace geode::prelude;

ccColor3B colors[] = {
    {255, 0, 0},    // Rojo
    {0, 255, 0},    // Verde
    {0, 0, 255}     // Azul
};
int numColors = sizeof(colors) / sizeof(colors[0]);
int currentColorIndex = 0;

void updateGroundColorSubZero(CCSpriteBatchNode* batch, const cocos2d::ccColor3B& color)
{

    for (int i = 0; i < batch->getChildren()->count(); ++i) {
        auto sprite = (CCSprite*)batch->getChildren()->objectAtIndex(i);
        sprite->setColor(color);
        for (int o = 0; o < sprite->getChildren()->count(); ++o) {
            auto spriteChild = (CCSprite*)sprite->getChildren()->objectAtIndex(o);
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

bool SubZeroSelectLayer::init(int page) {
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
    addChild(m_ground ,-1);

    auto m_pGround01Sprite = static_cast<CCSpriteBatchNode*>(m_ground->getChildByID("ground-sprites"));
    auto m_pGround02Sprite = static_cast<CCSpriteBatchNode*>(m_ground->getChildByID("ground-sprites-2"));


    CCArray* children = nullptr;  // Inicializamos children a nullptr

    for (int i = 0; i < m_pGround01Sprite->getChildren()->count(); ++i) {
        if (m_pGround01Sprite != nullptr) {
            updateGroundColorSubZero(m_pGround01Sprite, { 0, 0, 255 });
        }
        if (m_pGround02Sprite != nullptr) {
            updateGroundColorSubZero(m_pGround02Sprite, { 0, 0, 255 });
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

    m_mainLevels = CCArray::create();
    m_levelPages = CCArray::create();

    m_level = 0;

    //Subzero levels
    
  /*  auto level3 = GJGameLevel::create();
    std::ifstream t3("./Resources/levels/4003.txt");
    std::string text3((std::istreambuf_iterator<char>(t3)), std::istreambuf_iterator<char>());*/

    GJGameLevel* level3 = GLM->getMainLevel(4003, true);
    level3->m_levelName = "Power Trip";
    level3->m_levelID = 4003;
    level3->m_levelType = GJLevelType::Local;
    level3->m_stars = 8;
    level3->m_coins = 3;
    level3->m_audioTrack = 39;
    level3->m_difficulty = GJDifficulty::Harder;
    level3->m_creatorName = "RobTopGames";

    //auto level2 = GJGameLevel::create();
    //std::ifstream t2("./Resources/levels/4002.txt");
    //std::string text2((std::istreambuf_iterator<char>(t2)), std::istreambuf_iterator<char>());
    GJGameLevel* level2 = GLM->getMainLevel(4002, true);
    level2->m_levelName = "Nock Em";
    level2->m_levelType = GJLevelType::Local;
    level2->m_stars = 6;
    level2->m_coins = 3;
    level2->m_audioTrack = 38;
    level2->m_difficulty = GJDifficulty::Hard;
    level2->m_creatorName = "RobTopGames";

   /* auto level1 = GJGameLevel::create();
    std::ifstream t("./Resources/levels/4001.txt");
    std::string text((std::istreambuf_iterator<char>(t)), std::istreambuf_iterator<char>());*/


    GJGameLevel* level1 = GLM->getMainLevel(1, true);
    /*GJGameLevel* level1 = GLM->getMainLevel(4001, true);*/
    /*auto level1 = GJGameLevel::create();*/
   /* level1->m_levelName = "Press Start";
    level1->m_stars = 1;
    level1->m_coins = 3;
    level1->m_audioTrack = 23;
    level1->m_difficulty = GJDifficulty::Easy;
    level1->m_creatorName = "RobTopGames";*/
   /* level1->m_levelName = "Press Start";
    level1->m_levelID = 4001;
    level1->m_levelType = GJLevelType::Local;
    level1->m_stars = 4;
    level1->m_coins = 3;
    level1->m_audioTrack = 37;
    level1->m_difficulty = GJDifficulty::Normal;
    level1->m_creatorName = "RobTopGames";*/
    
  

    
    
        m_mainLevels->addObject(level1);
        m_mainLevels->addObject(level2);
        m_mainLevels->addObject(level3);
    
   

           
           
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

    m_scrollLayer = BoomScrollLayer::create(m_levelPages, 1, true, m_mainLevels, static_cast<DynamicScrollDelegate*>(this));
   
    auto pointer = (CCSpriteBatchNode*)m_scrollLayer->getChildren()->objectAtIndex(1);
    /*pointer->setVisible(false);*/
    pointer->setPositionY(director->getScreenBottom() - 45);
    addChild(m_scrollLayer);

    CCLabelBMFont* downloadLabel = CCLabelBMFont::create("Download the soundtracks", "bigFont.fnt");
    downloadLabel->setScale(0.5);

    CCMenuItemSpriteExtra* downloadBtn = CCMenuItemSpriteExtra::create(downloadLabel, this, menu_selector(SubZeroSelectLayer::onSoundtracks));

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
    CCMenuItemSpriteExtra* backBtn = CCMenuItemSpriteExtra::create(backSpr, this, menu_selector(SubZeroSelectLayer::onClose));

    CCMenu* backMenu = CCMenu::create();
    backMenu->addChild(backBtn);
    addChild(backMenu, 1);

    backMenu->setPosition(ccp(director->getScreenLeft() + 25.f, director->getScreenTop() - 22.f));
    setKeyboardEnabled(true);
    setKeypadEnabled(true);
   /* log::info("screen top: {}", director->getScreenTop());*/
    //scrollLayerMoved({0, 0});

    cocos2d::CCMenu* infoMenu = cocos2d::CCMenu::create();
    addChild(infoMenu);

    cocos2d::CCSprite* info = cocos2d::CCSprite::createWithSpriteFrameName("GJ_infoIcon_001.png");
    CCMenuItemSpriteExtra* infoBtn = CCMenuItemSpriteExtra::create(info, this, menu_selector(SubZeroSelectLayer::onInfo));
    infoMenu->addChild(infoBtn);

    infoMenu->setPosition({ director->getScreenRight() - 20.0f, director->getScreenTop() - 20.0f });


    return true;
}

void SubZeroSelectLayer::keyBackClicked() {
    onClose(nullptr);
}

void SubZeroSelectLayer::onClose(CCObject*) {
    auto back = Mod::get()->getSavedValue<int>("onsubzero");
    back = 10;
    Mod::get()->setSavedValue("onsubzero", back);
    CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(0.5, MenuLayer::scene(false)));
}

void SubZeroSelectLayer::onSoundtracks(CCObject*) {
    auto songs = SongsLayer::create();
    songs->enterLayer();
    CCDirector::get()->getRunningScene()->addChild(songs, 2);
}

ccColor3B SubZeroSelectLayer::colorForPage(int page) {
    auto GM = GameManager::sharedState();
	int colIDs[9] = { 5 ,7, 8, 9, 10, 11, 1, 3, 4 };

	return GM->colorForIdx(colIDs[page % 9]);
}


ccColor3B SubZeroSelectLayer::getColorValue(int level1, int level2, float a3)
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
void SubZeroSelectLayer::updatePageWithObject(LevelPage* page, GJGameLevel* level)
{
    page->updateDynamicPage(level);
    
}
//void SubZeroSelectLayer::updatePageWithObject(CCObject* page, CCObject* object) {
//    GJGameLevel* level = static_cast<GJGameLevel*>(object);
//    static_cast<LevelPage*>(page)->updateDynamicPage(level);
//    auto lol = Mod::get()->getSavedValue<int>("subzerolevellol");
//    if (level->m_levelID == 4001)
//    {
//        lol = 1;
//    }
//
//    if (level->m_levelID == 4002)
//    {
//        lol = 2;
//    }
//
//    if (level->m_levelID == 4003)
//    {
//        lol = 3;
//    }
//    if (level->m_levelID == -1)
//    {
//        lol = 4;
//    }
//
//    Mod::get()->setSavedValue("subzerolevellol", lol);
//    currentColorIndex = (currentColorIndex + 1) % numColors;
//  /*  updateColors();*/
//}

void SubZeroSelectLayer::onNext(CCObject*) {
    m_level++;

  /*  auto lol = Mod::get()->getSavedValue<int>("subzerolevellol");

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
    }*/
    m_scrollLayer->moveToPage(m_level);
    currentColorIndex = (currentColorIndex + 1) % numColors;
   /* updateColors();*/
    //scrollLayerMoved({0, 0});
}

void SubZeroSelectLayer::onPrev(CCObject*) {
    m_level--;
    m_scrollLayer->moveToPage(m_level);
    currentColorIndex = (currentColorIndex - 1 + numColors) % numColors;
    //updateColors();
    //scrollLayerMoved({0, 0});
}


void SubZeroSelectLayer::instantPage(CCObject* sender, int a1) {
    
    m_scrollLayer->instantMoveToPage(a1);
    currentColorIndex = (currentColorIndex - 1 + numColors) % numColors;
  /*  updateColors();*/
    //scrollLayerMoved({0, 0});
}
void SubZeroSelectLayer::updateColors() {
    ccColor3B color = colors[currentColorIndex];
    m_background->setColor(color);
    auto m_pGround01Sprite = static_cast<CCSpriteBatchNode*>(m_ground->getChildByID("ground-sprites"));
    auto m_pGround02Sprite = static_cast<CCSpriteBatchNode*>(m_ground->getChildByID("ground-sprites-2"));


    CCArray* children = nullptr;  // Inicializamos children a nullptr

    for (int i = 0; i < m_pGround01Sprite->getChildren()->count(); ++i) {
        if (m_pGround01Sprite != nullptr) {
            updateGroundColorSubZero(m_pGround01Sprite, color);
        }
        if (m_pGround02Sprite != nullptr) {
            updateGroundColorSubZero(m_pGround02Sprite, color);
        }
    }
}
void SubZeroSelectLayer::scrollLayerMoved(CCPoint point) {
    log::info("scrollLayerMoved");

    std::cout << "Works!" << std::endl;
    ccColor3B color = getColorValue(m_level, m_level - 1, 12);
    m_background->setColor(color);
    ccColor3B Color1 = color;
    Color1.r = color.r * 0.8;
    Color1.g = color.g * 0.8;
    Color1.b = color.b * 0.8;
    

    ccColor3B Color2 = color;
    Color2.r = color.r * 0.9;
    Color2.g = color.g * 0.9;
    Color2.b = color.b * 0.9;

    auto m_pGround01Sprite = static_cast<CCSpriteBatchNode*>(m_ground->getChildByID("ground-sprites"));
    auto m_pGround02Sprite = static_cast<CCSpriteBatchNode*>(m_ground->getChildByID("ground-sprites-2"));


    CCArray* children = nullptr;  // Inicializamos children a nullptr

    for (int i = 0; i < m_pGround01Sprite->getChildren()->count(); ++i) {
        if (m_pGround01Sprite != nullptr) {
            updateGroundColorSubZero(m_pGround01Sprite, Color1);
        }
        if (m_pGround02Sprite != nullptr) {
            updateGroundColorSubZero(m_pGround02Sprite, Color2);
        }
    }
}


void show(GJGameLevel* level) {

    if (level == nullptr) return;


    if (level->m_levelID == -1) {
        FLAlertLayer::create(nullptr, "It's a secret...", "<cr>Roses are red</c>\n<cl>Violets are blue</c>\n<cg>Welcome to</c>\n<cy>2.2</c>", "OK", nullptr, 360)->show();
        return;
    }

    if (level->m_levelID == -2) {
        FLAlertLayer::create(nullptr, "The Tower", "The path leads to an <cr>old tower</c>. It's been left alone for <cg>years</c>, with little reason to <co>explore</c>.", "OK", nullptr, 360)->show();
        return;
    }


    if(level->m_levelID != -1 && level->m_levelID != -2)
    {
        std::string name = level->m_levelName;
        std::string contentStream = 
            "<cy>" + name +"</c>"+
            "\n<cg>Total Attempts</c>: " + std::to_string(level->m_attempts) +
            "\n<cl>Total Jumps</c>: " + std::to_string(level->m_jumps) +
            "\n<cp>Normal</c>: " + std::to_string(level->m_normalPercent) + "%" +
            "\n<co>Practice</c>: " + std::to_string(level->m_practicePercent) + "%";

        FLAlertLayer::create(nullptr, "Level Stats", contentStream, "OK", nullptr, 360)->show();
        return;
    }
}
  

    

    

void SubZeroSelectLayer::onInfo(CCObject* sender) {


    auto lol = Mod::get()->getSavedValue<int>("subzerolevellol");
   
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

    /*std::cout << levellol << std::endl;*/
    auto levelObject = m_mainLevels->objectAtIndex(levellol);
    // Verificar si el objeto es de tipo GJGameLevel
    if (auto gameLevel = dynamic_cast<GJGameLevel*>(levelObject)) {
        show(gameLevel);
    }
}