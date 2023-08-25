'''
I was reading this article by Tim Urban - Your Life in Weeks and realised just how little time we actually have.

https://waitbutwhy.com/2014/05/life-weeks.html

Create a program using maths and f-Strings that tells us how many days, weeks, months we have left if we live until 90 years old.

It will take your current age as the input and output a message with our time left in this format:

You have x days, y weeks, and z months left.

Where x, y and z are replaced with the actual calculated numbers.

Warning your output should match the Example Output format exactly, even the positions of the commas and full stops.
'''

# 🚨 Don't change the code below 👇
age = input("What is your current age? ")
# 🚨 Don't change the code above 👆

#Write your code below this line 👇
# Find the difference in years from current age
ageDiff = 90 - int(age)

# Find number of days left using ageDiff
days = ageDiff * 365

# Find number of weeks left using ageDiff
weeks = ageDiff * 52

# Find number of months left using ageDiff
months = ageDiff * 12

print(f"You have {days} days, {weeks} weeks, and {months} months left")