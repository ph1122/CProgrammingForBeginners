/*
Problem Description
给你n个整数，求他们中所有奇数的乘积。


Input
输入数据包含多个测试实例，每个测试实例占一行，每行的第一个数为n，表示本组数据一共有n个，接着是n个整数，你可以假设每组数据必定至少存在一个奇数。


Output
输出每组数中的所有奇数的乘积，对于测试实例，输出一行。


Sample Input
3 1 2 3
4 2 3 4 5


Sample Output
3
15
https://acm.hdu.edu.cn/showproblem.php?pid=2006
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int mulnums(int* nums, int size) {
	int ret = 1;
	for (int i = 0; i < size; ++i) {
		if (nums[i] % 2) {
			ret *= nums[i];
		}
	}
	return ret;
}
int main() {
	int numsSize;
	int nums[1000];

	while (scanf("%d", &numsSize) != EOF) {
		int mul = 1;

		for (int i = 0; i < numsSize; ++i) {
			scanf("%d", &nums[i]);
			if (nums[i] % 2) {
				mul *= nums[i];
			}
		}
		//int mul = mulnums(nums, numsSize);
		printf("%d\n", mul);
	}
	return 0;
}