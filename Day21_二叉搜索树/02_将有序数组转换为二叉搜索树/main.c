/*
https://leetcode.cn/problems/convert-sorted-array-to-binary-search-tree/description/
给你一个整数数组 nums ，其中元素已经按 升序 排列，请你将其转换为一棵 平衡 二叉搜索树。
平衡二叉树 是指该树所有节点的左右子树的高度相差不超过 1。


示例 1：


输入：nums = [-10,-3,0,5,9]
输出：[0,-3,9,-10,null,5]
解释：[0,-10,5,null,-3,null,9] 也将被视为正确答案：

示例 2：


输入：nums = [1,3]
输出：[3,1]
解释：[1,null,3] 和 [3,1] 都是高度平衡二叉搜索树。


提示：

1 <= nums.length <= 104
-104 <= nums[i] <= 104
nums 按 严格递增 顺序排列
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* sortArray(int* nums, int l, int r) {
	if (l > r) {
		return 0;
	}
	struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
	// 找到中间索引
	int mid = (l + r) / 2;
	root->val = nums[mid];
	// 递归构建左右子树
	root->left = sortArray(nums, l, mid - 1);
	root->right = sortArray(nums, mid + 1, r);
	return root;
}

struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
	return sortArray(nums, 0, numsSize - 1);
}

