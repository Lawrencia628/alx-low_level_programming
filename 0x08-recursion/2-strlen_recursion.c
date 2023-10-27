#include "main.h"

/**
  * _strlen_recursion - this is the main function
  *
  * @s: this is the Function parameter
  *
  * Return: Length
  */
int _strlen_recursion(char *s)
{
	int lnt = 0;

	if (*s)
	{
	lnt++;
	lnt += _strlen_recursion(s + 1);
	}
	return (lnt);
}
