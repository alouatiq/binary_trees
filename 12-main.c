#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
	* main - Entry point for testing the binary_tree_leaves function.
	*
	* Return: Always 0 (Success)
	*/
int main(void)
{
	binary_tree_t *root;
	size_t leaves;

	root = binary_tree_node(NULL, 98);
	root->left = binary_tree_node(root, 12);
	root->right = binary_tree_node(root, 402);
	binary_tree_insert_right(root->left, 54);
	binary_tree_insert_right(root, 128);
	binary_tree_print(root);

	leaves = binary_tree_leaves(root);
	printf("Leaves in tree: %lu\n", leaves);

	binary_tree_delete(root);
	return (0);
}
