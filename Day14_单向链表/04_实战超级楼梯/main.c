/*
Problem Description
有一楼梯共M级，刚开始时你在第一级，若每次只能跨上一级或二级，要走上第M级，共有多少种走法？
 

Input
输入数据首先包含一个整数N，表示测试实例的个数，然后是N行数据，每行包含一个整数M（1<=M<=40）,表示楼梯的级数。
 

Output
对于每个测试实例，请输出不同走法的数量
 

Sample Input
2
2
3
 

Sample Output
1
2
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define eleType int

// 单向链表结点的定义
typedef struct ListNode {
	eleType data;
	struct ListNode* next;
}ListNode;

// 单向链表的定义
typedef struct LinkedList {
	struct ListNode* head;
	size_t size;
}LinkedList;

// 创建链表
void LinkedListCreate(LinkedList* list) {
	// 初始化链表头为 NULL
	list->head = NULL;
	list->size = 0;
}

// 销毁链表需要释放所有节点的内存，并将链表结构体的head置为NULL，size置为0。
void LinkedListDestroy(LinkedList* list) {
	// 防御性检查
	if (list == NULL) { // 检查传入的list指针是否为NULL
		printf("Error: List is NULL\n");
		return;
	}

	ListNode* current = list->head;
	while (current != NULL) {
		ListNode* temp = current;
		current = current->next;
		free(temp);
	}

	// 重置链表状态
	list->head = NULL; // 显式置空 head	明确链表状态，防止后续误用。
	list->size = 0;
}

// 添加函数说明：描述函数功能、参数及返回值。
/**
 * 在链表的指定位置插入新节点。
 * @param list 链表指针
 * @param index 插入位置（0-based）
 * @param value 插入的数据
 * @return 成功返回 true，失败返回 false
 */
void LinkedListInsert(LinkedList* list, int index, eleType data) {
	if (list == NULL) {
		printf("Error: List is NULL\n");
		return;
	}
	if (index < 0 || index > list->size) {
		printf("Invalid index\n");
		return;
	}

	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	if (newNode == NULL) {
		printf("Memory allocation failed\n");
		return;
	}
	newNode->data = data;
	newNode->next = NULL; // 显式初始化

	if (index == 0) {
		newNode->next = list->head;
		list->head = newNode;
	}
	else {
		ListNode* current = list->head;
		for (int i = 0; i < index - 1; ++i) {
			current = current->next;
		}
		newNode->next = current->next;
		current->next = newNode;
	}

	list->size++;
}

/**
 * @brief 删除链表中指定位置的节点
 *
 * @param list 要操作的链表指针。必须非空，否则函数直接返回。
 * @param index 要删除的节点索引（0-based）。有效范围为 [0, size-1]。
 *
 * @note 函数行为说明：
 * - 如果链表为空或索引越界，打印错误信息并返回。
 * - 删除节点后会更新链表大小 (`size`)，若链表变为空，头指针 (`head`) 会被显式置空。
 * - 若检测到链表结构异常（例如节点数与 `size` 字段不符），打印内部错误信息。
 * - 调用者需确保不再访问被删除节点的内存。
 */
void LinkedListRemove(LinkedList* list, int index) {
	if (list == NULL) {
		printf("Error: list is NULL\n");
		return;
	}
	if (index < 0 || index >= list->size) {
		printf("Invalid Index\n");
		return;
	}

	ListNode* toDelete = NULL;
	// 删除头节点
	if (index == 0) {
		toDelete = list->head;
		list->head = list->head->next;
	}
	// 删除中间或尾部节点
	else {
		ListNode* current = list->head;
		for (int j = 0; j < index - 1 && current != NULL; ++j) {
			current = current->next;
		}
		if (current == NULL || current->next == NULL) { // 防御性检查
			printf("Internal error: List structure corrupted\n");
			return;
		}
		toDelete = current->next;
		current->next = toDelete->next;
	}

	free(toDelete);
	list->size--;

	// 若链表为空，显式置空头指针
	if (list->size == 0) {
		list->head = NULL;
	}
	return;
}

/**
 * @brief 在链表中查找第一个匹配指定值的节点
 *
 * @param list 要搜索的链表指针。若为 NULL 则打印错误信息并返回 NULL。
 * @param value 要查找的目标值
 * @return ListNode*
 *         - 成功：返回第一个匹配节点的指针
 *         - 失败：返回 NULL（未找到值/链表为空/输入参数错误）
 */
ListNode* LinkedListFind(LinkedList* list, eleType value) {
	if (list == NULL) {
		printf("Error: list is NULL");
		return NULL;
	}
	ListNode* current = list->head;
	while (current != NULL) {
		if (current->data == value) {
			return current;
		}
		current = current->next;
	}
	return NULL;
}

/**
 * @brief 获取链表中指定索引位置的节点
 *
 * @param list 要操作的链表指针。若为 NULL 则触发错误。
 * @param index 要获取的节点索引（0-based）。有效范围为 [0, size-1]。
 * @return ListNode*
 *         - 成功：返回指向索引位置节点的指针。
 *         - 失败：返回 NULL（链表为空、索引越界或输入参数非法）。
 */
ListNode* LinkedListGet(LinkedList* list, int index) {
	if (list == NULL) {
		printf("Error: list is NULL!\n");
		return NULL;
	}
	if (index < 0 || index >= list->size) {
		printf("Error: Invalid index %d (valid range: [0, %zu])\n", index, list->size - 1);
		return NULL;
	}

	ListNode* current = list->head;
	for (int i = 0; i < index && current != NULL; ++i) {
		current = current->next;
	}
	// 防御性检查：链表实际长度与 size 字段不一致
	if (current == NULL) {
		printf("Error: List structure corrupted (expected size %zu, actual nodes fewer)\n", list->size);
		return NULL;
	}

	return current;
}

/**
 * @brief 更新链表中指定索引位置节点的值
 *
 * @param list 要操作的链表指针。若为 NULL 则触发错误。
 * @param index 要更新的节点索引（0-based）。有效范围为 [0, size-1]。
 * @param value 要设置的新值
 *
 * @note 错误类型：
 *       - 输入错误：链表指针为 NULL (`list == NULL`)
 *       - 参数错误：索引越界 (`index < 0 || index >= size`)
 *       - 内部错误：链表结构损坏（实际节点数与 size 字段不一致）
 * @code
 * // 典型调用示例：
 * LinkedListUpdate(&myList, 2, 100); // 将索引2的节点值改为100
 * @endcode
 */
void LinkedListUpdate(LinkedList* list, int index, eleType value) {
	if (list == NULL) {
		printf("Error: list is NULL!\n");
		return;
	}
	ListNode* Node = LinkedListGet(list, index);
	if (Node != NULL) {
		Node->data = value;
	}
	else {
		printf("Operation failed: Target node not found\n");  // 
	}
}

void LinkedListPrint(LinkedList* list) {
	ListNode* current = list->head;
	while (current) {
		printf("%d -> ", current->data);
		current = current->next;
	}
	printf("NULL\n");
}

int main() {
	LinkedList list;
	LinkedListCreate(&list);
	// 初始化前两个值（M=1和M=2）
	LinkedListInsert(&list, 0, 0); // M=1 走法数0
	LinkedListInsert(&list, 1, 1); // M=2 走法数1

	// 生成M=3到40的走法数
	for (int M = 3; M <= 40; M++) {
		int count = LinkedListGet(&list, M - 2)->data + LinkedListGet(&list, M - 3)->data;
		LinkedListInsert(&list, list.size, count); //  插入到链表末尾
	}

	int size;
	scanf("%d", &size);
	int num[999];
	for (int i = 0; i < size; i++)
	{
		scanf("%d", &num[i]);
	}
	for (int i = 0; i < size; i++)
	{
		ListNode* node = LinkedListGet(&list, num[i]);
		if (node != NULL) {
			printf("%d\n", node->data);
		}
		else {
			//printf("Invalid M: %d\n", num[i]);
		}
	}
	LinkedListDestroy(&list);

	return 0;
}