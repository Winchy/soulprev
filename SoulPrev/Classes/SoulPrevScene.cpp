#include "SoulPrevScene.h"
#include "SimpleAudioEngine.h"

using namespace cocos2d;
using namespace CocosDenshion;

CCScene* SoulPrev::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    SoulPrev *layer = SoulPrev::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool SoulPrev::init()
{
    bool bRet = false;
    
    do {
        CC_BREAK_IF(!CCLayerColor::initWithColor(ccc4(0, 0, 0, 255)));
        
        CCSize size = CCDirector::sharedDirector()->getWinSize();
        CCPoint center = ccp(size.width/2, size.height/2);
        
        CCMenuItemImage *pCloseItem = CCMenuItemImage::create("CloseNormal.png",
                                                              "CloseSelected.png",
                                                              this,
                                                              menu_selector(SoulPrev::menuCloseCallback));
        pCloseItem->setPosition(ccp(size.width - 20, 20));
        
        CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
        
        pMenu->setPosition( CCPointZero );        
        this->addChild(pMenu, 1);
        
        // add "HelloWorld" splash screen"
        CCSprite* pSprite = CCSprite::create("hudieyu_01.png");
        
        // position the sprite on the center of the screen
        pSprite->setPosition( ccp(size.width/2, size.height/2) );
        
        // add the sprite as a child to this layer
        /*this->addChild(pSprite, 0);
        
        pSprite->runAction(CCMoveTo::create(2, ccp(10, 10)));
         */
        
        //load image into CCSpriteFrameCache
        CCSpriteFrameCache* cache = CCSpriteFrameCache::sharedSpriteFrameCache();
        cache->addSpriteFramesWithFile("fish.plist", "fish.png");
        
        //add a single image into screen
        //createFish(center);
        
        //add an animation
        createFishAnimation(center, 96);
        
        bRet = true;
    } while (0);

    
    return bRet;
}

void SoulPrev::createFish(const CCPoint& point) {
    //use CCSpriteBachNode to draw texture
    CCTexture2D* texture = CCTextureCache::sharedTextureCache()->textureForKey("fish.png");
    CCSpriteBatchNode* spbatch = CCSpriteBatchNode::createWithTexture(texture);
    
    spbatch->setPosition(ccp(0, 0));
    this->addChild(spbatch);
    
    CCSprite* sprite = CCSprite::createWithSpriteFrameName("hudieyu_72.png");
    sprite->setPosition(point);
    
    sprite->setPosition(point);
    spbatch->addChild(sprite);
}

void SoulPrev::createFishAnimation(const CCPoint& point, int frames) {
    CCSpriteFrameCache* cache = CCSpriteFrameCache::sharedSpriteFrameCache();
    CCArray* animFrams = CCArray::createWithCapacity(96);
    
    char str[80];
    
    for (int i = 1; i <= frames; i++) {
        
        if (i < 10) {
            sprintf(str, "hudieyu_0%d.png", i);
        } else {
            sprintf(str, "hudieyu_%d.png", i);
        }
        
        CCSpriteFrame* sprite = cache->spriteFrameByName(str);
        
        CC_BREAK_IF(sprite == NULL);
        
        animFrams->addObject(sprite);
    }
    
    CCAnimation* animation = CCAnimation::createWithSpriteFrames(animFrams, 0.025f);
    
    //another method to create CCAnimation from CCSpriteFrame
    /*
     
     CCAnimation* animation = CCAnimation::create();
     for() {
        animation->addSpriteFram(spfr);
     }
     
     */
    
    CCSprite* animSprite = CCSprite::createWithSpriteFrameName("hudieyu_01.png");
    
    animSprite->setPosition(point);
    this->addChild(animSprite);
    
    animSprite->runAction(CCRepeatForever::create(CCAnimate::create(animation)));
}

void SoulPrev::menuCloseCallback(CCObject* pSender)
{
    CCDirector::sharedDirector()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}



