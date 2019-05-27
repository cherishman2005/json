#include "json/json.h"
#include <iostream>
#include <string>
using namespace std;

typedef unsigned long uint64_t;

int main(void) {
    Json::Value root;
    Json::Value arrayObj;
    Json::Value item;
    for (int i=0; i<10; i++)
    {
        item["key"] = i;
        arrayObj.append(item);
    }
    
    root["key1"] = "value1";
    root["key2"] = "value2";
    root["array"] = arrayObj;
    
    std::string out = root.toStyledString();
    std::cout << out << std::endl;
    
    Json::FastWriter writer;  
    std::string strWrite = writer.write(root);
    cout << strWrite << endl;
    
    return 0;
}
