#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

/*
1、只要是静态的，无论是局部还是全局，无论是变量还是常量，都在全局区
2、非静态的，只要是全局的，无论是变量还是常量，都在全局区
3、字符串常量 也在 全局区

全局区：存储全局变量、静态变量、常量（包括字符串常量）。
栈区：存储非静态局部变量和常量。

*/

int a = 1;              // 非静态全局变量（全局区）
const int b = 1;        // 非静态全局常量（全局区）

static int e = 3;       // 静态全局变量（全局区）
static const int f = 3; // 静态全局常量（全局区）

int main() {
	printf("非静态全局变量   a的地址是 %p\n", &a);  //	00007FF7AEF1D000
	printf("非静态全局常量   b的地址是 %p\n", &b);	//  00007FF7AEF1ABB0
	int c = 2;          // 非静态局部变量（栈区）
	const int d = 2;    // 非静态局部常量（栈区）
	printf("非静态局部变量   c的地址是 %p\n", &c);  // 000000BB8EB4FA24
	printf("非静态局部常量   d的地址是 %p\n", &d);  // 000000BB8EB4FA44

	printf("静态全局变量     e的地址是 %p\n", &e);  //  00007FF7AEF1D004
	printf("静态全局常量     f的地址是 %p\n", &f);  //  00007FF7AEF1ABB4
	static int g = 2;       // 静态局部变量（全局区）
	static const int h = 2; // 静态局部常量（全局区）
	printf("静态局部变量     g的地址是 %p\n", &g);	//   00007FF7AEF1D008
	printf("静态局部常量     h的地址是 %p\n", &h);	//   00007FF7AEF1ABB8

	printf("字符串常量的地址：         %p\n", &"Hello World"); // 00007FF7AEF1AC20
	return 0;
}