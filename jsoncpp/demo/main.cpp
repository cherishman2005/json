#include "json/json.h"
#include <iostream>
#include <string>
using namespace std;

int main(void) {
    const std::string jsonStr = 
        "{\"name\" : \"Tocy\", \"salary\" : 100, \"msg\" : \"work hard\", \
        \"files\" : [\"1.ts\", \"2.txt\"]}"; 
    Json::Reader jsonReader;
    Json::Value jsonValue;
    jsonReader.parse(jsonStr, jsonValue);
    
    cout << jsonValue["name"].asString() << endl;
    std::string out = jsonValue.toStyledString();
    cout << out << endl;
    
    // 输出无格式json字符串  
    Json::FastWriter writer;  
    std::string strWrite = writer.write(jsonValue);
    cout << strWrite << endl;
    
    return 0;
}
