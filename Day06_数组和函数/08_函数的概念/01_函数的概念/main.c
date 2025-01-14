#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main() {
    // function: 功能
    printf("这是一个函数，用来处理格式化输出（绝对值）\n");
    int x;
    scanf("%d", &x);
    int y = abs(x);
    printf("y = %d\n", y);

	return 0;
}