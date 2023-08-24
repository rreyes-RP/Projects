'''
Given two strings s and t, return true if t is an anagram of s, and false otherwise.

An Anagram is a word or phrase formed by rearranging the letters of a different word 
or phrase, typically using all the original letters exactly once.
'''

class Solution(object):
    # O(nlogn) solution
    def isAnagramNLogn(s, t):
        ##
        # need to check if the lengths for s an t match before proceeding
        # Otherwise, the answer is going to be false and no need to continue
        ##
        if len(s) != len(t):
            return False
        
        ##
        # Sort the string in order to verify both s and t match -> True
        # Otherwise -> False
        ##
        if sorted(s) == sorted(t):
            return True
        else:
            return False
        
    def isAnagramN(s, t):
        ##
        # need to check if the lengths for s an t match before proceeding
        # Otherwise, the answer is going to be false and no need to continue
        ##
        if len(s) != len(t):
            return False
        
        ##
        # creating a dictionary to keep track of the frequencies of each letter
        # in the string.
        # the letter will be the key, and the frequency will be the value -> letter: frequency
        ##
        countS, countT = {}, {}  
        
        ##
        # use the indices of s (since s and t have the same length) to loop for each character 
        ##
        for i in range(len(s)):
            ##
            # increments the count of that character countS dictionary using countS/T.get(s/t[i], 0)
            # This operation gets the current count of the character if it exists in the dictionary,
            # otherwise, it returns 0 (default). The +1 increments the count
            #
            countS[s[i]] = 1 + countS.get(s[i], 0) 
            countT[t[i]] = 1 + countT.get(t[i], 0)
        
        return countS == countT
        
        
    s = "anagram"
    t = "nagaram"
    print(f"O(nlogn) solution: {isAnagramNLogn(s, t)}")
    print(f"O(n) solution: {isAnagramN(s, t)}")
    
    u = "rat"
    v = "car"
    print(f"O(nlogn) solution: {isAnagramNLogn(u, v)}")
    print(f"O(n) solution: {isAnagramN(u, v)}")