'''
File: NormalSearch.py
Project: ClassicalSearching
File Created: Sunday, 27th March 2022 3:13:27 pm
Author: thanhtungpfiev (thanhtungpfiev@gmail.com)
-----
'''
from typing import List


def sequenceSearch(v: List[int], key: int) -> int:
    result = -1
    for i in range(len(v)):
        if v[i] == key:
            result = i
            break
    return result


if __name__ == '__main__':
    v = [5, 2, 3, 8, 9]
    print(sequenceSearch(v, 1))
    print(sequenceSearch(v, 5))
    print(sequenceSearch(v, 3))
    print(sequenceSearch(v, 9))
