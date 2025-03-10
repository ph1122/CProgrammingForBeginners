#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define eleType int

typedef struct {
	eleType* element;
	int size;
	int capacity;
}Stack;

void StackCreate(Stack* stk) {
	stk->element = (eleType* )malloc(sizeof(eleType) * 8);
	stk->size = 0;
	stk->capacity = 8;
}

void StackDestroy(Stack* stk) {
	free(stk->element);
	stk->element = NULL;
	stk->size = 0;
	stk->capacity = 0;
}

void StackResize(Stack* stk) {
	eleType* newelement = (eleType* )realloc(stk->element, sizeof(eleType) * stk->capacity * 2);
	if (!newelement) {
		fprintf(stderr, "Memory allocation failed\n");
		exit(1);
	}
	stk->element = newelement;
	stk->capacity = stk->capacity * 2;
}

void StackPush(Stack* stk, eleType element) {
	if (stk->size == stk->capacity) {
		StackResize(stk);
	}
	stk->element[stk->size++] = element;
}

// 弹栈
bool StackPop(Stack* stk, eleType* value) {
	if (stk->size == 0) {
		return false; // 栈空
	}
	*value = stk->element[--stk->size];
	return true; // 成功弹出
}

eleType StackTop(Stack* stk) {
	if (stk->size == 0) {
		exit(1);
	}
	return stk->element[stk->size - 1];
}

int StackSize(Stack* stk) {
	return stk->size;
}

int main() {
	Stack stk;
	StackCreate(&stk);

	// 测试 push 和 pop
	for (int i = 0; i < 20; i++) {
		StackPush(&stk, i);
	}
	printf("StackTop is: %d\n", StackTop(&stk));
	printf("StackSize is: %d\n", StackSize(&stk));
	eleType value;
	while (StackPop(&stk, &value)) {
		printf("%d ", value);
	}
	printf("\n");
	printf("StackSize is: %d\n", StackSize(&stk));

	StackDestroy(&stk);
	return 0;
}