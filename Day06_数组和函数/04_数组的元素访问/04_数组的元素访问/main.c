#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main() {
    int a[5] = { 9,8,7,6,5 };
    // ����\С��
    // 1����ȡ
    // ������[����]
    printf("%d\n", a[0]);
    printf("%d\n", a[1]);
    printf("%d\n", a[2]);
    printf("%d\n", a[3]);
    printf("%d\n", a[4]);

    // 2���޸�
    // ������[����] = �޸ĺ��ֵ;
    a[3] = -1;
    a[2] = -9;
    a[0] = 6;
    printf("%d\n", a[0]);
    printf("%d\n", a[1]);
    printf("%d\n", a[2]);
    printf("%d\n", a[3]); // -1
    printf("%d\n", a[4]);

    int b = a[3];
    printf("%d\n", b); // -1
    //b = 1;
    //printf("%d\n", b); // 1
    //printf("%d\n", a[3]); // -1
    a[3] = 10;
    printf("%d\n", b); // -1
    printf("%d\n", a[3]); // 10

	return 0;
}