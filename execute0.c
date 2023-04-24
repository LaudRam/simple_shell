#include "shell.h"

/**
 * find_path - function finds and returns path variable
 * @env: array of environment variables
 *
 * Return: path variable, otherwise NULL
 */

char *find_path(char **env)
{
	unsigned int i, j;
	char *path = "PATH=";

	for (i = 0; env[i] != NULL; i++)
	{
		for (j = 0; j < 5; j++)
			if (path[j] != env[i][j])
				break;
		if (j == 5)
			break;
	}
	return (env[i]);
}

/**
 * exe_path - function executes commands in the path
 * @comm: full path to the command
 * @variables: pointer to a structure of variables
 *
 * Return: 0 on success, 1 otherwise
 */

int exe_path(char *comm, vars_t *variables)
{
	pid_t child_pid;

	if (access(comm, X_OK) == 0)
	{
		child_pid = fork();

		if (child_pid == -1)
			is_error(variables, NULL);

		if (child_pid == 0)
		{
			if (execve(comm, variables->av, variables->env) == -1)
				is_error(variables, NULL);
		}
		else
		{
			wait(&variables->status);

			if (WIFEXITED(variables->status))
				variables->status = WEXITSTATUS(variables->status);

			else if (WIFSIGNALED(variables->status) &&
					WTERMSIG(variables->status) == SIGINT)
				variables->status = 130;
			return (0);
		}
		variables->status = 127;
		return (1);
	}
	else
	{
		is_error(variables, ": Permission denied\n");
		variables->status = 126;
	}
	return (0);
}
