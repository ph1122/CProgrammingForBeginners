#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

// void类型的指针，没有类型，没有步长的概念，当然就不能进行运算,只能记录地址的值
// 任意一个地址都可以赋值给void* 类型的地址
void Print(void* data, char type) {
	switch (type) {
	case 'i':
		printf("%d\n", *(int*)data);
		break;
	case 'f':
		printf("%lf\n", *(double*)data);
		break;
	case 'c':
		printf("%c\n", *(char*)data);
		break;
	default:
		printf("Unknown type\n");
	}
}

int main() {
	// 1、定义两个变量
	int a = 1314;
	double b = 520.0;

	// 2、定义两个指针
	int* pa = &a;
	double* pb = &b;

	// 3、打印出两个变量的值
	printf("%d\n", *pa);
	printf("%lf\n", *pb);

	 //pb = &a; // 从“int *”到“double *”的类型不兼容
	void* pc = &a; // 任意一个地址都可以赋值给void* 类型的地址
	void* pd = &b;

	// printf("%d\n", *pc);    不能进行解引用
	// printf("%p\n", pc + 1); 不能进行运算

	printf("%d\n", *(int*)pc); // 1314

	int x1 = 520;
	double x2 = 1314.520;
	char x3 = 'o';
	Print(&x1, 'i'); // 520
	Print(&x2, 'f'); // 1314.520000
	Print(&x3, 'c'); // o


	return 0;
}