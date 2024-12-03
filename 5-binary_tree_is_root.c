#include "binary_trees.h"

/**
	*binary_tree_is_root - function that checks if a given node is a root
	*@node: pointer to the node to check
	*Return: 1 if node is a root, otherwise 0, 0 if node is NULL
	*/

int binary_tree_is_root(const binary_tree_t *node)
{
if (node == NULL)
return (0);
/*case node is a root*/
if (node->parent == NULL)
return (1);
/*case node not a root*/
else
return (0);
}
