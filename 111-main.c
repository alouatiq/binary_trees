#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
	* main - Entry point to test bst_insert
	*
	* Return: Always 0 (Success)
	*/
int main(void)
{
	bst_t *root;
	bst_t *node;

	root = NULL;
	node = bst_insert(&root, 98);
	printf("Inserted: %d\n", node->n);
	binary_tree_print(root);

	node = bst_insert(&root, 402);
	printf("\nInserted: %d\n", node->n);
	binary_tree_print(root);

	node = bst_insert(&root, 12);
	printf("\nInserted: %d\n", node->n);
	binary_tree_print(root);

	node = bst_insert(&root, 46);
	printf("\nInserted: %d\n", node->n);
	binary_tree_print(root);

	node = bst_insert(&root, 128);
	printf("\nInserted: %d\n", node->n);
	binary_tree_print(root);

	node = bst_insert(&root, 402);
	printf("\nNode should be nil -> %p\n", (void *)node);

	return (0);
}
