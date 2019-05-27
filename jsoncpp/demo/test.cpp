#include "json/json.h"
#include <iostream>
#include <string>
using namespace std;

typedef unsigned long uint64_t;

struct AssetInfo {
    uint64_t assetid;
    std::string name;
    std::vector<string> files;
};

int main(void) {
    const std::string jsonStr = 
        "{\"assetid\" : 123456, \"name\" : \"cartoon\", \
        \"files\" : [\"1.ts\", \"2.txt\"]}";

    Json::Reader jsonReader;
    Json::Value jsonValue;
    jsonReader.parse(jsonStr, jsonValue);
    
    AssetInfo asset_info;
    asset_info.assetid = jsonValue["assetid"].asUInt64();
    asset_info.name = jsonValue["name"].asString();
    for (auto & file : jsonValue["files"])
    {
        asset_info.files.push_back(file.asString());
    }
    
    std::string out = jsonValue.toStyledString();
    cout << out << endl;
    
    // 输出无格式json字符串  
    Json::FastWriter writer;  
    std::string strWrite = writer.write(jsonValue);
    cout << strWrite << endl;
    
    return 0;
}
