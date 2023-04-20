'''
File: BinarySearch.py
Project: ClassicalSearching
File Created: Sunday, 27th March 2022 3:17:16 pm
Author: thanhtungpfiev (thanhtungpfiev@gmail.com)
-----
'''
from typing import List


def binarySearch(v: List[int], key: int) -> int:
    result = -1
    start = 0
    end = len(v) - 1
    while (start <= end):
        mid = start + (end - start) // 2
        if v[mid] == key:
            result = mid
            break
        elif v[mid] > key:
            end = mid - 1
        else:
            start = mid + 1
    return result


if __name__ == '__main__':
    v = [5, 2, 3, 8, 9]
    v.sort()
    print(binarySearch(v, 1))
    print(binarySearch(v, 5))
    print(binarySearch(v, 3))
    print(binarySearch(v, 9))
9
