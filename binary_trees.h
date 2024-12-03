#ifndef BINARY_TREES_H
#define BINARY_TREES_H

#include <stddef.h>
#include <stdlib.h>

/**
	* struct binary_tree_s - Binary tree node
	*
	* @n: Integer stored in the node
	* @parent: Pointer to the parent node
	* @left: Pointer to the left child node
	* @right: Pointer to the right child node
	*/
struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;

void binary_tree_print(const binary_tree_t *);
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value);
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value);
void binary_tree_delete(binary_tree_t *tree);
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int));
int binary_tree_is_leaf(const binary_tree_t *node);
int binary_tree_is_root(const binary_tree_t *node);
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int));
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int));
size_t binary_tree_height(const binary_tree_t *tree);
size_t binary_tree_depth(const binary_tree_t *node); /* task 11 */
size_t binary_tree_leaves(const binary_tree_t *tree); /* task 12 */
size_t binary_tree_nodes(const binary_tree_t *tree); /* task 13 */
int binary_tree_balance(const binary_tree_t *tree); /* task 14 */
int binary_tree_is_full(const binary_tree_t *tree); /* task 15 */
int binary_tree_is_perfect(const binary_tree_t *tree); /* task 16 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node); /* task 17 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node);  /* task 18 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second); /* task 19 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int)); /* task 20 */
int binary_tree_is_complete(const binary_tree_t *tree); /* task 21 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree); /* task 22 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree); /* task 23 */

/* Task 24: Check if a binary tree is a BST */
int binary_tree_is_bst(const binary_tree_t *tree);

/* Task 25: Insert a value into a BST */
bst_t *bst_insert(bst_t **tree, int value);

/* Task 26: Build a BST from an array */
bst_t *array_to_bst(int *array, size_t size);

/* Task 27: Search for a value in a BST */
bst_t *bst_search(const bst_t *tree, int value);

/* Task 28: Remove a node from a BST */
bst_t *bst_remove(bst_t *root, int value);

/* Task 30: Check if a binary tree is an AVL tree */
int binary_tree_is_avl(const binary_tree_t *tree);

/* Task 31: Insert a value into an AVL tree */
avl_t *avl_insert(avl_t **tree, int value);

/* Task 32: Build an AVL tree from an array */
avl_t *array_to_avl(int *array, size_t size);

/* Task 33: Remove a node from an AVL tree */
avl_t *avl_remove(avl_t *root, int value);

/* Task 34: Build an AVL tree from a sorted array */
avl_t *sorted_array_to_avl(int *array, size_t size);

/* Task 36: Check if a binary tree is a Max Binary Heap */
int binary_tree_is_heap(const binary_tree_t *tree);

/* Task 37: Insert a value into a Max Binary Heap */
heap_t *heap_insert(heap_t **root, int value);

/* Task 38: Build a Max Binary Heap from an array */
heap_t *array_to_heap(int *array, size_t size);

/* Task 39: Extract the root node of a Max Binary Heap */
int heap_extract(heap_t **root);

/* Task 40: Convert a Binary Max Heap to a sorted array */
int *heap_to_sorted_array(heap_t *heap, size_t *size);

#endif /* BINARY_TREES_H */
