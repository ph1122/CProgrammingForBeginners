#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
/*
strcpy ��Դ�ַ��������ݸ��Ƶ�Ŀ���ַ����С�

���Ḳ��Ŀ���ַ�����ԭ�����ݣ�����ĩβ����ַ��������� \0��
*/
int main() {
	char str1[5] = {'a', 'b', 'c', '\0'};
	char str2[10] = "abcef";
	char* str3 =    "abcefg";

	// 1����������
	strcpy(str2, str3);
	printf("%s\n", str2); // abcefg
	printf("%s\n", str3); // abcefg

	// 2�����Ȳ��������
	// strcpy(str1, str3);   ��һ���ַ����ĳ��ȱ�����ڵڶ����ַ����ĳ���

	 // 3��...
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

	//strcpy �ὫԴ�ַ��������ݣ����� \0�����Ƶ�Ŀ���ַ����У�����Ŀ���ַ�����ԭ�����ݡ�

	//	Ŀ���ַ�����δ�����ǵĲ��֣��� \0 ֮��Ĳ��֣����ֲ��䡣
	return 0;
}