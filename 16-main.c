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
	int perfect;

	root = binary_tree_node(NULL, 98);
	root->left = binary_tree_node(root, 12);
	root->right = binary_tree_node(root, 128);
	root->left->left = binary_tree_node(root->left, 6);
	root->left->right = binary_tree_node(root->left, 16);
	root->right->left = binary_tree_node(root->right, 64);
	root->right->right = binary_tree_node(root->right, 402);
	binary_tree_print(root);

	perfect = binary_tree_is_perfect(root);
	printf("Is the tree perfect? %d\n", perfect);

	root->right->right->left = binary_tree_node(root->right->right, 512);
	binary_tree_print(root);

	perfect = binary_tree_is_perfect(root);
	printf("Is the tree perfect? %d\n", perfect);

	binary_tree_delete(root);
	return (0);
}
