#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

// 99999
// 99999.00
// "99,999"

// 1、联合体的定义
// union 联合体名 { 联合体成员变量列表; };
union CurrencyType {
	int i;
	double d;
	char s[50];
};

typedef union CurrencyTypedef {
	int i;
	double d;
	char s[50];
}ctdef;

int main() {
	union CurrencyType ct;

	ct.i = 99999;
	printf("%d\n", ct.i);

	ct.d = 99999.0;
	printf("%lf\n", ct.d);

	strcpy(ct.s, "99,999");
	printf("%s\n", ct.s);

	ctdef ct1;
	ct1.i = 99999;
	printf("%d\n", ct1.i);

	ct1.d = 99999.0;
	printf("%lf\n", ct1.d);

	strcpy(ct1.s, "99,999");
	printf("%s\n", ct1.s);
	/*
	联合体不可以，因为当为联合的一个成员分配一个值时，它会覆盖所有其他成员共享的内存位置。
	ct1.i = 99999;
	ct1.d = 99999.0;
	strcpy(ct1.s, "99,999");
	printf("%d\n", ct1.i);
	printf("%ld\n", ct1.d);
	printf("%s\n", ct1.s);
	*/

	return 0;
}
