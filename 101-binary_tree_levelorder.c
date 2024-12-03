#include "binary_trees.h"
#include <stdlib.h>

/**
	* binary_tree_height - Measures the height of a binary tree
	* @tree: Pointer to the root node of the tree to measure the height
	* 
	* Return: Height of the tree, or 0 if tree is NULL
	*/
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
void binary_tree_level(const binary_tree_t *tree, size_t level, void (*func)(int))
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
	* binary_tree_levelorder - Goes through a binary tree using level-order traversal
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
