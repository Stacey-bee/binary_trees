#include "binary_trees.h"

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: pointer to first node
 * @second: pointer to the second node
 * Return: pointer to the lowest common ancestor node
 * of the two given nodes or null
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
									 const binary_tree_t *second)
{
	binary_tree_t *low, *high;
	size_t fd, sd;
	int dif, i = 0;

	if (first == NULL || second == NULL)
		return (NULL);

	fd = binary_tree_depth(first);
	sd = binary_tree_depth(second);

	dif = (int)fd - (int)sd;
	if (dif >= 0)
	{
		low = (binary_tree_t *)first;
		high = (binary_tree_t *)second;
	} else if (dif < 0)
	{
		low = (binary_tree_t *)second;
		high = (binary_tree_t *)first;
		dif *= -1;
	}

	while (i < dif)
	{
		low = low->parent;
		++i;
	}

	while (high != NULL && low != NULL)
	{
		if (high->n == low->n)
			return (high);
		high = high->parent;
		low = low->parent;
	}
	return (NULL);
}

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
