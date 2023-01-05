
#ifndef __GAME_SCENE_3_H__
#define __GAME_SCENE_3_H__

#include "cocos2d.h"

class GameScene3 : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    // implement the "static create()" method manually
    CREATE_FUNC(GameScene3);

private:
    cocos2d::PhysicsWorld* sceneWorld;
    void SetPhysicsWorld(cocos2d::PhysicsWorld* world) { sceneWorld = world; };

private:
    void GoToMenuScene(cocos2d::Ref* sender);
};
void addObstacle1(float dt);
void addObstacle2(float dt);
void addObstacle3(float dt);
#endif // __GAME_SCENE_3_H__
