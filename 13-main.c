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
	binary_tree_t *root;
	size_t nodes;

	root = binary_tree_node(NULL, 98);
	root->left = binary_tree_node(root, 12);
	root->right = binary_tree_node(root, 402);
	binary_tree_insert_right(root->left, 54);
	binary_tree_insert_right(root, 128);
	binary_tree_print(root);

	nodes = binary_tree_nodes(root);
	printf("Nodes with at least 1 child: %lu\n", nodes);
	nodes = binary_tree_nodes(root->left);
	printf("Nodes with at least 1 child in left subtree: %lu\n", nodes);
	nodes = binary_tree_nodes(root->right);
	printf("Nodes with at least 1 child in right subtree: %lu\n", nodes);
	return (0);
}
