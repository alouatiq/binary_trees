#include "binary_trees.h"
#include <stdlib.h>

/**
	* heap_to_sorted_array - Converts a Binary Max Heap to a sorted array
	* @heap: Pointer to the root node of the heap
	* @size: Address to store the size of the array
	*
	* Return: Pointer to the sorted array, or NULL on failure
	*/
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int *array;
	size_t i = 0;
	size_t heap_size;
	int value;

	if (!heap || !size)
	return (NULL);

	/* Calculate the size of the heap */
	heap_size = binary_tree_size(heap);
	*size = heap_size;

	/* Allocate memory for the array */
	array = malloc(heap_size * sizeof(int));
	if (!array)
	return (NULL);

	/* Extract elements from the heap and store them in the array */
	for (i = 0; i < heap_size; i++)
	{
	value = heap_extract(&heap);
	array[i] = value;
	}

	return (array);
}
