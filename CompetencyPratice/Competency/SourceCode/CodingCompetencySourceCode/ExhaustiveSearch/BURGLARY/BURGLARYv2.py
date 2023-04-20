'''
File: BURGLARY.py
Project: BURGLARY
File Created: Saturday, 19th March 2022 8:57:20 pm
Author: thanhtungpfiev (thanhtungpfiev@gmail.com)
-----
'''
from typing import List
from collections import defaultdict
from pprint import pprint


def tryConfig(i: int, n: int, c: List[int], b: List[List[int]]) -> None:
    if (i == n):
        b.append(c.copy())
        return
    for v in range(0, 2):
        c[i] = v
        tryConfig(i + 1, n, c, b)


def generateMap(arr: List[int]) -> dict[int: int]:
    result = {}
    result = defaultdict(lambda: 0, result)
    n = len(arr)
    b = []
    c1 = [0 for i in range(n)]
    tryConfig(0, n, c1, b)

    for i in range(len(b)):
        c = b[i]
        sum = 0
        for j in range(len(c)):
            if (c[j]):
                sum += arr[j]
        cnt = c.count(1)
        if (sum != 0):
            if (result[sum] != 0) and (result[sum] != cnt):
                result[sum] = -2
            else:
                result[sum] = cnt
        else:
            if cnt == 0:
                result[sum] = 0
            else:
                result[sum] = -2
    return result


def inputByReadFile() -> None:
    with open('BURGLARY\in.txt') as file:
        line = file.readline()
        T = int(line)
        caseth = 0
        while (T > 0):
            line = file.readline()
            N, D = [int(e) for e in line.split()]
            line = file.readline()
            arr = [int(e) for e in line.split()]
            arr1 = arr[0:N // 2]
            arr2 = arr[N // 2:N]
            m1 = generateMap(arr1)
            m2 = generateMap(arr2)
            caseth += 1
            can = 0
            ans = -1
            for k, v in m1.items():
                if (can == 2):
                    break
                n = D - k
                if (n in m2.keys()):
                    if (v == - 2 or m2[n] == -2):
                        can = 2
                        break
                    cur = v + m2[n]
                    if (ans != -1 and ans != cur):
                        can = 2
                        break
                    ans = cur
                    can = 1
            if (can == 0):
                print("Case #", caseth, ": IMPOSSIBLE", sep='')
            elif (can == 1):
                print("Case #", caseth, ": ", ans, sep='')
            else:
                print("Case #", caseth, ": AMBIGIOUS", sep='')
            T -= 1


def inputByReadKeyboard() -> None:
    T = int(input())
    caseth = 0
    while (T > 0):
        N, D = [int(e) for e in input().split()]
        arr = [int(e) for e in input().split()]
        arr1 = arr[0:N // 2]
        arr2 = arr[N // 2:N]
        m1 = generateMap(arr1)
        m2 = generateMap(arr2)
        caseth += 1
        can = 0
        ans = -1
        for k, v in m1.items():
            if (can == 2):
                break
            n = D - k
            if (n in m2.keys()):
                if (v == - 2 or m2[n] == -2):
                    can = 2
                    break
                cur = v + m2[n]
                if (ans != -1 and ans != cur):
                    can = 2
                    break
                ans = cur
                can = 1
        if (can == 0):
            print("Case #", caseth, ": IMPOSSIBLE", sep='')
        elif (can == 1):
            print("Case #", caseth, ": ", ans, sep='')
        else:
            print("Case #", caseth, ": AMBIGIOUS", sep='')
        T -= 1


if __name__ == '__main__':
    inputByReadKeyboard()
