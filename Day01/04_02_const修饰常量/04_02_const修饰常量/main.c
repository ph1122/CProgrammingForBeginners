// const 修饰常量
#include<stdio.h>

const int winWidth = 1024;

int main() {
	int a = 520;
	printf("%d", a);
	a = 1314;
	printf("%d\n", a);

	const int b = 1;
	printf("%d", b);
	//b = 2; // error C2166: 左值指定 const 对象 表达式必须是可修饰的左值
	return 0;
}