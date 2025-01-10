#include<stdio.h>
// 字符串就是将  一个一个字符  串起来
int main() {
	// 1、字符串常量
	"字符串";

	// 2_1、字符串变量 （第一种写法）
	// char 变量名[长度] = "字符串常量";
	char a[100] = "字符串常量";
	printf("%s\n", a);

	// 2_2、字符串变量 （第二种写法）
	// char 变量名[] = "字符串常量";    不定义长度时，编译器会根据字符串的长度自动分配大小
	char b[] = "没有长度";
	printf("%s\n", b);

	// 3、sizeof测量长度
	printf("%zu\n", sizeof("字符串常量"));//11   2*5 + 1   中文占两个字节，结尾又有一个结束标志符\0
	printf("%zu\n", sizeof("String"));    //7      6 + 1
	printf("%zu\n", sizeof(a));           //100  
	printf("%zu\n", sizeof(b));           //9    2*4 + 1

	// 4、字符在字符串中的访问
	char c[] = "HelloWorld";
	char d = c[6];// 0 1 2 3 4 5 6
	printf("第六个字符是%c\n", d);// 第六个字符是o

	// 5、字符串的修改
	c[5] = ' ';
	printf("%s\n", c);// Hello orld

	// 6、字符串的结束标志 '\0';
	printf("%zu\n", sizeof(c));// 11
	printf("%c\n", c[8]);// l
	printf("%c\n", c[9]);// d
	printf("%c\n", c[10]);// 转义字符'\0'不可见
	printf("%d\n", c[10]);// 0   空字符对应的ASCII码

	return 0;
}