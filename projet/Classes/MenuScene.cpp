#include "MenuScene.h"
#include "Definitions.h"
#include "GameScene.h"
#include "GameScene2.h"
#include "GameScene3.h"
#include "MainMenuScene.h"

USING_NS_CC;
Scene* MenuScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();

    // 'layer' is an autorelease object
    auto layer = MenuScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}
// on "init" you need to initialize your instance
bool MenuScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto backgroundSprite = Sprite::create("scene3.png");
    backgroundSprite->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

    this->addChild(backgroundSprite);

    auto menu_item_1 = MenuItemImage::create("scene3-1.png", "scene3-1clicked.png", CC_CALLBACK_1(MenuScene::GoToGameScene, this));
    auto menu_item_2 = MenuItemImage::create("scene3-2.png", "scene3-1clicked.png", CC_CALLBACK_1(MenuScene::GoToGameScene2, this));
    auto menu_item_3 = MenuItemImage::create("scene3-3.png", "scene3-1clicked.png", CC_CALLBACK_1(MenuScene::GoToGameScene3, this));
    
    auto* menu = Menu::create(menu_item_1, menu_item_2, menu_item_3, NULL);
    menu->alignItemsHorizontally();

    this->addChild(menu);


    auto playItem = MenuItemFont::create("Menu", CC_CALLBACK_1(MenuScene::GoToMainMenuScene, this));
    playItem->setPosition(Point(visibleSize.width + origin.x - 50, visibleSize.height + origin.y - 50));

    auto mn = Menu::create(playItem, NULL);
    mn->setPosition(Point::ZERO);

    this->addChild(mn);


    return true;
}
void MenuScene::GoToMainMenuScene(cocos2d::Ref* sender)
{
    auto scene = MainMenuScene::createScene();

    Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}
void MenuScene::GoToGameScene(cocos2d::Ref* sender)
{
    auto scene = GameScene::createScene();

    Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}

void MenuScene::GoToGameScene2(cocos2d::Ref* sender)
{
    auto scene = GameScene2::createScene();

    Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}

void MenuScene::GoToGameScene3(cocos2d::Ref* sender)
{
    auto scene = GameScene3::createScene();

    Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}