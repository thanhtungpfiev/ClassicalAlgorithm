'''
File: Cknv1.py
Project: Ckn
File Created: Sunday, 20th March 2022 2:38:36 pm
Author: thanhtungpfiev (thanhtungpfiev@gmail.com)
-----
'''


from typing import List


def tryConfig(i: int, n: int, k: int, arr: List[int]) -> None:
    if (i == k + 1):
        print(arr)
        return
    for v in range(arr[i - 1] + 1, n - k + i + 1):
        arr[i] = v
        tryConfig(i + 1, n, k, arr)


if __name__ == '__main__':
    n = int(input('Nhap n: '))
    k = int(input('Nhap k: '))
    if (n > 0):
        arr = [0 for e in range(k + 1)]
        tryConfig(1, n, k, arr)
