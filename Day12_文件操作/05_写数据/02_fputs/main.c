#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int main() {
	const char* name = "./hhh/fputs.txt";
	FILE* f = fopen(name, "w");
	if (f == NULL) {
		printf("文件不存在!\n");
		return -1;
	}

	const char* str = "Hello world!";
	int n = fputs(str, f);
	printf("%d", n);
	return 0;
}
/*
返回值
成功时：返回一个 非负整数（通常是 0 或写入的字符数，具体取决于实现）。
失败时：返回 EOF（通常是 -1）。

返回值的作用
成功：表示字符串已成功写入文件。
失败：表示写入过程中发生了错误（如文件未打开、磁盘空间不足等）。
*/