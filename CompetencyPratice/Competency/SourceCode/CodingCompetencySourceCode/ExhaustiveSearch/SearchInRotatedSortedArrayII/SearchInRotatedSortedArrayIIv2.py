'''
File: SearchInRotatedSortedArrayIIv2.py
Project: SearchInRotatedSortedArrayII
File Created: Saturday, 19th March 2022 2:57:25 pm
Author: thanhtungpfiev (thanhtungpfiev@gmail.com)
-----
'''
from typing import List

class Solution(object):
    def isExistInFirst(self, nums : List[int], start: int, target: int) -> bool:
        return nums[start] <= target

    def isBinarySearchHelpful(self, nums : List[int], start: int, target: int) -> bool:
        return nums[start] != target

    def search(self, nums, target):
        result = False
        n = len(nums)
        if (n == 0):
            result = False
        else:
            start = 0
            end = n - 1
            while (start <= end):
                mid = start + (int) ((end - start) / 2)
                if (nums[mid] == target):
                    result = True
                    break
                if (self.isBinarySearchHelpful(nums, start, nums[mid]) == False):
                    start += 1
                    continue
                pivotMid = self.isExistInFirst(nums, start, nums[mid])
                pivotTarget = self.isExistInFirst(nums, start, target)
                if (pivotMid == True and pivotTarget == False) or (pivotMid == True and pivotTarget == True and nums[mid] < target) or (pivotMid == False and pivotTarget == False and nums[mid] < target):
                    start = mid + 1
                elif (pivotMid == False and pivotTarget == True) or (pivotMid == True and pivotTarget == True and nums[mid] > target) or (pivotMid == False and pivotTarget == False and nums[mid] > target):
                    end = mid - 1
        return result

if __name__ == "__main__":
    s = Solution()
    result = s.search([1, 2,3], 5)
    print(result)
