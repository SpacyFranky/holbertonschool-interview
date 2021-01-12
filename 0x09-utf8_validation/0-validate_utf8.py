#!/usr/bin/python3
"""Function file"""

def validUTF8(data):
    """Determines if a given data set represents a valid UTF-8 encoding"""
    for i in data:
        if i < 256:
            pass
        else:
            return False
    return True
    