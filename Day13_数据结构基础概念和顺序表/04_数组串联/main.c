#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
/*
给你一个长度为 n 的整数数组 nums 。请你构建一个长度为 2n 的答案数组 ans ，数组下标 从 0 开始计数 ，对于所有 0 <= i < n 的 i ，满足下述所有要求：

ans[i] == nums[i]
ans[i + n] == nums[i]
具体而言，ans 由两个 nums 数组 串联 形成。

返回数组 ans 。

示例 1：

输入：nums = [1,2,1]
输出：[1,2,1,1,2,1]
解释：数组 ans 按下述方式形成：
- ans = [nums[0],nums[1],nums[2],nums[0],nums[1],nums[2]]
- ans = [1,2,1,1,2,1]
示例 2：

输入：nums = [1,3,2,1]
输出：[1,3,2,1,1,3,2,1]
解释：数组 ans 按下述方式形成：
- ans = [nums[0],nums[1],nums[2],nums[3],nums[0],nums[1],nums[2],nums[3]]
- ans = [1,3,2,1,1,3,2,1]
*/
int* getConcatenation(int* nums, int numSize, int* returnSize) {
	int* ans = (int*)malloc(sizeof(int) * numSize * 2);
	*returnSize = numSize * 2;
	for (int i = 0; i < numSize; ++i) {
		ans[i] = nums[i];
		ans[i + numSize] = nums[i];
	}
	return ans;
}
int main() {
	int numsSize;
	while (scanf("%d", &numsSize) != EOF) {

		int nums[1000];
		for (int i = 0; i < numsSize; ++i) {
			scanf("%d", &nums[i]);
		}
		//int nums[3] = { 1, 4, 7 };
		printf("%zu %zu\n", sizeof(nums), sizeof(int));// 12 4
		for (int i = 0; i < numsSize; ++i) {
			printf("%d ", nums[i]);
		}
		printf("\n");
		int ansSize;
		int* ret = getConcatenation(nums, numsSize, &ansSize);
		for (int i = 0; i < ansSize; ++i) {
			printf("%d ", ret[i]);
		}
		printf("\n");
	}
	
	return 0;
}