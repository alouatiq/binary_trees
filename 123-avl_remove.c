#include "binary_trees.h"
#include <stdlib.h>

/**
 * avl_remove - Removes a node from an AVL tree.
 * @root: Pointer to the root node of the tree for removing the node.
 * @value: Value to remove from the tree.
 *
 * Return: Pointer to the new root node of the tree after deletion
 *and rebalancing.
 */
avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *temp;
	avl_t *successor;
	int balance;

	if (!root)
	return (NULL);

	if (value < root->n)
	root->left = avl_remove(root->left, value);
	else if (value > root->n)
	root->right = avl_remove(root->right, value);
	else
	{
	if (!root->left || !root->right)
	{
	temp = root->left ? root->left : root->right;
	free(root);
	return (temp);
	}

	successor = root->right;
	while (successor->left)
	successor = successor->left;
	root->n = successor->n;
	root->right = avl_remove(root->right, successor->n);
	}


	/* Rebalance the tree */
	balance = binary_tree_balance(root);
	if (balance > 1 && binary_tree_balance(root->left) >= 0)
	return (binary_tree_rotate_right(root));
	if (balance > 1 && binary_tree_balance(root->left) < 0)
	{
	root->left = binary_tree_rotate_left(root->left);
	return (binary_tree_rotate_right(root));
	}
	if (balance < -1 && binary_tree_balance(root->right) <= 0)
	return (binary_tree_rotate_left(root));
	if (balance < -1 && binary_tree_balance(root->right) > 0)
	{
	root->right = binary_tree_rotate_right(root->right);
	return (binary_tree_rotate_left(root));
	}

	return (root);
	}
