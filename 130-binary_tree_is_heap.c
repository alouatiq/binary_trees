#include "binary_trees.h"
#include <stdbool.h>

/**
	* binary_tree_size - Measures the size of a binary tree
	* @tree: Pointer to the root node of the tree to measure the size
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
	* is_complete - Helper function to check if a binary tree is complete
	* @tree: Pointer to the root node of the tree
	* @index: Index of the current node in an array representation
	* @node_count: Total number of nodes in the tree
	*
	* Return: 1 if the tree is complete, 0 otherwise
	*/
bool is_complete(const binary_tree_t *tree, size_t index, size_t node_count)
{
	if (!tree)
	return (true);
	if (index >= node_count)
	return (false);
	return (is_complete(tree->left, 2 * index + 1, node_count) &&
	is_complete(tree->right, 2 * index + 2, node_count));
}

/**
	* is_max_heap - Helper function to check if a binary tree satisfies Max Heap
	* @tree: Pointer to the root node of the tree
	*
	* Return: 1 if the tree satisfies Max Heap, 0 otherwise
	*/
bool is_max_heap(const binary_tree_t *tree)
{
	if (!tree)
	return (true);

	if (tree->left && tree->left->n > tree->n)
	return (false);
	if (tree->right && tree->right->n > tree->n)
	return (false);

	return (is_max_heap(tree->left) && is_max_heap(tree->right));
}

/**
	* binary_tree_is_heap - Checks if a binary tree is a valid Max Binary Heap
	* @tree: Pointer to the root node of the tree
	*
	* Return: 1 if the tree is a Max Binary Heap, 0 otherwise
	*/
int binary_tree_is_heap(const binary_tree_t *tree)
{
	size_t node_count;

	if (!tree)
	return (0);

	node_count = binary_tree_size(tree);

	return (is_complete(tree, 0, node_count) && is_max_heap(tree));
}
