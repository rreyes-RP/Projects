'''
Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You must write an algorithm with O(log n) runtime complexity.
'''
class Solution(object):
    def searchInsert(nums, target):
        # use brute force
        # loop through the array until target matches one of the values
        for i in nums:
            if i == target:
                return nums.index(i)
            elif i != target:
                if nums.index(i) < target and nums.index(i+1):
                    nums.insert(nums.index(i+1,target))
                    return nums.index(target)
            
    nums = [1,3,5,6]
    target = 5
    print(searchInsert(nums, target))