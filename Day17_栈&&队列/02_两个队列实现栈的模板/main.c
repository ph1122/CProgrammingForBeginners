#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define eleType int

typedef struct {
	eleType* element;
	int front;
	int rear;
	int capacity;
}Queue;

Queue* QueueCreate() {
	Queue* obj = (Queue*)malloc(sizeof(Queue));
	if (!obj) {
		return NULL;
	}
	eleType* newelement = (eleType*)malloc(sizeof(eleType) * 8);
	if (!newelement) {
		free(obj);
		return NULL;
	}
	obj->element = newelement;
	obj->front = obj->rear = 0;
	obj->capacity = 8;
	return obj;
}

void QueueDestroy(Queue* q) {
	free(q->element);
	//free(q);
	q->front = q->rear = 0;
	q->capacity = 0;
}

bool QueueResize(Queue* q) {
	eleType* newelement = (eleType*)realloc(q->element, sizeof(eleType) * q->capacity * 2);
	if (!newelement) {
		printf("alloction fail!\n");
		return false;
	}

	q->element = newelement;
	q->capacity *= 2;
	return true;

}
bool QueuePush(Queue* q, eleType element) {
	if (q->rear == q->capacity) {
		if (!QueueResize(q)) {
			return false;
		}
	}
	q->element[q->rear++] = element;

	return true;
}

bool QueuePop(Queue* q, eleType* value) {
	if (q->front == q->rear) {
		printf("No element!\n");
		return false;
	}
	*value = q->element[q->front++];
	return true;
}

bool QueueTop(Queue* q, eleType* value) {
	if (q->front == q->rear) {
		printf("No element!\n");
		return false;
	}
	*value = q->element[q->front];
	return true;
}

int QueueGetSize(Queue* q) {
	
	return q->rear - q->front;
}

typedef struct {
	Queue q1;
	Queue q2;
}MyStack;

MyStack* myStackCreate() {
	MyStack* obj = (MyStack*)malloc(sizeof(MyStack));
	Queue* temp1 = QueueCreate();
	if (temp1 != NULL) {
		obj->q1 = *QueueCreate();
	}
	
	Queue* temp2 = QueueCreate();
	if (temp2 != NULL) {
		obj->q2 = *QueueCreate();
	}
	return obj;
}

void myStackDestroy(MyStack* obj) {
	QueueDestroy(&obj->q1);
	QueueDestroy(&obj->q2);
	free(obj);
	obj = NULL;
}

bool myStackPush(MyStack* obj, eleType element) {
	if (QueueGetSize(&obj->q2) != 0) {
		printf("q2 Not empty!\n");
		return false;
	}
	if (QueuePush(&obj->q1, element)) {
		return true;
	}
	return false;
}

void myStackPop(MyStack* obj, eleType* value) {
	if (QueueGetSize(&obj->q1) == 0) {
		printf("No number!\n");
		return;
	}
	while (QueueGetSize(&obj->q1) != 1) {
		eleType temp;
		QueuePop(&obj->q1, &temp);
		QueuePush(&obj->q2, temp);
	}
	QueuePop(&obj->q1, value);
	while (QueueGetSize(&obj->q2) != 0) {
		eleType temp;
		QueuePop(&obj->q2, &temp);
		QueuePush(&obj->q1, temp);
	}
}

void myStackTop(MyStack* obj, eleType* value) {
	if (QueueGetSize(&obj->q1) == 0) {
		printf("No Number!\n");
		return;
	}

	while (QueueGetSize(&obj->q1) != 1) {
		eleType temp;
		QueuePop(&obj->q1, &temp);
		printf("temp:%d\n", temp);
		printf("%d\n", QueueGetSize(&obj->q1));
		QueuePush(&obj->q2, temp);
	}

	QueuePop(&obj->q1, value);
	printf("value:%d\n", *value);
	QueuePush(&obj->q2, *value);
	while (QueueGetSize(&obj->q2) != 0) {
		eleType temp;
		QueuePop(&obj->q2, &temp);
		QueuePush(&obj->q1, temp);
	}
	printf("value:%d\n", *value);

}

bool myStackEmpty(MyStack* obj) {
	return QueueGetSize(&obj->q1) == 0;
}

int main() {
	MyStack* obj = myStackCreate();

	for (int i = 0; i < 5; ++i) {
		myStackPush(obj, i + 1);
		printf("Push is: %d\n", i + 1);
	}
	eleType temp;
	myStackTop(obj, &temp);
	while (!myStackEmpty(obj)) {
		myStackPop(obj, &temp);
		printf("Pop is : %d\n", temp);
	}
	myStackDestroy(obj);
	return 0;
}