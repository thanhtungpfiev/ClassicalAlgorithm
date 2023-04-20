'''
File: REPROAD.py
Project: REPROAD
File Created: Saturday, 19th March 2022 5:44:03 pm
Author: thanhtungpfiev (thanhtungpfiev@gmail.com)
-----
'''
from typing import List

def isCanBePrepaired(v: List[int], i: int, j: int, K: int) -> bool:
    count = 0
    for k in range(i, j + 1):
        if (v[k] == 0):
            count += 1
    if (count > K):
        return False
    return True

def bruteForce(v: List[int], K: int) -> int:
    result = 0
    for i in range(len(v) - 1):
        for j in range(i + 1, len(v)):
            if (j - i + 1 > result) and isCanBePrepaired(v, i, j, k):
                result = j - i + 1
    return result

def stackSolve(v : List[int], K: int) -> int:
    result = -1
    q = []
    length = 0
    cost = 0
    for i in range(len(v)):
        if (v[i] == 0):
            if (cost < K):
                cost += 1
                length += 1
            else:
                length = i - q.pop(0)
            q.append(i)
        else:
            length += 1
        result = max(result, length)
    return result

if __name__ == "__main__":
    T = int(input())
    while (T > 0):
        N, K = [int(e) for e in input().split()]
        v = [int(e) for e in input().split()]
        print(stackSolve(v, K))
        T -= 1
