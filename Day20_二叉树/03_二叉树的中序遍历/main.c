/*
https://leetcode.cn/problems/binary-tree-inorder-traversal/description/
给定一个二叉树的根节点 root ，返回 它的 中序 遍历 。



示例 1：


输入：root = [1,null,2,3]
输出：[1,3,2]
示例 2：

输入：root = []
输出：[]
示例 3：

输入：root = [1]
输出：[1]


提示：

树中节点数目在范围 [0, 100] 内
-100 <= Node.val <= 100


进阶: 递归算法很简单，你可以通过迭代算法完成吗？
*/

// 递归解法
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 /**
  * Note: The returned array must be malloced, assume caller calls free().
  */

void inorder(struct TreeNode* node, int* ret, int* returnSize) {
    if (node == NULL) {
        return;
    }
    inorder(node->left, ret, returnSize);
    ret[(*returnSize)++] = node->val;
    inorder(node->right, ret, returnSize);
}
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int* ret = (int*)malloc(sizeof(int) * 100);
    *returnSize = 0;
    inorder(root, ret, returnSize);
    return ret;
}

// 递归解法
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 /**
  * Note: The returned array must be malloced, assume caller calls free().
  */
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    if (root == NULL) {
        *returnSize = 0;
        return NULL;
    }

    int* ret = (int*)malloc(sizeof(int) * 100);
    struct TreeNode** stack = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * 100);
    int top = -1;
    int size = 0;
    struct TreeNode* current = root;
    while (current != NULL || top != -1) {
        while (current != NULL) {
            stack[++top] = current;
            current = current->left;
        }
        current = stack[top--];
        ret[size++] = current->val;
        current = current->right;
    }
    free(stack);
    stack = NULL;
    *returnSize = size;
    return ret;
}
