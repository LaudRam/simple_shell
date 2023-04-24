#include "shell.h"

/**
 * is_match - checks if a character matches any character in a string
 * @c: character trying to find a match
 * @s: string to check match in
 *
 * Return: 1 if match found, 0 otherwise
 */

unsigned int is_match(char c, const char *s)
{
	unsigned int i;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (c == s[i])
			return (1);
	}
	return (0);
}

/**
 * _strtok - customised strtok to split strings into tokens
 * @s: string to tokenise
 * @delim: delimiter to tokenise against
 *
 * Return: pointer to token or NULL
 */

char *_strtok(char *s, const char *delim)
{
	unsigned int i;
	static char *token_begin, *token_next;

	if (s != NULL)
		token_next = s;

	token_begin = token_next;

	if (token_begin == NULL)
		return (NULL);

	for (i = 0; token_next[i] != '\0'; i++)
	{
		if (is_match(token_next[i], delim) == 0)
			break;
	}
	if (token_next[i] == '\0' || token_next[i] == '#')
	{
		token_next = NULL;
		return (NULL);
	}
	token_begin = token_next + i;
	token_next = token_begin;

	for (i = 0, token_next[i] != '\0'; i++)
	{
		if (is_match(token_next[i], delim) == 1)
			break;
	}
	if (token_next[i] == '\0')
		token_next = NULL;
	else
	{
		token_next[i] = '\0';
		token_next = token_next + i + 1;

		if (*token_next == '\0')
			token_next = NULL;
	}
	return (token_begin);
}
