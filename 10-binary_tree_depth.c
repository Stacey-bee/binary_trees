#include <stdio.h>
#include "binary_trees.h"

/**
* binary_tree_depth - function that calculates the height of a node in a tree
*
* @tree: the node
* Return: The depth of the node
*/
size_t binary_tree_depth(const binary_tree_t *tree)
{
	int dl = 0, dr = 0;

	if (tree == NULL)
	return (0);

	if (tree->parent)
	{
		dl = binary_tree_depth(tree->parent) + 1;
		dr = binary_tree_depth(tree->parent) + 1;
	}

	if (dl > dr)
		return (dl);
	else
		return (dr);
}
