'''
File: ABCDEF.py
Project: ABCDEF
File Created: Monday, 28th March 2022 6:26:23 pm
Author: tung.dao (thanhtungpfiev@gmail.com)
-----
'''
from bisect import bisect_left, bisect_right
from typing import List


def searching(v: List[int]) -> int:
    result = 0
    v1 = []
    v2 = []
    for i1 in range(len(v)):
        for i2 in range(len(v)):
            for i3 in range(len(v)):
                v1.append(v[i1] * v[i2] + v[i3])
                if (v[i3] != 0):
                    v2.append((v[i1] + v[i2]) * v[i3])

    v1.sort()
    v2.sort()
    for i in range(len(v1)):
        lo = bisect_left(v2, v1[i])
        hi = bisect_right(v2, v1[i])
        result += hi - lo
    return result


if __name__ == '__main__':
    N = int(input())
    arr = []
    for i in range(N):
        e = int(input())
        arr.append(e)
    print(searching(arr))
