#include <stdio.h>
#include "binary_trees.h"

/**
 * main - Entry point for testing sorted_array_to_avl
 *
 * Return: Always 0
 */
int main(void)
{
    avl_t *tree;
    int array[] = {1, 2, 3, 4, 5, 6, 7};
    size_t n = sizeof(array) / sizeof(array[0]);

    tree = sorted_array_to_avl(array, n);
    if (!tree)
        return (1);

    binary_tree_print(tree);
    return (0);
}
