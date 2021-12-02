#include "binary_trees.h"

/**
* binary_tree_rotate_left - a function that rotates a tree leftward
*
* @tree: The root node
* Return: The new root
*/
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *tmp, *par;

	if (tree == NULL || tree->right == NULL)
		return (NULL);

	tmp = tree;
	par = tree->parent;
	tree = tree->right;

	if (tree->left)
	{
		tmp->right = tree->left;
		tree->left->parent = tmp;
	}
	else
	{
		tmp->right = NULL;
	}
	tmp->parent = tree;
	tree->left = tmp;

	if (par != NULL)
	{
		par->right = tree;
		tree->parent = par;
	}

	return (tree);
}
