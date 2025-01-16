#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

// void���͵�ָ�룬û�����ͣ�û�в����ĸ����Ȼ�Ͳ��ܽ�������,ֻ�ܼ�¼��ַ��ֵ
// ����һ����ַ�����Ը�ֵ��void* ���͵ĵ�ַ
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
	// 1��������������
	int a = 1314;
	double b = 520.0;

	// 2����������ָ��
	int* pa = &a;
	double* pb = &b;

	// 3����ӡ������������ֵ
	printf("%d\n", *pa);
	printf("%lf\n", *pb);

	 //pb = &a; // �ӡ�int *������double *�������Ͳ�����
	void* pc = &a; // ����һ����ַ�����Ը�ֵ��void* ���͵ĵ�ַ
	void* pd = &b;

	// printf("%d\n", *pc);    ���ܽ��н�����
	// printf("%p\n", pc + 1); ���ܽ�������

	printf("%d\n", *(int*)pc); // 1314

	int x1 = 520;
	double x2 = 1314.520;
	char x3 = 'o';
	Print(&x1, 'i'); // 520
	Print(&x2, 'f'); // 1314.520000
	Print(&x3, 'c'); // o


	return 0;
}