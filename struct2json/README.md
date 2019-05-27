# C结构体与 JSON 快速互转库

---

## struct2json

[struct2json]是一个开源的C结构体与 JSON 快速互转库，它可以快速实现 **结构体对象** 与 **JSON 对象** 之间序列化及反序列化要求。快速、简洁的 API 设计，大大降低直接使用 JSON 解析库来实现此类功能的代码复杂度。

### 声明结构体

如下声明了两个结构体，结构体 `Hometown` 是结构体 `Student` 的子结构体

```C
/* 籍贯 */
typedef struct {
    char name[16];
} Hometown;

/* 学生 */
typedef struct {
    uint8_t id;
    uint8_t score[8];
    char name[10];
    double weight;
    Hometown hometown;
} Student;
```

### 编译
```shell
gcc main.c ../struct2json/src/* -o main -I ../struct2json/inc/ -lm
```
### 运行结果
```shell
Converted OK!
{
	"id":	24,
	"weight":	65.200000,
	"score":	[1, 2, 3, 4, 5, 6, 7, 8],
	"name":	"armink",
	"hometown":	{
		"name":	"China"
	}
}

{"id":24,"weight":65.200000,"score":[1,2,3,4,5,6,7,8],"name":"armink","hometown":{"name":"China"}}
```


