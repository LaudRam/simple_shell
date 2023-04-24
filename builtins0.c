#include "shell.h"

/**
 * del_env - function removes an environment variable
 * @variables: pointer to a structure of variables
 */

void del_env(vars_t *variables)
{
	unsigned int i, j;
	char **cue, **new;

	if (variables->av[1] == NULL)
	{
		is_error(variables, ": Incorrect number of arguments\n");
		variables->status = 2;
		return;
	}

	cue = find_new_env(variables->env, variables->av[1]);

	if (cue == NULL)
	{
		is_error(variables, ": No variable to unset");
		return;
	}

	for (i = 0; variables->env[i] != NULL; i++)
		;

	new = malloc(i * sizeof(char *));

	if (new == NULL)
	{
		is_error(variables, NULL);
		variables->status = 127;
		mod_exit(variables);
	}

	for (i = 0; variables->env[i] != *cue; i++)
		new[i] = variables->env[i];
	for (j = i + 1; variables->env[j] != NULL; j++, i++)
		new[i] = variables->env[j];

	new[i] = NULL;
	free(*cue);
	free(variables->env);
	variables->env = new;
	variables->status = 0;
}

/**
 * new_env - function creates a new environment variable or modifies existing
 * @variables: pointer to a structure of variables
 */

void new_env(vars_t *variables)
{
	char **cue, *env_var;

	if (variables->av[1] == NULL || variables->av[2] == NULL)
	{
		is_error(variables, ": Incorrect number of arguments\n");
		variables->status = 2;
		return;
	}

	cue = find_new_env(variables->env, variables->av[1]);

	if (cue == NULL)
		add_new_env(variables);

	else
	{
		env_var = add_envstr(variables->av[1], variables->av[2]);

		if (env_var == NULL)
		{
			is_error(variables, NULL);
			free(variables->buff);
			free(variables->comms);
			free(variables->av);
			free(variables->env);
			exit(127);
		}
		free(*cue);
		*cue = env_var;
	}
	variables->status = 0;
}

/**
 * print_env - function prints curent environment
 * @variables: pointer to a structure of variables
 */

void print_env(vars_t *variables)
{
	unsigned int i;

	for (i = 0; variables->env[i]; i++)
	{
		_puts(variables->env[i]);
		_puts("\n");
	}

	variables->status = 0;
}

/**
 * mod_exit - function for exiting program
 * @variables: pointer to a structure of variables
 */

void mod_exit(vars_t *variables)
{
	int status;

	if (comp_string(variables->av[0], "exit") == 0 && variables->av[1] != NULL)
	{
		status = mod_atoi(variables->av[1]);

		if (status == -1)
		{
			variables->status = 2;
			is_error(variables, ": Illegal number: ");
			err_puts(variables->av[1]);
			err_puts("\n");
			free(variables->comms);
			variables->comms = NULL;
			return;
		}
		variables->status = status;
	}
	free(variables->buff);
	free(variables->av);
	free(variables->comms);
	free_env(variables->env);
	exit(variables->status);
}
