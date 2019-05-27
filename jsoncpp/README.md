# C++ 结构体与 JSON 快速互转库

---

## C++ struct2json

[Class2json]是一个开源的C结构体与 JSON 快速互转库，它可以快速实现 **结构体对象** 与 **JSON 对象** 之间序列化及反序列化要求。快速、简洁的 API 设计，大大降低直接使用 JSON 解析库来实现此类功能的代码复杂度。

### 示例代码

```C
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
```

### 运行结果
```shell
{
   "assetid" : 123456,
   "files" : [ "1.ts", "2.txt" ],
   "name" : "cartoon"
}

{"assetid":123456,"files":["1.ts","2.txt"],"name":"cartoon"}
```


