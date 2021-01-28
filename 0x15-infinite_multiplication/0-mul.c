#include "holberton.h"
#include <stdio.h>
#include <stdlib.h>


/**
* charToInt - converts char to int
* @c: character
* Return: an int
*/
int charToInt(char *c)
{
	int res;
	int sign;
	int i;

	if (*c == '\0')
		return (0);

	res = 0;
	sign = 1;
	i = 0;

	if (c[0] == '-')
	{
		sign = -1;
		i++;
	}

	for (; c[i] != '\0'; ++i)
	{
		if (c[i] < '0' || c[i] > '9')
			return (0);

		res = res * 10 + c[i] - '0';
	}

	return (sign * res);
}


/**
* main - multiplies two numbers
* @argc: arguments count
* @argv: arguments array
* Return: Always 0
*/
int main(int argc, char *argv[])
{
	char *msg = "Error\n";
	int a, b, m;

	if (argc != 3)
	{
		while (*msg)
		{
			_putchar(*msg);
			msg++;
		}
		return (EXIT_FAILURE);
	}

	a = charToInt(argv[1]);
	b = charToInt(argv[2]);

	m = a * b;

	printf("%d\n", m);


	return (0);
}
