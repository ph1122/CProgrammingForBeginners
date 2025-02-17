#define _CRT_SECURE_NO_WARNINGS
// 定义宏以禁用某些编译器警告（如 VS 中的安全函数警告）
#include <stdio.h>
// 引入标准输入输出库，用于 printf 等函数
#include <stdlib.h>
// 引入标准库，用于 malloc、free 等内存管理函数
#define eleType char
// 定义元素类型为字符型（char）
#define MAX_NODES 100 // 假设最多有 100 个节点
// 定义树的最大节点数为 100

struct TreeNode;
// 声明 TreeNode 结构体，稍后定义
typedef struct ListNode {
    struct TreeNode* node;
    // 指向树节点的指针
    struct ListNode* nextNode;
    // 指向下一个链表节点的指针
} ListNode;
// 定义链表节点结构体，用于存储子节点列表

typedef struct TreeNode {
    eleType data;
    // 节点的数据（字符型）
    ListNode* childrenHead;
    // 指向子节点链表的头指针
} TreeNode;
// 定义树节点结构体

typedef struct Tree {
    TreeNode* nodes;
    // 指向所有节点的数组
    TreeNode* root;
    // 指向树的根节点
} Tree;
// 定义树结构体

void AddNodeChild(TreeNode* parent, TreeNode* child) {
    // 向父节点添加一个子节点
    ListNode* newList = (ListNode*)malloc(sizeof(ListNode));
    // 分配一个新的链表节点
    newList->nextNode = NULL;
    // 初始化新链表节点的 nextNode 为 NULL
    newList->node = child;
    // 将新链表节点指向子节点
    if (parent->childrenHead == NULL) {
        // 如果父节点没有子节点
        parent->childrenHead = newList;
        // 将新链表节点设置为子节点链表的头
    }
    else {
        // 如果父节点已经有子节点
        newList->nextNode = parent->childrenHead;
        // 将新链表节点的 nextNode 指向当前子节点链表的头
        parent->childrenHead = newList;
        // 更新子节点链表的头为新链表节点
    }
}

Tree* TreeCreator() {
    // 创建一棵新的树
    Tree* res = (Tree*)malloc(sizeof(Tree));
    // 分配树结构体的内存
    if (res == NULL) {
        // 如果分配失败
        return NULL;
        // 返回 NULL 表示创建失败
    }
    res->nodes = (TreeNode*)malloc(MAX_NODES * sizeof(TreeNode));
    // 分配存储所有节点的数组
    if (res->nodes == NULL) {
        // 如果分配失败
        free(res);
        // 释放之前分配的树结构体内存
        return NULL;
        // 返回 NULL 表示创建失败
    }
    for (int i = 0; i < MAX_NODES; i++) {
        // 初始化每个节点
        res->nodes[i].data = '\0';
        // 将节点数据初始化为空字符
        res->nodes[i].childrenHead = NULL;
        // 将子节点链表头初始化为 NULL
    }
    res->root = NULL;
    // 初始化根节点为 NULL
    return res;
    // 返回创建的树
}

void FreeListNode(ListNode* head) {
    // 递归释放链表节点的内存
    while (head != NULL) {
        // 当链表节点不为空时
        ListNode* tmp = head;
        // 保存当前链表节点
        head = head->nextNode;
        // 移动到下一个链表节点
        free(tmp);
        // 释放当前链表节点的内存
    }
}

void TreeDestory(Tree* t) {
    // 销毁树并释放所有内存
    if (t == NULL) return;
    // 如果树为空，直接返回
    for (int i = 0; i < MAX_NODES; i++) {
        // 遍历所有节点
        FreeListNode(t->nodes[i].childrenHead);
        // 释放每个节点的子节点链表
    }
    free(t->nodes);
    // 释放节点数组的内存
    free(t);
    // 释放树结构体的内存
}

TreeNode* TreeGetNode(Tree* t, int index) {
    // 获取指定索引的节点
    if (index < 0 || index >= MAX_NODES) {
        // 如果索引越界
        printf("节点索引越界！\n");
        // 打印错误信息
        exit(EXIT_FAILURE);
        // 终止程序
    }
    return &t->nodes[index];
    // 返回指定索引的节点地址
}

void TreeSetRoot(Tree* t, int id) {
    // 设置树的根节点
    t->root = TreeGetNode(t, id);
    // 将根节点设置为指定索引的节点
}

void TreeAddChild(Tree* t, int parentId, int childId) {
    // 向指定父节点添加子节点
    TreeNode* parentNode = TreeGetNode(t, parentId);
    // 获取父节点
    TreeNode* childNode = TreeGetNode(t, childId);
    // 获取子节点
    AddNodeChild(parentNode, childNode);
    // 调用函数将子节点添加到父节点的子节点链表中
}

void TreeAssignData(Tree* t, int id, eleType data) {
    // 为指定节点赋值
    TreeGetNode(t, id)->data = data;
    // 设置指定节点的数据
}

void TreePrint(Tree* t, TreeNode* node) {
    // 打印树结构
    if (node == NULL) {
        // 如果传入的节点为空
        node = t->root;
        // 将节点设置为根节点
    }
    printf("%c ", node->data);
    // 打印当前节点的数据
    ListNode* tmp = node->childrenHead;
    // 获取当前节点的子节点链表头
    while (tmp) {
        // 遍历子节点链表
        TreePrint(t, tmp->node);
        // 递归打印子节点
        tmp = tmp->nextNode;
        // 移动到下一个子节点
    }
}

int main() {
    // 主函数
    Tree* T = TreeCreator();
    // 创建一棵树
    if (T == NULL) {
        // 如果树创建失败
        printf("树创建失败！\n");
        // 打印错误信息
        return 1;
        // 返回错误码
    }
    TreeSetRoot(T, 0);
    // 设置根节点为索引 0 的节点
    TreeAssignData(T, 0, 'a');
    // 为索引 0 的节点赋值 'a'
    TreeAssignData(T, 1, 'b');
    // 为索引 1 的节点赋值 'b'
    TreeAssignData(T, 2, 'c');
    // 为索引 2 的节点赋值 'c'
    TreeAssignData(T, 3, 'd');
    // 为索引 3 的节点赋值 'd'
    TreeAssignData(T, 4, 'e');
    // 为索引 4 的节点赋值 'e'
    TreeAssignData(T, 5, 'f');
    // 为索引 5 的节点赋值 'f'
    TreeAssignData(T, 6, 'g');
    // 为索引 6 的节点赋值 'g'
    TreeAssignData(T, 7, 'h');
    // 为索引 7 的节点赋值 'h'
    TreeAssignData(T, 8, 'i');
    // 为索引 8 的节点赋值 'i'

    TreeAddChild(T, 0, 2);
    // 将索引 2 的节点作为索引 0 的子节点
    TreeAddChild(T, 0, 1);
    // 将索引 1 的节点作为索引 0 的子节点
    TreeAddChild(T, 1, 3);
    // 将索引 3 的节点作为索引 1 的子节点
    TreeAddChild(T, 2, 5);
    // 将索引 5 的节点作为索引 2 的子节点
    TreeAddChild(T, 2, 4);
    // 将索引 4 的节点作为索引 2 的子节点
    TreeAddChild(T, 3, 8);
    // 将索引 8 的节点作为索引 3 的子节点
    TreeAddChild(T, 3, 7);
    // 将索引 7 的节点作为索引 3 的子节点
    TreeAddChild(T, 3, 6);
    // 将索引 6 的节点作为索引 3 的子节点
    TreePrint(T, NULL); // 打印整棵树
    printf("\n");
    // 换行
    TreeDestory(T);
    // 销毁树并释放内存
    return 0;
    // 返回成功状态
}