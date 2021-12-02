#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree
 * Return: the size or 0 if tree is null
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	int counter;

	if (tree == NULL)
		return (0);

	counter = tree_height(tree);

	return ((size_t)counter);
}

/**
 * tree_height - count node tree height
 * @node: node to measure
 * Return: height
 */

int tree_height(const binary_tree_t *node)
{
	int lDepth, rDepth;

	if (node == NULL)
		return (-1);

	lDepth = tree_height(node->left);
	rDepth = tree_height(node->right);

	if (lDepth > rDepth)
		return (lDepth + 1);
	else
		return (rDepth + 1);
}
