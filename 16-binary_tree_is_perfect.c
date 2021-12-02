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

	if (lcount == rcount)
		return (lcount + rcount + 1);
	else
		return (0);
}

/**
* binary_tree_is_perfect - A function that checks if a tree is perfect
* @tree: The tree in discussion
* Return: 0 or 1
*/
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (FALSE);

	if (binary_tree_size(tree) > 0)
		return (1);
	else
		return (0);
}
