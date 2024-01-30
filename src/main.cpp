#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>

using namespace geode::prelude;

class $modify(MenuLayer) {
	void onMoreGames(CCObject*) {
		FLAlertLayer::create("Geode", "Hello from my custom mod!", "OK")->show(); 
	} 
};
