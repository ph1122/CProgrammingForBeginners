#include<stdio.h>

int main() {
	// �ַ�����  �ַ������� = �ַ�����;		����������ֻ����һ���ַ���Ҳ����Ϊ0��
	char a = 'y';
	printf("%c\n", a);
	printf("%d\n", a);
	char b = '8';
	printf("%c\n", b);
	printf("%d\n", b);

	printf("%zu\n", sizeof(char));// 1
	printf("%zu\n", sizeof(a)); // 1
	printf("%zu\n", sizeof('y')); // c�����в����ǰ��ַ�����洢���ڴ��У�����ת����һ�������Ժ��ٴ洢���ڴ��У�ASCII�룩
	
	printf("Size of char: %zu\n", sizeof(char));  // ��� 1
	printf("Size of 'y': %zu\n", sizeof('y'));    // ��� 4����Ϊ 'y' �� int ����
	printf("Size of a: %zu\n", sizeof(a));        // ��� 1����Ϊ a �� char ����
	printf("ASCII value of 'y': %d\n", 'y');      // ��� 121��'y' �� ASCII ��ֵ

	return 0;
}