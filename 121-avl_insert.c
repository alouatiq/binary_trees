#include "binary_trees.h"
#include <stdlib.h>

/**
	* height - Helper function to calculate the height of a tree.
	* @tree: Pointer to the root node of the tree to measure.
	*
	* Return: Height of the tree, or 0 if tree is NULL.
	*/
int height(const binary_tree_t *tree)
{
	if (!tree)
	return (0);
	int left_height = height(tree->left);
	int right_height = height(tree->right);

	return (1 + (left_height > right_height ? left_height : right_height));
}

/**
	* balance_factor - Computes the balance factor of a tree.
	* @tree: Pointer to the root node of the tree to measure.
	*
	* Return: Balance factor, or 0 if tree is NULL.
	*/
int balance_factor(const binary_tree_t *tree)
{
	if (!tree)
	return (0);
	return (height(tree->left) - height(tree->right));
}

/**
	* rotate_left - Performs a left-rotation on a binary tree.
	* @tree: Pointer to the root node of the tree to rotate.
	*
	* Return: Pointer to the new root of the tree.
	*/
binary_tree_t *rotate_left(binary_tree_t *tree)
{
	binary_tree_t *new_root = tree->right;

	tree->right = new_root->left;
	if (new_root->left)
	new_root->left->parent = tree;

	new_root->left = tree;
	new_root->parent = tree->parent;
	tree->parent = new_root;

	return (new_root);
}

/**
	* rotate_right - Performs a right-rotation on a binary tree.
	* @tree: Pointer to the root node of the tree to rotate.
	*
	* Return: Pointer to the new root of the tree.
	*/
binary_tree_t *rotate_right(binary_tree_t *tree)
{
	binary_tree_t *new_root = tree->left;

	tree->left = new_root->right;
	if (new_root->right)
	new_root->right->parent = tree;

	new_root->right = tree;
	new_root->parent = tree->parent;
	tree->parent = new_root;

	return (new_root);
}

/**
	* avl_insert - Inserts a value into an AVL tree.
	* @tree: Double pointer to the root node of the tree for insertion.
	* @value: Value to insert.
	*
	* Return: Pointer to the created node, or NULL on failure.
	*/
avl_t *avl_insert(avl_t **tree, int value)
{
	if (!tree)
	return (NULL);

	if (!*tree) /* If the tree is empty */
	{
	*tree = binary_tree_node(NULL, value);
	return (*tree);
	}

	avl_t *node = NULL;

	if (value < (*tree)->n)
	{
	if (!(*tree)->left)
	(*tree)->left = binary_tree_node(*tree, value);
	else
	node = avl_insert((avl_t **)&(*tree)->left, value);
	}
	else if (value > (*tree)->n)
	{
	if (!(*tree)->right)
	(*tree)->right = binary_tree_node(*tree, value);
	else
	node = avl_insert((avl_t **)&(*tree)->right, value);
	}
	else
	return (NULL); /* Duplicates not allowed */

	int balance = balance_factor(*tree);

	if (balance > 1 && value < (*tree)->left->n)
	return (rotate_right(*tree));
	if (balance < -1 && value > (*tree)->right->n)
	return (rotate_left(*tree));
	if (balance > 1 && value > (*tree)->left->n)
	{
	(*tree)->left = rotate_left((*tree)->left);
	return (rotate_right(*tree));
	}
	if (balance < -1 && value < (*tree)->right->n)
	{
	(*tree)->right = rotate_right((*tree)->right);
	return (rotate_left(*tree));
	}

	return (node ? node : *tree);
}
