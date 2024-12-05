#include "binary_trees.h"
#include <stdlib.h>

/**
 * heap_to_sorted_array - Converts a Binary Max Heap to a sorted array of integers
 * @heap: Pointer to the root node of the heap to convert
 * @size: Address to store the size of the array
 *
 * Return: Pointer to the sorted array, or NULL on failure
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
    int *array;
    size_t i;
    size_t heap_size;
    heap_t *current = heap;

    if (!heap || !size)
        return (NULL);

    /* Calculate the size of the heap */
    heap_size = 0;
    while (current)
    {
        heap_size++;
        current = current->left ? current->left : current->right;
    }
    *size = heap_size;

    /* Allocate memory for the array */
    array = malloc(sizeof(int) * heap_size);
    if (!array)
        return (NULL);

    /* Extract elements from the heap and store them in the array */
    for (i = 0; i < heap_size; i++)
    {
        array[i] = heap_extract(&heap);
    }

    return (array);
}
