#include "shell.h"

/**
 * cmdlineint - This is a function that removes the newline
 * character from the users input
 *
 * @strg: This is the users input
 * @lent: This is the length of the users input
 *
 * Return: Return the command excluding the character with a newline at the end
 */

char *cmdlineint(char *strg, int lent)
{
	if (lent > 0 && strg[lent - 1] == '\n')
		strg[lent - 1] = '\0';

	return (strg);
}
