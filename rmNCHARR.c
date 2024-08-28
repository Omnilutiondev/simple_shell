#include "shell.h"

/**
 * rmNCHARR - This is a function that removes the newline
 * character from the users input
 *
 * @strg: This is the users input
 * @lent: This is the length of the users input
 *
 * Return: Return the command excluding the character with a newline at the end
 */

char *rmNCHARR(char *strg, int lent)
{
	if (strg > 0 && strg[lent - 1] == '\n')
		strg[lent - 1] = '\0';

	return (strg);
}
