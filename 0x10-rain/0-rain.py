#!/usr/bin/python3
""" Calculates how much retained water """


def rain(walls):
    """ Returns the total amount of rainwater retained """

    if len(walls) == 0:
        return 0

    for i in walls:
        if i < 0:
            return 0

    s = 0
    for i in range(1, len(walls) - 1):
        s += walls[i]
    return s
