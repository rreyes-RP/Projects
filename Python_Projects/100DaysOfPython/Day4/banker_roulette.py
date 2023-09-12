'''
You are going to write a program that will select a random name from a list of names. The person selected will have to pay for everybody's food bill.

Important: You are not allowed to use the choice() function.

Line 8 splits the string names_string into individual names and puts them inside a List called names. For this to work, you must enter all the names as names followed by comma then space. e.g. name, name, name
'''
import random

class Banker_Roulette:
    def banker_roulette(friends):
        friend_to_pay = random.randint(0, len(friends) - 1)
        return friends[friend_to_pay]
        
    name_of_friends = input("Give me everybody's names, separated by a comma. \n")
    names = name_of_friends.split(", ")
    print(f"{banker_roulette(names)} is going to buy the meal today!")