//
//  DrawingCanvas.cpp
//  Doodler
//
//  Created by Abishek on 9/30/16.
//
//

#include "DrawingCanvas.h"
#include "Constants.h"
#include "Lobby.h"

using namespace cocos2d;

bool DrawingCanvas::init()
{
    if (!Node::init())
        return false;
    
    drawNode  = DrawNode::create();
    background = LayerColor::create(Color4B(COLOR_WHITE));
    this ->addChild(background);
    this -> addChild(drawNode);
    return true;
}

void DrawingCanvas::onEnter()
{
    Node::onEnter();
    Size visibleSize = CCDirector::getInstance()->getWinSize();
    this->setContentSize(visibleSize);
    drawNode->setContentSize(visibleSize);
    this->setupMenus();
    this->setupTouchHandling();
}

void DrawingCanvas::setupMenus()
{
    Size visibleSize = CCDirector::getInstance()->getWinSize();
    this->setContentSize(visibleSize);
    auto clearButton = ui::Button::create();
    auto backButton = ui::Button::create();
    check = Sprite::create("checkMark.png");
    Node *colorButtonLayout = Node::create();
    
    //ColorbuttonLayout
    colorButtonLayout->setContentSize(Size(visibleSize.width, visibleSize.height* 0.20f));
    colorButtonLayout->setAnchorPoint(Vec2(0.5f,0));
    colorButtonLayout->setPosition(Vec2(visibleSize.width*1.0f,visibleSize.height* 0.0f));
   
    for (int i=1; i<=5; i++)
    {
        auto colorButton = ui::Button::create();
        colorButton -> setAnchorPoint(Vec2(0.5f,0.5f));
        colorButton -> loadTextures("colorSwatch.png", "colorSwatch.png");
        colorButton -> addTouchEventListener(CC_CALLBACK_2(DrawingCanvas::colorChangePressed,this));
        colorButton->setColor(Color3B(COLOR_BLUE));
        colorButtonLayout->addChild(colorButton);
        colorButton -> setNormalizedPosition(Vec2());
        
    }
    
    //clear Button
    clearButton -> setAnchorPoint(Vec2(0.5f,0.5f));
    clearButton -> setPosition(Vec2(visibleSize.width * 0.65f, visibleSize.height * 0.95f));
    clearButton->loadTextures("clearButton.png", "clearButtonPressed.png");
    clearButton->addTouchEventListener(CC_CALLBACK_2(DrawingCanvas::clearPressed, this));
    
    //backButton
    backButton -> setAnchorPoint(Vec2(0.5f,0.5f));
    backButton -> setPosition(Vec2(visibleSize.width * 0.35f, visibleSize.height * 0.95f));
    backButton -> loadTextures("backButton.png", "backButtonPressed.png");
    backButton -> addTouchEventListener(CC_CALLBACK_2(DrawingCanvas::backPressed, this));
    
    //Check
    check -> setAnchorPoint(Vec2(0.5f,0.5f));
    check ->setNormalizedPosition(Vec2(0.5f,0.5f));
    
    
    
    this->addChild(colorButtonLayout);
    this->addChild(clearButton);
    this->addChild(backButton);
    
    
}

void DrawingCanvas::clearPressed(cocos2d::Ref* pSender, cocos2d::ui::Widget::TouchEventType eEventType)
{
    if (eEventType == ui::Widget::TouchEventType::ENDED)
    {
        drawNode ->clear();
    }
}

void DrawingCanvas::backPressed(cocos2d::Ref* pSender, cocos2d::ui::Widget::TouchEventType eEventType)
{
    if (eEventType == ui::Widget::TouchEventType::ENDED)
    {
        
        Director::getInstance()->popScene();
    }
}

void DrawingCanvas::colorChangePressed(cocos2d::Ref* pSender, cocos2d::ui::Widget::TouchEventType eEventType)
{
    
}


void DrawingCanvas::setupTouchHandling()

{
    static Vec2 lastTouchPos;
    auto touchListener = EventListenerTouchOneByOne::create();
    touchListener->onTouchBegan = [&](Touch* touch, Event* event)
    {
        lastTouchPos = drawNode->convertTouchToNodeSpace(touch);
        return true;
    };
    touchListener->onTouchMoved = [&](Touch* touch, Event* event)
    {
        Vec2 touchPos = drawNode->convertTouchToNodeSpace(touch);
        drawNode->drawSegment(lastTouchPos, touchPos,INITIAL_RADIUS, Color4F(COLOR_BLACK));
        lastTouchPos = touchPos;

    };
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchListener, this);
}




