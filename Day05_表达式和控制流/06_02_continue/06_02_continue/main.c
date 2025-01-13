#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
/*
continue 是一个控制语句，用于跳过当前循环中的剩余代码，
并立即开始下一次循环迭代。它用于 for、while 和 do-while 循环中。
*/
int main() {
    printf("请输入6个整数：");
    int sum = 0;
    for (int i = 0; i < 6; ++i) {
        int x;
        scanf("%d", &x);
        if (x < 0) {
            continue;
        }
        printf("%d\n", x);
        sum += x;
    }
    printf("所有正整数的和为：%d\n", sum);
	return 0;
}