class Solution(object):
    def generateParenthesis(n):
        # back track method (recursive)
        # Rules:
        # - 3 open, 3 close
        # - close < open
        # - only add open parenthesis if open < n
        # - only add a closing parenthesis if closed < open
        # - valid IIF open == closed == n
        
        stack = []
        res = []
        
        def backtrack(openN, closedN):
            if openN == closedN == n:
                res.append("".join(stack))
                return
            
            if openN < n:
                stack.append("(")
                backtrack(openN + 1, closedN)
                stack.pop()
                
            if closedN < openN:
                stack.append(")")
                backtrack(openN, closedN + 1)
                stack.pop()
        
        backtrack(0,0)
        return res
    
    # Example 1:

    n1 = 3
    # Output: ["((()))","(()())","(())()","()(())","()()()"]
    
    # Example 2:

    n2 = 1
    # Output: ["()"]
    
    print(generateParenthesis(n1))
    print(generateParenthesis(n2))
    
    