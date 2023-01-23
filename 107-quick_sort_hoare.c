#include "sort.h"
#include <stdlib.h>
#include <stdlib.h>

/**
 * partition - Will find the partition for the quicksort using
 * the Hoare Scheme
 * @array: The array to sort
 * @lo: The lowest index of the partition to sort
 * @hi: The highest index of the partition to sort
 * @size: The size of the array
 *
 * Return: The index of the partition
 */
size_t partition(int *array, ssize_t lo, ssize_t hi, size_t size)
{
	int swap, pivot;

	pivot = array[hi];
	while (lo <= hi)
	{
		while (array[lo] < pivot)
			lo++;
		while (array[hi] > pivot)
			hi--;
		if (lo <= hi)
		{
			if (lo != hi)
			{
				swap = array[lo];
				array[lo] = array[hi];
				array[hi] = swap;
				print_array(array, size);
			}
			lo++;
			hi--;
		}
	}
	return (hi);
}

/**
 * quicksort - Will sort a partition of an  array of integers
 * @array: The array to sort
 * @lo: The lowest index of the partition to sort
 * @hi: The highest index of the partition to sort
 * @size: The size of the array
 *
 * Return: void
 */
void quicksort(int *array, ssize_t lo, ssize_t hi, size_t size)
{
	ssize_t pivot;

	if (lo < hi)
	{
		pivot = partition(array, lo, hi, size);
		quicksort(array, lo, pivot, size);
		quicksort(array, pivot + 1, hi, size);

	}
}

/**
 * quick_sort_hoare - Will sort an array of integers in ascending order
 * using the Quicksort Algorithm
 * @array: The array to sort
 * @size: The size of the array
 *
 * Return: void
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quicksort(array, 0, size - 1, size);
}
