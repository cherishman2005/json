#include "json/json.h"
#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <map>
using namespace std;

typedef unsigned long uint64_t;
typedef unsigned int uint32_t;

void jsonMapUnmarshal(const std::string & str, std::map<std::string, std::string> & m)
{
    Json::Reader jsonReader;
    Json::Value jsonValue;
    jsonReader.parse(str, jsonValue);

    Json::Value::Members members = jsonValue.getMemberNames();
    for (auto & item : members) 
    {
        Json::ValueType vt = jsonValue[item].type();
        if (Json::stringValue != vt)
            continue;

        m.insert(std::pair<std::string, std::string>(item, jsonValue[item].asString()));
    }
}

int main(void)
{
    Json::Reader jsonReader;
    Json::Value jsonValue;
    Json::Value mapK;
    Json::Value root;


    std::string str = "{\"uploadid\": \"UP000000\",\"code\": 100,\"msg\": \"\",\"files\": \"\"}";  
    std::map<std::string, std::string> m;
    
    jsonMapUnmarshal(str, m);
    
    for (auto & it : m)
    {
        cout << it.first << " : " << it.second << endl;
    }
    
  return 0;  
}