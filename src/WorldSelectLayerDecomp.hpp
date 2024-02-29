//#pragma once
//
//#include <Geode/Bindings.hpp>
//
//class WorldSelectLayerDecomp : public cocos2d::CCLayer, public BoomScrollLayerDelegate, public DynamicScrollDelegate {
//
//
//protected:
//	GJGroundLayer* m_ground;
//	cocos2d::CCSprite* m_background;
//	cocos2d::CCArray* m_mainLevels;
//	cocos2d::CCArray* m_levelPages;
//	BoomScrollLayer* m_scrollLayer;
//	int m_level;
//	   
//
//public:
//	/*cocos2d::ccColor3B colorForPage(int);
//	cocos2d::ccColor3B getColorValue(int, int, float);*/
//	bool init();
//	bool tryShowAd();
//	void onClose(CCObject*);
//	void onPrev(cocos2d::CCObject*);
//	void onNext(cocos2d::CCObject*);
//	void onDownload(cocos2d::CCObject*);
//	void onSoundtracks(CCObject*);
//	void onInfo(cocos2d::CCObject*);
//	void onPlay(cocos2d::CCObject*);
//	void onBack(cocos2d::CCObject*);
//	void keyBackClicked();
//	void runScroll();
//	void importSheet();
//	cocos2d::CCNode* createSideArt();
//	/*void pageNumberForPosition(cocos2d::CCPoint);*/
//	void keyDown(int);
//	void updateColors();
//	cocos2d::CCNode* createBackground();
//	void instantPage(cocos2d::CCObject*, int);
//	static WorldSelectLayerDecomp* create();
//	static cocos2d::CCScene* scene();
//	void updatePageWithObject(CCObject* page, CCObject* object);
//	void createStars(GJGameLevel* level, CCLayer* layer);
//	void onWorldLevel(cocos2d::CCObject* sender);
//	void onGarage(cocos2d::CCObject* sender);
//
//
////protected:
////    GJGameLevel* level;
////    int m_level;
////  /*  CCMenu* menu3;*/
////    cocos2d::CCNode* m_background;
////    BoomScrollLayer* m_sscrollLayer;
////    CCArray* m_levelPagess;
////public:
////    static WorldSelectLayerDecomp* create();
////    static cocos2d::CCScene* scene();
////    void instantPage(CCObject* sender, int a1);
////private:
////    bool init() override;
////    virtual void keyBackClicked();
////
////    void onPreva(cocos2d::CCObject* sender);
////    void onNext(cocos2d::CCObject* sender);
////    void onGarage(cocos2d::CCObject* sender);
////    void onPlay(cocos2d::CCObject* sender);
////    void onWorldLevel(cocos2d::CCObject* sender);
////    void importSheet();
////    void runParticle();
////    void createStars(GJGameLevel* level, CCLayer* layer);
////    void runScroll();
////    cocos2d::CCNode* createBackground();
////  /*  cocos2d::CCNode* createSideArt();*/
////  /*  cocos2d::CCNode* createArrows();*/
////    void onInfo(CCObject* sender);
////   /* void show2(GJGameLevel* level212);*/
////    /*void updatePageWithObject(CCObject* page, CCObject* object);*/
////    void onClose(CCObject*);
////   
////   /* cocos2d::CCArray* m_mainLevels2;*/
////   
//};
//
//
