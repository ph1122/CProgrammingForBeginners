#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

/*
�����printf
���룺scanf   scan  ɨ��  f��format��ʽ
*/

int main() {
	int a = 520;
	printf("%d\n", a);
	//scanf("Enter a number:%d", &a); //�ᵼ�³����Դ�������ƥ���ַ��� "Enter a number:"�������ǵȴ��û�����һ�����֡�
	printf("Enter a number: ");  // ��ʾ�û�����
	scanf("%d", &a);             // ��ȡ�û������ֵ
	printf("%d\n", a);  // ����û������ֵ
	
	int x, y;
	printf("������������ x �� y��");
	scanf("%d%d", &x, &y);// �ո�ͻس�����ָ���
	printf("x+y = %d\n", x + y);

	short b;
	long long c;
	scanf("%hd %lld", &b, &c);
	printf("%hd %lld\n", b, c);
	printf("%zu\n", sizeof(b));
	printf("%zu\n", sizeof(c));


	return 0;
}