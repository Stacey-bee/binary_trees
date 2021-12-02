#include "binary_trees.h"

/**
 * array_to_bst - builds a Binary Search Tree from an array
 * @array: pointer to the first element in the array
 * @size: number of elements in the array
 * Return: pointer to the root node of the created bst or null
 */

bst_t *array_to_bst(int *array, size_t size)
{
	int i;
	bst_t *root = NULL;

	if (array != NULL)
	{
		for (i = 0; i < (int)size; i++)
		{
			bst_insert(&root, *(array + i));
		}
	}
	return (root);
}
