#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

#define eleType char

typedef struct TreeNode {
	eleType data;
	struct TreeNode* left;
	struct TreeNode* right;
}TreeNode;

typedef struct Tree {
	TreeNode* nodes;
	TreeNode* root;
	size_t nodeSize;
}Tree;

void TreeInit(Tree* t, int size) {
	TreeNode* newNode = (TreeNode* )malloc(sizeof(TreeNode) * size);
	if (!newNode) {
		return;
	}
	t->nodes = newNode;
	t->root = NULL;
	t->nodeSize = size;
}

void TreeDestroy(Tree* t) {
	free(t->nodes);
	t->nodes = NULL;
	t->root = NULL;
	t->nodeSize = 0;
}

TreeNode* TreeGetNode(Tree* t, int index) {
	return &t->nodes[index];
}

void visit(TreeNode* node) {
	printf("%c ", node->data);
}

TreeNode* CreateRecursively(Tree* t, eleType a[], int size, int nodeId, eleType nullNode) {
	if (nodeId >= size || a[nodeId] == nullNode) {
		return NULL;
	}
	TreeNode* newNode = TreeGetNode(t, nodeId);
	newNode->data = a[nodeId];
	newNode->left = CreateRecursively(t, a, size, nodeId * 2, nullNode);
	newNode->right = CreateRecursively(t, a, size, nodeId * 2 + 1, nullNode);
	return newNode;
}

void TreeCreate(Tree* t, eleType a[], int size, eleType nullNode) {
	t->root = CreateRecursively(t, a, size, 1, nullNode);
}

void preOrder(Tree* t, TreeNode* node) {
	if (node) {
		visit(node);
		preOrder(t, node->left);
		preOrder(t, node->right);
	}
}

void TreePreOrderTraversal(Tree* t) {
	preOrder(t, t->root);
}

void InOrder(Tree* t, TreeNode* node) {
	if (node) {
		InOrder(t, node->left);
		visit(node);
		InOrder(t, node->right);
	}
}

void TreeInOrderTraversal(Tree* t) {
	InOrder(t, t->root);
}

void PostOrder(Tree* t, TreeNode* node) {
	if (node) {
		PostOrder(t, node->left);
		PostOrder(t, node->right);
		visit(node);
	}
}

void TreePostOrderTraversal(Tree* t) {
	PostOrder(t, t->root);
}

int main()
{
	const char nullNpde = '-';
	char a[15] = {
		nullNpde, 'a', 'b', 'c', 'd',
		nullNpde, 'e', 'f', 'g', 'h',
		nullNpde, nullNpde, nullNpde, nullNpde, 'i'
	};
	/*
			a
		b		c
	  d       e     f
     g  h         i 
	
	*/
	Tree T;
	TreeInit(&T, 15);

	TreeCreate(&T, a, 15, nullNpde);
	TreePreOrderTraversal(&T); printf("\n");
	TreeInOrderTraversal(&T); printf("\n");
	TreePostOrderTraversal(&T); printf("\n");

	TreeDestroy(&T);
	return 0;
}


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define eleType char

typedef struct TreeNode {
    eleType data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

typedef struct Tree {
    TreeNode* root;
} Tree;

// 创建新节点（动态分配）
TreeNode* createNode(eleType value) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    if (!newNode) {
        fprintf(stderr, "内存分配失败！\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// 递归构建树（动态方式）
TreeNode* buildTree(eleType a[], int size, int* index, eleType nullNode) {
    if (*index >= size || a[*index] == nullNode) {
        (*index)++;
        return NULL;
    }
    TreeNode* root = createNode(a[*index]);
    (*index)++;
    root->left = buildTree(a, size, index, nullNode);
    root->right = buildTree(a, size, index, nullNode);
    return root;
}

// 初始化树（动态创建）
void TreeCreate(Tree* t, eleType a[], int size, eleType nullNode) {
    int index = 0; // 从数组起始位置开始
    t->root = buildTree(a, size, &index, nullNode);
}

// 遍历函数（与前序、中序、后序相同，略）

void TreeDestroy(TreeNode* root) {
    if (root) {
        TreeDestroy(root->left);
        TreeDestroy(root->right);
        free(root);
    }
}

int main() {
    const char nullNode = '-';
    // 按前序遍历序列化树，'-'表示空节点
    char a[] = {
        'a', 'b', 'd', 'g', '-', '-', 'h', '-', '-',
        '-', 'c', 'e', '-', '-', 'f', '-', 'i', '-', '-'
    };
    /*
        树结构：
            a
          /   \
         b     c
        /     / \
       d     e   f
      / \        \
     g   h        i
    */
    Tree T = {NULL};
    TreeCreate(&T, a, sizeof(a)/sizeof(a[0]), nullNode);

    printf("前序遍历: ");
    TreePreOrderTraversal(&T); // 实现与前文类似
    printf("\n");

    TreeDestroy(T.root);
    return 0;
}

/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define eleType char

typedef struct TreeNode {
    eleType data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

typedef struct Tree {
    TreeNode* root;
} Tree;

// 创建新节点（动态分配）
TreeNode* createNode(eleType value) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    if (!newNode) {
        fprintf(stderr, "内存分配失败！\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// 递归构建树（动态方式）
TreeNode* buildTree(eleType a[], int size, int* index, eleType nullNode) {
    if (*index >= size || a[*index] == nullNode) {
        (*index)++;
        return NULL;
    }
    TreeNode* root = createNode(a[*index]);
    (*index)++;
    root->left = buildTree(a, size, index, nullNode);
    root->right = buildTree(a, size, index, nullNode);
    return root;
}

// 初始化树（动态创建）
void TreeCreate(Tree* t, eleType a[], int size, eleType nullNode) {
    int index = 0; // 从数组起始位置开始
    t->root = buildTree(a, size, &index, nullNode);
}

// 遍历函数（与前序、中序、后序相同，略）

void TreeDestroy(TreeNode* root) {
    if (root) {
        TreeDestroy(root->left);
        TreeDestroy(root->right);
        free(root);
    }
}

int main() {
    const char nullNode = '-';
    // 按前序遍历序列化树，'-'表示空节点
    char a[] = {
        'a', 'b', 'd', 'g', '-', '-', 'h', '-', '-',
        '-', 'c', 'e', '-', '-', 'f', '-', 'i', '-', '-'
    };
    
        树结构：
            a
          /   \
         b     c
        /     / \
       d     e   f
      / \        \
     g   h        i
    
Tree T = { NULL };
TreeCreate(&T, a, sizeof(a) / sizeof(a[0]), nullNode);

printf("前序遍历: ");
TreePreOrderTraversal(&T); // 实现与前文类似
printf("\n");

TreeDestroy(T.root);
return 0;
}

*/