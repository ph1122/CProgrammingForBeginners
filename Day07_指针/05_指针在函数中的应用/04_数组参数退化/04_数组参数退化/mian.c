#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
// 在 C 语言中，数组作为函数参数时，会自动退化为指针
// 当把一个数组作为参数传递给一个函数时，该数组自动退化为一个指向数组首元素的指针
//void minmax(int a[], int aSize, int* pmax, int* pmin) {  都可以  int a[]  int* a
void minmax(int* a, int aSize, int* pmax, int* pmin) {
    int min = a[0];
    int max = a[0];
    printf("函数内部：%zu\n", sizeof(a)); // 8   64位的系统地址是8个字节
    for (int i = 1; i < aSize; ++i) {
        if (a[i] > max) {
            max = a[i];
        }
        if (a[i] < min) {
            min = a[i];
        }
    }
    *pmax = max;
    *pmin = min;
}

int main() {
    int a[] = { 8,7,6,5,19,8,7,6,7,8,9, 10 };
    printf("函数外部：%zu\n", sizeof(a)); // 48
    int aSize = sizeof(a) / sizeof(int);  // 12
    //int m = max(a, aSize);
    // printf("max = %d\n", m);
    int min, max;
    minmax(a, aSize, &max, &min);
    printf("min = %d, max = %d\n", min, max); // 5 19
    return 0;
}
/*
为什么数组会退化为指针？
（1）效率考虑
如果数组作为参数时不退化为指针，那么每次调用函数时，都需要将整个数组的内容复制一份传递给函数。

对于大型数组来说，这种复制操作会消耗大量的时间和内存。

通过退化为指针，只需要传递数组的首地址，避免了不必要的内存复制，提高了效率。

（2）历史背景
C 语言的设计目标是高效和贴近硬件。

在早期的计算机系统中，内存和计算资源非常有限，因此 C 语言的设计者选择了这种高效的方式。

（3）灵活性
指针可以指向数组的任何位置，这使得函数可以处理数组的一部分，而不仅仅是整个数组。

例如，你可以传递 arr + 2 来跳过数组的前两个元素。
*/