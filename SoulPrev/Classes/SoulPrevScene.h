#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

using namespace cocos2d;

class SoulPrev : public cocos2d::CCLayerColor
{
public:
    // Method 'init' in cocos2d-x returns bool, instead of 'id' in cocos2d-iphone (an object pointer)
    virtual bool init();

    // there's no 'id' in cpp, so we recommend to return the class instance pointer
    static cocos2d::CCScene* scene();
    
    // a selector callback
    void menuCloseCallback(CCObject* pSender);
    
    // add a image of fish
    void createFish(const CCPoint&);
    
    // create an animation, can be implemented as a util function
    void createFishAnimation(const CCPoint&, int);

    // preprocessor macro for "static create()" constructor ( node() deprecated )
    CREATE_FUNC(SoulPrev);
};

#endif // __HELLOWORLD_SCENE_H__
