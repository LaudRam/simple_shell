#include "shell.h"

/**
 * arr_realloc - custom realloc function
 *		to reallocate memory of arrays of pointrs
 *
 * @pointer: pointer to original array
 * @amnt: pointer to number of elements in original array
 *
 * Return: pointer to new array
 */

char **arr_realloc(char **pointer, size_t *amnt)
{
	char **new_arr;
	size_t x;

	new_arr = malloc(((*amnt) + 10) * sizeof(char *));

	if (new_arr == NULL)
	{
		free(pointer);
		return (NULL);
	}

	for (x = 0; x < (*amnt); x++)
	{
		new_arr[x] = pointer[x];
	}

	*amnt += 10;
	free(pointer);
	return (new_arr);
}
