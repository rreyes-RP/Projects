print("Welcome to the rollercoaster!")
height = int(input("What is your height in cm? "))
bill = 0

if height > 120:
    print("You can ride the rollercoaster!")
    age = int(input("What is your age? "))
    if age < 12:
        bill = 5
        print("Child tickets are $5")
    elif age >= 12 and age < 18:
        bill = 18
        print("Youth tickets are $7")
    elif age >= 18 and age < 45:
        bill = 12
        print("Adult tickets are $12")
    elif age >= 45 and age<= 55:
        print("Mid life cisis folks are free!")
    
    wants_photo = input("Do you want a photo taken? Y or N. ")
    
    if wants_photo == "Y":
        # Add $3 to the bill
        bill += 3
    
    print(f"Your final bill is ${bill}. ")
    
else:
    print("You are not tall enough!")