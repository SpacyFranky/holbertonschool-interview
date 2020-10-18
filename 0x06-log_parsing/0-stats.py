#!/usr/bin/python3
"""A script that reads stdin line by line and computes metrics"""

import sys

i = 0
size = 0
list_of_status_code = []
sorted_items = {}

try:
    for line in sys.stdin:
        try:
            file_size = line.split(" ")[8]
            int(file_size)
            file_size = file_size[:-1]
        except Exception:
            pass
        size += int(file_size)

        try:
            status_code = line.split(" ")[7]
            int(status_code)
            list_of_status_code.append(int(status_code))
            list_of_status_code.sort()
            dictionary = dict((i, list_of_status_code.count(i))
                              for i in list_of_status_code)
            dictionary_items = dictionary.items()
            sorted_items = sorted(dictionary_items)

            i = i + 1
            if (i == 10):
                print("File size: {:d}".format(size))
                for k, v in sorted_items:
                    print("{:d}: {:d}".format(k, v))
                i = 0

        except Exception:
            pass

except KeyboardInterrupt:
    pass

finally:
    print("File size: {:d}".format(size))
    for k, v in sorted_items:
        print("{:d}: {:d}".format(k, v))
