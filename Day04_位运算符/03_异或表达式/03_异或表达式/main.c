#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
/*
x ^ y            ����  x���y

�������     �Ҳ�����      ���
   0            0            0
   0            1            1
   1            0            1
   1            1            0

���ۣ�
1��������ͬ������򣬽��Ϊ0
2���κ�һ������0��򣬽��һ����������
3���������ɺͽ�����
*/
int main() {
    // 1���������ĺ���
    int a = 0b1010;
    int b = 0b0110;
    //      0b1100;
    printf("%d %d\n", a ^ b, 0b1100);
    // 2�����λȡ��
    //int x = 0b10100;
    //int y = 0b01000;
    int x = 0b10100;
    int y = 0b11100;
    //      0b01000;
    a = x;
    printf("%d %d\n", a ^ 0b1000, y);
    a = y;  
    printf("%d %d\n", a ^ 0b1000, x);

    // 3����������
    x = 1;
    y = 2;
    x = x ^ y;  // x' = x ^ y
    y = x ^ y;  // y' = x' ^ y = x ^ y ^ y = x ^ 0 = x
    x = x ^ y;  // x''= x' ^ y' = (x ^ y) ^ x = x ^ x ^ y = 0 ^ y = y
    printf("%d %d\n", x, y);

	return 0;
}
