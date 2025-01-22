#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main() {
	char name[] = "./hhh/fgetc.txt";
	FILE* p = fopen(name, "r");

	if (p == NULL) {
		printf("文件不存在");
		return -1;
	}
	// fgetc 代表一次读取一个字符，如果读不到，返回 EOF
	/*
	char c = fgetc(p);
	printf("%c\n", c); // a
	c = fgetc(p);
	printf("%c\n", c); // b
	c = fgetc(p);
	printf("%c\n", c); // c
	c = fgetc(p);
	printf("%d\n", c); // -1   EOF
	*/
	// EOF end of file
	// 在C语言中，EOF（End Of File）表示文件结束标志。
	// 它是一个宏定义，通常值为-1，用于指示文件读取操作已到达文件末尾。

	char c;
	while ((c = fgetc(p)) != EOF) {
		printf("%c", c);   // abc
	}

	return 0;
}