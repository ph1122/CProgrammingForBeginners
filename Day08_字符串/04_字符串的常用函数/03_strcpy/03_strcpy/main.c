#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
/*
strcpy 将源字符串的内容复制到目标字符串中。

它会覆盖目标字符串的原有内容，并在末尾添加字符串结束符 \0。
*/
int main() {
	char str1[5] = {'a', 'b', 'c', '\0'};
	char str2[10] = "abcef";
	char* str3 =    "abcefg";

	// 1、正常拷贝
	strcpy(str2, str3);
	printf("%s\n", str2); // abcefg
	printf("%s\n", str3); // abcefg

	// 2、长度不够的情况
	// strcpy(str1, str3);   第一个字符串的长度必须大于第二个字符串的长度

	 // 3、...
	strcpy(str2, str1);
	printf("%s\n%s\n", str2, str1);// abc abc
	for (int i = 0; i < 6; ++i) {
		printf("(%c)", str2[i]);
	}
	// (a)(b)(c)()(f)(g)
	printf("\n");
	for (int i = 0; i < 10; i++) {
		printf("%d: %c (ASCII: %d)\n", i, str2[i], str2[i]);
	}
	/*
	0: a (ASCII: 97)
	1: b (ASCII: 98)
	2: c (ASCII: 99)
	3:  (ASCII: 0)
	4: f (ASCII: 102)
	5: g (ASCII: 103)
	6:  (ASCII: 0)
	7:  (ASCII: 0)
	8:  (ASCII: 0)
	9:  (ASCII: 0)
	*/

	//strcpy 会将源字符串的内容（包括 \0）复制到目标字符串中，覆盖目标字符串的原有内容。

	//	目标字符串中未被覆盖的部分（从 \0 之后的部分）保持不变。
	return 0;
}