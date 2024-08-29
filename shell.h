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


#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1


int readmyCommand(void);


int _strlen(char *bs);
int _strcmp(char *bs1, char *bs2);
char *starts_with(const char *input, const char *data);
char *_strcat(char *destbuf, char *srcbuf);

char *_strcpy(char *desti, char *src);
char *_strdup(const char *str);
void _puts(char *strdup);
int _putchar(char cpt);

char *_strncpy(char *deststr, char *srcstr, int ndx);
char *_strncat(char *deststr, char *srcstr, int ndx);
char *_strchr(char *schar, char c);

char **strtow(char *str, char *g);
char **strtow2(char *str, char g);


char *cmdlineint(char *strg, int lent);

#endif
