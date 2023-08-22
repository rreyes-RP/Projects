print(round(8/3, 2)) # rounding, 8/3,2 -> we round the answer to 2 decimal places
print(type(8 // 3)) # Floor division, rounds down to no decimals, this is an integer

# Performing math with variables
result = 4 / 2
result /= 2
print(result)

score = 0

# User scores a point
score += 1
print(score)

# to manipulate a value from it's previous value
# +=, -=, *=, /=

# f-strings
# mix strings and different data types
height = 1.8
isWinning = True
print(f"Your score is {score}, your height is {height}, you are winning is {isWinning}")