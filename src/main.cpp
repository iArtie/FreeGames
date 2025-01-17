#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>
#include <Geode/modify/PauseLayer.hpp>
#include <Geode/modify/PlayLayer.hpp>
#include <Geode/modify/LoadingLayer.hpp>
#include <Geode/modify/EndLevelLayer.hpp>
#include <Geode/modify/GJGarageLayer.hpp>


#include <Geode/modify/LevelTools.hpp>

#include <Geode/modify/SongsLayer.hpp>
#include <Geode/Enums.hpp>

#include "hooks/MoreGamesLayer.hpp"
#include "hooks/MoreGamesLayer.cpp"


#include "Meltdown/MeltdownSelectLayer.h"
#include "SubZero/SubZeroSelectLayer.h"
#include "World/ownWorldSelectLayer.h"

//#include "WorldSelectLayerDecomp.cpp"

//#include "ownWorldLevelPage.cpp"

using namespace geode::prelude;

#include <iostream>
#include <filesystem> 
using namespace more;



#include <Geode/utils/web.hpp>

void updateGroundColorM(CCSpriteBatchNode* batch, const cocos2d::ccColor3B& color)
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

class $modify(LevelTools)
{
	static GJGameLevel* getLevel(int levelID, bool getString)
	{
		

		GJGameLevel* level = GJGameLevel::create();


		switch (levelID) {
		case 1001:
			level->m_levelName = getAudioTitle(23);
			level->m_audioTrack = 23;
			level->m_coins = 3;
			level->m_stars = 1;
			level->m_difficulty = GJDifficulty::Easy;
			break;
		case 1002:
			level->m_levelName = getAudioTitle(24);
			level->m_audioTrack = 24;
			level->m_coins = 3;
			level->m_stars = 2;
			level->m_difficulty = GJDifficulty::Normal;
			break;
		case 1003:
			level->m_levelName = getAudioTitle(25);
			level->m_audioTrack = 25;
			level->m_coins = 3;
			level->m_stars = 3;
			level->m_difficulty = GJDifficulty::Hard;
			break;
		case 2001:
			level->m_levelName = getAudioTitle(27);
			level->m_audioTrack = 27;
			level->m_coins = 0;
			level->m_requiredCoins = 0;
			level->m_stars = 2;
			level->m_difficulty = GJDifficulty::Easy;
			break;
		case 2002:
			level->m_levelName = getAudioTitle(28);
			level->m_audioTrack = 28;
			level->m_coins = 0;
			level->m_requiredCoins = 0;
			level->m_stars = 2;
			level->m_difficulty = GJDifficulty::Easy;
			break;
		case 2003:
			level->m_levelName = getAudioTitle(29);
			level->m_audioTrack = 29;
			level->m_coins = 0;
			level->m_requiredCoins = 0;
			level->m_stars = 3;
			level->m_difficulty = GJDifficulty::Normal;
			break;
		case 2004:
			level->m_levelName = getAudioTitle(30);
			level->m_audioTrack = 30;
			level->m_coins = 0;
			level->m_requiredCoins = 0;
			level->m_stars = 3;
			level->m_difficulty = GJDifficulty::Normal;
			break;
		case 2005:
			level->m_levelName = getAudioTitle(31);
			level->m_audioTrack = 31;
			level->m_coins = 0;
			level->m_requiredCoins = 0;
			level->m_stars = 3;
			level->m_difficulty = GJDifficulty::Normal;
			break;
		case 2006:
			level->m_levelName = getAudioTitle(32);
			level->m_audioTrack = 32;
			level->m_coins = 0;
			level->m_requiredCoins = 0;
			level->m_stars = 3;
			level->m_difficulty = GJDifficulty::Normal;
			break;
		case 2007:
			level->m_levelName = getAudioTitle(33);
			level->m_audioTrack = 33;
			level->m_coins = 0;
			level->m_requiredCoins = 0;
			level->m_stars = 3;
			level->m_difficulty = GJDifficulty::Normal;
			break;
		case 2008:
			level->m_levelName = getAudioTitle(34);
			level->m_audioTrack = 34;
			level->m_coins = 0;
			level->m_requiredCoins = 0;
			level->m_stars = 3;
			level->m_difficulty = GJDifficulty::Normal;
			break;
		case 2009:
			level->m_levelName = getAudioTitle(35);
			level->m_audioTrack = 35;
			level->m_coins = 0;
			level->m_requiredCoins = 0;
			level->m_stars = 3;
			level->m_difficulty = GJDifficulty::Normal;
			break;
		case 2010:
			level->m_levelName = getAudioTitle(36);
			level->m_audioTrack = 36;
			level->m_coins = 0;
			level->m_requiredCoins = 0;
			level->m_stars = 3;
			level->m_difficulty = GJDifficulty::Normal;
			break;
		default:
		
			return LevelTools::getLevel(levelID, getString);
		}


		return level;
	}

	
};
class $modify(MenuLayer) {
	void onMoreGames(CCObject*) {

		auto* layer = more::MoreGamesLayer::create();

		addChild(layer, 100);
		layer->showLayer(false);
		
        }
	void onPlay(CCObject* sender) {
		auto back = Mod::get()->getSavedValue<int>("onsubzero");
		back = 10;
		Mod::get()->setSavedValue("onsubzero", back);

		MenuLayer::onPlay(sender);
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

		auto World = ownWorldSelectLayer::create(0);
		auto scene = CCScene::create();

		scene->addChild(World);
		
		if (pages != 0 && pages != 10)
		{
			auto transitionScene = CCScene::create(); 

			
			CCSize winSize = CCDirector::sharedDirector()->getWinSize();
			CCActionInterval* moveUp = CCMoveBy::create(0.23f, ccp(0, winSize.height));
			this->runAction(moveUp);

			if (pages == 1) {
				World->m_scrollLayer->instantMoveToPage(0);
				World->m_background->setColor(GameManager::sharedState()->colorForIdx(4));
			}
			else if (pages == 2) {
				World->m_scrollLayer->instantMoveToPage(1);
				World->m_background->setColor(GameManager::sharedState()->colorForIdx(6));
			}
			else if (pages == 3) {
			 //page 3 is bug bc BoomScrollLayer is sucks
			}

			auto transition = CCTransitionMoveInB::create(0.31f, scene);

		
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
	//L
};
//
class $modify(PauseLayer) {
	void onQuit(CCObject* sender) {

		auto GM = GameManager::sharedState();

		
		if (GM->m_playLayer->m_level->m_levelID > 1000 && GM->m_playLayer->m_level->m_levelID < 1004)
		{
		
			auto levelID = GM->m_playLayer->m_level->m_levelID;
			auto MeltdownScene = MeltdownSelectLayer::create(0);
			int colorID = 0;
			auto scene = CCScene::create();
			if (levelID == 1001)
			{
				MeltdownScene = MeltdownSelectLayer::create(0);
				/*MeltdownScene->m_pBoomScrollLayer->instantMoveToPage(0);
				colorID = 5;*/
			}

			if (levelID == 1002)
			{
				MeltdownScene = MeltdownSelectLayer::create(1);
				/*MeltdownScene->m_pBoomScrollLayer->instantMoveToPage(1);
				colorID = 9;*/
			}
			if (levelID == 1003)
			{
				MeltdownScene = MeltdownSelectLayer::create(2);
				/*MeltdownScene->m_pBoomScrollLayer->instantMoveToPage(2);
				colorID = 1;*/
			}
		/*	MeltdownScene->m_pBackground->setColor(GameManager::sharedState()->colorForIdx(colorID));
			auto m_pGround01Sprite = static_cast<CCSpriteBatchNode*>(MeltdownScene->m_pGround->getChildren()->objectAtIndex(3));
			auto m_pGround02Sprite = static_cast<CCSpriteBatchNode*>(MeltdownScene->m_pGround->getChildren()->objectAtIndex(4));

		
			CCArray* children = nullptr; 

			if (Loader::get()->getLoadedMod("bitz.darkmode_v4"))
			{
				for (int i = 0; i < m_pGround01Sprite->getChildren()->count(); ++i) {
					if (m_pGround01Sprite != nullptr) {
						updateGroundColorMeltdown2(m_pGround01Sprite, { 40,40,40 });
					}
					if (m_pGround02Sprite != nullptr) {
						updateGroundColorMeltdown2(m_pGround02Sprite, { 40,40,40 });
					}
				}
			}
			else
			{
				for (int i = 0; i < m_pGround01Sprite->getChildren()->count(); ++i) {
					if (m_pGround01Sprite != nullptr) {
						updateGroundColorMeltdown2(m_pGround01Sprite, GameManager::sharedState()->colorForIdx(colorID));
					}
					if (m_pGround02Sprite->getChildrenCount() == m_pGround01Sprite->getChildrenCount())
					{
						if (m_pGround02Sprite != nullptr) {
							updateGroundColorMeltdown2(m_pGround02Sprite, GameManager::sharedState()->colorForIdx(colorID));
						}
					}

				}
			}
			
			*/
			/*PauseLayer::onQuit(sender);*/
			scene->addChild(MeltdownScene);
			CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(0.5, scene));
			PauseLayer::onQuit(sender);
	
		}
	
		

		if (GM->m_playLayer->m_level->m_levelID > 2000 && GM->m_playLayer->m_level->m_levelID < 2011)
		{
		
			auto levelID = GM->m_playLayer->m_level->m_levelID;
		/*	auto worldScene = ownWorldSelectLayer::create(0);*/
			auto specificWorldScene = ownWorldSelectLayer::create(0);
			auto scene = CCScene::create();
#ifdef GEODE_IS_WINDOWS

			int colorID = 0;
	// Crear la escena para Windows usando ownWorldSelectLayer
			
			if (levelID > 2000 && levelID < 2006) {
				specificWorldScene->m_scrollLayer->instantMoveToPage(0);
				colorID = 4;
			}
			else if (levelID > 2005 && levelID < 2011) {
				specificWorldScene->m_scrollLayer->instantMoveToPage(1);
				colorID = 6;
			}

			specificWorldScene->m_background->setColor(GameManager::sharedState()->colorForIdx(colorID));
			scene->addChild(specificWorldScene);
			CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(0.5, scene));
#endif

#ifdef GEODE_IS_ANDROID

			int colorID = 0;
			// Crear la escena para Android directamente con el índice correspondiente
			if (levelID > 2000 && levelID < 2006) {
				worldScene = WorldSelectLayer::create(0);
				colorID = 4;
			}
			else if (levelID > 2005 && levelID < 2011) {
				worldScene = WorldSelectLayer::create(1);
				colorID = 6;
			}
			else {
				worldScene = WorldSelectLayer::create(0); // Valor por defecto
			}

			scene->addChild(worldScene);
			CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(0.5, scene));
#endif

			
			
			/*CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(0.5, scene));*/
			PauseLayer::onQuit(sender);
			
		}

		if (GM->m_playLayer->m_level->m_levelID > 4000 && GM->m_playLayer->m_level->m_levelID < 4004)
		{
		
			auto levelID = GM->m_playLayer->m_level->m_levelID;
			auto SubZeroScene = SubZeroSelectLayer::create(0);
			int colorID = 0;
			auto scene = CCScene::create();
			if (levelID == 4001)
			{
				SubZeroScene->m_pBoomScrollLayer->instantMoveToPage(0);
				colorID = 5;
			}

			if (levelID == 4002)
			{
				SubZeroScene->m_pBoomScrollLayer->instantMoveToPage(1);
				colorID = 9;
			}
			if (levelID == 4003)
			{
				SubZeroScene->m_pBoomScrollLayer->instantMoveToPage(2);
				colorID = 1;
			}
			SubZeroScene->m_pBackground->setColor(GameManager::sharedState()->colorForIdx(colorID));
			auto m_pGround01Sprite = static_cast<CCSpriteBatchNode*>(SubZeroScene->m_pGround->getChildren()->objectAtIndex(3));
			auto m_pGround02Sprite = static_cast<CCSpriteBatchNode*>(SubZeroScene->m_pGround->getChildren()->objectAtIndex(4));

			CCArray* children = nullptr; 

			if (Loader::get()->getLoadedMod("bitz.darkmode_v4"))
			{
				for (int i = 0; i < m_pGround01Sprite->getChildren()->count(); ++i) {
					if (m_pGround01Sprite != nullptr) {
						updateGroundColorMeltdown2(m_pGround01Sprite, { 40,40,40 });
					}
					if (m_pGround02Sprite != nullptr) {
						updateGroundColorMeltdown2(m_pGround02Sprite, { 40,40,40 });
					}
				}
			}
			else
			{
				for (int i = 0; i < m_pGround01Sprite->getChildren()->count(); ++i) {
					if (m_pGround01Sprite != nullptr) {
						updateGroundColorMeltdown2(m_pGround01Sprite, GameManager::sharedState()->colorForIdx(colorID));
					}
					if (m_pGround02Sprite->getChildrenCount() == m_pGround01Sprite->getChildrenCount())
					{
						if (m_pGround02Sprite != nullptr) {
							updateGroundColorMeltdown2(m_pGround02Sprite, GameManager::sharedState()->colorForIdx(colorID));
						}
					}

				}
			}

			/*PauseLayer::onQuit(sender);*/
			scene->addChild(SubZeroScene);
			CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(0.5, scene));
			PauseLayer::onQuit(sender);
			/*	PauseLayer::onQuit(sender);*/
		}

		PauseLayer::onQuit(sender);
	}

	/*void onEdit(cocos2d::CCObject* sender)
	{
		Mod::get()->setSavedValue("onsubzero", 25);
		PauseLayer::onEdit(sender);
	}*/

};

//
class $modify(EndLevelLayer) {
	void onMenu(CCObject * sender) {
	
		auto GM = GameManager::sharedState();


		if (GM->m_playLayer->m_level->m_levelID > 1000 && GM->m_playLayer->m_level->m_levelID < 1004)
		{
	
			auto levelID = GM->m_playLayer->m_level->m_levelID;
			auto MeltdownScene = MeltdownSelectLayer::create(0);
			int colorID = 0;
			auto scene = CCScene::create();
			if (levelID == 1001)
			{
				MeltdownScene->m_pBoomScrollLayer->instantMoveToPage(0);
				colorID = 5;
			}

			if (levelID == 1002)
			{
				MeltdownScene->m_pBoomScrollLayer->instantMoveToPage(1);
				colorID = 9;
			}
			if (levelID == 1003)
			{
				MeltdownScene->m_pBoomScrollLayer->instantMoveToPage(2);
				colorID = 1;
			}
			MeltdownScene->m_pBackground->setColor(GameManager::sharedState()->colorForIdx(colorID));
			auto m_pGround01Sprite = static_cast<CCSpriteBatchNode*>(MeltdownScene->m_pGround->getChildren()->objectAtIndex(3));
			auto m_pGround02Sprite = static_cast<CCSpriteBatchNode*>(MeltdownScene->m_pGround->getChildren()->objectAtIndex(4));

			
			CCArray* children = nullptr; 

			if (Loader::get()->getLoadedMod("bitz.darkmode_v4"))
			{
				for (int i = 0; i < m_pGround01Sprite->getChildren()->count(); ++i) {
					if (m_pGround01Sprite != nullptr) {
						updateGroundColorMeltdown2(m_pGround01Sprite, { 40,40,40 });
					}
					if (m_pGround02Sprite != nullptr) {
						updateGroundColorMeltdown2(m_pGround02Sprite, { 40,40,40 });
					}
				}
			}
			else
			{
				for (int i = 0; i < m_pGround01Sprite->getChildren()->count(); ++i) {
					if (m_pGround01Sprite != nullptr) {
						updateGroundColorMeltdown2(m_pGround01Sprite, GameManager::sharedState()->colorForIdx(colorID));
					}
					if (m_pGround02Sprite->getChildrenCount() == m_pGround01Sprite->getChildrenCount())
					{
						if (m_pGround02Sprite != nullptr) {
							updateGroundColorMeltdown2(m_pGround02Sprite, GameManager::sharedState()->colorForIdx(colorID));
						}
					}

				}
			}

			
			scene->addChild(MeltdownScene);
			CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(0.5, scene));
			EndLevelLayer::onMenu(sender);
	
		}
	


		if (GM->m_playLayer->m_level->m_levelID > 2000 && GM->m_playLayer->m_level->m_levelID < 2011)
		{
			
			auto levelID = GM->m_playLayer->m_level->m_levelID;
			/*	auto worldScene = ownWorldSelectLayer::create(0);*/
			auto specificWorldScene = ownWorldSelectLayer::create(0);
			auto scene = CCScene::create();
#ifdef GEODE_IS_WINDOWS

			int colorID = 0;
			// Crear la escena para Windows usando ownWorldSelectLayer

			if (levelID > 2000 && levelID < 2006) {
				specificWorldScene->m_scrollLayer->instantMoveToPage(0);
				colorID = 4;
			}
			else if (levelID > 2005 && levelID < 2011) {
				specificWorldScene->m_scrollLayer->instantMoveToPage(1);
				colorID = 6;
			}

			specificWorldScene->m_background->setColor(GameManager::sharedState()->colorForIdx(colorID));
			scene->addChild(specificWorldScene);
			CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(0.5, scene));
#endif

#ifdef GEODE_IS_ANDROID

			int colorID = 0;
			// Crear la escena para Android directamente con el índice correspondiente
			if (levelID > 2000 && levelID < 2006) {
				worldScene = WorldSelectLayer::create(0);
				colorID = 4;
			}
			else if (levelID > 2005 && levelID < 2011) {
				worldScene = WorldSelectLayer::create(1);
				colorID = 6;
			}
			else {
				worldScene = WorldSelectLayer::create(0); // Valor por defecto
			}

			scene->addChild(worldScene);
			CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(0.5, scene));
#endif

			EndLevelLayer::onMenu(sender);
			
		}

		if (GM->m_playLayer->m_level->m_levelID > 4000 && GM->m_playLayer->m_level->m_levelID < 4004)
		{
			
			auto levelID = GM->m_playLayer->m_level->m_levelID;
			auto SubZeroScene = SubZeroSelectLayer::create(0);
			int colorID = 0;
			auto scene = CCScene::create();
			if (levelID == 4001)
			{
				SubZeroScene->m_pBoomScrollLayer->instantMoveToPage(0);
				colorID = 5;
			}

			if (levelID == 4002)
			{
				SubZeroScene->m_pBoomScrollLayer->instantMoveToPage(1);
				colorID = 9;
			}
			if (levelID == 4003)
			{
				SubZeroScene->m_pBoomScrollLayer->instantMoveToPage(2);
				colorID = 1;
			}
			SubZeroScene->m_pBackground->setColor(GameManager::sharedState()->colorForIdx(colorID));
			auto m_pGround01Sprite = static_cast<CCSpriteBatchNode*>(SubZeroScene->m_pGround->getChildren()->objectAtIndex(3));
			auto m_pGround02Sprite = static_cast<CCSpriteBatchNode*>(SubZeroScene->m_pGround->getChildren()->objectAtIndex(4));

			
			CCArray* children = nullptr; 

			if (Loader::get()->getLoadedMod("bitz.darkmode_v4"))
			{
				for (int i = 0; i < m_pGround01Sprite->getChildren()->count(); ++i) {
					if (m_pGround01Sprite != nullptr) {
						updateGroundColorMeltdown2(m_pGround01Sprite, { 40,40,40 });
					}
					if (m_pGround02Sprite != nullptr) {
						updateGroundColorMeltdown2(m_pGround02Sprite, { 40,40,40 });
					}
				}
			}
			else
			{
				for (int i = 0; i < m_pGround01Sprite->getChildren()->count(); ++i) {
					if (m_pGround01Sprite != nullptr) {
						updateGroundColorMeltdown2(m_pGround01Sprite, GameManager::sharedState()->colorForIdx(colorID));
					}
					if (m_pGround02Sprite->getChildrenCount() == m_pGround01Sprite->getChildrenCount())
					{
						if (m_pGround02Sprite != nullptr) {
							updateGroundColorMeltdown2(m_pGround02Sprite, GameManager::sharedState()->colorForIdx(colorID));
						}
					}

				}
			}

			
			scene->addChild(SubZeroScene);
			CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(0.5, scene));
			EndLevelLayer::onMenu(sender);
			
		}

		EndLevelLayer::onMenu(sender);
	}



};

class $modify(PlayLayer) {
	// ultimate achievements - hello from iris
	void levelComplete() {
		PlayLayer::levelComplete();
		auto GSValues = GameStatsManager::sharedState()->m_playerStats;
		int coinsCollected = 0;
		int setPercentage;
		switch (m_level->m_levelID) {
		case 1001:
			// the seven seas
			if (GSValues->objectForKey("unique_1001_1") != nullptr) ++coinsCollected;
			if (GSValues->objectForKey("unique_1001_2") != nullptr) ++coinsCollected;
			if (GSValues->objectForKey("unique_1001_3") != nullptr) ++coinsCollected;
			setPercentage = coinsCollected * 100 / 3;
			GameManager::sharedState()->reportAchievementWithID("geometry.ach.mdcoin01", setPercentage, false);
			break;
		case 1002:
			// viking arena 
			if (GSValues->objectForKey("unique_1002_1") != nullptr) ++coinsCollected;
			if (GSValues->objectForKey("unique_1002_2") != nullptr) ++coinsCollected;
			if (GSValues->objectForKey("unique_1002_3") != nullptr) ++coinsCollected;
			setPercentage = coinsCollected * 100 / 3;
			GameManager::sharedState()->reportAchievementWithID("geometry.ach.mdcoin02", setPercentage, false);
			break;
		case 1003:
			// airborne robots
			if (GSValues->objectForKey("unique_1003_1") != nullptr) ++coinsCollected;
			if (GSValues->objectForKey("unique_1003_2") != nullptr) ++coinsCollected;
			if (GSValues->objectForKey("unique_1003_3") != nullptr) ++coinsCollected;
			setPercentage = coinsCollected * 100 / 3;
			GameManager::sharedState()->reportAchievementWithID("geometry.ach.mdcoin03", setPercentage, false);
			break;
		case 4001:
			// press start
			if (GSValues->objectForKey("unique_4001_1") != nullptr) ++coinsCollected;
			if (GSValues->objectForKey("unique_4001_2") != nullptr) ++coinsCollected;
			if (GSValues->objectForKey("unique_4001_3") != nullptr) ++coinsCollected;
			setPercentage = coinsCollected * 100 / 3;
			GameManager::sharedState()->reportAchievementWithID("geometry.ach.subzero.coins001", setPercentage, false);
			break;
		case 4002:
			// nock em
			if (GSValues->objectForKey("unique_4002_1") != nullptr) ++coinsCollected;
			if (GSValues->objectForKey("unique_4002_2") != nullptr) ++coinsCollected;
			if (GSValues->objectForKey("unique_4002_3") != nullptr) ++coinsCollected;
			setPercentage = coinsCollected * 100 / 3;
			GameManager::sharedState()->reportAchievementWithID("geometry.ach.subzero.coins002", setPercentage, false);
			break;
		case 4003:
			// power trip
			if (GSValues->objectForKey("unique_4003_1") != nullptr) ++coinsCollected;
			if (GSValues->objectForKey("unique_4003_2") != nullptr) ++coinsCollected;
			if (GSValues->objectForKey("unique_4003_3") != nullptr) ++coinsCollected;
			setPercentage = coinsCollected * 100 / 3;
			GameManager::sharedState()->reportAchievementWithID("geometry.ach.subzero.coins003", setPercentage, false);
			break;
		}
	}

};



