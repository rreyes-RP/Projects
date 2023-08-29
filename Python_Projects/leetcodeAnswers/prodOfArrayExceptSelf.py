'''
Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.
'''

class ProdOfArrayExceptSelf:
    def prodOfArrayExceptSelf(nums):
        # input is an array
        # need to find product of elements that's not the chosen element: i.e [1,2,3,4] if i = 1, then we want 2*3*4 = 24, etc
        # will need to know the product of prefix and postfix values based on the focused element
        
        res = [1] * (len(nums)) # initial values will be 1 with the same size as the input array nums
        
        prefix = 1 # this will be the value before the first element in the input array
        
        ##
        # go through every position in the input array
        ##
        for i in range(len(nums)):
            res[i] = prefix # each position for the result output array[i], put that in that position
            prefix *= nums[i] # take input value and multiply to prefix for the new prefix
        
        postfix = 1 # this value will be after the last element of the array
        ##
        # start at the end of the input array, and then go down until the beginning
        ##
        for i in range(len(nums) - 1, -1, -1):
            res[i] *= postfix # Not simply storing the postfix value because it will overwrite the prefix values, multiply what's already in the result
            postfix *= nums[i] # continuesly update the postfix, multiply by the input array nums
        return res
    
    nums = [1,2,3,4]
    print(prodOfArrayExceptSelf(nums))
        