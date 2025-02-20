#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define eleType int

typedef struct Node {
    eleType data;
    struct Node* nextNode;
} Node;

typedef struct {
    Node* head;
    size_t size;
} Stack;

// 初始化栈
void StackInit(Stack* stk) {
    stk->head = NULL;
    stk->size = 0;
}

// 销毁栈
void StackDestroy(Stack* stk) {
    while (stk->head) {
        Node* temp = stk->head->nextNode;
        free(stk->head);
        stk->head = temp;
    }
    stk->head = NULL; // 显式置空
    stk->size = 0;
}

// 检查栈是否为空
bool StackIsEmpty(Stack* stk) {
    return stk->size == 0 || stk->head == NULL;
}

// 压栈
void StackPush(Stack* stk, eleType element) {
    Node* node = (Node*)malloc(sizeof(Node));
    if (!node) {
        fprintf(stderr, "Error: Memory allocation failed in StackPush.\n");
        exit(EXIT_FAILURE);
    }
    node->data = element;
    node->nextNode = stk->head;
    stk->head = node;
    stk->size++;
}

// 弹栈
bool StackPop(Stack* stk, eleType* value) {
    if (StackIsEmpty(stk)) {
        return false; // 栈空
    }
    *value = stk->head->data;
    Node* next = stk->head->nextNode;
    free(stk->head);
    stk->head = next;
    stk->size--;
    return true; // 成功弹出
}

// 获取栈顶元素
bool StackTop(Stack* stk, eleType* value) {
    if (StackIsEmpty(stk)) {
        return false; // 栈空
    }
    *value = stk->head->data;
    return true; // 成功获取
}

// 获取栈大小
int StackSize(Stack* stk) {
    return stk->size;
}

// 测试代码
int main() {
    Stack stk;
    StackInit(&stk);

    // 测试 push
    for (int i = 0; i < 10; i++) {
        StackPush(&stk, i);
        printf("Pushed: %d, Stack size: %d\n", i, StackSize(&stk));
    }

    // 测试 top
    eleType topValue;
    if (StackTop(&stk, &topValue)) {
        printf("Top element: %d\n", topValue);
    }
    else {
        printf("Stack is empty, cannot get top element.\n");
    }

    // 测试 pop
    while (!StackIsEmpty(&stk)) {
        eleType value;
        if (StackPop(&stk, &value)) {
            printf("Popped: %d, Stack size: %d\n", value, StackSize(&stk));
        }
    }

    // 测试空栈 pop
    if (!StackPop(&stk, &topValue)) {
        printf("Stack is empty, cannot pop.\n");
    }

    StackDestroy(&stk);
    return 0;
}