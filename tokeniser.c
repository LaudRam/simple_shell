#include "shell.h"

/**
 * tokenise - tokenises a buffer with a delimiter
 * @buff: buffer to be tokenised
 * @delim: delimiter to tokenise with
 *
 * Return: pointer to array of pointers, to the tokens
 */

char **tokenise(char *buff, char *delim)
{
	char **tokens = NULL;
	size_t x = 0, counter = 10;

	if (buff == NULL)
		return (NULL);

	tokens = malloc(counter * sizeof(char *));

	if (tokens == NULL)
	{
		perror("Fatal Error");
		return (NULL);
	}
	while ((tokens[x] = _strtok(buff, delim)) != NULL)
	{
		x++;
		if (x == counter)
		{
			tokens = arr_realloc(tokens, &counter);

			if (tokens == NULL)
			{
				perror("Fatal Error");
				return (NULL);
			}
		}
		buff = NULL;
	}
	return (tokens);
}
