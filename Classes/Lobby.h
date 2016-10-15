
//
//  Lobby.h
//  Doodler
//
//  Created by Abishek on 9/30/16.
//
//

#ifndef __Doodler__Lobby__
#define __Doodler__Lobby__

#include "cocos2d.h"
#include "ui/CocosGUI.h"

class Lobby : public cocos2d::Node
{
public:
    CREATE_FUNC(Lobby);
    
protected:
   
    cocos2d::LayerColor* background;
    
    bool init() override;
    void onEnter() override;
    void setupUI();
    void soloPressed(cocos2d::Ref* pSender, cocos2d::ui::Widget::TouchEventType eEventType);
    void duoPressed(cocos2d::Ref* pSender, cocos2d::ui::Widget::TouchEventType eEventType);
};

#endif /* defined(__Doodler__Lobby__) */
