#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * main - Entry point for testing the binary_tree_node function
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    binary_tree_t *root;

    root = binary_tree_node(NULL, 98);
    if (root == NULL)
    {
        printf("Failed to create the root node.\n");
        return (1);
    }
    printf("Node created! Value: %d\n", root->n);

    free(root);
    return (0);
}
