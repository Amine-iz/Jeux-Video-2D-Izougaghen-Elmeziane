
#ifndef __MENU_SCENE_H__
#define __MENU_SCENE_H__

#include "cocos2d.h"

class MenuScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    // implement the "static create()" method manually
    CREATE_FUNC(MenuScene);

private:
    void GoToGameScene(cocos2d::Ref* sender);

private:
    void GoToGameScene2(cocos2d::Ref* sender);

private:
    void GoToGameScene3(cocos2d::Ref* sender);

private:
    void GoToMainMenuScene(cocos2d::Ref* sender);
};

#endif // __MENU_SCENE_H__
