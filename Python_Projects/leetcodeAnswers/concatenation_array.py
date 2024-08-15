class Solution:
    def getConcatenation(nums):
        # Input: integer array nums of length n
        # Output: another integer array ans of length 2n
        # Brute force
        ans = nums + nums
        
        return ans
    
    arr = [1,2,1]
    print(getConcatenation(arr))