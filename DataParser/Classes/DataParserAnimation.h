//
//  DataParserAnimation.h
//  DataParserBase
//
//  Created by Konvie Shaw on 15/7/19.
//
//

#ifndef __DataParserBase__DataParserAnimation__
#define __DataParserBase__DataParserAnimation__

#include "DataParserBase.h"
#include "cocos2d.h"

USING_NS_CC;


typedef struct{
    int index;
    const char* name;
    const char* fileName;
    cocos2d::Rect rect;
}FrameSprite;

typedef struct{
    const char* name;
    int FrameCount;
    int index[20];
}AnimateInfo;

class DataParserAnimation : public DataParserBase
{
public:
    ~DataParserAnimation();
    CREATE_FUNC(DataParserAnimation);
    static DataParserAnimation* creat(const char* path);
    
    Sprite* FrameSpriteFromFile(const char* key,const char* name);
    Sprite* FrameSpriteFromFile(const char* key,int index);
    SpriteFrame* SpriteFrameFromFile(const char* key,int index);
    SpriteFrame* SpriteFrameFromFile(const char* key,const char* name);
    Animation* animateFromFile(const char* key,const char* name,const char* key2);
    
};

#endif /* defined(__DataParserBase__DataParserAnimation__) */
