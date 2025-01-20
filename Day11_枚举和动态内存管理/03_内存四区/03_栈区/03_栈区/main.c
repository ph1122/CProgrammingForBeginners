#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

// 栈区和堆区都是程序运行中申请和释放的，
// 栈区的内存是操作系统控制生命周期的
// 堆区的内存是程序员控制生命周期的

// 不要返回局部变量的地址
char* func() {
    char c[20] = "Hello";
    printf("%s\n", c);// Hello
    return c;
}

void test(int a, int b) {
    int c, d;
    printf("&a = %p\n", &a); // 000000D2B03FFAE0
    printf("&b = %p\n", &b); // 000000D2B03FFAE8
    printf("&c = %p\n", &c); // 000000D2B03FF9C4
    printf("&d = %p\n", &d); // 000000D2B03FF9E4

}

int main() {
    printf("%s\n", func()); // 烫烫烫烫烫烫烫烫楮?耙
    test(5, 6);
    return 0;
}