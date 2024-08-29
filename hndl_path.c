#include "shell.h"

/**
 **_strncpy - This function copies a string
 *
 *@deststr: This is the destination strg to be copied to
 *@srcstr: This is the source string
 *@ndx: the amount of characters to be copied
 *
 *Return: the concatenated string
 */

char *_strncpy(char *deststr, char *srcstr, int ndx)
{
	int idx, jdx;
	char *schar = deststr;

	idx = 0;
	while (srcstr[idx] != '\0' && idx < ndx - 1)
	{
		deststr[idx] = srcstr[idx];
		idx++;
	}
	if (idx < ndx)
	{
		jdx = idx;
		while (jdx < ndx)
		{
			deststr[jdx] = '\0';
			jdx++;
		}
	}
	return (schar);
}

/**
 **_strncat - This function concatenates two strings
 *
 *@deststr: This is the first string
 *@srcstr: This is the second string
 *@ndx: This is the amount of bytes to be maximally used
 *
 *Return: The Concat string
 */

char *_strncat(char *deststr, char *srcstr, int ndx)
{
	int idx, jdx;
	char *schar = deststr;

	idx = 0;
	jdx = 0;
	while (deststr[idx] != '\0')
		idx++;
	while (srcstr[jdx] != '\0' && jdx < ndx)
	{
		deststr[idx] = srcstr[jdx];
		idx++;
		jdx++;
	}
	if (jdx < ndx)
		deststr[idx] = '\0';
	return (schar);
}

/**
 **_strchr - This function locates a character in a string
 *
 *@schar: This is the string to be parsed
 *@c: This is the character to look for
 *
 *Return: (schar) a pointer to the memory area schar
 */

char *_strchr(char *schar, char c)
{
	do {
		if (*schar == c)
			return (schar);
	} while (*schar++ != '\0');

	return (NULL);
}
