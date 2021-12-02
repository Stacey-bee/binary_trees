#include "binary_trees.h"

/**
 * createQueue - createQueue a queue
 * @front: pointer to the front of the queue
 * @rear: pointer to rear of the queue
 * Return: pointer to pointer to queue
 */

binary_tree_t **createQueue(int *front, int *rear)
{
	binary_tree_t **queue =
	(binary_tree_t **)malloc(sizeof(binary_tree_t *) * 500);

	*front = *rear = 0;
	return (queue);
}

/**
 * enQueue - enQueue the new node
 * @queue: pointer to pointer to queue
 * @rear: pointer to rear of the queue
 * @new_node: pointer to the new node
 * Return: void
 */

void enQueue(binary_tree_t **queue, int *rear, binary_tree_t *new_node)
{
	queue[*rear] = new_node;
	(*rear)++;
}

/**
 * deQueue - deQueue the front node
 * @queue: pointer to pointer to queue
 * @front: pointer to front of the queue
 * Return: deQueueed node
 */

binary_tree_t *deQueue(binary_tree_t **queue, int *front)
{
	(*front)++;
	return (queue[*front - 1]);
}

/**
 * isQueueEmpty - checks queue is empty
 * @front: pointer to front of the queue
 * @rear: pointer to rear fo the queue
 * Return: TRUE or FALSE
 */

int isQueueEmpty(int *front, int *rear)
{
	return (*rear == *front);
}

/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: pointer to the root node of the tree
 * Return: 1 or 0
 */

int binary_tree_is_complete(const binary_tree_t *tree)
{
	binary_tree_t *root = (binary_tree_t *)tree;
	binary_tree_t **queue;
	int rear, front, flag;

	if (tree == NULL)
		return (0);

	queue = createQueue(&front, &rear);
	flag = FALSE;
	enQueue(queue, &rear, root);
	while (!isQueueEmpty(&front, &rear))
	{
		binary_tree_t *temp_node = deQueue(queue, &front);
		/* Check if left child is present*/
		if (temp_node->left)
		{
			if (flag == TRUE)
			{
				free(queue);
				return (FALSE);
			}
			enQueue(queue, &rear, temp_node->left);
		}
		else
			flag = TRUE;
		/* Check if right child is present*/
		if (temp_node->right)
		{
			if (flag == TRUE)
			{
				free(queue);
				return (FALSE);
			}
			enQueue(queue, &rear, temp_node->right);
		}
		else
			flag = (TRUE);
	}
	free(queue);
	return (TRUE);
}
