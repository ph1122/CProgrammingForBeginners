#include <stdio.h>
#include <float.h>

/*
-------------------------------------------------------------
| ������         �ֽ���          λ��          ���ݷ�Χ     |
------------------------------------------------------------|
| float         4�ֽ�  0000       32    (FLT_MIN -> FLT_MAX)|
| double        8�ֽ�  00000000   64    (DBL_MIN -> DBL_MAX)|
-------------------------------------------------------------
*/

int main() {
    // 1��float �Ķ�������
    float a = 3.1415926F;// ����F����double
    printf("%f\n", a); // 3.141593 Ĭ������£�%f ����� 6 λС�����������ֻ��������롣
    printf("%.7f\n", a);// 3.1415925 ʹ�� %.nf������ n ��ϣ�������С��λ����float ֻ�ܾ�ȷ��ʾ 6-7 λ��Ч���֣��������ֻᶪʧ���ȡ�
    printf("%f\n", 123456789.0);// 123456789.000000
    // 2��double �Ķ�������
    /*
    �� printf �У�

%f �� %lf û�����𣬶������������ float �� double ���͡�

�� scanf �У�

%f ���ڶ�ȡ float ���͡�

%lf ���ڶ�ȡ double ���͡�
    */
    double b = 3.1415926;
    printf("%f\n", b); // 3.141593
    printf("%lf\n", b);// 3.141593
    printf("%.7lf\n", b); // 3.1415926

    // 3��С����ʡ��д��
    double c = .6;
    double d = 6.;
    printf("%lf\n", c);// 0.600000
    printf("%lf\n", d);// 6.000000

    // 4��С���Ŀ�ѧ������
    double f = 2.332e6;  // 2.332 x 10^6
    printf("%lf\n", f);// 2332000.000000
    printf("%e\n", f);// 2.332000e+06
    printf("%.3e\n", f);// 2.332e+06

    // 5��sizeof �ڸ������е�Ӧ��
    printf("%zu\n", sizeof(float));//4
    printf("%zu\n", sizeof(1.1F));//4

    printf("%zu\n", sizeof(double));//8
    printf("%zu\n", sizeof(1.1));//8

    // 6��unsigned �ڸ������е�Ӧ��(�޷��͸����ͽ������)unsigned ֻ�ܺ��������
    // unsigned double a = 1;

    // 7���������ķ�Χ
    printf("float  ����С������ʾ�ǣ�%e\n", FLT_MIN);
    printf("float  ����С������ʾ�ǣ�%f\n", FLT_MIN);

    printf("float  �����������ʾ�ǣ�%e\n", FLT_MAX);
    printf("double ����С������ʾ�ǣ�%e\n", DBL_MIN);
    printf("double �����������ʾ�ǣ�%e\n", DBL_MAX);
    // ��� float ����С�����������
    printf("float  ����С������ʾ�ǣ�%e\n", -FLT_MAX);
    printf("float  ���������ʾ�ǣ�%e\n", -FLT_MIN);

    // ��� double ����С�����������
    printf("double ����С������ʾ�ǣ�%e\n", -DBL_MAX);
    printf("double ���������ʾ�ǣ�%e\n", -DBL_MIN);

    return 0;
}