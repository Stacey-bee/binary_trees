#include "binary_trees.h"

/**
* binary_tree_rotate_right - a function that rotates a tree rightward
*
* @tree: The root node
* Return: The new root
*/
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *tmp, *par;

	if (tree == NULL || tree->left == NULL)
		return (NULL);

	tmp = tree;
	par = tree->parent;
	tree = tree->left;

	if (tree->right)
	{
		tmp->left = tree->right;
		tree->right->parent = tmp;
	}
	else
		tmp->left = NULL;
	tmp->parent = tree;
	tree->right = tmp;

	if (par != NULL)
		par->left = tree;
	tree->parent = par;

	return (tree);
}
