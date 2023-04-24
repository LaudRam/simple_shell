#include "shell.h"

/**
 * is_builtin - checks if the command passed is a builtin
 * @variables: variables
 *
 * Return: pointer to funcion else NULL
 */

void (*is_builtin(vars_t *variables))(vars_t *variables)
{
	unsigned int i;

	builtins_t look[] = {
		{"unsetenv", del_env};
		{"setenv", new_env};
		{"env", print_env};
		{"exit", mod_exit};
		{NULL, NULL};
	};

	for (i = 0; look[i].func != NULL; i++)
	{
		if (comp_string(variables->av[0], look[i].tag) == 0)
			break;
	}

	if (look[i].func != NULL)
		look[i].func(variables);

	return (look[i].func);
}
