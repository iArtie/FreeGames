#include <Geode/Geode.hpp>
#include "../Meltdown/MeltdownSelectLayer.h"
#include "../extras/BetterMDPopup.hpp"

using namespace geode::prelude;

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

	//Optimization code idea taked from gd lunar (big thanks to Capeling!)

	m_scrollLayer->m_dynamicObjects->removeAllObjects();

	auto dotsArray = CCArrayExt<CCSprite*>(m_scrollLayer->m_dots);

	for (CCSprite* dot : dotsArray) {
		dot->removeFromParent();
	}
	m_scrollLayer->m_dots->removeAllObjects();

	// Configurar niveles
	std::vector<std::tuple<int, const char*>> levels = {
		{1001, "The Seven Seas"},
		{1002, "Viking Arena"},
		{1003, "Airborne Robots"}
	};


	
	auto GLM = GameLevelManager::sharedState();
	for (auto [id, name] : levels) {
		auto level = GLM->getMainLevel(id, true);
		level->m_levelString = LocalLevelManager::sharedState()->getMainLevelString(id);
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

	return true;
}