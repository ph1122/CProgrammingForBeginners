/*
https://leetcode.cn/problems/number-of-segments-in-a-string/description/
统计字符串中的单词个数，这里的单词指的是连续的不是空格的字符。

请注意，你可以假定字符串里不包括任何不可打印的字符。

示例:

输入: "Hello, my name is John"
输出: 5
解释: 这里的单词是指连续的不是空格的字符，所以 "Hello," 算作 1 个单词。
*/

int countSegments(char* s) {
	bool preisBank = true;
	int len = strlen(s);
	int sum = 0;
	for (int i = 0; i < len + 1; ++i) {
		if (s[i] == ' ' || s[i] == '\0') {
			if (!preisBank) {
				sum++;
			}
			preisBank = true;
		}
		else {
			preisBank = false;
		}
	}
	return sum;
}