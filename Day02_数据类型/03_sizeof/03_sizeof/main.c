#include<stdio.h>

int main() {
	short a = 1;
	int b = 2;
	long c = 3L;

	long long d = 4LL;

	sizeof(short);
	/*
	* 解释
z：

是一个长度修饰符，表示对应的参数是 size_t 类型。

size_t 是一个无符号整数类型，通常用于表示内存大小或对象的大小
（例如 sizeof 运算符的返回值）。

u：

表示无符号十进制整数。

因此，%zu 组合在一起表示：输出一个 size_t 类型的无符号整数。
	*/
	printf("short: %zu Byte\n", sizeof(short));
	printf("int: %zu Byte\n", sizeof(int));
	printf("long: %zu Byte\n", sizeof(long));
	printf("long long: %zu Byte\n", sizeof(long long));

	printf("%zu\n", sizeof(a));
	printf("%zu\n", sizeof(b));
	printf("%zu\n", sizeof(c));

	printf("%zu\n", sizeof(d));

	return 0;
}
