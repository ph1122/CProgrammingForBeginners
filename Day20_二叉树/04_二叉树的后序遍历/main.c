/*
https://leetcode.cn/problems/binary-tree-postorder-traversal/
给你一棵二叉树的根节点 root ，返回其节点值的 后序遍历 。



示例 1：

输入：root = [1,null,2,3]

输出：[3,2,1]

解释：



示例 2：

输入：root = [1,2,3,4,5,null,8,null,null,6,7,9]

输出：[4,6,7,5,2,9,8,3,1]

解释：



示例 3：

输入：root = []

输出：[]

示例 4：

输入：root = [1]

输出：[1]



提示：

树中节点的数目在范围 [0, 100] 内
-100 <= Node.val <= 100


进阶：递归算法很简单，你可以通过迭代算法完成吗？
*/


// 递归算法
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
void postorder(struct TreeNode* node, int* ret, int* returnSize) {
    if (node == NULL) {
        return;
    }

    postorder(node->left, ret, returnSize);
    postorder(node->right, ret, returnSize);
    ret[(*returnSize)++] = node->val;
}

int* postorderTraversal(struct TreeNode* root, int* returnSize) {
    *returnSize = 0;
    if (root == NULL) {
        return NULL;
    }
    int* ret = (int*)malloc(sizeof(int) * 100);
    postorder(root, ret, returnSize);
    return ret;
}

// 迭代算法

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
int* postorderTraversal(struct TreeNode* root, int* returnSize) {
    *returnSize = 0;
    if (root == NULL) {
        return NULL;
    }
    int* ret = (int*)malloc(sizeof(int) * 100);
    struct TreeNode** stack = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * 100);
    int top = -1;
    int size = 0;
    struct TreeNode* current = root;
    struct TreeNode* lastVisited = NULL;
    while (current != NULL || top != -1) {
        while (current) {
            stack[++top] = current;
            current = current->left;
        }
        struct TreeNode* peekNode = stack[top];
        // 如果当前节点的右子树为空，或者右子树的根节点就是 lastVisited，
        // 那么我们可以确定右子树已经访问完毕，可以安全地访问当前节点（即根节点）。
        if (peekNode->right == NULL || lastVisited == peekNode->right) {
            current = NULL;
            ret[size++] = peekNode->val;
            lastVisited = peekNode;
            top--;
        }
        else
        {
            current = peekNode->right;
        }
    }
    free(stack);
    stack = NULL;
    *returnSize = size;
    return ret;
}