#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main() {
	char str[100];
	//scanf("%s", str);
	//printf("%s\n", str);

	gets(str); // 可以输入空格和中文
	printf("%s\n", str);

	//char*
	return 0;
}