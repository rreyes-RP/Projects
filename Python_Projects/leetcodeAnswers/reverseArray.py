class Solution(object):
    def reverseString(s):
        # given input array s, reverse the string
        
        stringS = ''.join(s)
        reverseS = stringS[::-1]
        
        reverseSArray = []
        
        for i in reverseS:
            reverseSArray.append(i)
        
        return reverseSArray
        
        
    s = ["h","e","l","l","o"]
    print(reverseString(s))