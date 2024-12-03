#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree to measure the height
 *
 * Return: Height of the tree, or 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
    size_t left_height, right_height;

    if (!tree)
        return (0);

    /* Measure the height of the left and right subtrees */
    left_height = tree->left ? binary_tree_height(tree->left) + 1 : 0;
    right_height = tree->right ? binary_tree_height(tree->right) + 1 : 0;

    /* Return the maximum of the two */
    return (left_height > right_height ? left_height : right_height);
}
