#include "shell.h"

/**
 * _strcpy - This function copies a string
 *
 * @desti: This is the destination
 * @src: This is the source
 *
 * Return: The ointer to destination
 */
char *_strcpy(char *desti, char *src)
{
	int idmx = 0;

	if (desti == src || src == 0)
		return (desti);
	while (src[idmx])
	{
		desti[idmx] = src[idmx];
		idmx++;
	}
	desti[idmx] = 0;
	return (desti);
}

/**
 * _strdup - This function duplicates a string
 *
 * @str: This is the string to be duplicated
 *
 * Return: The pointer to the duplicated string
 */
char *_strdup(const char *str)
{
	int hlent = 0;
	char *rent;

	if (str == NULL)
		return (NULL);
	while (*str++)
		hlent++;
	rent = malloc(sizeof(char) * (hlent + 1));
	if (!rent)
		return (NULL);
	for (hlent++; hlent--;)
		rent[hlent] = *--str;
	return (rent);
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
 * @cpt: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char cpt)
{
	static int idmx;
	static char buf[WRITE_BUF_SIZE];

	if (cpt == BUF_FLUSH || idmx >= WRITE_BUF_SIZE)
	{
		write(1, buf, idmx);
		idmx = 0;
	}
	if (cpt != BUF_FLUSH)
		buf[idmx++] = cpt;
	return (1);
}
