#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define eleType int

// 链表节点定义
typedef struct Node {
    eleType element;
    struct Node* next;  // 修正为 struct Node*
} Node;

// 队列结构定义
typedef struct {
    Node* front;   // 队头指针
    Node* rear;    // 队尾指针
    size_t size;   // 队列元素个数
} Queue;

// 初始化队列
void QueueCreate(Queue* q) {
    q->front = q->rear = NULL;
    q->size = 0;
}

// 销毁队列
void QueueDestroy(Queue* q) {
    while (q->front != NULL) {
        Node* temp = q->front;
        q->front = q->front->next;
        free(temp);
    }
    q->rear = NULL;
    q->size = 0;
}

// 入队操作
void QueuePush(Queue* q, eleType element) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        fprintf(stderr, "内存分配失败！\n");
        exit(EXIT_FAILURE);
    }
    newNode->element = element;
    newNode->next = NULL;

    if (q->size == 0) {
        q->front = q->rear = newNode;
    }
    else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
    q->size++;
}

// 出队操作
int QueuePop(Queue* q, eleType* element) {
    if (q->front == NULL) {
        return 0;  // 队列为空，返回失败
    }

    Node* temp = q->front;
    *element = temp->element;
    q->front = q->front->next;

    if (q->front == NULL) {
        q->rear = NULL;  // 队列已空，重置 rear
    }

    free(temp);
    q->size--;
    return 1;  // 返回成功
}

// 获取队头元素
int QueueFront(Queue* q, eleType* element) {
    if (q->front == NULL) {
        return 0;  // 队列为空，返回失败
    }
    *element = q->front->element;
    return 1;      // 返回成功
}

// 获取队列大小
size_t QueueSize(Queue* q) {
    return q->size;
}

// 测试代码
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