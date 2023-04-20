'''
File: QuickSort.py
Project: QuickSort
File Created: Sunday, 27th March 2022 2:49:03 pm
Author: thanhtungpfiev (thanhtungpfiev@gmail.com)
-----
'''
from typing import List
from random import randint


def partition(v: List[int], lo: int, hi: int) -> int:
    pivot = v[hi]
    left = lo
    right = hi - 1
    while (True):
        while (v[left] < pivot and left <= right):
            left = left + 1
        while (v[right] > pivot and left <= right):
            right = right - 1
        if (left < right):
            v[left], v[right] = v[right], v[left]
            left = left + 1
            right = right - 1
        else:
            break
    v[left], v[hi] = v[hi], v[left]
    return left


def quickSort(v: List[int], lo: int, hi: int) -> None:
    if (lo < hi):
        p = partition(v, lo, hi)
        quickSort(v, lo, p - 1)
        quickSort(v, p + 1, hi)


def fillVector(size: int) -> List[int]:
    v = [randint(0, size) for i in range(size)]
    return v


if __name__ == '__main__':
    v = fillVector(100)
    quickSort(v, 0, len(v) - 1)
    print(v)
