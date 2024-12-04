#include "binary_trees.h"
#include <stdlib.h>
/**
	* avl_insert - Inserts a value into an AVL tree.
	* @tree: Double pointer to the root node of the tree for insertion.
	* @value: Value to insert.
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
	{ /* If the tree is empty */
	*tree = binary_tree_node(NULL, value);
	return (*tree);
	}
	if (value < (*tree)->n)
	{
	if ((*tree)->left == NULL)
	{
	(*tree)->left = binary_tree_node(*tree, value);
	node = ((*tree)->left);
	}
	else
	node = avl_insert((avl_t **)&(*tree)->left, value);
	}
	else if (value > (*tree)->n)
	{
	if ((*tree)->right == NULL)
	{
	(*tree)->right = binary_tree_node(*tree, value);
	node = (*tree)->right;
	}
	else
	node = avl_insert((avl_t **)&(*tree)->right, value);
	}
	else
	return (NULL); /* Duplicates not allowed */
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
