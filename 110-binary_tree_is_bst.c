#include "binary_trees.h"

/**
 * binary_tree_is_bst - checks if a binary tree is a valid Binary Search Tree
 * @tree: pointer to the tree tree of the tree
 * Return: 1 if true or 0 otherwise
 */

int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (isValid((binary_tree_t *)tree));
}

/**
 * isValid - checks it bt is bst
 * @root: root node
 * Return: 1 or 0
 */

int isValid(binary_tree_t *root)
{
	int isvalid[] = {1};
	binary_tree_t *prev[] = {NULL};

	inorder(root, prev, isvalid);
	return (isvalid[0]);
}

/**
 * inorder - helper function for isValid
 * @root: pointer to node
 * @prev: array of prev pointers to nodes
 * @isvalid: array of numbers
 * Return: 1 or 0
 */

void inorder(binary_tree_t *root, binary_tree_t *prev[], int isvalid[])
{
	if (root != NULL)
	{
		inorder(root->left, prev, isvalid);

		if (prev[0] != NULL && prev[0]->n >= root->n)
		{
			isvalid[0] = 0;
			return;
		}
		prev[0] = root;
		inorder(root->right, prev, isvalid);
	}
}
