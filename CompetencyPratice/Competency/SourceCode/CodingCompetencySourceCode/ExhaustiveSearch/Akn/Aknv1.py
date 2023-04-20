'''
File: Akn.py
Project: Akn
File Created: Sunday, 20th March 2022 2:01:24 pm
Author: thanhtungpfiev (thanhtungpfiev@gmail.com)
-----
'''

from typing import List


def tryConfig(i: int, n: int, k: int, arr: List[int], mark: List[int]) -> None:
    if (i == k + 1):
        print(arr)
        return
    for v in range(1, n + 1):
        if (mark[v] == False):
            arr[i] = v
            mark[v] = True
            tryConfig(i + 1, n, k, arr, mark)
            mark[v] = False


if __name__ == '__main__':
    n = int(input('Nhap n: '))
    k = int(input('Nhap k: '))
    if (n > 0):
        arr = [0 for e in range(k + 1)]
        mark = [False for e in range(n + 1)]
        tryConfig(1, n, k, arr, mark)
