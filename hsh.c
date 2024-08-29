#include "shell.h"

/**
 * hsh - This function controls the main shell loop
 *
 * @infocont: This is the parameter & return infocont struct
 * @argvmain: This is the argument vector from main()
 *
 * Return: 0 on success, 1 on error, or error code
 */
int hsh(info_t *infocont, char **argvmain)
{
	ssize_t rdx = 0;
	int bill_re = 0;

	while (rdx != -1 && bill_re != -2)
	{
		clear_info(infocont);
		if (interactive(infocont))
			_puts("$ ");
		_eputchar(BUF_FLUSH);
		rdx = get_input(infocont);
		if (rdx != -1)
		{
			set_info(infocont, argvmain);
			bill_re = find_builtin(infocont);
			if (bill_re == -1)
				find_cmd(infocont);
		}
		else if (interactive(infocont))
			_putchar('\n');
		free_info(infocont, 0);
	}
	write_history(infocont);
	free_info(infocont, 1);
	if (!interactive(infocont) && infocont->status)
		exit(infocont->status);
	if (bill_re == -2)
	{
		if (infocont->err_num == -1)
			exit(infocont->status);
		exit(infocont->err_num);
	}
	return (bill_re);
}

/**
 * find_builtin - This function finds a builtin command
 *
 * @infocont: This is the parameter & return infocont struct
 *
 * Return: -1 if builtin not found,
 *			0 if builtin execute is successful,
 *			1 if builtin found but unsuccessful,
 *			-2 if builtin signals exit()
 */
int find_builtin(info_t *infocont)
{
	int idmx, cmd_built = -1;
	builtin_table builtintbl[] = {
		{"exit", _must_exit},
		{"env", _must_env},
		{"help", _must_help},
		{"history", _must_history},
		{"setenv", _must_setenv},
		{"unsetenv", _must_unsetenv},
		{"cd", _must_cd},
		{"alias", _must_alias},
		{NULL, NULL}
	};

	for (idmx = 0; builtintbl[idmx].type; idmx++)
		if (_strcmp(infocont->argv[0], builtintbl[idmx].type) == 0)
		{
			infocont->line_count++;
			cmd_built = builtintbl[idmx].func(infocont);
			break;
		}
	return (cmd_built);
}

/**
 * find_cmd - This function finds a command in PATH
 *
 * @infocont: This is the parameter & return infocont struct
 *
 * Return: void
 */
void find_cmd(info_t *infocont)
{
	char *path = NULL;
	int idmx, kinte;

	infocont->path = infocont->argv[0];
	if (infocont->linecount_flag == 1)
	{
		infocont->line_count++;
		infocont->linecount_flag = 0;
	}
	for (idmx = 0, kinte = 0; infocont->arg[idmx]; idmx++)
		if (!is_delim(infocont->arg[idmx], " \t\n"))
			kinte++;
	if (!kinte)
		return;

	path = find_path(infocont, _getenv(infocont, "PATH="), infocont->argv[0]);
	if (path)
	{
		infocont->path = path;
		fork_cmd(infocont);
	}
	else
	{
		if ((interactive(infocont) || _getenv(infocont, "PATH=")
			|| infocont->argv[0][0] == '/') && is_cmd(infocont, infocont->argv[0]))
			fork_cmd(infocont);
		else if (*(infocont->arg) != '\n')
		{
			infocont->status = 127;
			print_error(infocont, "not found\n");
		}
	}
}

/**
 * fork_cmd - This function forks a an exec thread to run cmd
 *
 * @infocont: This is the parameter & return infocont struct
 *
 * Return: void
 */
void fork_cmd(info_t *infocont)
{
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error: Failed to run");
		return;
	}
	if (child_pid == 0)
	{
		if (execve(infocont->path, infocont->argv, get_environ(infocont)) == -1)
		{
			free_info(infocont, 1);
			if (errno == EACCES)
				exit(126);
			exit(1);
		}
	}
	else
	{
		wait(&(infocont->status));
		if (WIFEXITED(infocont->status))
		{
			infocont->status = WEXITSTATUS(infocont->status);
			if (infocont->status == 126)
				print_error(infocont, "Permission denied\n");
		}
	}
}
