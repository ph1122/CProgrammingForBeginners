#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

// 数组的定义
int main() {
	// 数据类型 数组名[长度];
    int scores[45];
    double db[100];
    char ch[88];

    printf("%zu\n", sizeof(scores) / sizeof(int)); // 45
    printf("%zu\n", sizeof(db) / sizeof(double));  // 100
    printf("%zu\n", sizeof(ch) / sizeof(char));    // 88

	return 0;
}