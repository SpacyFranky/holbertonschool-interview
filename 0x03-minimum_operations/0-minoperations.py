#!/usr/bin/python3
"""
Minimum Operations
"""


def minOperations(n):
    """ Calculates the fewest number of operations needed to result
        in exactly n H characters in the file
    """
    if (n < 2):
        return 0
    if (type(n) is not int):
        return 0

    n_op = 0
    copy_all = 1
    h = 1
    while (n > h):
        if (n % h == 0):
            copy_all = h
            h *= 2
            n_op += 2
        else:
            h += copy_all
            n_op += 1

    return n_op
