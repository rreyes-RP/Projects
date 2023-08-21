'''
Given an array of integers temperatures represents the daily temperatures, 
return an array answer such that answer[i] is the number of days you have 
to wait after the ith day to get a warmer temperature. If there is no 
future day for which this is possible, keep answer[i] == 0 instead.

- Monotonic Decreasing Order
'''

class Solution(object):
    def dailyTemperatures(temperatures):
        res = [0] * len(temperatures)
        stack = [] # pair: [temp, index]
        
        for i, t in enumerate(temperatures):
            while stack and t > stack[-1][0]:
                stackT, stackInd = stack.pop()
                res[stackInd] = (i - stackInd)
            stack.append((t, i))
        return res
        
    # Example 1:
    temperatures1 = [73,74,75,71,69,72,76,73]
    # Output: [1,1,4,2,1,1,0,0]

    # Example 2:
    temperatures2 = [30,40,50,60]
    # Output: [1,1,1,0]

    # Example 3:
    temperatures3 = [30,60,90]
    # Output: [1,1,0]

    print(dailyTemperatures(temperatures1)) 
    print(dailyTemperatures(temperatures2)) 
    print(dailyTemperatures(temperatures3)) 