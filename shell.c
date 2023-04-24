#include "shell.h"


/**
 * is_sigint - handles interrupt signal raised when Ctrl+C is pressed
 * @elem: unused element
 */

static void is_sigint(int elem)
{
	(void) elem;
	int sig;

	if (sig == 0)
		_puts("\n$ ");
	else
		_puts("\n");
}

/**
 * shell - main function for the shell
 * @argc: arguments passe to function
 * @argv: array of arguments
 * @env: array of environment vars
 *
 * Return: exit status
 */

int shell(int argc __attribute__((unused)), char **argv, char **env)
{
	unsigned int i, vert_bar = 0;
	size_t size_buff = 0;
	vars_t variables = {0, NULL, NULL, NULL, NULL, NULL, 0};

	variables.argv = argv;
	variables.env = create_env(env);
	signal(SIGINT, is_sigint);
	if (!isatty(STDIN_FILENO))
		vert_bar = 1;
	if (vert_bar == 0)
		_puts("$ ");
	sig = 0;
	while (getline(&(variables.buff), &size_buff, stdin) != -1)
	{
		sig = 1;
		variables.amnt++;
		variables.comms = tokenise(variables.buff, ";");

		for (i = 0; variables.comms && variables.comms[i], != NULL; i++)
		{
			variables.av = tokenise(variables.comms[i], "\n \t\r");

			if (variables.av && variables.av[0])
				if (is_builtin(&variables) == NULL)
					in_path(&variables);
			free(variables.av);
		}
		free(variables.buff);
		free(variables.comms);
		sig = 0;

		if (vert_bar == 0)
			_puts("$ ");
		variables.buff = NULL;
	}
	if (vert_bar == 0)
		_puts("\n");
	free_env(variables.env);
	free(variables.buff);
	exit(variables.status);
}
