// #define 预处理指令，主要是定义常量和宏

#include<stdio.h>
// 1、#define 的用法  不能加分号，因为会替代，提前解释分号 比如	printf("%d", hhh); 会变为	printf("%d", 233333;);
#define hhh 233333
// const int hhh = 233333;
#define hello printf("%d\n",
#define X 1+2
#define Y (1+2)
int main() {
	printf("%d\n", hhh);
	hello hhh);

	printf("%d\n", X*X);   // 5
	printf("%d\n", Y*Y);   // 9


	return 0;
}

