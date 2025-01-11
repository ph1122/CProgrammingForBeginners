#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int a = 1, b = 2, c = 3;
    printf("%d\n", (a++, ++b, --c));   // 2  最后一个数字   1, 3, 2

    int x = 1, y = 2, tmp;
    tmp = x;  // 1 2 1
    x = y; // 2 2 1
    y = tmp;  // 2 1 1
    printf("%d %d\n", x, y);

    tmp = x, x = y, y = tmp;
    printf("%d %d\n", x, y);

    int tmp2 = x;  // 保存 x 的值
    x = y;         // 将 y 的值赋给 x
    y = tmp2;      // 将 tmp1（原始 x 的值）赋给 y
      //int tmp1 = x, x = y, y = tmp1;  //不能达到交换变量的效果
    //当你写 int tmp1 = x, x = y, y = tmp1; 时，编译器会认为你在尝试声明三个变量：

    //    int tmp1 = x;

    //int x = y; // 这里 x 被重新声明

    //int y = tmp1; // 这里 y 被重新声明

    printf("x = %d, y = %d\n", x, y);  // 输出：x = 20, y = 10
    return 0;
}