# C++ 结构体与 JSON 快速互转库

---

## C++ struct2json

[Class2json]是一个开源的C结构体与 JSON 快速互转库，它可以快速实现 **结构体对象** 与 **JSON 对象** 之间序列化及反序列化要求。快速、简洁的 API 设计，大大降低直接使用 JSON 解析库来实现此类功能的代码复杂度。

### 声明结构体

```C
struct AssetInfo {
    uint64_t assetid;
    std::string name;
    std::vector<string> files;
};
```

### 编译
```shell
g++ test.cpp -o test -I ../json_lib ../json_lib/lib/json_lib.a -std=c++11
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


