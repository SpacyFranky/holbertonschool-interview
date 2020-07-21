#!/usr/bin/python3
"""Lockboxes"""


def checkAllBoxes(boxes):
    """checks if all values are lists"""
    f = (bool)
    for i in boxes:
        if type(i) is list:
            f = True
        else:
            f = False
            break
    return f


def canUnlockAll(boxes):
    """determines if all the boxes can be opened"""

    if boxes is None or len(boxes) == 0:
        return False

    if type(boxes) is not list:
        return False

    if len(boxes) == 1 and type(boxes[0]) is list:
        return True

    if len(boxes) == 1 and type(boxes[0]) is not list:
        return False

    if checkAllBoxes(boxes) is False:
        return False

    """Checking if all boxes can be unlocked or not"""
    opened = {}
    opened[0] = True
    for i in range(1, len(boxes)):
        for j in range(len(boxes[i])):
            opened[i] = False

    keys = set()
    for i in range(len(boxes[0])):
        keys.add(boxes[0][i])
    old_len = 0

    while old_len < 100:
        for i in range(1, len(boxes)):
            for j in range(len(boxes[i])):
                if i in keys:
                    keys.add(boxes[i][j])
                    opened[i] = True
                    old_len += 1

    v = False
    if v in opened.values():
        return False
    return True
