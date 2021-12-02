
#include "binary_trees.h"

/**
 * binary_tree_delete - deletes an entire binary tree
 * @tree: pointer to the root node of the tree
 * Return: void
 */

void binary_tree_delete(binary_tree_t *tree)
{
	binary_tree_t *left = NULL, *right = NULL;

	if (tree != NULL)
	{
		left = tree->left;
		right = tree->right;
		free(tree);
		binary_tree_delete(left);
		binary_tree_delete(right);
	}
}
