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

    if len(boxes) == 1:
        return False

    if checkAllBoxes(boxes) is False:
        return False

    """Checking if all boxes can be unlocked or not"""
    v = True
    keys = []
    used_boxes = set()
    for box_number in range(len(boxes)):
        for i in range(len(boxes[box_number])):
            if box_number == 0:
                keys.append(boxes[box_number][i])
                used_boxes.add(box_number)
            else:
                if box_number in keys:
                    keys.append(boxes[box_number][i])
                    used_boxes.add(box_number)

    for box_number in range(len(boxes)):
        if box_number not in used_boxes:
            for i in range(len(boxes[box_number])):
                if box_number in keys:
                    keys.append(boxes[box_number][i])
                    used_boxes.add(box_number)
                else:
                    v = False

    return v
