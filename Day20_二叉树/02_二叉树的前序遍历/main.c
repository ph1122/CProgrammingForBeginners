/*
https://leetcode.cn/problems/binary-tree-preorder-traversal/description/

给你二叉树的根节点 root ，返回它节点值的 前序 遍历。



示例 1：

输入：root = [1,null,2,3]

输出：[1,2,3]

解释：



示例 2：

输入：root = [1,2,3,4,5,null,8,null,null,6,7,9]

输出：[1,2,4,5,6,7,3,8,9]

解释：



示例 3：

输入：root = []

输出：[]

示例 4：

输入：root = [1]

输出：[1]



提示：

树中节点数目在范围 [0, 100] 内
-100 <= Node.val <= 100


进阶：递归算法很简单，你可以通过迭代算法完成吗？
*/

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

void preorder(struct TreeNode* node, int* ret, int* returnSize) {
    if (node == NULL) {
        return;
    }
    ret[(*returnSize)++] = node->val;
    preorder(node->left, ret, returnSize);
    preorder(node->right, ret, returnSize);
}

int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    int* ret = (int*)malloc(sizeof(int) * 100);
    *returnSize = 0;
    preorder(root, ret, returnSize);
    return ret;
}


// 迭代解法

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
int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    if (root == NULL) {
        *returnSize = 0;
        return NULL;
    }
    
    // 使用数组模拟栈
    struct TreeNode** stack = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * 100);
    int top = 0; // 栈顶指针
    int* ret = (int*)malloc(sizeof(int) * 100);
    int size = 0; // 结果数组的大小
    
    stack[top++] = root; // 根节点入栈
    while (top > 0) {
        struct TreeNode* node = stack[--top]; // 弹出栈顶节点
        ret[size++] = node->val; // 访问根节点
        // 右子树先入栈（因为栈是后进先出，左子树需要先访问）
        if (node->right) stack[top++] = node->right;
        if (node->left) stack[top++] = node->left;
    }
    
    *returnSize = size;
    free(stack); // 释放栈空间
    return ret;
}