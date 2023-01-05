
#include "MainMenuScene.h"
#include "MenuScene.h"
#include "Definitions.h"

USING_NS_CC;
Scene* MainMenuScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();

    // 'layer' is an autorelease object
    auto layer = MainMenuScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the sceneS
    return scene;
}
// on "init" you need to initialize your instance
bool MainMenuScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto backgroundSprite = Sprite::create("scene2.png");
    backgroundSprite->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

    this->addChild(backgroundSprite);

    auto playItem = MenuItemImage::create("playbutton.png", "playbutton.png", CC_CALLBACK_1(MainMenuScene::GoToMenuScene, this));
    playItem->setPosition(Point(visibleSize.width / 4 + origin.x, visibleSize.height / 3 + origin.y - 20));
    
    auto menu = Menu::create( playItem, NULL );
    menu->setPosition( Point::ZERO );
    
    this->addChild( menu );

    return true;
}

void MainMenuScene::GoToMenuScene(cocos2d::Ref* sender)
{
    auto scene = MenuScene::createScene();

    Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}