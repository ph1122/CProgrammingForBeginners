#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
// strcat 是 C 语言中用于拼接字符串的函数
// str 代表字符串（string）。cat 是 concatenate（连接）的缩写。
// 第一个参数是目标字符串（destination）。第二个参数是源字符串（source）。 “目标在前，源在后，连接起来不回头。”
int main() {
	char str1[10] = { 'a', 'b','c','\0' };
	char str2[10] = "ab2";
	char* str3 = "abc";
	strcat(str2, str1);
	printf("%s\n", str2); // abc2abc

	//strcat(str3, str1);    只读常量区的字符串，无法作为拼接的目标串,因为只要拼接就会改变值，指针定义的字符串是存储在只读变量区内的
	strcat(str2, str1);
	printf("%s\n", str2); // ab2abcabc 
	strcat(str2, str1); // 会超过数组大小（10）会溢出数组报错
	printf("%s\n", str2); // ab2abcabcabc 

	return 0;
}