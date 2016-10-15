//Lobby.cpp


//
//  Lobby.cpp
//  Doodler
//
//  Created by Abishek on 9/30/16.
//
//

#include "Lobby.h"
#include "DrawingCanvas.h"
#include "Constants.h"

using namespace cocos2d;

bool Lobby::init()
{
    
    if (!Node::init())
        return false;
    
    return true;
    
}

void Lobby::onEnter()
{
    Node::onEnter();
    background = LayerColor::create(Color4B(COLOR_WHITE));
    this->addChild(background);
    setupUI();
    
}

void Lobby::setupUI()
{
    Size visibleSize = Director::getInstance()->getWinSize();
    Sprite* logo = Sprite::create("doodlerLogo.png");
    auto soloButton = ui::Button::create();
    auto duoButton = ui::Button::create();
    //Solo Button
    soloButton -> setAnchorPoint(Vec2(0.5f,0.5f));
    soloButton -> setPosition(Vec2(visibleSize.width * 0.5f, visibleSize.height * 0.40f));
    soloButton->loadTextures("soloButton.png", "soloButtonPressed.png");
    soloButton->addTouchEventListener(CC_CALLBACK_2(Lobby::soloPressed, this));
    
    //Duo Button
    duoButton->setAnchorPoint(Vec2(0.5f,0.5f));
    duoButton -> setPosition(Vec2(visibleSize.width * 0.5f, visibleSize.height * 0.25f));
    duoButton->loadTextures("duoButton.png", "duoButtonPressed.png");
    duoButton->addTouchEventListener(CC_CALLBACK_2(Lobby::duoPressed, this));


    //Logo
    logo->setAnchorPoint(Vec2(0.5f, 0.5f));
    logo->setPosition(Vec2(visibleSize.width * 0.5f,visibleSize.height * 0.75f));
    
    //Add child
    this->addChild(logo);
    this->addChild(soloButton);
    this->addChild(duoButton);
    
    
}

void Lobby::soloPressed(Ref *pSender, ui::Widget::TouchEventType eEventType)
{
    if (eEventType == ui::Widget::TouchEventType::ENDED)
    {
        Scene* scene = Scene::create();
        
        DrawingCanvas* drawingCanvas = DrawingCanvas::create();
        scene->addChild(drawingCanvas);
        
        Director::getInstance()->pushScene(scene);
        
    }
}


void Lobby::duoPressed(cocos2d::Ref* pSender, cocos2d::ui::Widget::TouchEventType eEventType)
{
    
}