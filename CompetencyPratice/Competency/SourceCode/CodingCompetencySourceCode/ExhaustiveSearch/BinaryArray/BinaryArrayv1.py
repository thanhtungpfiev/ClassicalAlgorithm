'''
File: BinaryArrayv1.py
Project: BinaryArray
File Created: Sunday, 20th March 2022 3:12:52 pm
Author: thanhtungpfiev (thanhtungpfiev@gmail.com)
-----
'''


from typing import List


def tryConfig(i: int, n: int, arr: List[int]) -> None:
    if (i == n):
        print(arr)
        return
    for v in range(0, 2):
        arr[i] = v
        tryConfig(i + 1, n, arr)


if __name__ == '__main__':
    n = int(input('Nhap n: '))
    if (n > 0):
        arr = [0 for e in range(n)]
        tryConfig(0, n, arr)
