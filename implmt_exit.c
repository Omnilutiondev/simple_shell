
#include "shell.h"

/**
 * **strtow - This function splits a string into words.
 * Repeat delimiters are ignored
 *
 * @str: This is the input string
 * @g: the delimeter string
 * Return: The pointer to an array of strings, or NULL on failure
 */

char **strtow(char *str, char *g)
{
	int idx, jdx, kdx, mdx, nbwd = 0;
	char **schar;

	if (str == NULL || str[0] == 0)
		return (NULL);
	if (!g)
		g = " ";
	for (idx = 0; str[idx] != '\0'; idx++)
		if (!is_delim(str[idx], g) && (is_delim(str[idx + 1], g) || !str[idx + 1]))
			nbwd++;

	if (nbwd == 0)
		return (NULL);
	schar = malloc((1 + nbwd) * sizeof(char *));
	if (!schar)
		return (NULL);
	for (idx = 0, jdx = 0; jdx < nbwd; jdx++)
	{
		while (is_delim(str[idx], g))
			idx++;
		kdx = 0;
		while (!is_delim(str[idx + kdx], g) && str[idx + kdx])
			kdx++;
		schar[jdx] = malloc((kdx + 1) * sizeof(char));
		if (!schar[jdx])
		{
			for (kdx = 0; kdx < jdx; kdx++)
				free(schar[kdx]);
			free(schar);
			return (NULL);
		}
		for (mdx = 0; mdx < kdx; mdx++)
			schar[jdx][mdx] = str[idx++];
		schar[jdx][mdx] = 0;
	}
	schar[jdx] = NULL;
	return (schar);
}

/**
 * **strtow2 - This function splits a string into words
 *
 * @str: the input string
 * @g: the delimeter
 *
 * Return: a pointer to an array of strings, or NULL on failure
 */

char **strtow2(char *str, char g)
{
	int idx, jdx, kdx, mdx, nbwd = 0;
	char **schar;

	if (str == NULL || str[0] == 0)
		return (NULL);
	for (idx = 0; str[idx] != '\0'; idx++)
		if ((str[idx] != g && str[idx + 1] == g) ||
		    (str[idx] != g && !str[idx + 1]) || str[idx + 1] == g)
			nbwd++;
	if (nbwd == 0)
		return (NULL);
	schar = malloc((1 + nbwd) * sizeof(char *));
	if (!schar)
		return (NULL);
	for (idx = 0, jdx = 0; jdx < nbwd; jdx++)
	{
		while (str[idx] == g && str[idx] != g)
			idx++;
		kdx = 0;
		while (str[idx + kdx] != g && str[idx + kdx] && str[idx + kdx] != g)
			kdx++;
		schar[jdx] = malloc((kdx + 1) * sizeof(char));
		if (!schar[jdx])
		{
			for (kdx = 0; kdx < jdx; kdx++)
				free(schar[kdx]);
			free(schar);
			return (NULL);
		}
		for (mdx = 0; mdx < kdx; mdx++)
			schar[jdx][mdx] = str[idx++];
		schar[jdx][mdx] = 0;
	}
	schar[jdx] = NULL;
	return (schar);
}
