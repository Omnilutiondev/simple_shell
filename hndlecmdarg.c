#include "shell.h"

/**
 * _strcpy - This function copies a string
 *
 * @destiny: This is the destination
 * @srcstr: This is the source
 *
 * Return: The ointer to destination
 */
char *_strcpy(char *destiny, char *srcstr)
{
	int idmx = 0;

	if (destiny == srcstr || srcstr == 0)
		return (destiny);
	while (srcstr[idmx])
	{
		destiny[idmx] = srcstr[idmx];
		idmx++;
	}
	destiny[idmx] = 0;
	return (destiny);
}

/**
 * _strdup - This function duplicates a string
 *
 * @strdup: This is the string to be duplicated
 *
 * Return: The pointer to the duplicated string
 */
char *_strdup(const char *str)
{
	int hlent = 0;
	char *ret;

	if (str == NULL)
		return (NULL);
	while (*str++)
		hlent++;
	ret = malloc(sizeof(char) * (hlent + 1));
	if (!ret)
		return (NULL);
	for (hlent++; hlent--;)
		ret[hlent] = *--str;
	return (ret);
}

/**
 *_puts - This function prints an input string
 *
 *@strdup: This is the string to be printed
 *
 * Return: Nothing
 */
void _puts(char *str)
{
	int idmx = 0;

	if (!str)
		return;
	while (str[idmx] != '\0')
	{
		_putchar(str[idmx]);
		idmx++;
	}
}

/**
 * _putchar - This function writes the character cprnt to stdout
 *
 * @cprnt: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char cprnt)
{
	static int idmx;
	static char buf[WRITE_BUF_SIZE];

	if (cprnt == BUF_FLUSH || idmx >= WRITE_BUF_SIZE)
	{
		write(1, buf, idmx);
		idmx = 0;
	}
	if (cprnt != BUF_FLUSH)
		buf[idmx++] = cprnt;
	return (1);
}
