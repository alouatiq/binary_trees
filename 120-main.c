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
	int avl;

	root = binary_tree_node(NULL, 98);
	root->left = binary_tree_node(root, 90);
	root->right = binary_tree_node(root, 128);
	root->left->left = binary_tree_node(root->left, 70);
	root->left->right = binary_tree_node(root->left, 96);
	root->right->left = binary_tree_node(root->right, 120);
	root->right->right = binary_tree_node(root->right, 140);

	binary_tree_print(root);

	avl = binary_tree_is_avl(root);
	printf("Is %d AVL: %d\n", root->n, avl);

	root->right->right->right = binary_tree_node(root->right->right, 150);
	binary_tree_print(root);

	avl = binary_tree_is_avl(root);
	printf("Is %d AVL: %d\n", root->n, avl);

	return (0);
}
