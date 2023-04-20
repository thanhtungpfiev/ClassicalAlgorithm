'''
File: Kadane.py
Project: FindMaximumContinuosSubArray
File Created: Sunday, 27th March 2022 4:25:10 pm
Author: thanhtungpfiev (thanhtungpfiev@gmail.com)
-----
'''
from typing import List
import sys


def kadane(v: List[int]) -> int:
    max_so_far = -sys.maxsize
    max_ending_here = 0
    for i in range(len(v)):
        max_ending_here = max_ending_here + v[i]
        if (max_so_far < max_ending_here):
            max_so_far = max_ending_here
        if (max_ending_here < 0):
            max_ending_here = 0
    return max_so_far


if __name__ == '__main__':
    v = [1, 2, 3, -2, 5]
    print(kadane(v))
