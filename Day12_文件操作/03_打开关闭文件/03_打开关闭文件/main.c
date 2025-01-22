#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>


int main() {
	//"E:\Project\C\c_base\CProgrammingForBeginners\Day12_文件操作\03_打开关闭文件\03_打开关闭文件\hhh\gg.txt"
	//char name[] = "hhh\\gg.txt";
	char name[] = "./hhh/gg.txt";
	printf("%s\n", name);
	FILE* P = fopen(name, "r");   // 只读
	if (P == NULL) {
		printf("文件不存在\n");
		return -1;
	}

	/*
	读取数据
	*/

	fclose(P);
	return 0;
}