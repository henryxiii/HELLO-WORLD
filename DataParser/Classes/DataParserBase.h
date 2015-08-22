//
//  DataParserBase.h
//  AA
//
//  Created by sven on 13-9-6.
//
//

/// 处理文本内容数据，存放进 map

#ifndef __AA__DataParserBase__
#define __AA__DataParserBase__

#include <map>
#include <vector>

using namespace std;

struct DataParserBase
{
    void initWithFile(const char* path);
    void printContent(); // Print map data.
  
    // Use map to store data after parsing from file.
    map<string,vector<string> >mapinfo;
    vector<string>keyVec;
};
#endif /* defined(__AA__DataParserBase__) */

