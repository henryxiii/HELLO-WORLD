//
//  DataParserText.h
//  DataParser
//
//  Created by Henry on 15/7/19.
//
//

/// 可以读取数据中的文本信息，支持多语言

#ifndef __DataParser__DataParserText__
#define __DataParser__DataParserText__

#include "DataParserBase.h"

struct DataParserText : public DataParserBase
{
    // WARNING! The sequence corresponding to the file.
    // Int means the count number of finding "{".
    enum LANGUAGE
    {
        EN = 1,
        CN,
    };
    
    LANGUAGE lng;
    void setLanguage(LANGUAGE lang);
    
    std::string textFromFile(const char* key, const char* name);
    std::string textFromFile(const char* key, int _index);

};

#endif /* defined(__DataParser__DataParserText__) */
