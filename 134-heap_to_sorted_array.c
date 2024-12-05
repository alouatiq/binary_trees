#include "binary_trees.h"
#include <stdlib.h>

/**
	* heap_size - Calculate the size of the heap
	* @heap: Pointer to the root node of the heap
	*
	* Return: Size of the heap
	*/
size_t heap_size(const heap_t *heap)
{
	if (!heap)
	return (0);
	return (1 + heap_size(heap->left) + heap_size(heap->right));
}

/**
	* heap_to_sorted_array - Converts a Binary Max
 	* Heap to a sorted array of integers
	* @heap: Pointer to the root node of the heap to convert
	* @size: Address to store the size of the array
	*
	* Return: Pointer to the sorted array, or NULL on failure
	*/
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int *array;
	size_t i, heap_len;

	if (!heap || !size)
	return (NULL);

	/* Calculate the size of the heap */
	heap_len = heap_size(heap);
	*size = heap_len;

	/* Allocate memory for the array */
	array = malloc(sizeof(int) * heap_len);
	if (!array)
	return (NULL);

	/* Extract elements from the heap and store them in the array */
	for (i = 0; i < heap_len; i++)
	{
	array[i] = heap_extract(&heap);
	if (!heap && i < heap_len - 1) /* Ensure heap extraction is correct */
	{
	free(array);
	return (NULL);
	}
	}

	return (array);
}
