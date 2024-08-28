#ifndef SHELL_H
#define SHELL_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <errno.h>
#include <signal.h>
#include <limits.h>
#include <fcntl.h>

#define MAX_C 10
#define BUFSIZE 1024
#define TOK_BUFFSIZE 128
#define TOK_DELIM " \t\r\n\a"


int readmyCommand(void);
char *cmdlineint(char *strg, int lent);

#endif
