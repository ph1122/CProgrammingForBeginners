#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int a = 7, b = 6;
    printf("a + b = %d\n", a + b);
    printf("a - b = %d\n", a - b);
    printf("a * b = %d\n", a * b);
    printf("a / b = %d\n", a / b);// 1 当整数相除，编译器会把小数去掉
    printf("a / b = %lf\n", a / b);// 0.000000 由于类型不匹配，printf 会错误地解释内存中的数据，导致输出为 0.000000。

    printf("a / b = %d\n", 7 / 6);   // 1
    printf("a / b = %lf\n", 7. / 6);   // 1.166667

    printf("a / b = %d\n", -7 / 6);  // -1
    printf("a / b = %d\n", 7 / -6);  // -1
    printf("a / b = %d\n", -7 / -6); // 1

    printf("a * b = %d\n", 100000000 * 10000);// -727379968
    printf("a * b = %lld\n", 100000000 * 10000);// 3567587328
    printf("a * b = %lld\n", (long long)100000000 * 10000);// 1000000000000
    return 0;
}