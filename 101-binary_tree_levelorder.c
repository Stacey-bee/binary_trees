#include "binary_trees.h"

/**
 * visitCurrentLevel - calls ths func on each node on a level
 * @root: pointer to the node in the level to call the function in it's nodes
 * @level: level targeted
 * @func: pointer to the function to call on each node
 * Return: void
 */
void visitCurrentLevel(binary_tree_t *root, int level, void (*func)(int))
{
	if (root == NULL)
		return;
	if (level == 1)
		func(root->n);
	else if (level > 1)
	{
		visitCurrentLevel(root->left, level - 1, func);
		visitCurrentLevel(root->right, level - 1, func);
	}
}

/**
 * visitLevelOrder - travers tree using level order traversal
 * @root: root node in the level to travers
 * @func: function to call on each node
 * Return: Void
 */

void visitLevelOrder(binary_tree_t *root, void (*func)(int))
{
	int h = binary_tree_height(root) + 1;
	int i;

	for (i = 1; i <= h; i++)
		visitCurrentLevel(root, i, func);
}

/**
 * binary_tree_levelorder - goes through a binary tree
 * using level-order traversal
 * @tree: pointer to the root node of the tree
 * @func: pointer to a function to call for each node
 * Return: void
 */

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;
	visitLevelOrder((binary_tree_t *)tree, func);
}

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
