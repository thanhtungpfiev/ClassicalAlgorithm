'''
File: Cknv1.py
Project: Ckn
File Created: Sunday, 20th March 2022 2:38:36 pm
Author: thanhtungpfiev (thanhtungpfiev@gmail.com)
-----
'''


from typing import List
from itertools import combinations


if __name__ == '__main__':
    n = int(input('Nhap n: '))
    k = int(input('Nhap k: '))
    if (n > 0):
        arr = [e + 1 for e in range(n)]
        comb = combinations(arr, k)

        for i in list(comb):
            print(i)
