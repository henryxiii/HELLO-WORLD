#include "HelloWorldScene.h"
#include "DataParserText.h"
USING_NS_CC;


#include <fstream>
#include <iostream>

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);
    
    return scene;
}

HelloWorld::~HelloWorld()
{
    CC_SAFE_DELETE(data1_);
    CC_SAFE_DELETE(data2_);
}
                         
                         
// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    // test  --------------------------
    const char* file = "content.txt";
    data1_ = new struct DataParserBase;
    data1_->initWithFile(file);
    data1_->printContent();
    
    data2_ = new struct DataParserText;
    data2_->initWithFile(file);
    data2_->setLanguage(DataParserText::LANGUAGE::CN);
    string str1 = data2_->textFromFile("button", "confirm");
    string str2 = data2_->textFromFile("button", "cancel");
    log("Find by name 'confirm'：%s ", str1.c_str());
    log("Find by name 'cancel'：%s ", str2.c_str());
  
    string str3 = data2_->textFromFile("button", 0);
    string str4 = data2_->textFromFile("button", 1);
    log("Find by key '0'：%s ", str3.c_str());
    log("Find by key '1'：%s ", str4.c_str());
    
    
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    
	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
    auto label = Label::createWithTTF("Data Parser", "fonts/Marker Felt.ttf", 44);
    
    // position the label on the center of the screen
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));

    // add the label as a child to this layer
    this->addChild(label, 1);

    
    
    return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif

    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
