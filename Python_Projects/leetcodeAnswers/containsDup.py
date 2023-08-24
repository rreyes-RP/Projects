class Solution:
    def containsDuplicate(nums: list[int]) -> bool:
        # given input nums, contains an array of integers
        # return true if a number appears twice: i.e [1,2,3,3,4]
        # return false if all are distinct: i.e [1,2,3,4,5]
        
        # Answer:
        # create a hash set to input values of the input nums. Duplicates aren't allowed in hash sets
        hashNum = set()
        
        ##
        # create a loop that will iterate through the input nums
        ##
        for i in nums:
            ##
            # check if i is in hashNum
            ##
            if i in hashNum:
                return True # verifies a duplicate
            hashNum.add(i) # add the value from array num into the hash set hashNum
        return False # no duplicates found
    
    nums = [1,2,3,4]
    print(containsDuplicate(nums))