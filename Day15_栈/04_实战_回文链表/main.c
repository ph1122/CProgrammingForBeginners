/*
https://leetcode.cn/problems/aMhZSa/description/
给定一个链表的 头节点 head ，请判断其是否为回文链表。

如果一个链表是回文，那么链表节点序列从前往后看和从后往前看是相同的。



示例 1：



输入: head = [1,2,3,3,2,1]
输出: true
示例 2：



输入: head = [1,2]
输出: false


提示：

链表 L 的长度范围为 [1, 105]
0 <= node.val <= 9


进阶：能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
int stack[100000];
int top;

bool isPalindrome(struct ListNode* head) {
    top = 0;
    struct ListNode* temp = head;
    while (temp) {
        stack[top++] = temp->val;
        temp = temp->next;
    }

    while (top--) {
        if (stack[top] != head->val) {
            return false;
        }
        head = head->next;
    }
    return true;
}