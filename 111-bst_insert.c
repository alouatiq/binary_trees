#include "binary_trees.h"

/**
	* bst_insert - Inserts a value into a Binary Search Tree.
	* @tree: Double pointer to the root node of the BST.
	* @value: The value to insert into the tree.
	*
	* Return: A pointer to the newly inserted node, or NULL on failure.
	*/
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *current, *new_node;

	if (tree == NULL)
	return (NULL);

	if (*tree == NULL)
	{
	new_node = binary_tree_node(NULL, value);
	if (new_node == NULL)
	return (NULL);
	*tree = new_node;
	return (new_node);
	}

	current = *tree;
	if (value < current->n)
	{
	if (current->left != NULL)
	return (bst_insert(&current->left, value));
	new_node = binary_tree_node(current, value);
	if (new_node == NULL)
	return (NULL);
	current->left = new_node;
	}
	else if (value > current->n)
	{
	if (current->right != NULL)
	return (bst_insert(&current->right, value));
	new_node = binary_tree_node(current, value);
	if (new_node == NULL)
	return (NULL);
	current->right = new_node;
	}
	else
	return (NULL); /* Duplicate values are not allowed in BST */

	return (new_node);
}
