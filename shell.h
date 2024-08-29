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
#define BUF_FLUSH -1


int readmyCommand(void);
int _strlen(char *bs);
int _strcmp(char *bs1, char *bs2);
char *start_with(const char *input, const char *data);
char *_strcat(char *destbuf, char *srcbuf);
char *cmdlineint(char *strg, int lent);

#endif
