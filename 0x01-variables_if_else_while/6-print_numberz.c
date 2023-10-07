#include <stdio.h>


/**
 * main - program that printsall single digit numbers of base ten
 *
 * Return: Always 0.
 */

int main(void)
{
	int number;

	for (number = '0'; number <= '9'; number++)

	{
	if (number != '4' && number != '8')
	putchar(number);
	}

	putchar('\n');

	return (0);
}
