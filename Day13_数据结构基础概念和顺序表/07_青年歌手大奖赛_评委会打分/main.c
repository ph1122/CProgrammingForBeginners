/*
Problem Description
青年歌手大奖赛中，评委会给参赛选手打分。选手得分规则为去掉一个最高分和一个最低分，然后计算平均得分，请编程输出某选手的得分。


Input
输入数据有多组，每组占一行，每行的第一个数是n(2<n<=100)，表示评委的人数，然后是n个评委的打分。


Output
对于每组输入数据，输出选手的得分，结果保留2位小数，每组输出占一行。


Sample Input
3 99 98 97
4 100 99 98 97


Sample Output
98.00
98.50
https://acm.hdu.edu.cn/showproblem.php?pid=2014
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

float calculateAverage(int nums[], int size) {
	int max = nums[0];
	int min = nums[0];
	int sum = 0;
	for (int i = 0; i < size; ++i) {
		sum += nums[i];
		if (max < nums[i]) {
			max = nums[i];
		}
		if (min > nums[i])
		{
			min = nums[i];
		}
	}
	sum -= (max + min);
	return (float)sum / (size - 2);
}
int main() {
	int numsSize;
	while (scanf("%d", &numsSize) != EOF) {
		int source[100];
		for (int i = 0; i < numsSize; ++i) {
			scanf("%d", &source[i]);
		}
		
		printf("%.2f\n", calculateAverage(source, numsSize));
	}
	return 0;
}