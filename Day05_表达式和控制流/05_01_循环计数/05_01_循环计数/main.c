#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main() {
    /*
        输入一个数 t
        然后是 t 组数据
        每组数据要求输入两个数 a 和 b
        输出 a + b 的和
    */
    int t, a, b, sum = 0;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &a, &b);
        printf("%d\n", a + b);
        sum += (a + b);
    }

    printf("%d", sum);

	return 0;
}