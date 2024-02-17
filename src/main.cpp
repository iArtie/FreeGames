#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>
#include <Geode/modify/LevelSelectLayer.hpp>
#include <Geode/modify/LevelInfoLayer.hpp>
#include <Geode/modify/LevelPage.hpp>
using namespace geode::prelude;

#include <iostream>
#include <filesystem> 
class $modify(MenuLayer) {
	void onMoreGames(CCObject*) {
		auto scene = CCScene::create();
		

		auto level = GJGameLevel::create();
		std::ifstream t("./Resources/levels/4001.txt");
		std::string text((std::istreambuf_iterator<char>(t)), std::istreambuf_iterator<char>());
			if (text != "")
			{
				
				std::cout << text << std::endl;
			}
			level->m_levelName = "Press Start";
			level->m_levelID = 4001;
			level->m_levelType = GJLevelType::Local;
			level->m_stars = 4;
			level->m_levelString = text;
			auto layer = LevelPage::create(nullptr);
			layer->updateDynamicPage(level);
			
			layer->m_level->m_audioTrack = 37;
			scene->addChild(layer);
		
			CCDirector::sharedDirector()->pushScene(CCTransitionFade::create(0.5f, scene));
     
        }


	
};

//class $modify(LevelSelectLayer)
//{
//	bool init(int a1)
//	{
//		
//		/*if (LevelSelectLayer::init(a1)) return false;
//		a1 = 25;*/
//
//		return LevelSelectLayer::init(25);
//	}
//
//};


