#!/usr/bin/python3
""" Calculates how much retained water """


def rain(walls):
    """ Returns the total amount of rainwater retained """

    if len(walls) == 0:
        return 0

    water = 0
    n = len(walls)

    left = [0] * n
    right = [0] * n
    left[0] = walls[0]
    right[n - 1] = walls[n - 1]

    for i in range(1, n):
        left[i] = max(left[i - 1], walls[i])
    for i in range(n - 2, -1, -1):
        right[i] = max(right[i + 1], walls[i])
    for i in range(n):
        water += min(left[i], right[i]) - walls[i]

    return water
