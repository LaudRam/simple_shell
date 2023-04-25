#include "shell.h"

/**
 * comp_string - compares two strings
 * @s_c1: first string to compare
 * @s_c2: second string to compare
 *
 * Return: 0 on success
 */

int comp_string(char *s_c1, char *s_c2)
{
	int i = 0;

	while (s_c1[i] == s_c2[i])
	{
		if (s_c1[i] == '\0')
			return (0);
		i++;
	}
	return (s_c1[i] - s_c2[i]);
}

/**
 * dup_string - duplicates a string
 * @s_dup: string to be duplicated
 *
 * Return: pointer to new duplicated string
 */

char *dup_string(char *s_dup)
{
	char *dup;
	int i, size;

	if (s_dup == 0)
		return (NULL);

	for (size = 0; s_dup[size]; size++)
		;

	dup = malloc((size + 1) * sizeof(char));

	for (i = 0; i <= size; size++)
		dup[i] = s_dup[i];

	return (dup);
}

/**
 * join_string - joins two strings
 * @s_j1: first string
 * @s_j2: second string
 *
 * Return: new string
 */

char *join_string(char *s_j1, char *s_j2)
{
	unsigned int i, j, len1 = 0, len2 = 0, new_len;
	char *new_str;

	if (s_j1 == NULL)
		len1 = 0;

	else
	{
		for (len1 = 0; s_j1[len1]; len1++)
			;
	}

	if (s_j2 == NULL)
		len2 = 0;
	else
	{
		for (len2 = 0; s_j2[len2]; len2++)
			;
	}
	new_len = len1 + len2 + 2;
	new_str = malloc(new_len * sizeof(char));

	if (new_str == NULL)
		return (NULL);
	for (i = 0; i < len1; i++)
		new_str[i] = s_j1[i];
	new_str[i] = '/';
	for (j = 0; j < len2; j++)
		new_str[i + j + 1] = s_j2[j];
	new_str[len1 + len2 + 1] = '\0';

	return (new_str);
}

/**
 * len_string - checks length of a string
 * @s: string to check
 *
 * Return: length of string
 */

unsigned int len_string(char *s)
{
	unsigned int len = 0;

	for (len = 0; s[len]; len++)
		;
	return (len);
}

/**
 * _puts - custom puts, writes a string to stdout
 * @s: string to be written
 *
 * Return: number of chars printed, otherwise -1
 */

ssize_t _puts(char *s)
{
	ssize_t size, num;

	size = len_string(s);
	num = write(STDOUT_FILENO, s, size);

	if (num != size)
	{
		perror("Fatal Error");
		return (-1);
	}
	return (num);
}
