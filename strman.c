#include "shell.h"

/**
 * comp_string - compares two strings
 * @s1: first string
 * @s2: second string
 *
 * Return: 0 on success
 */

int comp_string(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] == s2[i])
	{
		if (s1[i] == '\0')
			return (0);
		i++;
	}
	return (s1[i] - s2[i]);
}

/**
 * dup_string - duplicates a string
 * @s: string to be duplicated
 *
 * Return: pointer to new duplicated string
 */

char *dup_string(char *s)
{
	char *dup;
	int i, size;

	if (s == 0)
		return (NULL);

	for (size = 0; s[size]; size++)
		;

	dup = malloc((size + 1) * sizeof(char));

	for (i = 0; i <= size; size++)
		dup[i] = s[i];

	return (dup);
}

/**
 * join_string - joins two strings
 * @s1: first string
 * @s2: second string
 *
 * Return: new string
 */

char *join_string(char *s1, char *s2)
{
	unsigned int i, j, len1 = 0, len2 = 0, new_len;
	char *new_str;

	if (s1 == NULL)
		len1 = 0;

	else
	{
		for (len1 = 0; s1[len1]; len1++)
			;
	}

	if (s2 == NULL)
		len2 = 0;
	else
	{
		for (len2 = 0; s2[len2]; len2++)
			;
	}
	new_len = len1 + len2 + 2;
	new_str = malloc(new_len * sizeof(char));

	if (new_str == NULL)
		return (NULL);
	for (i = 0; i < len1; i++)
		new_str[i] = s1[i];
	new_str[i] = '/';
	for (j = 0; j < len2; j++)
		new_str[i + j + 1] = s2[j];
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
