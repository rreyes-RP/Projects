'''
Given an array of strings strs, group the anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.
'''
from collections import defaultdict

class GroupAnagrams:
    def groupAnagrams(strs):
        # time complexity O(m*n)
        
        # use a hashmap to represent each word in strs and the value will be each letter represnted for a number of times
        res = defaultdict(list)
        
        for s in strs:
            count = [0] * 26 # make an array that will represent each 26 letters: a - z
            
            ##
            # go through each character in each string
            for c in s:
                count[ord(c) - ord("a")] += 1 # find the diff in ASCII value of what's currently in c to "a": ex: a = 80 -> c(a) - a == 80 - 80 = 0
                
            res[tuple(count)].append(s)
        
        return res.values()
        
    strs = ["eat","tea","tan","ate","nat","bat"]
    # Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
    print(groupAnagrams(strs))