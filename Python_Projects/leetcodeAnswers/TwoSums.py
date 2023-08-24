'''
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.
'''

class TwoSum:
    def twoSum(nums, target):
        # given a target sum for two indices of array nums to equal
        # can't use the same element twice
        # return the indices of the two values that add up to target
        
        # use a hash map to save the value of the index as the key and the index as the value representing the key
        hashNums = {}
        
        # now we need to input the value of the array as the key and the index as they value
        for i, n in enumerate(nums):
            diff = target - n # get the difference between the target and the value in array nums
            
            # use diff to find the remainder that should be in the hash map
            if diff in hashNums:
                return [hashNums[diff], i]

            hashNums[n] = i # add diff as a key to hash map if diff is not in hashNums, and the index as the value
        return
    
    nums = [2,7,11,15]
    target = 9
    print(f"Two Sum: {twoSum(nums, target)}")
                