#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main() {
	const char* name = "./hhh/fputc.txt";
	FILE* f = fopen(name, "w");
	if (f == NULL) {
		printf("文件不存在！");
		return -1;
	}

	int c = fputc(97, f);
	printf("%d\n", c);// 97
	printf("%c\n", c);// a
	c = fputc(98, f);
	printf("%d\n", c);// 98
	printf("%c\n", c);// b
	c = fputc('c', f);
	printf("%d\n", c);// 99
	printf("%c\n", c);// c

	const char* str = "\nHello World!";
	while (*str++) {
		fputc(*(str - 1), f);
	}

	const char* str1 = "\nHello World!";
	while (*str1) {
		fputc(*str1++, f);
	}

	str1 = "\nHello World!";
	while (*str1) {
		fputc(*str1, f);
		str1++;
	}

	const char* str2 = "\nHello World!";
	for (int i = 0; str2[i]; ++i) {
		fputc(str2[i], f);
	}

	fclose(f);
	return 0;
}
/*
### **`(*str++)` 的执行顺序**

- `*str++` 是一个复合表达式，涉及两个操作：
  1. **`str++`**：这是后置递增运算符，它的作用是：
	 - 先返回 `str` 的当前值（即指针的当前地址）。
	 - 然后将 `str` 的值增加 1（指向下一个字符）。
  2. **`\*`**：这是解引用运算符，它的作用是：
	 - 获取 `str++` 返回的地址所指向的字符。
- 因此，`*str++` 的执行顺序是：
  1. 返回 `str` 的当前值（当前地址）。
  2. 将 `str` 的值增加 1（指向下一个字符）。
  3. 解引用 `str` 的当前值（即步骤 1 返回的地址），获取字符。

*/

