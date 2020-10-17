#include "palindrome.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
* is_palindrome -  checks whether or not a given unsigned
* integer is a palindrome
* @n: unsigned long int
* Return: 1 if n is a palindrome, and 0 otherwise.
*/
int is_palindrome(unsigned long n)
{
	/* This method takes more time to finish
	* int i, j;
	char buffer[21];
	(void)(n);

	sprintf(buffer, "%lu", n);

	j = strlen(buffer) - 1;
	for (i = 0; i <= j; i++)
	{
		if (buffer[i] != buffer[j])
			return (0);
		j--;
	}
	return (1);
	*/

	unsigned long i, sum, rest;

	sum = 0;
	for (i = n; n != 0; n = n / 10)
	{
		rest = n % 10;
		sum = sum * 10 + rest;
	}

	if (i != sum)
		return (0);

	return (1);

}
