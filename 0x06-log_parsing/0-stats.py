#!/usr/bin/python3
"""A script that reads stdin line by line and computes metrics"""

import sys

i = 0
s = 0
list_of_filesize = []
list_of_status_code = []

try:
    for line in sys.stdin:
        file_size = line.split(" ")[8]
        file_size = file_size[:-1]
        list_of_filesize.append(int(file_size))

        status_code = line.split(" ")[7]
        list_of_status_code.append(int(status_code))
        list_of_status_code.sort()

        dictionary = dict((i, list_of_status_code.count(i))
                          for i in list_of_status_code)
        dictionary_items = dictionary.items()
        sorted_items = sorted(dictionary_items)

        i = i + 1
        if (i == 10):
            i = 0
            s += sum(list_of_filesize)
            print("File size: {:d}".format(s))
            for k, v in sorted_items:
                print("{}: {}".format(k, v))

except KeyboardInterrupt:
    pass
