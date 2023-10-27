#include "main.h"
/**
  * _pow_recursion - this is the function name
  * @x: let this be parameter 1
  * @y: let this be parameter 2
  * Return: let this be the value of a given number passed to the function
  */


int _pow_recursion(int x, int y)
{

if (y < 0)
	return (-1);

else if (y == 0)
	return (1);

else
	return (x * _pow_recursion(x, (y - 1)));

return (0);
}
