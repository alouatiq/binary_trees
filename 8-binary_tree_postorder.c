#include "binary_trees.h"

/**
	*binary_tree_postorder - function that goes through a binary
	* tree using post-order traversal
	*@tree: pointer to the root node of the tree to traverse
	*@func: pointer to a function to call for each node.
	*Return: Nothing.
	*/

void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
if (func == NULL || tree == NULL)
return;
/*recursively go left-right-root*/
binary_tree_postorder(tree->left, func);
binary_tree_postorder(tree->right, func);
/*execute function for current leaf*/
func(tree->n);
}
