#include "shell.h"

/**
 * in_path - function checks if command is in PATH
 * @variables: pointer to structure of variables
 */

void in_path(vars_t *variables)
{
	unsigned int i = 0, j = 0;
	char *look = NULL, *path, *path2 = NULL, **path_tok;
	struct stat buffer;

	if (is_dir(variables->av[0]))
		j = run_comm(variables);

	else
	{
		path = find_path(variables->env);
		if (path != NULL)
		{
			path2 = dup_string(path + 5);
			path_tok = tokenise(path2, ":");
			for (i = 0; path_tok && path_tok[i]; i++, free(look))
			{
				look = join_string(path_tok[i], variables->av[0]);
				if (stat(look, &buffer) == 0)
				{
					j = exe_path(look, variables);
					free(look);
					break;
				}
			}
			free(path2);
			if (path_tok == NULL)
			{
				variables->status = 127;
				mod_exit(variables);
			}
		}
		if (path == NULL || path_tok[i] == NULL)
		{
			is_error(variables, ": not found\n");
			variables->status = 127;
		}
		free(path_tok);
	}
	if (j == 1)
		mod_exit(variables);
}

/**
 * is_dir - function checks if the command contains an absolute path
 * @s: command
 *
 * Return: 1 on success, 0 otherwise
 */

int is_dir(char *s)
{
	unsigned int i;

	for (i = 0; s[i]; i++)
	{
		if (s[i] == '/')
			return (1);
	}
	return (0);
}

/**
 * run_comm - function to execute command in current working directory
 * @variables: pointer to structure of variables
 *
 * Return: 0 on success, 1 otherwise
 */

int run_comm(vars_t *variables)
{
	struct stat buffer;
	pid_t child_pid;

	if (stat(variables->av[0], &buffer) == 0)
	{
		if (access(variables->av[0], X_OK) == 0)
		{
			child_pid = fork();
			if (child_pid == -1)
				is_error(variables, NULL);
			if (child_pid == 0)
			{
				if (execve(variables->av[0], variables->av,
							variables->env) == -1)
					is_error(variables, NULL);
			}
			else
			{
				wait(&variables->status);
				if (WIFEXITED(variables->status))
					variables->status =
						WEXITSTATUS(variables->status);
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
	is_error(variables, ": not found\n");
	variables->status = 127;
	return (0);
}
