# don't use a set to prevent extra space
# find the difference from each value starting at index 0, match the diff to the index in the array, flip the + to a -
# 

class Solution:
    def findDups(nums):
        result = [] # answer will be appended in this array
        for i in nums:
            index = abs(i) - 1 # Get the absolute value of the number at the it's index if it already converted to a negative number
            
            ##
            # If the value at the index is a neg number, it means the number has been encountered before
            # this indicates a duplicate
            ##
            if nums[index] < 0:
                result.append(abs(i))
            else:
                nums[index] = -nums[index] # mark the value at the index as a negative after matching the diff
        return result
    
    nums = [4,3,2,7,8,2,3,1]
    print(findDups(nums))
            