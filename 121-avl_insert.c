#include "binary_trees.h"
#include <stdlib.h>

/**
	* insert_node - Helper function to insert a node into the tree.
	* @tree: Double pointer to the root node of the tree for insertion.
	* @value: Value to insert.
	*
	* Return: Pointer to the created node, or NULL on failure.
	*/
avl_t *insert_node(avl_t **tree, int value)
{
	avl_t *node = NULL;

	if (value < (*tree)->n)
	{
	if ((*tree)->left == NULL)
	{
	(*tree)->left = binary_tree_node(*tree, value);
	node = (*tree)->left;
	}
	else
	node = insert_node((avl_t **)&(*tree)->left, value);
	}
	else if (value > (*tree)->n)
	{
	if ((*tree)->right == NULL)
	{
	(*tree)->right = binary_tree_node(*tree, value);
	node = (*tree)->right;
	}
	else
	node = insert_node((avl_t **)&(*tree)->right, value);
	}
	return (node);
}

/**
	* rebalance_tree - Helper function to rebalance the AVL tree.
	* @tree: Double pointer to the root node of the tree.
	* @value: Value that caused imbalance.
	*/
void rebalance_tree(avl_t **tree, int value)
{
	int balance = binary_tree_balance(*tree);

	if (balance > 1 && value < (*tree)->left->n)
	*tree = binary_tree_rotate_right(*tree);
	else if (balance < -1 && value > (*tree)->right->n)
	*tree = binary_tree_rotate_left(*tree);
	else if (balance > 1 && value > (*tree)->left->n)
	{
	(*tree)->left = binary_tree_rotate_left((*tree)->left);
	*tree = binary_tree_rotate_right(*tree);
	}
	else if (balance < -1 && value < (*tree)->right->n)
	{
	(*tree)->right = binary_tree_rotate_right((*tree)->right);
	*tree = binary_tree_rotate_left(*tree);
	}
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
	avl_t *node;

	if (!tree)
	return (NULL);

	if (!*tree)
	{
	*tree = binary_tree_node(NULL, value);
	return (*tree);
	}

	node = insert_node(tree, value);
	if (!node)
	return (NULL);

	rebalance_tree(tree, value);
	return (node);
}
