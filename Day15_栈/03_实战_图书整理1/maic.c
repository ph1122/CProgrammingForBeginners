/*
https://leetcode.cn/problems/cong-wei-dao-tou-da-yin-lian-biao-lcof/
书店店员有一张链表形式的书单，每个节点代表一本书，节点中的值表示书的编号。
为更方便整理书架，店员需要将书单倒过来排列，就可以从最后一本书开始整理，逐一将书放回到书架上。
请倒序返回这个书单链表。

示例 1：

输入：head = [3,6,4,1]

输出：[1,4,6,3]


提示：

0 <= 链表长度 <= 10000
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 /**
  * Note: The returned array must be malloced, assume caller calls free().
  */
int stack[10001];
int top;
int* reverseBookList(struct ListNode* head, int* returnSize) {
    top = 0;
    struct ListNode* temp = head;
    while (head != NULL)
    {
        stack[top++] = head->val;
        head = head->next;
    }
    *returnSize = 0;
    int* ret = (int*)malloc(sizeof(int) * top);
    while (top--) {
        ret[(*returnSize)++] = stack[top];
    }
    return ret;
}