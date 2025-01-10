#include <stdio.h>
#include <float.h>

/*
-------------------------------------------------------------
| 类型名         字节数          位数          数据范围     |
------------------------------------------------------------|
| float         4字节  0000       32    (FLT_MIN -> FLT_MAX)|
| double        8字节  00000000   64    (DBL_MIN -> DBL_MAX)|
-------------------------------------------------------------
*/

int main() {
    // 1、float 的定义和输出
    float a = 3.1415926F;// 不加F就是double
    printf("%f\n", a); // 3.141593 默认情况下，%f 会输出 6 位小数，超出部分会四舍五入。
    printf("%.7f\n", a);// 3.1415925 使用 %.nf，其中 n 是希望输出的小数位数。float 只能精确表示 6-7 位有效数字，超出部分会丢失精度。
    printf("%f\n", 123456789.0);// 123456789.000000
    // 2、double 的定义和输出
    /*
    在 printf 中：

%f 和 %lf 没有区别，都可以用于输出 float 和 double 类型。

在 scanf 中：

%f 用于读取 float 类型。

%lf 用于读取 double 类型。
    */
    double b = 3.1415926;
    printf("%f\n", b); // 3.141593
    printf("%lf\n", b);// 3.141593
    printf("%.7lf\n", b); // 3.1415926

    // 3、小数的省略写法
    double c = .6;
    double d = 6.;
    printf("%lf\n", c);// 0.600000
    printf("%lf\n", d);// 6.000000

    // 4、小数的科学计数法
    double f = 2.332e6;  // 2.332 x 10^6
    printf("%lf\n", f);// 2332000.000000
    printf("%e\n", f);// 2.332000e+06
    printf("%.3e\n", f);// 2.332e+06

    // 5、sizeof 在浮点数中的应用
    printf("%zu\n", sizeof(float));//4
    printf("%zu\n", sizeof(1.1F));//4

    printf("%zu\n", sizeof(double));//8
    printf("%zu\n", sizeof(1.1));//8

    // 6、unsigned 在浮点数中的应用(无法和浮点型进行组合)unsigned 只能和整型组合
    // unsigned double a = 1;

    // 7、浮点数的范围
    printf("float  的最小正数表示是：%e\n", FLT_MIN);
    printf("float  的最小正数表示是：%f\n", FLT_MIN);

    printf("float  的最大正数表示是：%e\n", FLT_MAX);
    printf("double 的最小正数表示是：%e\n", DBL_MIN);
    printf("double 的最大正数表示是：%e\n", DBL_MAX);
    // 输出 float 的最小负数和最大负数
    printf("float  的最小负数表示是：%e\n", -FLT_MAX);
    printf("float  的最大负数表示是：%e\n", -FLT_MIN);

    // 输出 double 的最小负数和最大负数
    printf("double 的最小负数表示是：%e\n", -DBL_MAX);
    printf("double 的最大负数表示是：%e\n", -DBL_MIN);

    return 0;
}