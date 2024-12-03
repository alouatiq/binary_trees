#include "binary_trees.h"
#include <stdlib.h>

/**
	* binary_tree_size - Measures the size of a binary tree
	* @tree: Pointer to the root node of the tree to measure
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
	* is_complete_util - Recursive utility to check if a binary tree is complete
	* @tree: Pointer to the root node of the tree
	* @index: Current index in the level-order traversal
	* @size: Total number of nodes in the tree
	*
	* Return: 1 if the tree is complete, 0 otherwise
	*/
int is_complete_util(const binary_tree_t *tree, size_t index, size_t size)
{
	if (!tree)
	return (1);

	if (index >= size)
	return (0);

	return (is_complete_util(tree->left, 2 * index + 1, size) &&
	is_complete_util(tree->right, 2 * index + 2, size));
}

/**
	* binary_tree_is_complete - Checks if a binary tree is complete
	* @tree: Pointer to the root node of the tree to check
	*
	* Return: 1 if the tree is complete, 0 otherwise
	*/
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t size;

	if (!tree)
	return (0);

	size = binary_tree_size(tree);
	return (is_complete_util(tree, 0, size));
}
