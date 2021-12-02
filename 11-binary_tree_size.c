#include "binary_trees.h"

/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: pointer to the root node of the tree
 * Return: tree is NULL, the function will return 0
 */

size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t lcount, rcount;

	if (tree == NULL)
		return (0);

	lcount = binary_tree_size(tree->left);
	rcount = binary_tree_size(tree->right);

	return (lcount + rcount + 1);
}
