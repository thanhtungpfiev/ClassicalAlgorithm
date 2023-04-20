'''
File: BURGLARY.py
Project: BURGLARY
File Created: Saturday, 19th March 2022 8:57:20 pm
Author: thanhtungpfiev (thanhtungpfiev@gmail.com)
-----
'''
from typing import List

def tryConfig(i: int, n: int, c: List[int], b: List[List[int]]) -> None:
    if (i == n):
        b.append(c.copy())
        return
    for v in range(0, 2):
        c[i] = v
        tryConfig(i + 1, n, c, b)

def solve(arr: List[int], D: int) -> List[int]:
    result = []
    n = len(arr)
    b = []
    c = [0 for i in range(n)]
    tryConfig(0, n, c, b)

    cnt = 0
    k = 0
    for i in range(len(b)):
        c = b[i]
        sum = 0
        for j in range(len(c)):
            if (c[j]):
                sum += arr[j]
        if (sum == D):
            if (k != c.count(1)):
                k = c.count(1)
                cnt += 1
            if (cnt > 1):
                break

    result.append(cnt)
    result.append(k)
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
            result = solve(arr, D)
            caseth += 1
            if (result[0] == 0):
                print("Case #", caseth, ": IMPOSSIBLE", sep ='')
            elif (result[0] == 1):
                print("Case #", caseth, ": ", result[1], sep ='')
            else:
                print("Case #", caseth, ": AMBIGIOUS", sep ='')
            T -= 1

def inputByReadKeyboard() -> None:
    T = int(input())
    caseth = 0
    while (T > 0):
        N, D = [int(e) for e in input().split()]
        arr = [int(e) for e in input().split()]
        result = solve(arr, D)
        caseth += 1
        if (result[0] == 0):
            print("Case #", caseth, ": IMPOSSIBLE", sep ='')
        elif (result[0] == 1):
            print("Case #", caseth, ": ", result[1], sep ='')
        else:
            print("Case #", caseth, ": AMBIGIOUS", sep ='')
        T -= 1

if __name__ == '__main__':
    inputByReadFile()
