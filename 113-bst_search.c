#include "binary_trees.h"

/**
* bst_search - a function that searches for a node
*
* @tree: the tree's root
* @value: the value to match
* Return: The node containing @value
*/
bst_t *bst_search(const bst_t *tree, int value)
{
	if (tree == NULL)
		return (NULL);

	if (tree->n == value)
		return ((bst_t *)tree);

	if (tree->n < value)
		return (bst_search(tree->right, value));

	if (tree->n > value)
		return (bst_search(tree->left, value));

	return (NULL);
}
