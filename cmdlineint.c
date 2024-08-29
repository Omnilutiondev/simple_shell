#include "shell.h"

/**
 * _strlen - This function returns the length of a string
 *
 * @bs: This the string whose length will be checked
 *
 * Return: integer length of string
 */
int _strlen(char *bs)
{
	int idx = 0;

	if (!bs)
		return (0);

	while (*bs++)
		idx++;
	return (idx);
}

/**
 * _strcmp - This function will perform comparison of two strangs.
 *
 * @bs1: This is the first strang
 * @bs2: This is the second strang
 *
 * Return: negative if bs1 < bs2, positive if bs1 > bs2, zero if bs1 == bs2
 */
int _strcmp(char *bs1, char *bs2)
{
	while (*bs1 && *bs2)
	{
		if (*bs1 != *bs2)
			return (*bs1 - *bs2);
		bs1++;
		bs2++;
	}
	if (*bs1 == *bs2)
		return (0);
	else
		return (*bs1 < *bs2 ? -1 : 1);
}

/**
 * start_with - This function checks if input starts with data
 *
 * @input: This is the string to search
 * @data: This is the substring to find
 *
 * Return: address of next char of haystack or NULL
 */
char *start_with(const char *input, const char *data)
{
	while (*data)
		if (*data++ != *input++)
			return (NULL);
	return ((char *)input);
}

/**
 * _strcat - This function concatenates two strings
 *
 * @destbuf: This is the destination buffer
 * @srcbuf: This is the source buffer
 *
 * Return: The pointer to destination bufr
 */
char *_strcat(char *destbuf, char *srcbuf)
{
	char *ret = destbuf;

	while (*destbuf)
		destbuf++;
	while (*srcbuf)
		*destbuf++ = *srcbuf++;
	*destbuf = *srcbuf;
	return (ret);
}
