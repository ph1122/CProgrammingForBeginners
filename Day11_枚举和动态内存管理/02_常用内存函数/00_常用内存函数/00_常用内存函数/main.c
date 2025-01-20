#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

// 在静态内存分配下，int a[10]，必须在编译前就要定义好内存大小，如果在程序
// 运行时，实际的数据使用量小于数组长度会造成内存空间的浪费，如果是大于
// 数组长度，会造成数组下标越界。
// 而动态内存分配会根据程序的实际运行的实际需求，精确分配内存空间。
// int a[] = {1, 2,3,4,5}是根据初始化列表分配数组长度，并不能起到动态的效果。

int main() {
    // malloc    memory allocation         申请一块连续的内存空间
    // calloc    contiguous allocation     申请一块连续的内存空间 + 数据初始化
    // realloc   re-allocation             修改已经申请的内存空间的大小
    // free      free                      释放内存空间

	return 0;
}