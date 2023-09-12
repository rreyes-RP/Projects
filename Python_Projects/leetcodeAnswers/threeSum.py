'''
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.
'''
class ThreeSum:
    def threeSum(nums):
        res = [] # return the result as a list of list
        nums.sort() # sort the input array to our advantage to find duplicates
        
        ##
        # use each number of the input array as a possible value
        ##
        for i, a in enumerate(nums):
            # we don't want to use the same value in the same position twice
            if i > 0 and a == nums[i - 1]:
                continue
            
            l, r = i + 1, len(nums) - 1 # use left and right pointers to get two sum for the remaining values in the triplets
            
            ##
            # left and right can't be equa;l
            ##
            while l < r:
                threeSum = a + nums[l] + nums[r] # compute the sum
                if threeSum > 0:
                    r -= 1 # shift right pointer to the left
                
                elif threeSum < 0:
                    l += 1 # shift left pointer to the right
                else:
                    res.append([a, nums[l], nums[r]])
                    l += 1
                    while nums[l] == nums[l - 1] and l < r:
                        l += 1
        return res
    
    nums = [-1,0,1,2,-1,-4]
    print(threeSum(nums))
                
        