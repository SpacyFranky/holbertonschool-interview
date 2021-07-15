#!/usr/bin/python3
""" 0-island_perimeter.py """


def island_perimeter(grid):
    """ returns the perimeter of the island described in grid """
    land = 0
    for i in range(len(grid)):
        for j in range(len(grid[i])):
            if grid[i][j] == 1:
                land += 4
                if j - 1 >= 0 and grid[i][j-1] == 1:
                    land -= 1
                if j + 1 <= len(grid[j]) and grid[i][j+1] == 1:
                    land -= 1
                if i + 1 <= len(grid) and grid[i+1][j] == 1:
                    land -= 1
                if i - 1 >= 0 and grid[i-1][j] == 1:
                    land -= 1
    return land
