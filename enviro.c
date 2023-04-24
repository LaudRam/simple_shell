#include "shell.h"

/**
 * create_env - creates shell environment from the parent environment, to main
 * @env: environment passed to main
 *
 * Return: pointer to new environment
 */

char **create_env(char **env)
{
	char **new_env = NULL;
	size_t x;

	for (x = 0; env[x] != NULL; x++)
		;
	new_env = malloc((x + 1) * sizeof(char *));

	if (new_env == NULL)
	{
		perror("Fatal Error");
		exit(1);
	}

	for (x = 0; env[x] != NULL; x++)
		new_env[x] = dup_string(env[x]);

	new_env[x] = NULL;
	return (new_env);
}

/**
 * free_env - frees the shell environment
 * @env: shell environment
 */

void free_env(char **env)
{
	unsigned int i;

	for (i = 0; env[i] != NULL; i++)
		free(env[i]);
	free(env);
}
