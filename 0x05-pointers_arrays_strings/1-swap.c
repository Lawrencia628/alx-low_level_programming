#include "main.h"
/**
 * swap_int - this is the name of the function
 * @a: the first parameter
 * @b: the second parameter
 */

void swap_int(int *a, int *b)
{
int c;
c = *a;
*a = *b;
*b = c;
}
