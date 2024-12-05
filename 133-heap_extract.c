#include "binary_trees.h"
#include <stdlib.h>

/*----------------Helper Functions----------------*/

/**
 * binary_tree_height - Measures the height of a binary tree.
 * @tree: Pointer to the root node of the tree.
 *
 * Return: Height of the tree.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
    size_t left_height, right_height;

    if (!tree)
        return (0);

    left_height = binary_tree_height(tree->left);
    right_height = binary_tree_height(tree->right);

    return ((left_height > right_height ? left_height : right_height) + 1);
}

/**
 * binary_tree_level - Processes a given level in a binary tree.
 * @tree: Pointer to the root node of the tree.
 * @level: Current level to process.
 * @func: Function to call for each node.
 */
void binary_tree_level(const binary_tree_t *tree, size_t level, void (*func)(heap_t *))
{
    if (!tree)
        return;

    if (level == 0)
        func((heap_t *)tree);
    else
    {
        binary_tree_level(tree->left, level - 1, func);
        binary_tree_level(tree->right, level - 1, func);
    }
}

/**
 * get_last_node_helper - Callback to update the last node pointer.
 * @node: Current node being visited.
 */
void get_last_node_helper(heap_t *node)
{
    static heap_t *last_node = NULL;
    last_node = node;
}

/**
 * get_last_node - Finds the last node in a Max Binary Heap.
 * @root: Pointer to the root of the heap.
 *
 * Return: Pointer to the last node.
 */
heap_t *get_last_node(heap_t *root)
{
    size_t height, level;
    heap_t *last_node = NULL;

    if (!root)
        return (NULL);

    height = binary_tree_height(root);
    for (level = 0; level < height; level++)
    {
        binary_tree_level(root, level, get_last_node_helper);
    }

    return (last_node);
}

/**
 * swap_values - Swaps the values of two nodes.
 * @a: Pointer to the first node.
 * @b: Pointer to the second node.
 */
void swap_values(heap_t *a, heap_t *b)
{
    int temp = a->n;
    a->n = b->n;
    b->n = temp;
}

/**
 * heapify_down - Restores Max Binary Heap property by sifting down.
 * @node: Pointer to the root of the heap.
 */
void heapify_down(heap_t *node)
{
    heap_t *largest = node;

    if (node->left && node->left->n > largest->n)
        largest = node->left;

    if (node->right && node->right->n > largest->n)
        largest = node->right;

    if (largest != node)
    {
        swap_values(node, largest);
        heapify_down(largest);
    }
}

/*----------------Main Function----------------*/

/**
 * heap_extract - Extracts the root node of a Max Binary Heap.
 * @root: Double pointer to the root of the heap.
 *
 * Return: Value of the extracted node, or 0 if the heap is empty.
 */
int heap_extract(heap_t **root)
{
    int value;
    heap_t *last_node;

    if (!root || !*root)
        return (0);

    value = (*root)->n;

    if (!(*root)->left && !(*root)->right)
    {
        free(*root);
        *root = NULL;
        return (value);
    }

    last_node = get_last_node(*root);

    if (last_node->parent)
    {
        if (last_node->parent->right == last_node)
            last_node->parent->right = NULL;
        else
            last_node->parent->left = NULL;
    }

    (*root)->n = last_node->n;
    free(last_node);

    heapify_down(*root);

    return (value);
}
