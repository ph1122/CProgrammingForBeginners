#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main() {
	// 1、字符数组
	char h1[] = { 'h', 'e', 'l', 'l', 'o' };
	int h1size = sizeof(h1) / sizeof(char); // sizeof(char) 等于 1
	for (int i = 0; i < h1size; i++) {
		printf("%c", h1[i]);
	}
	printf("\n");

	// 字符串就是字符数组在末尾加了一个换行符
	char wd[] = { 'w', 'o', 'r','l' ,'d','\0' };
	printf("%s\n", wd); // world
	printf("%s\n", h1); // hello烫烫烫烫烫烫烫烫烫烫烫烫烫?   
	printf("wdsize = %zu\n", sizeof(wd));  // 6
	wd[1] = '0';
	printf("%s\n", wd);  // w0rld

	// 指针定义的会存储在只读常量区
	char* hhh = "hhhh";
	//hhh[1] = '0';		只读常量区的内容不能进行修改
	char* hhh1 = "hhhh";

	printf("hhh   = %p\n", hhh);   // 00007FF77150AC30
	printf("hhh1  = %p\n", hhh1);  // 00007FF77150AC30

	return 0;
} 
