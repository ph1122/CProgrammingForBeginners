#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

// 函数的址传递
void swap(int* x, int* y)
{
	printf("交换前：x的值  ：%p，y的值  ：%p\n", x, y);
	// 交换前：x的值  ：00D3FEAC，y的值  ：00D3FEA0
	int temp;
	temp = *y;
	*y = *x;
	*x = temp;
}
int main() {
	int a = 1, b = 2;
	printf("a = %d, b = %d\n", a, b);// a = 1, b = 2

	printf("交换前：a的地址：%p，b的地址：%p\n", &a, &b); // 交换前：a的地址：00D3FEAC，b的地址：00D3FEA0
	swap(&a, &b);
	printf("a = %d, b = %d\n", a, b); // a = 2, b = 1
	printf("交换后：a的地址：%p，b的地址：%p\n", &a, &b);
	// 交换后：a的地址：00D3FEAC，b的地址：00D3FEA0

	return 0;
}
