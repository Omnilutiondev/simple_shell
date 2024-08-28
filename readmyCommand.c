#include "shell.h"

/**
 * readmyCommand - This function takes users input
 *
 * Return: Returns the number of chars read inside
 * the standard input
 */

int readmyCommand(void)

{
	size_t n = 0;
	char *buff = NULL, *commandz;
	int size;

	size = getline(&buff, &n, stdin);
	if (size == -1)
	{
		if (feof(stdin))
		{
			free(buff);
			exit(0);
		}
		else
		{
		perror("Failed: Cannot read user input");
		free(buff);
		}
	}

	commandz = cmdlineint(buff, size);
	printf("%s", commandz);

	free(buff);
	return (size);
}
