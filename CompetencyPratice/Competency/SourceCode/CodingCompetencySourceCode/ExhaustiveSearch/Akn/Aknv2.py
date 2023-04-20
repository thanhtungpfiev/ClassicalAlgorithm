'''
File: Akn.py
Project: Akn
File Created: Sunday, 20th March 2022 2:01:24 pm
Author: thanhtungpfiev (thanhtungpfiev@gmail.com)
-----
'''

from typing import List
from itertools import permutations5

if __name__ == '__main__':
    n = int(input('Nhap n: '))
    k = int(input('Nhap k: '))
    if (n > 0):
        arr = [e + 1 for e in range(n)]
        perm = permutations(arr, k)
        for i in list(perm):
            print(i)
