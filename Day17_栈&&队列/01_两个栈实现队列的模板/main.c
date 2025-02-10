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

void StackCreate(Stack* s) {
	s->element = (eleType*)malloc(sizeof(eleType) * 8);
	s->size = 0;
	s->capacity = 8;
}

void StackDestroy(Stack* s) {
	free(s->element);
	s->element = NULL;
	s->size = 0;
	s->capacity = 0;
}

bool StackResize(Stack* s) {
	eleType* new = (eleType*)realloc(s->element, sizeof(eleType) * s->capacity * 2);
	if (!new) {
		return false;
	}
	s->element = new;
	s->capacity *= 2;
	return true;
}

void StackPush(Stack* s, eleType value) {
	if (s->size == s->capacity) {
		if (!StackResize(s)) {
			return;
		}
	}

	s->element[s->size++] = value;
	return;
}

bool StackPop(Stack* s, eleType* value) {
	if (s->size == 0) {
		return false;
	}
	*value = s->element[--s->size];
	return true;
}

bool StackTop(Stack* s, eleType* value) {
	if (s->size == 0) {
		return false;
	}
	*value = s->element[s->size - 1];
	return true;
}

int StackGetSize(Stack* s) {
	return s->size;
}

typedef struct {
	Stack s1;
	Stack s2;
}MyQueue;

MyQueue* myQueueCreate() {
	MyQueue* obj = (MyQueue*)malloc(sizeof(MyQueue));
	StackCreate(&obj->s1);
	StackCreate(&obj->s2);
	return obj;
}

void myQueuePush(MyQueue* obj, int x) {
	StackPush(&obj->s1, x);
}

void myQueuePop(MyQueue* obj, eleType* value) {
	if (StackGetSize(&obj->s2) == 0) {
		while (StackGetSize(&obj->s1)) {
			eleType temp;
			StackPop(&obj->s1, &temp);
			StackPush(&obj->s2, temp);
		}
	}
	StackPop(&obj->s2, value);
}

void myQueuePeek(MyQueue* obj, eleType* value) {
	if (StackGetSize(&obj->s2) == 0) {
		while (StackGetSize(&obj->s1)) {
			eleType temp;
			StackPop(&obj->s1, &temp);
			StackPush(&obj->s2, temp);
		}
	}
	StackTop(&obj->s2, value);
}

int myQueueEmpty(MyQueue* obj) {
	return StackGetSize(&obj->s1) + StackGetSize(&obj->s2) == 0;
}

void myQueueFree(MyQueue* obj) {
	StackDestroy(&obj->s1);
	StackDestroy(&obj->s2);
	free(obj);
}

int main() {
	MyQueue* q = myQueueCreate();
	myQueuePush(q, 1);
	myQueuePush(q, 2);
	myQueuePush(q, 3);
	myQueuePush(q, 4);

	int val;
	while (!myQueueEmpty(q)) {
		myQueuePop(q, &val);
		printf("%d\n", val);
	}

	myQueueFree(q);
}
