#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
	* main - Entry point to test array_to_bst
	*
	* Return: Always 0 (Success)
	*/
int main(void)
{
	bst_t *tree;
	int array[] = {79, 47, 68, 87, 84, 91, 21, 32, 34, 2, 20, 22, 98, 1, 62, 95};
	size_t n = sizeof(array) / sizeof(array[0]);

	tree = array_to_bst(array, n);
	if (!tree)
	return (1);

	binary_tree_print(tree);
	return (0);
}
