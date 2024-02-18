#pragma once
#include <Geode/Geode.hpp>
#include <Geode/Bindings.hpp>
class DialogLayer;

class ownWorldLevelPage : public cocos2d::CCLayer, public DialogDelegate
{
protected:
	bool m_bUnlocked;
	GJGameLevel* m_pLevel;
	cocos2d::CCMenu* m_pMenu;
	cocos2d::extension::CCScale9Sprite* m_pBackgroundSquare;
	cocos2d::CCLabelBMFont* m_pLabel;
	cocos2d::CCLabelBMFont* m_pPracticeLabel;
	cocos2d::CCLabelBMFont* m_pNameLabel;
	cocos2d::CCLabelBMFont* m_pStarsLabel;
	float m_fProgressBarWidth;
	cocos2d::CCSprite* m_pProgressBar;
	cocos2d::CCSprite* m_pPracticeBar;
	cocos2d::CCSprite* m_pDifficulty;
	cocos2d::CCSprite* m_pStars;
	cocos2d::CCSize m_obPageSize;
	cocos2d::CCArray* m_pCoins;
	cocos2d::CCArray* m_pEvents;
	cocos2d::CCArray* m_pLevelInfo;
	cocos2d::CCArray* m_pPlayerLevelStats;
	GameObject* m_pSecretMenuCoin;
	cocos2d::CCSprite* m_pDoor;

public:

	static ownWorldLevelPage* create(GJGameLevel*);
	bool init(GJGameLevel*);
	void addSecretDoor();
	void updateDynamicPage(GJGameLevel*);
	void addSecretCoin();
	bool ccTouchBegan(cocos2d::CCTouch*, cocos2d::CCEvent*) override;
	void ccTouchCancelled(cocos2d::CCTouch*, cocos2d::CCEvent*) override;
	void ccTouchEnded(cocos2d::CCTouch*, cocos2d::CCEvent*) override;
	void ccTouchMoved(cocos2d::CCTouch*, cocos2d::CCEvent*) override;
	
	virtual void dialogClosed(DialogLayer*);
	void onInfo(cocos2d::CCObject*);
	void onPlay(cocos2d::CCObject*);
	void onSecretDoor(cocos2d::CCObject*);
	void playCoinEffect();
	void playStep2();
	void playStep3();
	void registerWithTouchDispatcher() override;

};