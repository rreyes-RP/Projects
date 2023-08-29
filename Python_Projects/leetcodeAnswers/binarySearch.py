'''
Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search target in nums. 
If target exists, then return its index. Otherwise, return -1.

You must write an algorithm with O(log n) runtime complexity.
'''
class BinarySearch:
    def binarySearch(nums, target):
        
        l, r = 0, len(nums) - 1 # use two pointer method
        
        ##
        # have l less than or equal to r
        ##
        while l <= r:
            m = l + ((r - l) // 2) # get the midway point (m) and start there to finding the target       
            if nums[m] > target:
                r = m - 1
            elif nums[m] < target:
                l = m + 1
            else:
                return m
        return -1
        
    nums = [-1,0,3,5,9,12]
    target = 9
    print(binarySearch(nums, target))