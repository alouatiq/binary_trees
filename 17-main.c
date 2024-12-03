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
    binary_tree_t *root, *sibling;

    root = binary_tree_node(NULL, 98);
    root->left = binary_tree_node(root, 12);
    root->right = binary_tree_node(root, 128);
    root->left->left = binary_tree_node(root->left, 10);
    root->left->right = binary_tree_node(root->left, 54);
    root->right->left = binary_tree_node(root->right, 402);
    root->right->right = binary_tree_node(root->right, 65);
    binary_tree_print(root);

    sibling = binary_tree_sibling(root->left);
    if (sibling)
        printf("Sibling of %d is %d\n", root->left->n, sibling->n);
    else
        printf("Sibling of %d is NULL\n", root->left->n);

    sibling = binary_tree_sibling(root->right->left);
    if (sibling)
        printf("Sibling of %d is %d\n", root->right->left->n, sibling->n);
    else
        printf("Sibling of %d is NULL\n", root->right->left->n);

    sibling = binary_tree_sibling(root);
    if (sibling)
        printf("Sibling of %d is %d\n", root->n, sibling->n);
    else
        printf("Sibling of %d is NULL\n", root->n);

    binary_tree_delete(root);
    return (0);
}
