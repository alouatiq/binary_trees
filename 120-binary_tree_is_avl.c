#include "binary_trees.h"
#include <stddef.h>
#include <limits.h>
/**
	* height - Helper function to measure the height of a binary tree.
	* @tree: Pointer to the root node of the tree to measure the height.
	*
	* Return: Height of the tree or 0 if tree is NULL.
	*/
int height(const binary_tree_t *tree)
{
	int left_height;
	int right_height;
	if (!tree)
	return (0);
	left_height = height(tree->left);
	right_height = height(tree->right);

	return (1 + (left_height > right_height ? left_height : right_height));
}

/**
	* is_avl_helper - Recursively checks if a binary tree is an AVL tree.
	* @tree: Pointer to the root node of the tree to check.
	* @min: Minimum allowed value for the current node.
	* @max: Maximum allowed value for the current node.
	*
	* Return: 1 if tree is an AVL tree, 0 otherwise.
	*/
int is_avl_helper(const binary_tree_t *tree, int min, int max)
{
	int left_height;
	int right_height;
	if (!tree)
	return (1);

	if (tree->n <= min || tree->n >= max)
	return (0);

        left_height = height(tree->left);
	right_height = height(tree->right);

	if (abs(left_height - right_height) > 1)
	return (0);

	return (is_avl_helper(tree->left, min, tree->n) &&
	is_avl_helper(tree->right, tree->n, max));
}

/**
	* binary_tree_is_avl - Checks if a binary tree is a valid AVL tree.
	* @tree: Pointer to the root node of the tree to check.
	*
	* Return: 1 if tree is a valid AVL tree, 0 otherwise.
	*/
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (!tree)
	return (0);

	return (is_avl_helper(tree, INT_MIN, INT_MAX));
}
