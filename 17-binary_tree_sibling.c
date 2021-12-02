#include "binary_trees.h"

/**
* binary_tree_sibling - a function that finds the sibling of a node
*
* @node: the node
* Return: the node's sibling
*/
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	binary_tree_t *sibling;

	if (node == NULL || node->parent == NULL ||
	   node->parent->right == NULL ||
	   node->parent->left == NULL)
		return (NULL);

	if (node == node->parent->left)
		sibling = node->parent->right;
	else if (node == node->parent->right)
		sibling = node->parent->left;
	return (sibling);
}
