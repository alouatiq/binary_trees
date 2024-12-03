#include "binary_trees.h"

/**
	*binary_tree_preorder - function that goes through a binary
	* tree using pre-order traversal
	*@tree: Pointer to the root node of the tree to traverse.
	*@func: Pointer to a function to call for each node.
	*Return: Nothing
	*/

void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
if (tree == NULL || func == NULL)
return;
/*call the function*/
func(tree->n);
/*recursively go root-left-right*/
binary_tree_preorder(tree->left, func);
binary_tree_preorder(tree->right, func);
}
