'''
File: SearchInsertPosition.py
Project: SearchInsertPosition
File Created: Monday, 28th March 2022 4:44:39 pm
Author: tung.dao (thanhtungpfiev@gmail.com)
-----
'''
from typing import List


def binarySearch(arr: List[int], target: int) -> int:
    result = 0
    lo = 0
    hi = len(arr) - 1
    while (lo <= hi):
        mid = lo + (hi - lo) // 2
        if (target == arr[mid]):
            result = mid
            break
        elif (target < arr[mid]):
            hi = mid - 1
        else:
            lo = mid + 1

    if (result == 0):
        result = lo
    return result


if __name__ == '__main__':
    nums = [1, 3, 5, 6]
    target = 5
    print(binarySearch(nums, target))
