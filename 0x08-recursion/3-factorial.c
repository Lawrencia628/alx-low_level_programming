#include "main.h"

/**
  * factorial - this is the main function parameter
  *
  * @n: this is the function parameter
  *
  * Return: Function n.
  */
int factorial(int n)
{
	if (n < 0)
	return (-1);
	if (n == 0)
	return (1);
	return (n * factorial(n - 1));
}
