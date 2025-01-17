#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

// strcmp 是 C 语言中用于比较两个字符串的函数。它的功能是比较两个字符串的内容，并根据比较结果返回一个整数值
//返回值
//  返回值 <  0：str1 小于 str2（按字典顺序）。
//	返回值 == 0：str1 和 str2 相等。
//	返回值 >  0：str1 大于 str2（按字典顺序）。
// 
// str 代表字符串（string）。
// cmp 是 compare（比较）的缩写。
int main() {
    char str1[] = "apple";
    char str2[] = "banana";
    char str3[] = "apple";

    int result1 = strcmp(str1, str2); // "apple" vs "banana"
    int result2 = strcmp(str1, str3); // "apple" vs "apple"

    printf("Result1: %d\n", result1); // -1 输出负数（"apple" < "banana"）  "apple" 小于 "banana" 是因为 'a' < 'b'。'a'（97）和 'b'（98）。
    printf("Result2: %d\n", result2); // 0  输出 0（"apple" == "apple"）

	return 0;
}