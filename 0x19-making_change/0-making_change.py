#!/usr/bin/python3
""" Make Change """


def makeChange(coins, total):
    """ etermine the fewest number of coins
        needed to meet a given amount total
    """
    if total == 0:
            return 0

    k = total + 1
    T = [0 if i == 0 else float('inf') for i in range(k)]

    for j in range(len(coins)):
        for i in range(1, k):
            coin = coins[j]
            if(i >= coins[j]):
                T[i] = min(T[i], T[i - coin] + 1)

    return -1 if (T[-1] == float('inf')) else T[-1]
