#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
/*
1������ֵ����
2��������
3�������б����룩
4��������  ���㷨��
5������ֵ  �������

����ֵ���� ������(�����б�) {
     ������;
     return ����ֵ;
}

void ���� �ǲ���Ҫ return;
*/
int add(int a, int b) {
    int c = a + b;
    return c;
}
int main() {
    int num1, num2;
    printf("�����������֣�");
    scanf("%d %d", &num1, &num2);

    printf("%d\n", add(num1, num2));
	return 0;
}
