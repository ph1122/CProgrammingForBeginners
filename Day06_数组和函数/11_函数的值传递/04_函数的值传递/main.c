#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
// ������ֵ����

/*
�ֽ���|4|4|4|4| 4 |
������|a|b|a|b|tmp|
����ֵ|6|9|9|6| 6 |

�ֽ���|4|4|
������|a|b|
����ֵ|6|9|
*/
void swap(int a, int b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
	printf("%d, %d\n", a, b);
}

int main() {
	int a = 6, b = 9;
	swap(a, b);
	printf("a=%d, b=%d\n", a, b);

	return 0;
}
