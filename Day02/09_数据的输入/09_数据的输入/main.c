#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

/*
输出：printf
输入：scanf   scan  扫描  f：format格式
*/

int main() {
	int a = 520;
	printf("%d\n", a);
	//scanf("Enter a number:%d", &a); //会导致程序尝试从输入中匹配字符串 "Enter a number:"，而不是等待用户输入一个数字。
	printf("Enter a number: ");  // 提示用户输入
	scanf("%d", &a);             // 读取用户输入的值
	printf("%d\n", a);  // 输出用户输入的值
	
	int x, y;
	printf("请输入两个数 x 和 y：");
	scanf("%d%d", &x, &y);// 空格和回车都算分隔符
	printf("x+y = %d\n", x + y);

	short b;
	long long c;
	scanf("%hd %lld", &b, &c);
	printf("%hd %lld\n", b, c);
	printf("%zu\n", sizeof(b));
	printf("%zu\n", sizeof(c));


	return 0;
}