#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int add(int a, int b) {
    return a + b;
}
int sub(int a, int b) {
    return a - b;
}
int mul(int a, int b) {
    return a * b;
}
int div(int a, int b) {
    return a / b;
}
int mod(int a, int b) {
    return a % b;
}

int main() {
    /*
    * ������������ a �� b
    * Ҫ����� �ӡ������ˡ�����ȡ�� �Ľ��
    */
    int (*operation[5])(int, int) = { add, sub, mul, div, mod };
    char op[5] = { '+', '-', '*', '/', '%' };
    for (int i = 0; i < 5; ++i) {
        int re = operation[i](5, 6);
        printf("5 %c 6 = %d\n", op[i], re);
    }

	return 0;
}