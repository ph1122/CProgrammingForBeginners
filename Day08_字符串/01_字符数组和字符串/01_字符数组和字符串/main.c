#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main() {
	// 1���ַ�����
	char h1[] = { 'h', 'e', 'l', 'l', 'o' };
	int h1size = sizeof(h1) / sizeof(char); // sizeof(char) ���� 1
	for (int i = 0; i < h1size; i++) {
		printf("%c", h1[i]);
	}
	printf("\n");

	// �ַ��������ַ�������ĩβ����һ�����з�
	char wd[] = { 'w', 'o', 'r','l' ,'d','\0' };
	printf("%s\n", wd); // world
	printf("%s\n", h1); // hello��������������������������?   
	printf("wdsize = %zu\n", sizeof(wd));  // 6
	wd[1] = '0';
	printf("%s\n", wd);  // w0rld

	// ָ�붨��Ļ�洢��ֻ��������
	char* hhh = "hhhh";
	//hhh[1] = '0';		ֻ�������������ݲ��ܽ����޸�
	char* hhh1 = "hhhh";

	printf("hhh   = %p\n", hhh);   // 00007FF77150AC30
	printf("hhh1  = %p\n", hhh1);  // 00007FF77150AC30

	return 0;
} 
