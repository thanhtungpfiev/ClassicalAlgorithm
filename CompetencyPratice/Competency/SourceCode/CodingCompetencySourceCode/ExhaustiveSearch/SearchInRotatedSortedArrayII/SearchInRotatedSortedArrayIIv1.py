'''
File: SearchInRotatedSortedArrayIIv1.py
Project: SearchInRotatedSortedArrayII
File Created: Saturday, 19th March 2022 2:48:28 pm
Author: thanhtungpfiev (thanhtungpfiev@gmail.com)
-----
'''
from typing import List

class Solution:
    def search(self, nums: List[int], target: int) -> bool:
        result = False
        for i in nums:
            if target == i:
                result = True
                break
        return result

if __name__ == "__main__":
    s = Solution()
    result = s.search([1, 2,3], 5)
    print(result)
