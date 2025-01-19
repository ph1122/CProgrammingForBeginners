#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
// 把不同数据类型的整合到一起，形成一个结构化的整体
// struct 是 structure（结构）的缩写。
// 1、结构体的定义
// struct 结构体名 { 结构体成员变量列表 };
struct Book
{
	char name[50];
	double price;
	int value;
};

int main() {
	// 2、结构体的创建（使用）
	// 2.1、struct 结构体名 变量名;
	struct Book c;
		strcpy(c.name, "C语言程序设计");
	printf("%s\n", c.name); // C语言程序设计
	*c.name = 'ABCD';  // 'ABCD'是一个多字符字符常量，在C语言中，多字符字符常量的值是其最后一个字符的ASCII码，即'D'。
	printf("%s\n", c.name); // D语言程序设计
	//c.name = "C语言程序设计";   // 在 C 语言中，数组名是一个常量指针，表示数组的首地址.这里的 name 是一个指向字符数组的常量指针，不能被重新赋值
	// 2.2、struct 结构体名 变量名 = {  初始化列表  }
	struct Book cpp = { "C++", 213.32, 32413 };
	printf("%s\n", cpp.name); // C++

	// 直接创建，在定义的最后一个括号加上变量名
	struct MyBook
	{
		char name[50];
		double price;
		int value;
	}python;

	strcpy(python.name, "Python");
	printf("%s\n", python.name);

	struct MyBook MyPython;
	strcpy(MyPython.name, "MyPython");
	printf("%s\n", MyPython.name);

	return 0;
}