#include "binary_trees.h"
#include <stdlib.h>

/**
	*binary_tree_insert_left - function that inserts a node as
	* the left-child of another node
	*@parent: pointer to the node to insert the left-child in
	*@value:value to store in the new node
	*Return: pointer to the created node, or NULL on failure or if parent is NULL
	*/

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
binary_tree_t *new_node;
binary_tree_t *temp;
if (parent == NULL)
return (NULL);
/*create a new node*/
new_node = binary_tree_node(parent, value);
if (new_node == NULL)
return (NULL);
/*case parent has already a left child*/
if (parent->left != NULL)
{
temp = parent->left;
new_node->left = temp;
temp->parent = new_node;
parent->left = new_node;
}
/*parent has no child*/
else
{
parent->left = new_node;
}
return (new_node);
}
