#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * main - Entry point to test bst_search
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    bst_t *tree;
    bst_t *node;
    int array[] = {79, 47, 68, 87, 84, 91, 21, 32, 34, 2, 20, 22, 98, 1, 62, 95};
    size_t n = sizeof(array) / sizeof(array[0]);

    tree = array_to_bst(array, n);
    if (!tree)
        return (1);

    binary_tree_print(tree);

    node = bst_search(tree, 32);
    if (node)
        printf("Found: %d\n", node->n);
    else
        printf("Value not found\n");

    node = bst_search(tree, 512);
    if (node)
        printf("Found: %d\n", node->n);
    else
        printf("Value not found\n");

    return (0);
}
