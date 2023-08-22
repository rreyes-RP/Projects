# Data types: strings, integer, float, boolean

print("Hello"[0])
print("123" + "345") # this just concatenate the strings
print(type("Hello"))

# number data type or integers (int)
print(123 + 345)

# Decimal numbers: float
print(type(3.14159))

# Boolean: True or False
print(type(True))

# Type Error, Type checking, and Type conversion
num_char = len(input("What is your name? "))
print(type(num_char))
print("Your name has " + str(num_char) + " characters.")

print(70 + float("100.5"))