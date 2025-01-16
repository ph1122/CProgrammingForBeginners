#include<stdio.h>

int main() {
	// 1、变量的定义
	// 数据类型   变量名;
	int name_a;   // 整型  变量名
	
	// 2、变量的赋值
	// 变量名 = 值;
	name_a = 520;
	printf("%d\n", name_a);

	// 3、变量初始化
	// 数据类型 变量名 = 值;
	int name_b = 1314;
	printf("%d\n", name_b);

	// 4、多变量定义
	// 数据类型 变量名1 = 值1, 变量名2 = 值2, 变量名3 = 值3;
	int c = 1, d = 2, e = 3;
	int f, g = 4, h; // 只给 g 赋值了
	//printf("%d", f); // 使用了未初始化的局部变量“f”

	return 0;
}