'''
File: SearchInRotatedSortedArray.py
Project: SearchInRotatedSortedArray
File Created: Saturday, 19th March 2022 3:39:01 pm
Author: thanhtungpfiev (thanhtungpfiev@gmail.com)
-----
'''
from typing import List

class Solution:
    def binarySearch(self, nums: List[int], start: int, end: int, target: int) -> bool:
        result = -1
        if (start < 0 or end > len(nums)):
            pass
        else:
            while (start <= end):
                mid = start + (end - start) // 2
                if (nums[mid] == target):
                    result = mid
                    break
                elif (nums[mid] < target):
                    start = mid + 1
                else:
                    end = mid - 1
        return result


    def search(self, nums: List[int], target: int) -> int:
        result = -1
        size = len(nums)
        if (size > 0):
            index = -1
            start = 0
            end = size - 1
            # find pivot by binary search
            while (start <= end):
                mid = start + (end - start) // 2
                if (nums[mid] > nums[size - 1]):
                    start = mid + 1
                else:
                    end = mid - 1
                    index = mid
            # find target in 2 arrays
            if (target == nums[index]):
                result = index
            elif (target > nums[size - 1]):
                result = self.binarySearch(nums, 0, index - 1, target)
            else:
                result = self.binarySearch(nums, index, size - 1, target)
        return result

if __name__ == "__main__":
    s = Solution()
    result = s.search([1, 3], 3)
    print(result)
