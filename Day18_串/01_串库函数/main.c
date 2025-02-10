#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {
	char str1[50] = "Hello,";
	char str2[50] = "World!";
	char str3[50];

	printf("str1:%s\n", str1);
	printf("str2:%s\n", str2);
	// 获取字符串的长度
	printf("strlen(str1) %d\n", strlen(str1)); // 6
	printf("strlen(str2) %d\n", strlen(str2)); // 6

	// 字符串的拷贝
	strcpy(str3, str2);
	printf("str2:%s\n", str2);
	printf("str3:%s\n", str3);

	// 字符串的比较
	/*
	如果返回值小于 0，则表示 str1 小于 str2。
	如果返回值大于 0，则表示 str1 大于 str2。
	如果返回值等于 0，则表示 str1 等于 str2。
	*/
	int ret = strcmp(str1, str2);
	if (ret < 0)
	{
		printf("str1 小于 str2\n");  /// str1 小于 str2   H < W
	}
	else if (ret > 0)
	{
		printf("str1 大于 str2\n");
	}
	else
	{
		printf("str1 等于 str2\n");
	}

	// 字符串的拼接
	printf("%s\n", strcat(str1, str2));

	// 字符串的索引
	for (int i = 0; i < strlen(str1); i++)
	{
		printf("%d %d %c\n", i, str1[i], str1[i]);
	}
	for (int i = 0; i < strlen(str2); i++)
	{
		printf("%d %d %c\n", i, str2[i], str2[i]);
	}
	return 0;
}