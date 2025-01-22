#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int* element;
	size_t size;
	size_t capacity;
}SeqList;

// 顺序表的初始化
void SeqListInit(SeqList* list, int capacity)
{
	list->element = (int*)malloc(sizeof(int) * capacity);
	list->size = 0;
	list->capacity = capacity;
}

// 顺序表的销毁
void SeqListDestory(SeqList* list){
	if (list->element != NULL) {
		free(list->element);
		list->element = NULL;
	}
}

// 顺序表的插入
void SeqListInsert(SeqList* list, int index, int element) {
	if (list->element == NULL) {
		printf("未初始化");
		return;
	}
	if (index < 0 || index > list->size) {
		printf("Invalid index\n");
		return;
	}
	if (list->size >= list->capacity) {
		int* newElement = (int*)realloc(list->element, sizeof(int) * 2 * list->capacity);
		if (newElement == NULL) {
			printf("Failed to allocate memory\n");
			return;
		}
		list->element = newElement;
		list->capacity *= 2;
	}
	for (int i = list->size; i > index; --i) {
		list->element[i] = list->element[i - 1];
	}
	list->element[index] = element;
	++(list->size);
}

// 顺序表的删除
void SeqListDelte(SeqList* list, int index) {
	if (index < 0 || index >= list->size) {
		printf("Invalid index\n");
		return;
	}
	for (int i = index; i < list->size; ++i) {
		list->element[i] = list->element[i + 1];
	}
	list->size--;
}

// 顺序表的查找
int SeqListFind(SeqList* list, int data) {
	for (int i = 0; i < list->size; ++i) {
		if (data == list->element[i]) {
			return i;
		}
	}
	return -1;
}

// 顺序表的索引
int SeqListIndex(SeqList* list, int index) {
	if (index < 0 || index >= list->size) {
		printf("Invalid index\n");
		return -1;
	}
	return list->element[index];
}

// 顺序表的修改
void SeqListSet(SeqList* list, int index, int element) {
	if (index < 0 || index > list->size) {
		printf("Invalid index\n");
		return;
	}
	list->element[index] = element;
	return;
}

// 顺序表的输出
void SeqListPrint(SeqList* list) {
	for (int i = 0;i < list->size; ++ i) {
		printf("index = %d, element = %d\n", i, list->element[i]);
	}
}

int main()
{
	SeqList list;
	SeqListInit(&list, 5);
	SeqListInsert(&list, 1, 41);
	SeqListInsert(&list, 0, 21);
	for (int i = 0; i < 7; ++i) {
		SeqListInsert(&list, i, i * 10);
	}
	SeqListDelte(&list, 4);
	SeqListPrint(&list);

	printf("%d\n", SeqListFind(&list, 4)); // -1
	printf("%d\n", SeqListFind(&list, 21));// 6
	printf("%d\n", SeqListIndex(&list, 2));// 20
	printf("%d\n", SeqListIndex(&list, 7));// Invalid index -1

	SeqListSet(&list, 9, 2); // Invalid index
	SeqListSet(&list, 5, 2);
	SeqListPrint(&list);
	printf("Current capacity: %zu\n", list.capacity);

	SeqListDestory(&list);
	return 0;
}

