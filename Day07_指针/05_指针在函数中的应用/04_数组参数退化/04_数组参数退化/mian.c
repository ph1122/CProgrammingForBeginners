#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
// �� C �����У�������Ϊ��������ʱ�����Զ��˻�Ϊָ��
// ����һ��������Ϊ�������ݸ�һ������ʱ���������Զ��˻�Ϊһ��ָ��������Ԫ�ص�ָ��
//void minmax(int a[], int aSize, int* pmax, int* pmin) {  ������  int a[]  int* a
void minmax(int* a, int aSize, int* pmax, int* pmin) {
    int min = a[0];
    int max = a[0];
    printf("�����ڲ���%zu\n", sizeof(a)); // 8   64λ��ϵͳ��ַ��8���ֽ�
    for (int i = 1; i < aSize; ++i) {
        if (a[i] > max) {
            max = a[i];
        }
        if (a[i] < min) {
            min = a[i];
        }
    }
    *pmax = max;
    *pmin = min;
}

int main() {
    int a[] = { 8,7,6,5,19,8,7,6,7,8,9, 10 };
    printf("�����ⲿ��%zu\n", sizeof(a)); // 48
    int aSize = sizeof(a) / sizeof(int);  // 12
    //int m = max(a, aSize);
    // printf("max = %d\n", m);
    int min, max;
    minmax(a, aSize, &max, &min);
    printf("min = %d, max = %d\n", min, max); // 5 19
    return 0;
}
/*
Ϊʲô������˻�Ϊָ�룿
��1��Ч�ʿ���
���������Ϊ����ʱ���˻�Ϊָ�룬��ôÿ�ε��ú���ʱ������Ҫ��������������ݸ���һ�ݴ��ݸ�������

���ڴ���������˵�����ָ��Ʋ��������Ĵ�����ʱ����ڴ档

ͨ���˻�Ϊָ�룬ֻ��Ҫ����������׵�ַ�������˲���Ҫ���ڴ渴�ƣ������Ч�ʡ�

��2����ʷ����
C ���Ե����Ŀ���Ǹ�Ч������Ӳ����

�����ڵļ����ϵͳ�У��ڴ�ͼ�����Դ�ǳ����ޣ���� C ���Ե������ѡ�������ָ�Ч�ķ�ʽ��

��3�������
ָ�����ָ��������κ�λ�ã���ʹ�ú������Դ��������һ���֣������������������顣

���磬����Դ��� arr + 2 �����������ǰ����Ԫ�ء�
*/