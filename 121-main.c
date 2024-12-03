#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    avl_t *root = NULL;
    avl_t *node;

    node = avl_insert(&root, 98);
    printf("Inserted: %d\n", node->n);
    binary_tree_print(root);

    node = avl_insert(&root, 402);
    printf("Inserted: %d\n", node->n);
    binary_tree_print(root);

    node = avl_insert(&root, 12);
    printf("Inserted: %d\n", node->n);
    binary_tree_print(root);

    node = avl_insert(&root, 46);
    printf("Inserted: %d\n", node->n);
    binary_tree_print(root);

    node = avl_insert(&root, 128);
    printf("Inserted: %d\n", node->n);
    binary_tree_print(root);

    node = avl_insert(&root, 256);
    printf("Inserted: %d\n", node->n);
    binary_tree_print(root);

    return (0);
}
