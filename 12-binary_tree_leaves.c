#include "binary_trees.h"

/**
 * binary_tree_leaves - counts the leaves in a binary tree
 * @tree: pointer to the tree root node
 * Return: 0 if tree is null or the count
 */

size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t lcount, rcount;

	if (tree == NULL)
		return (0);

	lcount = binary_tree_leaves(tree->left);
	rcount = binary_tree_leaves(tree->right);

	if (tree->left == NULL && tree->right == NULL)
		return (1);

	return (lcount + rcount);
}
