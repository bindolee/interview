// findAllelementsonNthlevel.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>
/* 
find and print all elements on Nth level from the given binary search tree on left to right order

		3
	   / \
	  1   4

print level 2... which are 1 and 4. 
*/

struct node {
	int data;
	struct node* left;
	struct node* right;
};

typedef struct node Tree;

Tree* newNode(int data) {
	Tree *root = (Tree*) malloc(sizeof(Tree));
	root->data = data;
	root->left = NULL;
	root->right = NULL;
	return root;
}

Tree* Insert(Tree* root, int data) {
	if (root == NULL) {
		root = newNode(data);
		return root;
	}

	if (root->data < data) // goes to right chhild
		root->right = Insert(root->right, data);
	else // node goes to left child
		root->left = Insert(root->left, data);

	return root;
}

// Root level is level 1.
void printNthLevel(Tree* root, int level) {
	if (root == NULL)
		return;

	if (level -1 == 0)
		printf(" %d ", root->data);
	else {
		printNthLevel(root->left, level-1);
		printNthLevel(root->right, level-1);
	}
}

int main()
{
	Tree * bTree;
	bTree = newNode(5);
	bTree = Insert(bTree, 3);
	bTree = Insert(bTree, 4);
	bTree = Insert(bTree, 8);
	bTree = Insert(bTree, 6);
	bTree = Insert(bTree, 11);
	bTree = Insert(bTree, 2);
	bTree = Insert(bTree, 1);
	bTree = Insert(bTree, 7);
	bTree = Insert(bTree, 14);
	bTree = Insert(bTree, 0);

	int level = 0;
	for (int i = 0; i < 4; i++) {
		printf("\n\nEnter which level you want to print?\n");
		scanf_s("%d", &level);
		printf("\nPrinting %dth level:\n", level);
		printf("\nData: ");
		printNthLevel(bTree, level);
	}
    return 0;
}

