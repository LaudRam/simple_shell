# 0x16. C - Simple Shel

## Output
* Unless specified otherwise, your program must have the exact same output as sh (/bin/sh) as well as the exact same error output.
* The only difference is when you print an error, the name of the program must be equivalent to your argv[0]

## Compilation
The shell will be compiled this way:

`gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh`

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
