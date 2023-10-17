#include "main.h"
/**
 * _strlen - the name of the function
 * @s: the function of the parameter
 * Return: length of the string
 */

int _strlen(char *s)
{
	int len;

	len = 0;
	while (*s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}
