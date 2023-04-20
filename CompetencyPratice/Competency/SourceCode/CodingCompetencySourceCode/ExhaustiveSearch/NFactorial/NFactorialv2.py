'''
File: NFactorial.py
Project: NFactorial
File Created: Sunday, 20th March 2022 10:11:36 am
Author: thanhtungpfiev (thanhtungpfiev@gmail.com)
-----
'''
from itertools import permutations


if __name__ == '__main__':
    n = int(input('Nhap n: '))
    if (n > 0):
        arr = [e + 1 for e in range(n)]
        perm = permutations(arr)
        for i in perm:
            print(i)
