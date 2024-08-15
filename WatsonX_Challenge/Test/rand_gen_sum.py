import random

'''def is_even(n):                                                                                       
     return n % 2 == 0                                                                                 
                                                                                                       
def is_odd(n):                                                                                        
    return n % 2 != 0                                                                                 
                                                                                                       
def random_num1():                                                                                    
    return random.randint(1, 100)                                                                     
                                                                                                       
def random_num2():                                                                                    
    return random.randint(1, 100)                                                                     
                                                                                                       
def find_sum(num1, num2):                                                                             
    return num1 + num2                                                                                
                                                                                                       
num1 = random_num1()                                                                                  
num2 = random_num2()                                                                                  
                                                                                                       
is_odd_or_even = is_odd(num1) or is_even(num2)                                                        
                                                                                                       
if is_odd_or_even:                                                                                    
    print(f"The sum is {find_sum(num1, num2)} and it's odd")                                          
else:                                                                                                 
    print(f"The sum is {find_sum(num1, num2)} and it's even") '''
    
# Generate two random numbers
num1 = random.randint(1, 100)
num2 = random.randint(1, 100)

# Calculate the sum of the two numbers
sum_nums = num1 + num2

# Check if the sum is even or odd
if sum_nums % 2 == 0:
    print("The sum", sum_nums, "is even.")
else:
    print("The sum", sum_nums, "is odd.")