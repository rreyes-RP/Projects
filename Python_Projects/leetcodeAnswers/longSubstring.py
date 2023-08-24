'''
Given a string s, find the length of the longest substring without repeating characters.
'''

class Solution(object):
    def lengthOfLongestSubstring(s):
        # input the characters into a hashset until a character is repeated
        hashSet = set()
        
        count = 0 # keeps track of the largest length of substrings
        
        left = 0 # left pointer starting at the beginning of the string
        
        # loop through the size of s
        for i in range(len(s)):
            while s[i] in hashSet:
                hashSet.remove(s[left])
                left += 1
                
            hashSet.add(s[i])
            count = max(count, len(hashSet))
        
        return count
    
    s = "abcabcbb"
    print(lengthOfLongestSubstring(s))
    
    t = "bbbbb"
    print(lengthOfLongestSubstring(t))
    
    u = "pwwkew"
    print(lengthOfLongestSubstring(u))