#include "binary_trees.h"

/**
 * heapify_up - Restores the Max Heap property by moving a node up
 * @node: Pointer to the node to heapify
 *
 * Return: Pointer to the new root node after heapification
 */
heap_t *heapify_up(heap_t *node)
{
	while (node->parent && node->n > node->parent->n)
	{
	int temp = node->n;

	node->n = node->parent->n;
	node->parent->n = temp;
	node = node->parent;
	}
	return (node);
}

/**
 * find_insertion_point - Finds the insertion point for the new node
 * @root: Pointer to the root node of the heap
 * @size: Size of the current heap
 *
 * Return: Pointer to the parent node where the new node will be inserted
 */
heap_t *find_insertion_point(heap_t *root, size_t size)
{
	size_t mask = 1;

	while (mask <= size)
	mask <<= 1;
	mask >>= 2;

	while (mask > 0)
	{
	if (root == NULL)
	return (NULL);
	if (size & mask)
	{
	if (root->right == NULL)
	break;
	root = root->right;
	}
	else
	{
	if (root->left == NULL)
	break;
	root = root->left;
	}
	mask >>= 1;
	}
	return (root);
}

/**
 * binary_tree_size - Measures the size of a binary tree
 * @tree: Pointer to the root node of the tree
 *
 * Return: Size of the tree, or 0 if tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
	return (0);
	return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}

/**
 * heap_insert - Inserts a value into a Max Binary Heap
 * @root: Double pointer to the root node of the heap
 * @value: Value to store in the new node
 *
 * Return: Pointer to the new node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	size_t size;
	heap_t *new_node, *parent;

	if (!root)
	return (NULL);

	if (!*root)
	{
	*root = binary_tree_node(NULL, value);
	return (*root);
	}

	size = binary_tree_size(*root);
	parent = find_insertion_point(*root, size + 1);

	new_node = binary_tree_node(parent, value);
	if (!new_node)
	return (NULL);

	if (!parent->left)
	parent->left = new_node;
	else
	parent->right = new_node;

	return (heapify_up(new_node));
	}
