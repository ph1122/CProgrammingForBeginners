#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define eleType int

typedef struct TreeNode {
	eleType val;
	struct TreeNode* left;
	struct TreeNode* right;
}TreeNode;

typedef struct BinarySearchTree {
	TreeNode* root;
}BinarySearchTree;

void BSTCreate(BinarySearchTree* t) {
	t->root = NULL;
}

void BSTRemove(BinarySearchTree* t, eleType value);
void BSTDestroy(BinarySearchTree* t) {
	while (t->root) {
		BSTRemove(t, t->root->val);
	}
}

TreeNode* insertNode(TreeNode* node, eleType value) {
	if (node == NULL) {
		TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
		temp->val = value;
		temp->left = NULL;
		temp->right = NULL;
		return temp;
	}

	if (value < node->val) {
		node->left = insertNode(node->left, value);
	}
	else if (value > node->val) {
		node->right = insertNode(node->right, value);
	}
	else {
		return node;
	}

	return node;
}

void BSTInsert(BinarySearchTree* t, eleType value) {
	t->root = insertNode(t->root, value);
}

TreeNode* removeNode(TreeNode* node, eleType value) {
	if (node == NULL) {
		return NULL;
	}
	
	if (value < node->val) {
		node->left = removeNode(node->left, value);
	}
	else if (value > node->val) {
		node->right = removeNode(node->right, value);
	}
	else {
		if (node->left == NULL && node->right == NULL) {
			free(node);
			node = NULL;
			return NULL;
		}
		if (node->left == NULL) {
			TreeNode* tempNode = node->right;
			free(node);
			node = tempNode;
			return node;
		}
		if (node->right == NULL) {
			TreeNode* tempNode = node->left;
			free(node);
			node = tempNode;
			return node;
		}
		TreeNode* replaceNode = node->right;
		while (replaceNode->left) {
			replaceNode = replaceNode->left;
		}
		node->val = replaceNode->val;
		node->right = removeNode(node->right, replaceNode->val);
	}
	return node;
}

TreeNode* BSTSearch(BinarySearchTree* t, eleType value);
void BSTRemove(BinarySearchTree* t, eleType value) {
	if (BSTSearch(t, value) == NULL) {  // 先检查是否存在
		printf("值 %d 未找到，删除失败！\n", value);
		return;
	}
	t->root = removeNode(t->root, value);  // 存在则执行删除
}

TreeNode* searchNode(TreeNode* node, eleType value) {
	if (node == NULL) {
		return NULL;
	}

	if (value < node->val) {
		return searchNode(node->left, value);
	}
	else if (value > node->val) {
		return searchNode(node->right, value);
	}
	else {
		return node;
	}
}

TreeNode* BSTSearch(BinarySearchTree* t, eleType value) {
	return searchNode(t->root, value);
}

void inorderTraversal(TreeNode* node) {
	if (node) {
		inorderTraversal(node->left);
		printf("%d ", node->val);
		inorderTraversal(node->right);
	}
}

void BSTInorderTraversal(BinarySearchTree* t) {
	inorderTraversal(t->root);
	printf("\n");
}

int main() {
	BinarySearchTree bst;
	BSTCreate(&bst);
	// 插入
	BSTInsert(&bst, 50);
	BSTInsert(&bst, 10);
	BSTInsert(&bst, 40);
	BSTInsert(&bst, 20);
	BSTInsert(&bst, 80);
	BSTInsert(&bst, 60);
	BSTInsert(&bst, 90);
	// 中序遍历
	BSTInorderTraversal(&bst);// 10 20 40 50 60 80 90

	// 删除
	BSTRemove(&bst, 70);
	BSTInorderTraversal(&bst);// 10 20 40 50 60 80 90

	BSTRemove(&bst, 60);
	BSTInorderTraversal(&bst);// 10 20 40 50 80 90

	// 查询
	BSTInsert(&bst, 60);
	BSTInsert(&bst, 70);
	TreeNode* temp = BSTSearch(&bst, 60);
	inorderTraversal(temp); // 60 70
	printf("\n");
	temp = BSTSearch(&bst, 50);
	inorderTraversal(temp);// 10 20 40 50 60 70 80 90
	printf("\n");
	temp = BSTSearch(&bst, 80);
	inorderTraversal(temp); // 60 70 80 90
	printf("\n");

	BSTDestroy(&bst);

	return 0;
}

/*
		   50
	10            80
	   40     60      90
	 20         70
*/
