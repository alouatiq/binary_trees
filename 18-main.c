#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
	* main - Entry point
	*
	* Return: Always 0 (Success)
	*/
int main(void)
{
	binary_tree_t *root, *uncle;

	root = binary_tree_node(NULL, 98);
	root->left = binary_tree_node(root, 12);
	root->right = binary_tree_node(root, 128);
	root->left->left = binary_tree_node(root->left, 10);
	root->left->right = binary_tree_node(root->left, 54);
	root->right->left = binary_tree_node(root->right, 402);
	root->right->right = binary_tree_node(root->right, 65);
	binary_tree_print(root);

	uncle = binary_tree_uncle(root->left->right);
	if (uncle)
	printf("Uncle of %d is %d\n", root->left->right->n, uncle->n);
	else
	printf("Uncle of %d is NULL\n", root->left->right->n);

	uncle = binary_tree_uncle(root->right->left);
	if (uncle)
	printf("Uncle of %d is %d\n", root->right->left->n, uncle->n);
	else
	printf("Uncle of %d is NULL\n", root->right->left->n);

	uncle = binary_tree_uncle(root);
	if (uncle)
	printf("Uncle of %d is %d\n", root->n, uncle->n);
	else
	printf("Uncle of %d is NULL\n", root->n);

	binary_tree_delete(root);
	return (0);
}
