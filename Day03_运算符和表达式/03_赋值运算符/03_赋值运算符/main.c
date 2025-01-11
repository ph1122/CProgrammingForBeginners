#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main() {
	// 赋值就是给一个变量赋予一个值
	// 一、简单赋值运算符
	int x, y;
	// 1、常量赋值给变量
	x = 6;
	printf("%d\n", x);

	// 2、变量赋值给变量
	y = x;
	printf("%d\n", y);
	x = 5;
	printf("%d, %d\n", x, y);
	// 3、计算结果赋值给变量
	x = x + y;   // x = 5 + 6 = 11;
	printf("%d %d\n", x, y);

	// 二、复合赋值运算符(好处是减少一行的长度)
	x += y;    // x = x + y;
	printf("%d %d\n", x, y);

	x -= y;    // x = x - y;
	printf("%d %d\n", x, y);

	x *= y;    // x = x * y;
	printf("%d %d\n", x, y);

	x /= y;    // x = x / y;
	printf("%d %d\n", x, y);

	x %= y;    // x = x % y;
	printf("%d %d\n", x, y);

	int alonglonglongname = 3;
	alonglonglongname += 6;
	// alonglonglongname = alonglonglongname + 6;
	printf("alonglonglongname = %d", alonglonglongname);
	return 0;

}