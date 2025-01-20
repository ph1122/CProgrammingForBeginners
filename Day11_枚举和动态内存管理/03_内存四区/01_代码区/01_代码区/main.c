#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

// 代码区、全局区、栈区、堆区

// 代码区的特点：只读、共享

void PrintMeg() {
	printf("Hello World!\n");
}

int main() {
	PrintMeg();
	while (1) {

	}
	return 0;
}