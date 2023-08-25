class OddOrEven:
    def oddOrEven(num):
        ans = num % 2
        odd = "This is an odd number."
        even = "This is an even number."
        if ans == 0:
            return even
        else:
            return odd 
    
    num = int(input("Give me a number: "))
    print(oddOrEven(num))        
    