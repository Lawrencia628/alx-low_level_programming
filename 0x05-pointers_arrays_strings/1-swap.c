#include "main.h"
/**
 * swap_int - this is the name of the function
 * @a- let this be the first parameter
 * @b- let this be the second parameter
 */

void swap_int(int *a, int *b)
{
int c;
c = *a;
*a = *b;
*b = c;
}
