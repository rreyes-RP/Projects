
# Welcome message
print("Welcome to the tip calculator app.")
# User gets prompt with total bill. Make sure to include the dollar sign as part of the prompt. If cents will be added use two decimals places. 
bill = input("What was the total bill? $")
# User is asked how much to tip: 18, 20, 22. Make sure to divide by 100 for the percentage
tip = input("What percentage tip would you like to give? 18, 20, or 22? ")
# User is asked how many people are splitting the bill based on the total + tip
split = input("How many people to split the bill? ")
# Split the total + tip with the number of people in the group
# Note: keep the cents to 2 decimal places
totalBill = float(bill) + (float(bill) * (int(tip)/100))
splitTotal = round(totalBill / int(split),2)

print(f"Each person should pay: ${splitTotal}")


