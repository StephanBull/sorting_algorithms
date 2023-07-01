#include "sort.h"
/**
 * swap_integers - swaps two integersin an array
 * @a: first integer
 * @b: second integer
 */
void swap_integers(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * bubble_sort - sorts an array of integers in ascending order
 * @array: array of integers
 * @size: size of the array
 *
 * Description:prints an  array each time you swap two elements
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, len = size;
	bool bubbly = false;

	if (array == NULL || size < 2)
		return;

	while (bubbly == false)
	{
		bubbly = true;
		for (i = 0; i < len - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				swap_integers(array + i, array + i + 1);
				print_array(array, size);
				bubbly = false;
			}
		}
		len--;
	}
}
