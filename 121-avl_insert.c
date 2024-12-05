#include "binary_trees.h"
#include <stdlib.h>

/**
	* avl_insert - Inserts a value in an AVL Tree.
	* @tree: Double pointer to the root node of the AVL tree.
	* @value: The value to insert in the tree.
	*
	* Return: Pointer to the created node, or NULL on failure.
	*/
avl_t *avl_insert(avl_t **tree, int value)
{
	int balance;
	avl_t *node = NULL;

	if (!tree)
	return (NULL);

	if (!*tree)
	{
	/* If the tree is empty, create the root node */
	*tree = binary_tree_node(NULL, value);
	return (*tree);
	}

	/* Perform normal BST insertion */
	if (value < (*tree)->n)
	{
	node = avl_insert((avl_t **)&((*tree)->left), value);
	(*tree)->left->parent = *tree;
	}
	else if (value > (*tree)->n)
	{
	node = avl_insert((avl_t **)&((*tree)->right), value);
	(*tree)->right->parent = *tree;
	}
	else
	return (NULL); /* No duplicates allowed */

	/* Update balance factor and balance the tree */
	balance = binary_tree_balance(*tree);
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

	return (node ? node : *tree);
}
