#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * print_array - Prints an array of integers
 *
 * @array: The array to be printed
 * @size: Number of elements in @array
 */
void print_array(const int *array, size_t size)
{
    size_t i;

    for (i = 0; i < size; i++)
        printf("%d ", array[i]);
    printf("\n");
}

/**
 * main - Entry point
 *
 * Return: 0 on success, error code on failure
 */
int main(void)
{
    avl_t *tree;
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    size_t n = sizeof(array) / sizeof(array[0]);

    printf("Array: ");
    print_array(array, n);

    tree = sorted_array_to_avl(array, n);
    if (!tree)
        return (1);

    printf("AVL tree:\n");
    binary_tree_print(tree);
    binary_tree_delete(tree);

    return (0);
}
