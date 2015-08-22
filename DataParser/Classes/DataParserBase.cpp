//
//  DataParserBase.cpp
//  AA
//
//  Created by sven on 13-9-6.
//
//

#include<fstream>
#include "DataParserBase.h"

void DataParserBase::initWithFile(const char *path)
{
    string fullpath = cocos2d::FileUtils::getInstance()->fullPathForFilename(path);

    ifstream readfile;
    string linestr;
    
    readfile.open(fullpath.c_str(),ios::in);
    if(!readfile)
    {
        printf("读取文件失败！！！！！！\n");
    }
    mapinfo.clear();
    keyVec.clear();
    vector<string>contentVec;
    
    string key;
    
    
    while (!readfile.eof() && !readfile.fail()) {
        getline(readfile,linestr);
        
        string::size_type index =linestr.find_first_of("#");
        if (index != -1) {
            linestr = linestr.substr(0,index);
        }
        index = linestr.find_first_of("=",0);
        if (index!=-1) {
            key = linestr.substr(0,index);
            keyVec.push_back(key);
        }else {
        index = linestr.find_first_of("(",0);
            int tempindex = (int)linestr.find_last_of(")");
            if (index!=-1 && tempindex!=-1) {
                linestr = linestr.substr(index+1,tempindex-index-1);
                contentVec.push_back(linestr) ;
                
            }
            
        }
        if (linestr.find_first_of(")")==0) {
            mapinfo[key]=contentVec;
            contentVec.clear();
        }
        
    }
    readfile.close();
}

void DataParserBase::printContent()
{    
    for (auto iter = mapinfo.begin(); iter != mapinfo.end(); iter++) {
        cocos2d::log("key = %s", iter->first.c_str() ); 
        vector<string> content = iter->second;
        for (auto str : content) {
            cocos2d::log("%s", str.c_str());
        }
    }
}

