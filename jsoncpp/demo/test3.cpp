#include "json/json.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef unsigned long uint64_t;

int main(void) {
    Json::Value root;
    Json::Value arrayObj;
    Json::Value jv;
    root.resize(0); 

#if 1
    //root["ap"] = "hha";
   
    { 
      std::string traceInfo;
      traceInfo.reserve(2048);

      traceInfo = "nihao";
      jv["nginxToVue"].append(traceInfo);
    
      root.append(jv);
    }
#endif

    std::string out = root.toStyledString();
    std::cout << out << std::endl;
    
    Json::FastWriter writer;
    writer.omitEndingLineFeed();
    std::string strWrite = writer.write(root);
    cout << strWrite << endl;

    //strWrite.assign(strWrite.c_str(), strWrite.size()-1);

    printf("log{%s}", strWrite.c_str());    
    
    return 0;
}
