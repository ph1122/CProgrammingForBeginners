#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

/*
x | y            读作  x位或y

左操作数     右操作数      结果
   0            0            0
   0            1            1
   1            0            1
   1            1            1

结论：
1、无论是0或1，只要位或上1，结果就是1
2、只有当两个操作数都是0的时候，结果才是0
*/

int main() {
    // 1、位或运算的含义
    int a = 0b1010;
    int b = 0b0110;
    //      0b1110;
    printf("%d\n", (a | b)); // 14

    // 2、设置标记位
    int x = 0b1011;
    int y = 0b0100;
    printf("%d %d\n", x | y, 0b1111);

    // 3、置空标记位
    x = 0b1111; // 0b1111 或者 0b1011;
    y = 0b0100;
    printf("%d %d\n", (x | y) - y, 0b1011);
    printf("%d\n", x & 0b1011);

    // 4、低位连续零变一
    x = 0b1010010000;
    //  0b0000001111;
  //x-1=0b1010001111
    printf("%d %d\n", (x | (x - 1)), 0b1010011111);

    return 0;
}