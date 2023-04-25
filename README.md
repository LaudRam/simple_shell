# 0x16. C - Simple Shell

## Files

* [AUTHORS](AUTHORS) - List of contributors to repo
* [README.md](README.md) - Info on project
* [_strtok.c](_strtok.c) - Breaks strings into tokens
* [builtins0.c](builtins0.c) & [builtins1.c](builtins1.c) - Related to shell builtins
* [enviro.c](enviro.c) - Related to creating the environment, etc.
* [err.c](err.c) - Printing errors
* [execute0.c](execute0.c) & [execute1.c](execute1.c) - Functions for executing commands
* [is_builtin.c](is_builtin.c) - Checks if user input matches any builtins
* [memory.c](memory.c) - Memory allocation
* [shell.c](shell.c) - Main shell function
* [shell.h](shell.h) - Project header file
* [strman.c](strman.c) - Functions for string manipulation
* [tokeniser.c](tokeniser.c) - Creates tokens

## Output
* Unless specified otherwise, your program must have the exact same output as sh (/bin/sh) as well as the exact same error output.
* The only difference is when you print an error, the name of the program must be equivalent to your argv[0]

## Compilation
The shell will be compiled this way:

```
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```

## Testing
Your shell should work like this in interactive mode:
```
$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$
```
But also in non-interactive mode:
```
$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls2
$
$ cat test_ls2
/bin/ls
/bin/ls
$
$ cat test_ls2 | ./hsh
hsh main.c shell.c test_ls2
hsh main.c shell.c test_ls2
$
```
