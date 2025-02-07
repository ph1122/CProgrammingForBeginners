#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define eleType int

typedef struct {
    eleType* element;
    int front;
    int rear;
    size_t capacity;
} Queue;

// 初始化队列
void QueueCreate(Queue* q) {
    q->element = (eleType*)malloc(sizeof(eleType) * 8);
    q->front = 0;
    q->rear = 0;
    q->capacity = 8;
}

// 销毁队列
void QueueDestroy(Queue* q) {
    free(q->element);
    q->element = NULL;
    q->front = 0;
    q->rear = 0;
    q->capacity = 0;
}

// 扩容队列
void QueueResize(Queue* q) {
    eleType* newelement = (eleType*)realloc(q->element, sizeof(eleType) * q->capacity * 2);
    if (newelement == NULL) {
        printf("内存分配失败！\n");
        exit(1);
    }
    q->element = newelement;
    q->capacity *= 2;
}

// 入队操作
void QueuePush(Queue* q, eleType element) {
    if (q->rear == q->capacity) {
        QueueResize(q);
    }
    q->element[q->rear++] = element;
}

// 出队操作
int QueuePop(Queue* q, eleType* element) {
    if (q->rear == q->front) {
        printf("队列无数据1\n");
        return 0;
    }
    *element = q->element[q->front++];
    return 1;
}

// 获取队头元素
int QueueFront(Queue* q, eleType* element) {
    if (q->rear == q->front) {
        printf("队列无数据2\n");
        return 0;
    }
    *element = q->element[q->front];
    return 1;
}

// 获取队列大小
size_t QueueSize(Queue* q) {
    return q->rear - q->front;
}

int main() {
    Queue q;
    eleType value;

    QueueCreate(&q);
    QueuePush(&q, 10);
    QueuePush(&q, 20);
    QueuePush(&q, 30);

    printf("队列大小: %zu\n", QueueSize(&q));

    if (QueueFront(&q, &value)) {
        printf("队头元素: %d\n", value);
    }

    while (QueuePop(&q, &value)) {
        printf("出队元素: %d\n", value);
    }

    printf("队列大小: %zu\n", QueueSize(&q));
    QueueDestroy(&q);
    return 0;
}
