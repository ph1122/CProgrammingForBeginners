#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
// �� C �����У�������Ϊ��������ʱ�����Զ��˻�Ϊָ��
void maxmin(int arr[], int asize, int* pmax, int* pmin)
{
	int max = arr[0];
	int min = arr[0];
	for (int i = 0; i < asize; ++i) {
		if (max < arr[i]) {
			max = arr[i];
		}
		if (min > arr[i]) {
			min = arr[i];
		}
	}
	*pmax = max;
	printf("%d\n", max);  // 19
	printf("%d\n", *pmax);// 19

	*pmin = min;
	printf("%d\n", min);  // 5
	printf("%d\n", *pmin);// 5
}

int main() {
	int a[] = { 8,12,6,5,19,8,7,6,7,8,9 };
	
	int max, min;
	maxmin(a, sizeof(a) / sizeof(int), &max, &min);
	printf("max = %d, min = %d\n", max, min); // 19 5
	return 0;
}