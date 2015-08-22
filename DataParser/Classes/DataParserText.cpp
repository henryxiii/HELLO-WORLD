//
//  DataParserText.cpp
//  DataParser
//
//  Created by Henry on 15/7/19.
//
//

#include "DataParserText.h"
#include <iostream>

void DataParserText::setLanguage(LANGUAGE lang)
{
    lng = lang;
}

std::string DataParserText::textFromFile(const char *key, const char *name)
{
    string line = "";

    vector<string> temp = mapinfo[key];
    if (temp.empty()) {
        printf("Not find any string for the 'key' !!!!!!");
    }
    else {
        // First to find the whole string line for name.
        vector<string>::iterator piter;
        for (piter=temp.begin(); piter!=temp.end(); piter++)
        {
            string tempstr = *piter;
            if (tempstr.find(name) != -1) {
                line = tempstr;
                break;
            }
        }
        
        if (line == "") {
            printf("Not find any string for the 'name' !!!! ");
        }
        else {
            // Second to fetch the text from the string line.
            int count = (int)lng;
            
            while (count) {
                string::size_type index = line.find_first_of("{");
                if (index != -1)
                {
                    line = line.substr(index + 1);
                    
                }
                count--;
            }
            line = line.substr(0, line.find_first_of("}") );
            
        }
    
    }
    
    return line;
}

std::string DataParserText::textFromFile(const char *key, int _index)
{
    string line = "";
    
    vector<string> temp = mapinfo[key];
    if (temp.empty()) {
        printf("Not find any string for the 'key' !!!!!!");
    }
    else {
        // First to find the whole string line for index.
        vector<string>::iterator piter;
        for (piter=temp.begin(); piter!=temp.end(); piter++)
        {
            string tempstr = *piter;
            string::size_type it = line.find_first_of(" ");
            string intStr = tempstr.substr(0, it);

            if (_index == atoi(intStr.c_str())) {
                line = tempstr;
                break;
            }
        }
        
        if (line == "") {
            printf("Not find any string for the 'key' !!!! ");
        }
        else {
            // Second to fetch the text from the string line.
            int count = (int)lng;
            
            while (count) {
                string::size_type index = line.find_first_of("{");
                if (index != -1)
                {
                    line = line.substr(index + 1);
                    
                }
                count--;
            }
            line = line.substr(0, line.find_first_of("}") );
            
        }
        
    }
    
    return line;
}

