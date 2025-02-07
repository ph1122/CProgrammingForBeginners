/*
https://leetcode.cn/problems/maximum-nesting-depth-of-the-parentheses/description/
给定 有效括号字符串 s，返回 s 的 嵌套深度。嵌套深度是嵌套括号的 最大 数量。



示例 1：

输入：s = "(1+(2*3)+((8)/4))+1"

输出：3

解释：数字 8 在嵌套的 3 层括号中。

示例 2：

输入：s = "(1)+((2))+(((3)))"

输出：3

解释：数字 3 在嵌套的 3 层括号中。

示例 3：

输入：s = "()(())((()()))"

输出：3



提示：

1 <= s.length <= 100
s 由数字 0-9 和字符 '+'、'-'、'*'、'/'、'('、')' 组成
题目数据保证括号字符串 s 是 有效的括号字符串
*/

int maxDepth(char* s) {
    char stack[100];
    int top = 0;
    while (*s != '\0') {
        if (*s == '(' || *s == ')') {
            stack[top++] = *s;
        }
        s++;
    }
    int num, maxnum;
    maxnum = 0;
    num = 0;
    while (top--) {
        if (stack[top] == ')') {
            num++;
        }
        if (stack[top] == '(') {
            num--;
        }
        if (num > maxnum) {
            maxnum = num;
        }
    }
    return maxnum;
}