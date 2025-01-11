#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
int main() {
	printf("%c\n", 'y' + 1);  // z
	printf("%c\n", 'y' - 1);  // x

	printf("%d\n", 'y');     //121
	printf("%d\n", 'y' + 1); // 122
	printf("%d\n", 'y' - 1); // 120

	// 'A' + x;   如果 x 的值是 0 到 25，那是不是代表这个表达式的值是 'A' 到 大写的 'Z' 
	printf("输入一个小写字母：");
	char ch[100];
	scanf("%s", ch);
	char ch1 = ch[0];
	int x = ch1 - 'a';
	printf("大写字母是：%c\n", 'A' + x);

	printf("输入一个大写字母：");
	scanf("%s", ch);
	char ch2 = ch[0];
	int y = ch2 - 'A';
	printf("小写字母是：%c\n", 'a' + y);
	return 0;
}