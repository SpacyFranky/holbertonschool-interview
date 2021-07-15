#!/usr/bin/python3
""" 0-island_perimeter.py """


def island_perimeter(grid):
    """ returns the perimeter of the island described in grid """
    land = 0
    if len(grid) <= 2:
        return land
    for i in range(len(grid)):
        for j in range(len(grid[i])):
            if grid[i][j] == 1:
                land += 4
                if grid[i][j-1] == 1 and j - 1 >= 0:
                    land -= 1
                if grid[i][j+1] == 1 and j + 1 <= len(grid[j]):
                    land -= 1
                if grid[i+1][j] == 1 and i + 1 <= len(grid):
                    land -= 1
                if grid[i-1][j] == 1 and i - 1 >= 0:
                    land -= 1
    return land
