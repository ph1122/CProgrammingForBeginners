#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main() {
	int a = 100;
	int b = 9;

	printf("%d\n", a % b);// 1
	printf("%d\n", a / b);// 11
	//   100  =  9  * 11   +  1
	//  被除数  除数  商     余数

	printf("%d\n", 100 % 9);   // 1
	printf("%d\n", 100 / 9);   // 11
	printf("%d\n", 100 % -9);  // 1
	printf("%d\n", 100 / -9);   // -11
	printf("%d\n", -100 % 9);  // -1
	printf("%d\n", -100 / 9);   // -11
	printf("%d\n", -100 % -9); // -1
	printf("%d\n", -100 / -9);   // 11
	// 取余结果的符号 取决于 被除数的符号
	// -100 =  9 * x + y
	// x = (-11)
	// y = -100 - 9*(-11) = -1
	return 0;

}