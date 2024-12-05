#include "binary_trees.h"
#include <stdlib.h>

/**
 * swap_values - Swap values between two nodes
 * @a: Pointer to the first node
 * @b: Pointer to the second node
 */
void swap_values(heap_t *a, heap_t *b)
{
	int temp;

	temp = a->n;
	a->n = b->n;
	b->n = temp;
}

/**
 * get_last_node - Get the last node in level-order traversal
 * @root: Pointer to the root of the heap
 *
 * Return: Pointer to the last node
 */
heap_t *get_last_node(heap_t *root)
{
	heap_t *last_node = NULL;
	size_t level = 0, max_level = 0;

	if (!root)
		return (NULL);

	binary_tree_levelorder(root, ^(heap_t *node, size_t lvl) {
		if (lvl > max_level)
		{
			max_level = lvl;
			last_node = node;
		}
	});

	return (last_node);
}

/**
 * heapify_down - Restore the Max Heap property by sifting down
 * @node: Pointer to the root node of the heap
 */
void heapify_down(heap_t *node)
{
	heap_t *largest = node;

	if (node->left && node->left->n > largest->n)
		largest = node->left;
	if (node->right && node->right->n > largest->n)
		largest = node->right;

	if (largest != node)
	{
		swap_values(node, largest);
		heapify_down(largest);
	}
}

/**
 * heap_extract - Extracts the root node of a Max Binary Heap
 * @root: Double pointer to the root of the heap
 *
 * Return: The value of the extracted root node, or 0 if the heap is empty
 */
int heap_extract(heap_t **root)
{
	int value;
	heap_t *last_node;

	if (!root || !*root)
		return (0);

	value = (*root)->n;

	if (!(*root)->left && !(*root)->right)
	{
		free(*root);
		*root = NULL;
		return (value);
	}

	last_node = get_last_node(*root);
	if (last_node == (*root)->right)
		last_node->parent->right = NULL;
	else
		last_node->parent->left = NULL;

	(*root)->n = last_node->n;
	free(last_node);

	heapify_down(*root);

	return (value);
}
