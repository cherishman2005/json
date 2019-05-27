#include "json/json.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef unsigned long uint64_t;

int main(void) {
    Json::Value root;
    Json::Value arrayObj;
    for (int i=0; i<10; i++)
    {
        //root["array"][i] = i;
        root["array"].append(i);
    }
    
    root["key1"] = "value1";
    root["key2"] = "value2";
    
    std::string out = root.toStyledString();
    std::cout << out << std::endl;
    
    Json::FastWriter writer;  
    std::string strWrite = writer.write(root);
    cout << strWrite << endl;
    
    return 0;
}
