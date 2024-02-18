
#include <Geode/Geode.hpp>

#include "../src/ownWorldLevelPage.hpp"
//#include "ownWorldLevelPage.hpp"
#include <windows.h>
#include <string>
#include <cstdlib>
#include <cocos2d.h>
//#include "enums.h"



using namespace geode::prelude;

//ownWorldLevelPage* ownWorldLevelPage::create(GJGameLevel* level) {
//	auto ret = new ownWorldLevelPage();
//	if (ret && ret->init(level)) {
//		ret->autorelease();
//		return ret;
//	}
//	CC_SAFE_DELETE(ret);
//	return nullptr;
//};

void ownWorldLevelPage::addSecretDoor()
{
	GameManager* GM = GameManager::sharedState();
	
	if (GM->getGameVariable("6"))
	{
		cocos2d::CCSize winSize = cocos2d::CCDirector::sharedDirector()->getWinSize();

		std::string door = GM->getGameVariable("8") ? "secretDoorBtn2_open_001.png" : "secretDoorBtn2_closed_001.png";
		
		m_pDoor = cocos2d::CCSprite::createWithSpriteFrameName(door.c_str());

		if (!GM->getGameVariable("7"))
			m_pDoor->setOpacity(0);

		cocos2d::CCMenu* menu = cocos2d::CCMenu::create();
		addChild(menu);

		auto doorBtn = CCMenuItemSpriteExtra::create(m_pDoor, this, menu_selector(LevelPage::onSecretDoor));
		// doorBtn->0x480 = 0;
		// doorBtn->0x484 = 1;
		menu->addChild(doorBtn);
		menu->setPosition({ winSize.width / 2, 80.0f });

		doorBtn->setSizeMult(2.0f);
		m_pEvents->addObject(doorBtn);
		m_pEvents->addObject(m_pDoor);
	}
}

bool ownWorldLevelPage::init(GJGameLevel* level)
{
	bool init = cocos2d::CCLayer::init();
	if (init)
	{
		setTouchEnabled(true);
		cocos2d::CCDirector* director = cocos2d::CCDirector::sharedDirector();
		cocos2d::CCSize winSize = director->getWinSize();
		m_obPageSize = cocos2d::CCSize(340, 95);

		m_pPlayerLevelStats = cocos2d::CCArray::create();
		m_pPlayerLevelStats->retain();

		m_pLevelInfo = cocos2d::CCArray::create();
		m_pLevelInfo->retain();

		m_pMenu = cocos2d::CCMenu::create();
		addChild(m_pMenu, -1);

		m_pMenu->setPosition({ winSize.width / 2, (winSize.height / 2) + 60.0f });

		m_pBackgroundSquare = cocos2d::extension::CCScale9Sprite::create("square02_001.png", { 0.0f, 0.0f, 80.0f, 80.0f });
		m_pBackgroundSquare->setOpacity(125);
		m_pBackgroundSquare->setPosition({ winSize.width / 2,(winSize.height / 2) + 50.0f });

		cocos2d::CCSprite* sprite = cocos2d::CCSprite::create();
		sprite->addChild(m_pBackgroundSquare);
		sprite->setContentSize(m_pBackgroundSquare->getContentSize());

		CCSize contentSize = m_pBackgroundSquare->getContentSize();
		m_pBackgroundSquare->setContentSize({ contentSize.width / 2, contentSize.height / 2 });

		auto playBtn = CCMenuItemSpriteExtra::create(sprite, this, menu_selector(LevelPage::onPlay));

		// playBtn->0x118 = 1.1f;

		m_pMenu->addChild(playBtn);

		cocos2d::CCSprite* normalOutterBar = cocos2d::CCSprite::create("GJ_progressBar_001.png");
		normalOutterBar->setColor({ 0, 0, 0 });
		normalOutterBar->setOpacity(125);
		normalOutterBar->setScale(1.0f);
		addChild(normalOutterBar, 3);

		m_pPlayerLevelStats->addObject(normalOutterBar);


		m_pProgressBar = cocos2d::CCSprite::create("GJ_progressBar_001.png");
		m_pProgressBar->setScaleX(0.992f);
		m_pProgressBar->setScaleY(0.86f);

		m_pProgressBar->setColor({0,255,0}); // { 0x00, 0xFF, 0x00 }

		m_fProgressBarWidth = m_pProgressBar->getTextureRect().size.width;

		float width = m_pProgressBar->getContentSize().width - (m_pProgressBar->getContentSize().width * 0.992);

		normalOutterBar->addChild(m_pProgressBar);

		m_pProgressBar->setAnchorPoint({ 0.0f, 0.5f });
		m_pPracticeBar->setPosition({ width / 2,normalOutterBar->getContentSize().height / 2 });



		cocos2d::CCSprite* practiceOutterBar = cocos2d::CCSprite::create("GJ_progressBar_001.png");
		practiceOutterBar->setColor({ 0, 0, 0 });
		practiceOutterBar->setOpacity(125);
		practiceOutterBar->setScale(1.0f);
		addChild(practiceOutterBar, 3);

		cocos2d::CCPoint practicePos = normalOutterBar->getPosition();
		practicePos.y -= 50.0f;

		practiceOutterBar->setPosition(practicePos);

		m_pPlayerLevelStats->addObject(practiceOutterBar);


		m_pPracticeBar = cocos2d::CCSprite::create("GJ_progressBar_001.png");
		m_pPracticeBar->setScaleX(0.992f);
		m_pPracticeBar->setScaleY(0.86f);

		m_pPracticeBar->setColor({ 0x00, 0xFF, 0xFF }); // { 0x00, 0xFF, 0xFF }

		m_pPracticeBar->setAnchorPoint({ 0.0f, 0.5f });
		m_pPracticeBar->setPosition(m_pProgressBar->getPosition()); // aight then


		m_pLabel = cocos2d::CCLabelBMFont::create(" ", "bigFont.fnt");
		addChild(m_pLabel, 4);

		m_pLabel->setPosition(normalOutterBar->getPosition());
		m_pLabel->setScale(0.5f);

		m_pPlayerLevelStats->addObject(m_pLabel);

		m_pPracticeLabel = cocos2d::CCLabelBMFont::create(" ", "bigFont.fnt");
		addChild(m_pLabel, 4);

		m_pPracticeLabel->setPosition(practiceOutterBar->getPosition());
		m_pPracticeLabel->setScale(0.5f);

		m_pPlayerLevelStats->addObject(m_pPracticeLabel);


		cocos2d::CCLabelBMFont* normalMode = cocos2d::CCLabelBMFont::create("Normal Mode", "bigFont.fnt");
		addChild(normalMode, 4);

		cocos2d::CCPoint NormalLabel = normalOutterBar->getPosition();
		NormalLabel.y += 20.0f;
		normalMode->setPosition(NormalLabel);

		m_pPlayerLevelStats->addObject(normalMode);


		cocos2d::CCLabelBMFont* practiceMode = cocos2d::CCLabelBMFont::create("Practice Mode", "bigFont.fnt");
		addChild(practiceMode, 4);

		cocos2d::CCPoint practiceLabel = practiceOutterBar->getPosition();
		practiceLabel.y += 20.0f;
		practiceMode->setPosition(practiceLabel);

		m_pPlayerLevelStats->addObject(practiceMode);


		m_pNameLabel = cocos2d::CCLabelBMFont::create(" ", "bigFont.fnt");
		m_pNameLabel->setAnchorPoint({ 0.0f,0.5f });

		m_pBackgroundSquare->addChild(m_pNameLabel);

		m_pLevelInfo->addObject(m_pNameLabel);


		m_pDifficulty = cocos2d::CCSprite::createWithSpriteFrameName("diffIcon_01_btn_001.png");
		m_pBackgroundSquare->addChild(m_pDifficulty);
		m_pDifficulty->setScale(1.1f);

		m_pLevelInfo->addObject(m_pDifficulty);


		m_pStars = cocos2d::CCSprite::createWithSpriteFrameName("GJ_starsIcon_001.png");
		m_pBackgroundSquare->addChild(m_pStars);
		m_pStars->setScale(0.7f);
		m_pStars->setPosition({ m_obPageSize.width - 15.0f, m_obPageSize.height - 13.0f });

		m_pLevelInfo->addObject(m_pStars);


		m_pStarsLabel = cocos2d::CCLabelBMFont::create(" ", "bigFont.fnt");
		m_pBackgroundSquare->addChild(m_pStarsLabel);
		m_pStarsLabel->setAnchorPoint({ 1.0f,0.5f });

		cocos2d::CCPoint starPos = m_pStars->getPosition();

		m_pStarsLabel->setPosition({ starPos.x - 12.0f, starPos.y + 0.5f });
		m_pStarsLabel->setScale(0.5f);

		m_pLevelInfo->addObject(m_pStarsLabel);

		m_pCoins = cocos2d::CCArray::create();
		m_pCoins->retain();

		cocos2d::CCPoint coinBasePos = { m_obPageSize.width - 16, 16 };

		for (size_t i = 0; i < 3; i++)
		{
			cocos2d::CCSprite* coin = cocos2d::CCSprite::createWithSpriteFrameName("GJ_coinsIcon_001.png");
			m_pBackgroundSquare->addChild(coin);
			coin->setScale(1.0f);

			// GD does this backwards, i didn't want to use an ugly dowhile loop
			coin->setPosition({ coinBasePos.x + (i * -26.0f), coinBasePos.y });
			m_pCoins->addObject(coin);
		}

		m_pEvents = cocos2d::CCArray::create();
		m_pEvents->retain();

		if (PlatformToolbox::isControllerConnected())
		{
			cocos2d::CCSprite* controller = cocos2d::CCSprite::createWithSpriteFrameName("controllerBtn_Start_001.png");
			sprite->addChild(controller, 10);

			cocos2d::CCPoint pos = m_pBackgroundSquare->getPosition();
			pos.y -= 35.0f;

			controller->setPosition(pos);
			m_pLevelInfo->addObject(controller);

		}
	}
	return init;
}

void ownWorldLevelPage::dialogClosed(DialogLayer* layer)
{
	GameManager::sharedState()->setUGV("8", true);
	if (m_pDoor)
		m_pDoor->setDisplayFrame(cocos2d::CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("secretDoorBtn2_open_001.png"));
}

void ownWorldLevelPage::onPlay(cocos2d::CCObject* sender)
{
	if (m_pLevel->m_levelID != -1)
	{
		if (m_pLevel->m_requiredCoins <= GameStatsManager::sharedState()->getStat("8"))
		{
			if (!m_bUnlocked) // still unsure about the name
			{
				m_bUnlocked = true;
				/*Globals::gClickedPlay = true;*/

				FMODAudioEngine::sharedEngine()->stopAllMusic();
				FMODAudioEngine::sharedEngine()->playEffect("playSound_01.ogg");

				cocos2d::CCDelayTime* delay = cocos2d::CCDelayTime::create(0.0f);
				auto func = cocos2d::CCCallFunc::create(this, callfunc_selector(ownWorldLevelPage::playStep2));

				runAction(cocos2d::CCSequence::create(delay, func, 0));

			}
		}
		else
		{
			std::string msg = cocos2d::CCString::createWithFormat("Collect %i more <cy>Secret Coins</c> to unlock this <cl>level</c>!", m_pLevel->m_requiredCoins - GameStatsManager::sharedState()->getStat("8"))->m_sString;
			FLAlertLayer::create(nullptr, "Locked", msg, "OK", nullptr, 300.0f)->show();
		}
	}
}

void ownWorldLevelPage::playStep2()
{
	FMODAudioEngine::sharedEngine()->playMusic(m_pLevel->getAudioFileName(), 0, 1,1);
	
	cocos2d::CCDelayTime* delay = cocos2d::CCDelayTime::create(0.0f);
	cocos2d::CCCallFunc* func = cocos2d::CCCallFunc::create(this, callfunc_selector(ownWorldLevelPage::playStep3));
	runAction(cocos2d::CCSequence::create(delay, func, 0));
}

void ownWorldLevelPage::playStep3()
{
	GameManager::sharedState()->m_sceneEnum = 9;
	/*std::string levelstring;
	levelstring = LocalLevelManager::sharedState()->getMainLevelString(1);*/
	/*LocalLevelManager::sharedState()->getMainLevelString(1);*/
	m_pLevel->m_levelString = "";
}