#include "shell.h"

/**
 * add_envstr - function creates an environment variable string
 * @cue: variable name
 * @value: value of variable
 *
 * Return: pointer to created string
 */

char *add_envstr(char *cue, char *value)
{
	unsigned int i, j, c_size, v_size;
	char *new;

	c_size = len_string(cue);
	v_size = len_string(value);
	new = malloc((c_size + v_size + 2) * sizeof(char));

	if (new == NULL)
		return (NULL);

	for (i = 0; cue[i] != '\0'; i++)
		new[i] = cue[i];

	new[i] = '=';

	for (j = 0; value[j] != '\0'; j++)
		new[j + i + 1] = value[j];

	new[j + i + 1] = '\0';

	return (new);
}

/**
 * add_new_env - fuction creates new environment variable
 * @variables: pointer to structure of variables
 */

void add_new_env(vars_t *variables)
{
	unsigned int i;
	char **new;

	for (i = 0; variables->env[i] != NULL; i++)
		;

	new = malloc((i + 2) * sizeof(char *));

	if (new == NULL)
	{
		is_error(variables, NULL);
		variables->status = 127;
		mod_exit(variables);
	}
	for (i = 0; variables->env[i] != NULL; i++)
		new[i] = variables->env[i];

	new[i] = add_envstr(variables->av[1], variables->av[2]);

	if (new[i] == NULL)
	{
		is_error(variables, NULL);
		free(variables->buff);
		free(variable->av);
		free(variables->comms);
		free_env(new);
		exit(127);
	}

	new[i + 1] = NULL;
	free(variables->env);
	variables->env = new;
}

/**
 * find_new_env - function finds environment variable
 * @env: environment variables array
 * @cue: variable to find
 *
 * Return: pointer to address of variable
 */

char **find_new_env(char **env, char *cue)
{
	unsigned int i, j, size;

	size = len_string(cue);

	for (i = 0; env[i] != NULL; i++)
	{
		for (j = 0; j < size; j++)

			if (cue[j] != env[i][j])
				break;

		if (j == size && env[i][j] == '=')
			return (&env[i]);
	}
	return (NULL);
}

/**
 * mod_atoi - function converts strings into non-negative integers
 * @s: string to convert
 *
 * Return: integer, or -1 on failure
 */

int mod_atoi(char *s)
{
	int num = 0, temp;
	unsigned int i, j;

	temp = INT_MAX;

	for (j = 0; temp != 0; j++)
		temp /= 10;

	for (i = 0; s[i] != '\0' && i < j; i++)
	{
		num *= 10;

		if (s[i] < '0' || s[i] > '9')
			return (-1);
		if ((i == j - 1) && (s[i] - '0' > INT_MAX % 10))
			return (-1);

		num += s[i] - '0';

		if ((i == j - 2) && (s[i + 1] != '\0') && (num > INT_MAX / 10))
			return (-1);
	}
	if (i > j)
		return (-1);
	return (num);
}
