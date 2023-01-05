
#include "HelloWorldScene.h"
#include "MainMenuScene.h"
#include "Definitions.h"
#include "AudioEngine.h"

USING_NS_CC;
Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();

    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    this->scheduleOnce(CC_SCHEDULE_SELECTOR(HelloWorld::GoToMainMenuScene), DISPLAY_TIME_HELLOWORLD_SCENE);


    auto backgroundSprite = Sprite::create("scene1.png");
    backgroundSprite->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

    this->addChild(backgroundSprite);

    AudioEngine::play2d("game-music.mp3", true, 1);

    /*auto musicVol = 1.0f;
    auto gameAudioProfile = cocos2d::AudioEngine::INVALID_AUDIO_ID;

    if (gameAudioProfile == cocos2d::AudioEngine::INVALID_AUDIO_ID) {
        gameAudioProfile = cocos2d::AudioEngine::play2d("Rusty.mp3", true, MusicVol);
    }*/



    return true;
}
void HelloWorld::GoToMainMenuScene(float dt)
{
    auto scene = MainMenuScene::createScene();

    Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}