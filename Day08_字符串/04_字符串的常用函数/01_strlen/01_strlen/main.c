#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
// 获取字符串的长度
int main() {
	char str1[10] = { 'a', 'b',' c','\0' };
	char str2[10] = "abc";
	char* str3 = "abc";

	int a = strlen(str1);
	int b = strlen(str2);
	int c = strlen(str3);
	
	printf("strlen(str1)  = %d\n", a);  // 3
	printf("strlen(str2)  = %d\n", b);  // 3
	printf("strlen(str3)  = %d\n", c);  // 3

	for (int i = 0; i < a; ++i) {
		printf("%c", str1[i]);  
	}
	// abc
	printf("\n");

	return 0;
}