class Solution:
    def isSubsequence(s, t):
        # Input 1 will contain the mandatory characters
        # Input 2 will contain both mandatory and deletable (if necessary) characters 
        # Output == true or false, true if input 2 contains same characters as input 1
        
        # create a hash set to save the same characters of input 1 from input 2
        i, j = 0, 0

        while i < len(s) and j < len(t):
            if s[i] == t[j]:
                i += 1
            j += 1
        return i == len(s)
        
    str1 = "abc"
    str2 = "ahbgdc"
    
    print(isSubsequence(str1, str2))
    
    str3 = "axc"
    
    print(isSubsequence(str3, str2))
            
        
        
        