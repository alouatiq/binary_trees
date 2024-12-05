#include "binary_trees.h"
#include <stdlib.h>

/*---------------Functions to use binary_tree_levelorder function---------*/
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (!tree)
	return (0);

	left_height = tree->left ? binary_tree_height(tree->left) + 1 : 0;
	right_height = tree->right ? binary_tree_height(tree->right) + 1 : 0;

	return ((left_height > right_height) ? left_height : right_height);
}

/**
	* binary_tree_level - Traverses a binary tree level by level
	* @tree: Pointer to the root node of the current level
	* @level: Current level being traversed
	* @func: Function to call for each node
	*/
void binary_tree_level(const binary_tree_t *tree, size_t level,
		       void (*func)(int))
{
	if (!tree)
	return;

	if (level == 0)
	func(tree->n);
	else
	{
	binary_tree_level(tree->left, level - 1, func);
	binary_tree_level(tree->right, level - 1, func);
	}
}

/**
	* binary_tree_levelorder - Goes through a binary tree using
	*level-order traversal
	* @tree: Pointer to the root node of the tree to traverse
	* @func: Function to call for each node
	*/
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t height, level;

	if (!tree || !func)
	return;

	height = binary_tree_height(tree);

	for (level = 0; level <= height; level++)
	binary_tree_level(tree, level, func);
}

/*---------------------------------------------------------*/

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
	size_t lvl = 0, max_level = 0;

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
