#ifndef OWN_LEVEL_PAGE_H
#define OWN_LEVEL_PAGE_H

#include <Geode/Geode.hpp>
#include "cocos2d.h"

class ownLevelPage : public cocos2d::CCLayer, public DialogDelegate
{
public:
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
	bool init(GJGameLevel*);
	void addSecretDoor();
	void updateDynamicPage(GJGameLevel*);
	void addSecretCoin();
	//virtual bool ccTouchBegan(cocos2d::CCTouch*, cocos2d::CCEvent*) override;
	//virtual void ccTouchCancelled(cocos2d::CCTouch*, cocos2d::CCEvent*) override;
	//virtual void ccTouchEnded(cocos2d::CCTouch*, cocos2d::CCEvent*) override;
	//virtual void ccTouchMoved(cocos2d::CCTouch*, cocos2d::CCEvent*) override;
	static ownLevelPage* create(GJGameLevel*);
	virtual void dialogClosed(DialogLayer*);
	void onInfo(cocos2d::CCObject*);
	void onPlay(cocos2d::CCObject*);
	void onSecretDoor(cocos2d::CCObject*);
	void playCoinEffect();
	void playStep2();
	void playStep3();
	/*virtual void registerWithTouchDispatcher() override;*/

};

#endif // OWN_LEVEL_PAGE_H
