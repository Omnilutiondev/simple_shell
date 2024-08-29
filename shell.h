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

#define CMD_NORM	0
#define CMD_OR		1
#define CMD_AND		2
#define CMD_CHAIN	3

#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2

#define USE_GETLINE 0
#define USE_STRTOK 0

#define HIST_FILE	".simple_shell_history"
#define HIST_MAX	4096

extern char **environ;



/**
 *struct passinfo - This contains pseudo-arguements to pass into a function,
 *allowing uniform prototype for function pointer struct
 *@arg: This is the string generated from getline containing arguements
 *@argv: This is an array of strings generated from arg
 *@path: This is the string path for the current command
 *@argc: This is the argument count
 *@line_count: This is the error count
 *@err_num: This is the error code for exit()s
 *@linecount_flag: Only if on count this line of input
 *@fname: This is the program filename
 *@env: This is the linked list local copy of environ
 *@environ: This is the custom modified copy of environ from LL env
 *@history: This is the history node
 *@alias: This is the alias node
 *@env_changed: This is on if environ was changed
 *@status: This is the return status of the last exec'd command
 *@cmd_buf: This is the address of pointer to cmd_buf, on if chaining
 *@cmd_buf_type: This is the CMD_type ||, &&, ;
 *@readfd: This is the fd to read line input from
 *@histcount: This is the history line number count
 */
typedef struct passinfo
{
	char *arg;
	char **argv;
	char *path;
	int argc;
	unsigned int line_count;
	int err_num;
	int linecount_flag;
	char *fname;
	list_t *env;
	list_t *history;
	list_t *alias;
	char **environ;
	int env_changed;
	int status;

	char **cmd_buf;
	int cmd_buf_type;
	int readfd;
	int histcount;
} info_t;

#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
	0, 0, 0}

int readmyCommand(void);


int _strlen(char *bs);
int _strcmp(char *bs1, char *bs2);
char *starts_with(const char *input, const char *data);
char *_strcat(char *destbuf, char *srcbuf);

char *_strcpy(char *destiny, char *srcstr);
char *_strdup(const char *strdup);
void _puts(char *strdup);
int _putchar(char cprnt);

char *_strncpy(char *deststr, char *srcstr, int ndx);
char *_strncat(char *deststr, char *srcstr, int ndx);
char *_strchr(char *schar, char c);

char **strtow(char *str, char *g);
char **strtow2(char *str, char g);


char *cmdlineint(char *strg, int lent);

#endif
