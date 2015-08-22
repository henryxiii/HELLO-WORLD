//
//  DataParserAnimation.cpp
//  DataParserAnimation
//
//  Created by Konvie Shaw on 15/7/19.
//
//

#include "DataParserAnimation.h"

DataParserAnimation::~DataParserAnimation(){
}

DataParserAnimation* DataParserAnimation::creat(const char* path){
    DataParserAnimation *parser = DataParserAnimation::create();
    parser->initWithFile(path);
    return parser;
}

Sprite* DataParserAnimation::FrameSpriteFromFile(const char* _key,const char* name){
    
    SpriteFrame *frame = SpriteFrameFromFile(_key, name);
    Sprite *sprite = Sprite::createWithSpriteFrame(frame);
    return sprite;
}
Sprite* DataParserAnimation::FrameSpriteFromFile(const char* _key,int _index){
    
    SpriteFrame *frame = SpriteFrameFromFile(_key, _index);
    Sprite *sprite = Sprite::createWithSpriteFrame(frame);
    return sprite;
}

SpriteFrame* DataParserAnimation::SpriteFrameFromFile(const char* _key,int _index){
    map<string, string>spriteMap;
    vector<string> temp =mapinfo[_key];
    if (temp.size()<_index) {
        return NULL;
    }
    vector<string>content;
    
    string tempstr = temp[_index-1];
    FrameSprite tempFrameSprite;
    int index;
    while ((index = tempstr.find_first_of(" "))!=-1) {
        
        string tempstr1 = tempstr.substr(0,index);
        content.push_back(tempstr1);
        tempstr = tempstr.substr(index+1);
    }
    content.push_back(tempstr);
    tempFrameSprite.index =atoi(content[0].c_str()) ;
    tempFrameSprite.name = content[1].c_str();
    tempFrameSprite.fileName = content[2].c_str();
    tempFrameSprite.rect = CCRect(atoi(content[3].c_str()), atoi(content[4].c_str()), atoi(content[5].c_str()), atoi(content[6].c_str()));
    char file[100];
    strcpy(file, tempFrameSprite.fileName);
    strcat(file, ".png");
    
    CCTexture2D* texture =CCTextureCache::sharedTextureCache()->textureForKey(file);
    SpriteFrame *frame = SpriteFrame::createWithTexture(texture, tempFrameSprite.rect);
    return frame;
}
SpriteFrame* DataParserAnimation::SpriteFrameFromFile(const char* _key,const char* name){
    map<string, string>spriteMap;
    vector<string> temp =mapinfo[_key];
    vector<string> content;
    FrameSprite tempFrameSprite;
    vector<string>::iterator piter;
    for (piter=temp.begin(); piter!=temp.end(); piter++) {
        string tempstr = *piter;
        if (tempstr.find(name)!=-1) {
            int index = 0;
            while ((index = tempstr.find_first_of(" "))!=-1) {
                
                string tempstr1 = tempstr.substr(0,index);
                content.push_back(tempstr1);
                tempstr = tempstr.substr(index+1);
                
                
            }
            content.push_back(tempstr);
            break;
        }
    }
    tempFrameSprite.index =atoi(content[0].c_str()) ;
    tempFrameSprite.name = content[1].c_str();
    tempFrameSprite.fileName = content[2].c_str();
    tempFrameSprite.rect = CCRect(atoi(content[3].c_str()), atoi(content[4].c_str()), atoi(content[5].c_str()), atoi(content[6].c_str()));
    char file[100];
    strcpy(file, tempFrameSprite.fileName);
    strcat(file, ".png");
    
    Texture2D* texture =CCTextureCache::sharedTextureCache()->textureForKey(file);
    return  SpriteFrame::createWithTexture(texture, tempFrameSprite.rect);
}

Animation* DataParserAnimation::animateFromFile(const char* _key,const char* name,const char* key2){
    map<string, string>spriteMap;
    vector<string> temp =mapinfo[_key];
    vector<string> content;
    AnimateInfo tempAnimateInfo = {"",0,{0}};
    
    vector<string>::iterator piter;
    for (piter=temp.begin(); piter!=temp.end(); piter++) {
        string tempstr = *piter;
        if (tempstr.find(name)!=-1) {
            int index = 0;
            while ((index = tempstr.find_first_of(" "))!=-1) {
                
                string tempstr1 = tempstr.substr(0,index);
                content.push_back(tempstr1);
                tempstr = tempstr.substr(index+1);
                
                
            }
            content.push_back(tempstr);
            break;
        }
    }
    tempAnimateInfo.name =content[0].c_str();
    tempAnimateInfo.FrameCount = atoi(content[1].c_str()) ;
    
    int i = 0;
    for (piter=content.begin()+2; piter!=content.end(); piter++) {
        int val= atoi((*piter).c_str());
        tempAnimateInfo.index[i] = val;
        i++;
    }
    
    // old edition
    //    CCArray *frameArr = CCArray::create();
    //    for (i=0; i<tempAnimateInfo.FrameCount; i++) {
    //        SpriteFrame *frame = this->SpriteFrameFromFile(key2, tempAnimateInfo.index[i]);
    //        frameArr->addObject(frame);
    //    }
    
    Vector<SpriteFrame*> frames;
    for (i=0; i<tempAnimateInfo.FrameCount; i++) {
        SpriteFrame *frame = SpriteFrameFromFile(key2, tempAnimateInfo.index[i]);
        frames.pushBack(frame);
    }
    
    Animation *animation = Animation::createWithSpriteFrames(frames);
    
    return animation;
}