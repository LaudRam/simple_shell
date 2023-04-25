#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <limits.h>
#include <signal.h>

/*========== Structures ==========*/

/**
 * struct variables - structure for variables
 * @status: exit status
 * @buff: buffer for command
 * @comms: commands passed
 * @env: variables for environment
 * @av: command line arguments
 * @argv: arguments at start of shell
 * @amnt: amount of commands entered
 */

typedef struct variables
{
	int status;
	char *buff;
	char **comms;
	char **env;
	char **av;
	char **argv;
	size_t amnt;
} vars_t;

/**
 * struct builtins - structure for builtins
 * @tag: name of builtin command
 * @func: function for corresponding builtin
 */

typedef struct builtins
{
	char *tag;
	void (*func)(vars_t *);
} builtins_t;

/*========== _strtok ==========*/

unsigned int is_match(char c, const char *s);
char *_strtok(char *s, const char *delim);

/*========== builtins ==========*/

void del_env(vars_t *variables);
void new_env(vars_t *variables);
void print_env(vars_t *variables);
void mod_exit(vars_t *variables);
char *add_envstr(char *cue, char *value);
void add_new_env(vars_t *variables);
char **find_new_env(char **env, char *cue);
int mod_atoi(char *s);
void (*is_builtin(vars_t *variables))(vars_t *variables);

/*========== environment and errors ==========*/

char **create_env(char **env);
void free_env(char **env);
char *uint_to_str(unsigned int unum);
void err_puts(char *s);
void is_error(vars_t *variables, char *txt);

/*========== execute ==========*/

char *find_path(char **env);
int exe_path(char *comm, vars_t *variables);
void in_path(vars_t *variables);
int is_dir(char *s);
int run_comm(vars_t *variables);

/*========== strman ==========*/

int comp_string(char *s1, char *s2);
char *dup_string(char *s);
char *join_string(char *s1, char *s2);
unsigned int len_string(char *s);
ssize_t _puts(char *s);

/*========== memory and tokeniser ==========*/

char **arr_realloc(char **pointer, size_t *size);
char **tokenise(char *buff, char *delim);

/*========== main function ==========*/

int main(int argc __attribute__((unused)), char **argv, char **enviro);

#endif
