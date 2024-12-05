#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree
 *
 * Return: The height of the tree
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
    size_t left, right;

    if (!tree)
        return (0);

    left = binary_tree_height(tree->left);
    right = binary_tree_height(tree->right);

    return ((left > right ? left : right) + 1);
}

/**
 * get_last_node - Gets the last node of the binary tree using level-order
 * @root: Pointer to the root node of the tree
 *
 * Return: Pointer to the last node
 */
heap_t *get_last_node(heap_t *root)
{
    size_t height, level;
    heap_t *last_node = NULL;

    if (!root)
        return (NULL);

    height = binary_tree_height(root);

    for (level = 0; level <= height; level++)
    {
        binary_tree_levelorder_helper(root, level, &last_node);
    }

    return (last_node);
}

/**
 * binary_tree_levelorder_helper - Traverses the tree and finds the last node
 * @tree: Pointer to the root node of the tree
 * @level: Current level of the tree
 * @last_node: Pointer to store the last node found
 */
void binary_tree_levelorder_helper(heap_t *tree, size_t level, heap_t **last_node)
{
    if (!tree)
        return;

    if (level == 0)
        *last_node = tree;
    else
    {
        binary_tree_levelorder_helper(tree->left, level - 1, last_node);
        binary_tree_levelorder_helper(tree->right, level - 1, last_node);
    }
}

/**
 * swap_values - Swaps the values of two nodes
 * @a: Pointer to the first node
 * @b: Pointer to the second node
 */
void swap_values(heap_t *a, heap_t *b)
{
    int temp;

    temp = a->n;
    a->n = b->n;
    b->n = temp;
}

/**
 * heapify_down - Restores the Max Binary Heap property by sifting down
 * @node: Pointer to the root node of the heap
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

/**
 * heap_extract - Extracts the root node of a Max Binary Heap
 * @root: Double pointer to the root node of the heap
 *
 * Return: The value stored in the root node, or 0 if the heap is empty
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
        if (last_node->parent->left == last_node)
            last_node->parent->left = NULL;
        else
            last_node->parent->right = NULL;
    }

    (*root)->n = last_node->n;
    free(last_node);

    heapify_down(*root);

    return (value);
}
