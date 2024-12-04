#include "binary_trees.h"

/**
	* min_value_node - Finds the node with the smallest value in a BST.
	* @node: Pointer to the root node of the tree to search.
	*
	* Return: Pointer to the node with the smallest value.
	*/
bst_t *min_value_node(bst_t *node)
{
	bst_t *current = node;

	while (current && current->left)
	current = current->left;

	return (current);
}

/**
	* bst_remove - Removes a node with a specific value from a BST.
	* @root: Pointer to the root node of the tree.
	* @value: Value of the node to remove.
	*
	* Return: Pointer to the new root of the tree.
	*/
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *temp;

	if (root == NULL)
	return (NULL);

	if (value < root->n)
	root->left = bst_remove(root->left, value);
	if (root->left)
	root->left->parent = root;
	else if (value > root->n)
	root->right = bst_remove(root->right, value);
	if (root->right)
	root->right->parent = root;
	else
	{
	if (root->left == NULL)
	{
	temp = root->right;
	if (temp)
	temp->parent = root->parent;
	free(root);
	return (temp);
	}
	else if (root->right == NULL)
	{
	temp = root->left;
	if (temp)
	temp->parent = root->parent;
	free(root);
	return (temp);
	}

	temp = min_value_node(root->right);
	root->n = temp->n;
	root->right = bst_remove(root->right, temp->n);
	}

	return (root);
}
