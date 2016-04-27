// mirror_double_and_misc_tree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>
/*
Mirror Tree:
Change a tree so that the roles of the left and right pointers are swapped at every node
So the tree...
4
/ \
2   5
/ \
1   3

is changed to...
4
/ \
5   2
/ \
3   1


Double tree:
For each node in a binary search tree, create a new duplicate node, and insert the duplicate as the left child of the original node. The resulting tree should still be a binary search tree.
So the tree...
2
/ \
1   3

is changed to...
2
/ \
2   3
/   /
1   3
/
1

*/

struct node {
	int data;
	struct node* left;
	struct node* right;
};

typedef struct node Tree;

Tree* newNode(int data) {
	Tree *root = (Tree*)malloc(sizeof(Tree));
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

	if (level - 1 == 0)
		printf(" %d ", root->data);
	else {
		printNthLevel(root->left, level - 1);
		printNthLevel(root->right, level - 1);
	}
}

void printTree(Tree* root) {
	if (root == NULL) 
		return;
	printTree(root->left);
	printf("%d ", root->data);
	printTree(root->right);
}

void mirrorTree(Tree* root) {
	if (root == NULL)
		return;
	else {
		Tree* temp;

		// do the subtree
		mirrorTree(root->left);
		mirrorTree(root->right);

		// swap the pointers in this node 
		temp = root->left;
		root->left = root->right;
		root->right = temp;
	}
}

void duplicateTree(Tree* root) {
	
	if (root == NULL)
		return;
	else {
		Tree * origLeft;

		// do the subtrees 
		duplicateTree(root->left);
		duplicateTree(root->right);

		// duplicate this node to its left
		origLeft = root->left;
		root->left = newNode(root->data);
		root->left->left = origLeft;
	}
}

int main()
{
	int level = 0;
	Tree * bTree;
	bTree = newNode(5);
	bTree = Insert(bTree, 2);
	bTree = Insert(bTree, 1);
	bTree = Insert(bTree, 3);
	bTree = Insert(bTree, 6);

	printf("\nBefore Mirror \n");
	printTree(bTree);
	printf("\nAfter Mirror \n");
	mirrorTree(bTree);
	printTree(bTree);


	for (int i = 0; i < 2; i++) {
		printf("\n\nEnter which level you want to print?\n");
		scanf_s("%d", &level);
		printf("\nPrinting %dth level:\n", level);
		printf("\nData: ");
		printNthLevel(bTree, level);
	}

	Tree * dup;
	dup = newNode(2);
	dup = Insert(dup, 3);
	dup = Insert(dup, 1);
	printf("\nBefore Duplicate \n");
	printTree(dup);
	printf("\nAfter Duplicate \n");
	duplicateTree(dup);
	printTree(dup);


	return 0;
}


