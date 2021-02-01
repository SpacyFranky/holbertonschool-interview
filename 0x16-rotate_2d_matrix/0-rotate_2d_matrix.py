#!/usr/bin/python3
""" Rotating a 2D Matrix """

def rotate_2d_matrix(matrix):
    """ 90 degrees matrix rotation """
    k = 0
    for i in range(len(matrix) - 1, -1, -1):
        l = []
        for j in range(len(matrix[i])):
            l.append(matrix[j][k])
        l.reverse()
        matrix.append(l)
        k += 1
    for i in matrix:
        matrix.pop(0)
