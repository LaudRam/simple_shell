#include "shell.h"

/**
 * uint_to_str - converts unsigned integers into strings
 * @unum: unsigned int to convert
 *
 * Return: pointer to string
 */

char *uint_to_str(unsigned int unum)
{
	unsigned int temp, figs;
	char *int_str;

	temp = unum;
	for (figs = 0; temp != 0; figs++)
		temp /= 10;

	int_str = malloc((figs + 1) * sizeof(char));

	if (int_str == NULL)
	{
		perror("Fatal Error1");
		exit(127);
	}
	int_str[figs] = '\0';

	for (--figs; unum; --figs)
	{
		int_str[figs] = (unum % 10) + '0';
		unum /= 10;
	}
	return (int_str);
}

/**
 * err_puts - prints a string to STDERR
 * @s: string to be printed
 */

void err_puts(char *s)
{
	ssize_t len, num;

	num = len_string(s);
	len = write(STDERR_FILENO, s, num);

	if (len != num)
	{
		perror("Fatal Error");
		exit(1);
	}
}

/**
 * is_error - for printing error messages
 * @variables: pointer to structure of variables
 * @txt: error message to print
 */

void is_error(vars_t *variables, char *txt)
{
	char *amount;

	err_puts(variables->argv[0]);
	err_puts(": ");
	amount = unint_to_str(variables->amount);
	err_puts(amount);
	free(amount);
	err_puts(": ");
	err_puts(variables->av[0]);

	if (txt)
	{
		err_puts(txt);
	}
	else
		perror("");
}
