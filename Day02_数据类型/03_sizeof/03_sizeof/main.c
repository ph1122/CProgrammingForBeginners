#include<stdio.h>

int main() {
	short a = 1;
	int b = 2;
	long c = 3L;

	long long d = 4LL;

	sizeof(short);
	/*
	* ����
z��

��һ���������η�����ʾ��Ӧ�Ĳ����� size_t ���͡�

size_t ��һ���޷����������ͣ�ͨ�����ڱ�ʾ�ڴ��С�����Ĵ�С
������ sizeof ������ķ���ֵ����

u��

��ʾ�޷���ʮ����������

��ˣ�%zu �����һ���ʾ�����һ�� size_t ���͵��޷���������
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
