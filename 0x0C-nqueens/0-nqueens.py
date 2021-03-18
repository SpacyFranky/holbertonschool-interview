#!/usr/bin/python3
import sys


def createMatrix(n):
    matrix = []
    for i in range(n):
        a = []
        for j in range(n):
            a.append(0)
        matrix.append(a)
    return(matrix)


def printMatrix(matrix, n):
    a = []
    for i in range(n):
        b = []
        for j in range(n):
            if matrix[i][j] == 1:
                b.append(i)
                b.append(j)
                a.append(b)
    print(a)


def isSafe(matrix, row, col, n):
    for i in range(col):
        if matrix[row][i] == 1:
            return False

    i = row
    j = col
    while i >= 0 and j >= 0:
        if (matrix[i][j]):
            return False
        i -= 1
        j -= 1

    i = row
    j = col
    while j >= 0 and i < n:
        if (matrix[i][j]):
            return False
        i = i + 1
        j = j - 1

    return True


def solveNQUtil(matrix, col, n):
    if (col == n):
        printMatrix(matrix, n)
        return True

    res = False
    for i in range(n):
        if (isSafe(matrix, i, col, n)):
            matrix[i][col] = 1

            res = solveNQUtil(matrix, col + 1, n) or res

            matrix[i][col] = 0

    return res


def solveNQ(matrix, n):
    if (solveNQUtil(matrix, 0, n) is False):
        print("Solution does not exist")
        sys.exit(1)


if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        sys.exit(1)

    try:
        if not type(int(sys.argv[1])) is int:
            print("N must be a number")
            sys.exit(1)
    except:
        print("N must be a number")
        sys.exit(1)

    n = int(sys.argv[1])

    if n < 4:
        print("N must be at least 4")
        sys.exit(1)

    matrix = createMatrix(n)

    solveNQ(matrix, n)
