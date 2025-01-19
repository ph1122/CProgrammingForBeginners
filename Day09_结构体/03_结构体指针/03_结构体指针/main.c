#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

struct Book
{
	char name[100];
	double price;
	int value;
};

int main() {
    struct Book b = { "C语言入门到精通", 999, 1912992 };
    struct Book c = b;
    printf("%s的价格是%.2lf，价值是%d\n", c.name, c.price, c.value); // C语言入门到精通的价格是999.00，价值是1912992
    c.price = 399.99;
    printf("%s的价格是%.2lf，价值是%d\n", c.name, c.price, c.value); // C语言入门到精通的价格是399.99，价值是1912992
    printf("%s的价格是%.2lf，价值是%d\n", b.name, b.price, b.value); // C语言入门到精通的价格是999.00，价值是1912992
    printf("%p\n", &b); // 00000037BA6FF8A0   
    printf("%p\n", &c); // 00000037BA6FF940

    // struct 结构体名* 变量名;
    struct Book* pd;
    pd = &b;

    pd->price = 399.99;    // 当结构体是指针的时候，访问成员变量的时候，需要用->访问。
    //(*pd).name = 399.99;   // 也可以


    printf("%s的价格是%.2lf，价值是%d\n", pd->name, pd->price, pd->value); // C语言入门到精通的价格是399.99，价值是1912992
    printf("%s的价格是%.2lf，价值是%d\n", b.name, b.price, b.value); // C语言入门到精通的价格是399.99，价值是1912992


}