#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main() {
    int a = 1, b = 2, c = 3, d = 4;
    // 1、算术表达式
    printf("%d\n", a + b + c + d); // 10
    printf("%d\n", a + b * c - d); // 3

    // 2、赋值表达式
    // a = b;  // 赋值表达式的结果，是赋值符号右边的值
    printf("%d\n", a = b);         // 2
    printf("%d\n", a = (b = c));  // b = 3 --> a = 3   
    printf("a=%d, b=%d, c=%d\n", a, b, c);// 3 3 3
    printf("%d\n", a -= b);  // a = a - b     0
    printf("a=%d, b=%d, c=%d\n", a, b, c);// 0 3 3 

    // 3、关系表达式
    printf("%d\n", a > b); // 0
    printf("%d\n", a < b < c);  // 1   0 3 3
    // (a<b) < c
    // 1 < c
    // 1 < 3  ->  1
    printf("%d\n", a > b > c < d);  // 1

    // 4、逻辑表达式    一元运算符 优先级 大于二元优先级
    printf("%s\n", "4、逻辑表达式");
    printf("%d\n", (a == 0) && (b == 0));// 0
    printf("%d\n", !a && !b); // 0
    a = 0, b = 0;
    printf("%d\n", !a && !b);   // 1

    // 5、逗号表达式
    printf("a = %d, b = %d, c = %d, d = %d\n", a, b, c, d); // a = 0, b = 0, c = 3, d = 4
    int e = (a = b + c, !b || a++, a < b && c++, d = a + c);
    /*
    a = b + c   ->  a = 3
    !b || a++     !b等于1，所以a++并没有执行
    a < b && c++
    d = a + c   -> d = a + c = 3 + 3 = 6
    e = 6
    */
    printf("a=%d, b=%d, c=%d, d=%d, e=%d\n", a, b, c, d, e);// 3 0 3 6 6

    // 6、位表达式
    a = (33 >> 5) & 0b1;      // 0b100001  -> 0b1 & 0b1 -> 1
    b = (1 << 4) | (1 << 3) | (1 << 2) | (1 << 1); // 2 + 4 + 8 + 16 = 30
    c = a ^ a ^ a ^ a ^ b;     // 30
    d = ~~~~~~~a;              // ~a = ~1 = -2 // 奇数次取反等同于取反一次
    printf("a=%d, b=%d, c=%d, d=%d\n", a, b, c, d);// a = 1, b = 30, c = 30, d = -2

	return 0;
}