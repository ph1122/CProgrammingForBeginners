#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
// ����������������ԭ�ͣ�
int add(int, int);

int main() {
    int x, y;
    scanf("%d %d", &x, &y);
    // ʵ�ʲ���
    int z = add(x, y);
    printf("x+y=%d\n", z);
	return 0;
}

// ��ʽ����
int add(int a, int b) {
    return a + b;
}