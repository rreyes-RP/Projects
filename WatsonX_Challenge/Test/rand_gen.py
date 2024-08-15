import random

def is_odd(num):
    return num % 2 == 1

num = random.randint(1, 100)

if is_odd(num):
    print("the number", num, "is odd.")
else:
    print("The number", num, "is even.")