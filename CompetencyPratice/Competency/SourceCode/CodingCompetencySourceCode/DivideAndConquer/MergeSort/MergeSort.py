'''
File: MergeSort.py
Project: MergeSort
File Created: Sunday, 27th March 2022 3:36:01 pm
Author: thanhtungpfiev (thanhtungpfiev@gmail.com)
-----
'''
from typing import List


def copyArray(A: List[int], iBegin: int, iEnd: int, B: List[int]) -> None:
    for i in range(iBegin, iEnd):
        B[i] = A[i]


def topdownMerge(A: List[int], iBegin: int, iMiddle: int, iEnd: int, B: List[int]) -> None:
    i = iBegin
    j = iMiddle
    for k in range(iBegin, iEnd):
        if(i < iMiddle and (j >= iEnd or A[i] < A[j])):
            B[k] = A[i]
            i += 1
        else:
            B[k] = A[j]
            j += 1


def topdownSplitMerge(B: List[int], iBegin: int, iEnd: int, A: List[int]) -> None:
    if (iEnd - iBegin <= 1):
        return None
    iMiddle = (iBegin + iEnd) // 2
    topdownSplitMerge(A, iBegin, iMiddle, B)
    topdownSplitMerge(A, iMiddle, iEnd, B)
    topdownMerge(B, iBegin, iMiddle, iEnd, A)


def topdownMergeSort(A: List[int], B: List[int], n: int) -> None:
    copyArray(A, 0, n, B)
    topdownSplitMerge(B, 0, n, A)


if __name__ == '__main__':
    A = [1, 3, 2, 5, 4]
    B = [None] * len(A)
    topdownMergeSort(A, B, len(A))
    print(A)

    A2 = [1, 3, 2, 5, 4, 7, 1, 5]
    B2 = [None] * len(A2)
    topdownMergeSort(A2, B2, len(A2))
    print(A2)
