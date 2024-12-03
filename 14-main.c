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
    binary_tree_t *root;
    int balance;

    root = binary_tree_node(NULL, 98);
    root->left = binary_tree_node(root, 12);
    root->right = binary_tree_node(root, 128);
    root->left->left = binary_tree_node(root->left, 6);
    root->left->right = binary_tree_node(root->left, 16);
    root->right->right = binary_tree_node(root->right, 402);
    root->right->left = binary_tree_node(root->right, 256);
    binary_tree_print(root);

    balance = binary_tree_balance(root);
    printf("Balance factor of %d: %d\n", root->n, balance);
    balance = binary_tree_balance(root->left);
    printf("Balance factor of %d: %d\n", root->left->n, balance);
    balance = binary_tree_balance(root->right);
    printf("Balance factor of %d: %d\n", root->right->n, balance);

    binary_tree_delete(root);
    return (0);
}
