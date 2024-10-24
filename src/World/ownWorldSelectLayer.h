#pragma once
#include <Geode/Geode.hpp>
//#include "../src/NewLevelSelectLayer.cpp"


class ownWorldSelectLayer : public cocos2d::CCLayer, public BoomScrollLayerDelegate, public DynamicScrollDelegate {
public:
    GJGroundLayer* m_ground;
    cocos2d::CCSprite* m_background;
    cocos2d::CCArray* m_mainLevels;
    cocos2d::CCArray* m_levelPages;
    BoomScrollLayer* m_scrollLayer;
	float m_fWindowWidth;
    int m_level;
	GJGameLevel* level;
	cocos2d::CCMenu* menu3;
public:
	cocos2d::ccColor3B colorForPage(int);
	cocos2d::ccColor3B getColorValue(int, int, float);
	bool init(int page);
	bool tryShowAd();
	void onClose(CCObject*);
	void onPrev(cocos2d::CCObject*);
	void onNext(cocos2d::CCObject*);
	void onDownload(cocos2d::CCObject*);
	void onSoundtracks(CCObject*);
	void onInfo(cocos2d::CCObject*);
	void onPlay(cocos2d::CCObject*);
	void onBack(cocos2d::CCObject*);
	void keyBackClicked();
	void createStars(GJGameLevel* level, CCLayer* layer);
	void onWorldLevel(cocos2d::CCObject* sender);
	void onGarage(cocos2d::CCObject* sender);
	void importSheet();
	void runScroll();
	void runParticle();
	void scrollLayerMoved(cocos2d::CCPoint) override;
	/*void pageNumberForPosition(cocos2d::CCPoint);*/
	CCNode* createSideArt();
	//CCSprite* createBackground();
	void keyDown(int);
	void updateColors();
	/*void instantPage(cocos2d::CCObject*,int);*/
	static ownWorldSelectLayer* create(int page);
	static cocos2d::CCScene* scene(int page);
	void updatePageWithObject(CCObject* page, CCObject* object);
	
}; 

//static NewLevelSelectLayer* create(int page);
//static cocos2d::CCScene* scene(int page);
//bool init(int page);
//void onClose(CCObject*);
//void keyBackClicked();
//void updateColors();
//void updatePageWithObject(CCObject* page, CCObject* object) override;
//void scrollLayerMoved(cocos2d::CCPoint) override;
//void onSoundtracks(CCObject*);
//void onNext(CCObject*);
//void onPrev(CCObject*);
//cocos2d::ccColor3B colorForPage(int page);
//cocos2d::ccColor3B getColorValue(int level1, int level2, float a3);