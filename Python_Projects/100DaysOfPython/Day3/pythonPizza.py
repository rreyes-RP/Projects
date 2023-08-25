'''
Python Pizza
Congratulations, you've got a job at Python Pizza. Your first job is to build an automatic pizza order program.

Based on a user's order, work out their final bill.

Small Pizza: $15

Medium Pizza: $20

Large Pizza: $25

Pepperoni for Small Pizza: +$2

Pepperoni for Medium or Large Pizza: +$3

Extra cheese for any size pizza: + $1
'''

def pythonPizza(size, pep, cheese):
    bill = 0
    
    if size == "S":
        bill = 15
    elif size == "M":
        bill = 20
    elif size == "L":
        bill = 25
    
    if pep == "Y" and size == "S":
        bill += 2
    elif pep == "Y" and size == "M" or pep == "Y" and size == "L":
        bill += 3
    
    if cheese == "Y":
        bill += 1
        return bill
    return bill

print("Welcome to Python Pizza Deliveries!")
size = input("What size pizza do you want? S, M, or L: ")
add_pepperoni = input("Do you want pepperoni? Y or N: ")
extra_cheese = input("Do you want extra cheese? Y or N: ")

print(pythonPizza(size, add_pepperoni, extra_cheese))
    