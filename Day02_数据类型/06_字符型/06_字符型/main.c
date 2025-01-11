#include<stdio.h>

int main() {
	// 字符类型  字符变量名 = 字符常量;		单引号里面只能是一个字符，也不能为0个
	char a = 'y';
	printf("%c\n", a);
	printf("%d\n", a);
	char b = '8';
	printf("%c\n", b);
	printf("%d\n", b);

	printf("%zu\n", sizeof(char));// 1
	printf("%zu\n", sizeof(a)); // 1
	printf("%zu\n", sizeof('y')); // c语言中并不是把字符本身存储到内存中，而是转换成一个整数以后再存储到内存中（ASCII码）
	
	printf("Size of char: %zu\n", sizeof(char));  // 输出 1
	printf("Size of 'y': %zu\n", sizeof('y'));    // 输出 4，因为 'y' 是 int 类型
	printf("Size of a: %zu\n", sizeof(a));        // 输出 1，因为 a 是 char 类型
	printf("ASCII value of 'y': %d\n", 'y');      // 输出 121，'y' 的 ASCII 码值

	return 0;
}