'''
File: BinaryArrayv2.py
Project: BinaryArray
File Created: Sunday, 20th March 2022 3:17:01 pm
Author: thanhtungpfiev (thanhtungpfiev@gmail.com)
-----
'''
from typing import List
from itertools import product


if __name__ == '__main__':
    n = int(input('Nhap n: '))
    if (n > 0):
        arr = product([0, 1], repeat=n)
        for i in arr:
            print(i)
