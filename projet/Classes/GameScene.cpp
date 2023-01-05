#include "GameScene.h"
#include "MenuScene.h"
#include "Definitions.h"


USING_NS_CC;
Scene* GameScene::createScene()
{    

    // 'scene' is an autorelease object
    auto scene = Scene::createWithPhysics();
    scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);

    // 'layer' is an autorelease object
    auto layer = GameScene::create();
    layer->SetPhysicsWorld(scene->getPhysicsWorld());

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool GameScene::init()
{
    //////////////////////////////
    // 1. super init first
    if (!Layer::init())
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();


    auto edgebody = PhysicsBody::createEdgeBox(visibleSize, PHYSICSBODY_MATERIAL_DEFAULT, 3);
    auto edgeNode = Node::create();
    edgeNode->setPosition(Point(visibleSize.width / 2 + origin.x, (visibleSize.height / 2) + 200 + origin.y));
    edgeNode->setPhysicsBody(edgebody);
    this->addChild(edgeNode);

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    auto backgroundSprite = Sprite::create("terre.png");
    backgroundSprite->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
    this->addChild(backgroundSprite);

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void addObstacle1(float dt); {
        auto addObstacle1 = Sprite::create("obstacle1.png");
        addObstacle1->setPosition(Point(visibleSize.width / 2 , visibleSize.height / 2 + origin.y));
        auto spriteBd = PhysicsBody::createBox(addObstacle1->getContentSize(), PhysicsMaterial(0, 0, 0));
        addObstacle1->setPhysicsBody(spriteBd);
        this->addChild(addObstacle1); }

    auto sprite = Sprite::create("layer.png");
    sprite->setPosition(Point(2 + origin.x, visibleSize.height / 2 + origin.y));
    auto spriteBody = PhysicsBody::createBox(sprite->getContentSize(), PhysicsMaterial(0, 0, 0));
    sprite->setPhysicsBody(spriteBody);
    this->addChild(sprite);


    auto eventListener = EventListenerKeyboard::create();

    eventListener->onKeyPressed = [](EventKeyboard::KeyCode keyCode, Event* sprite) {

        Vec2 loc = sprite->getCurrentTarget()->getPosition();
        auto jump = JumpTo::create(1, Point(loc.x + 70, loc.y), 70, 1);

        switch (keyCode) {
        case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
        case EventKeyboard::KeyCode::KEY_A:
            sprite->getCurrentTarget()->setPosition(loc.x - 50, loc.y);
            break;
        case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
        case EventKeyboard::KeyCode::KEY_D:
            sprite->getCurrentTarget()->setPosition(loc.x + 50, loc.y);
            break;
        case EventKeyboard::KeyCode::KEY_SPACE:
        case EventKeyboard::KeyCode::KEY_W:
            sprite->getCurrentTarget()->runAction(jump);
            break;
        }
    };
    this->_eventDispatcher->addEventListenerWithSceneGraphPriority(eventListener, sprite);

    /*void addObstacle2(float dt); {
        auto addObstacle2 = Sprite::create("obstacle2.png");
        addObstacle2->setPosition(Point(visibleSize.width, visibleSize.height / 2 + origin.y));
        auto spriteBd = PhysicsBody::createBox(addObstacle2->getContentSize(), PhysicsMaterial(0, 0, 0));
        addObstacle2->setPhysicsBody(spriteBd);
        this->addChild(addObstacle2); }*/


    void addObstacle3(float dt); {
        auto addObstacle3 = Sprite::create("obstacle3.png");
        addObstacle3->setPosition(Point(visibleSize.width, visibleSize.height / 2 + origin.y));
        auto spriteBd = PhysicsBody::createBox(addObstacle3->getContentSize(), PhysicsMaterial(1, 1, 1));
        addObstacle3->setPhysicsBody(spriteBd);
        this->addChild(addObstacle3); }


    auto playItem = MenuItemFont::create("Menu", CC_CALLBACK_1(GameScene::GoToMenuScene, this));
    playItem->setPosition(Point(visibleSize.width + origin.x - 50, visibleSize.height + origin.y - 50));

    auto menu = Menu::create(playItem, NULL);
    menu->setPosition(Point::ZERO);

    this->addChild(menu);


    return true;
}
void GameScene::GoToMenuScene(cocos2d::Ref* sender)
{
    auto scene = MenuScene::createScene();

    Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}
    

   



