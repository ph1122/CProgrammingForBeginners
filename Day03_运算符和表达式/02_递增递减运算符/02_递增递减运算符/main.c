#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
// ++ 递增运算符
// -- 递减运算符

int main() {
	int i = 1;
	i++;
	printf("%d\n", i);
	++i;
	printf("%d\n", i);

	int a = 1, b = 1;
	int c = a++;// 先赋值再递增   先用后加
	int d = ++b;// 先递增再赋值   先加后用
	printf("c = %d\n", c);
	printf("d = %d\n", d);
	printf("a = %d, b = %d\n", a, b);
	printf("a++ = %d, ++b = %d\n", a++, ++b);

	return 0;
}