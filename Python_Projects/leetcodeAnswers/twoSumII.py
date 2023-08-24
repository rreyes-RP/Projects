# Two Sum II
'''
Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order, find two numbers such that they add up to a specific target number. Let these two numbers be numbers[index1] and numbers[index2] where 1 <= index1 < index2 < numbers.length.

Return the indices of the two numbers, index1 and index2, added by one as an integer array [index1, index2] of length 2.

The tests are generated such that there is exactly one solution. You may not use the same element twice.

Your solution must use only constant extra space.
'''

class Solution:
    def twoSumII(numbers, target):
        # using two pointer algorithm
        # use the target to figuer out if the sum is greater, less, or equal to target
        
        
        # return indices that has the values equal to the target
        # big O(n)
        
        l, r = 0, len(numbers) - 1 # left starts at 0 (beginning) and right starts at the end (last index)
        
        ##
        # left pointer is always less than right
        ##
        while l < r:
            curSum = numbers[l] + numbers[r] # get sum to match with the target
            
            ##
            # Check if curSum is greater than or equal to the target
            ##
            if curSum > target:
                r -= 1 # greater ->  move the right pointer to the left
            elif curSum < target:
                l += 1 # less -> move the left pointer to the right
            else:
                return [l + 1, r + 1] # indices are based on 0 so we add 1 to produce an integer array
        return []
    
    numbers = [2,7,11,15]
    target = 9
    print(twoSumII(numbers, target))
            