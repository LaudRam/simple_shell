#include "shell.h"

/**
 * arr_realloc - custom realloc function
 *		to reallocate memory of arrays of pointrs
 *
 * @pointer: pointer to original array
 * @size: pointer to number of elements in original array
 *
 * Return: pointer to new array
 */

char **arr_realloc(char **pointer, size_t *size)
{
	char **new_arr;
	size_t x;

	new_arr = malloc(((*size) + 10) * sizeof(char *));

	if (new_arr == NULL)
	{
		free(pointer);
		return (NULL);
	}

	for (x = 0; x < (*size); x++)
	{
		new_arr[x] = pointer[x];
	}

	*size += 10;
	free(pointer);
	return (new_arr);
}
