	CCAnimation *animation = CCAnimation:create();

	//load image file from local system to CCSpriteFrame, then add into CCAnimation

	for (int i = 0; i < 15; ++i)
	{
		char szImageFileName[128] = {0};
		sprintf(szImageFileName, "Images/grossini_dance_%02d.png", i);
		animation->addSpriteFrameWithFilename(szImageFileName);
	}

	animation->setDelayPerUnit(2.8f / 14.0f);// This animation contains 14 frames, will continuous 2.8 seconds.
	animation->setRestoreOriginalFrame(true);// Return to the 1st frame after the 14th frame is played.

	CCAnimate *action = CCAnimate::create(animation);
	sprite->runAction(action);

m_pSprite1 = CCSprite::createWithSpriteFrameName("grossini_dance_01.png");
spritebatch->child(m_pSprite1)
addChild(spritebatch)