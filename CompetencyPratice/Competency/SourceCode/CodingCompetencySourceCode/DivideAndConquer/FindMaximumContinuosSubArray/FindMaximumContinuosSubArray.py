'''
File: FindMaximumContinuosSubArray.py
Project: FindMaximumContinuosSubArray
File Created: Sunday, 27th March 2022 4:11:03 pm
Author: thanhtungpfiev (thanhtungpfiev@gmail.com)
-----
'''
from typing import List
import sys


def maxIn3Elements(sum1: int, sum2: int, sum3: int) -> int:
    maxSum = sum1
    maxSum = max(sum1, sum2)
    maxSum = max(maxSum, sum3)
    return maxSum


def maxCrossingSum(arr: List[int], l: int, m: int, h: int) -> int:
    sum = 0
    left_sum = -sys.maxsize - 1
    for i in range(m, l - 1, -1):
        sum += arr[i]
        if (sum > left_sum):
            left_sum = sum

    sum = 0
    right_sum = -sys.maxsize - 1
    for i in range(m + 1, h + 1):
        sum += arr[i]
        if (sum > right_sum):
            right_sum = sum

    return maxIn3Elements(left_sum + right_sum, left_sum, right_sum)


def maxSubArraySum(arr: List[int], l: int, h: int) -> int:
    if (l == h):
        return arr[l]
    m = (l + h) // 2
    return maxIn3Elements(maxSubArraySum(arr, l, m), maxSubArraySum(arr, m + 1, h), maxCrossingSum(arr, l, m, h))


if __name__ == '__main__':
    arr = [1, 2, 3, -2, 5]
    print(maxSubArraySum(arr, 0, len(arr) - 1))
