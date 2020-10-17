#include "palindrome.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
* is_palindrome -  checks whether or not a given unsigned
* integer is a palindrome
* @n: unsigned long int
* Retun: 1 if n is a palindrome, and 0 otherwise.
*/
int is_palindrome(unsigned long n)
{       
        int i, j;
        char buffer[sizeof(unsigned long) * 8 + 1];
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
}
