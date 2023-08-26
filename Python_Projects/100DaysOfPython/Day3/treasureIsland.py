## Treasure Island Game

class TreasureIsland:
    def treasureIsLand(name):
        print(f"Let's hunt for treasure, Captain {name}!")
        whichDirection = input("Should we go Left or Right? ")
        if whichDirection == "Left":
            swimOrWait = input("The boat is coming. Do you want to Swim across or Wait for the boat? ")
            if swimOrWait == "Wait":
                whichDoor = input("Which door color should we enter? Red, Yellow, or Blue? ")
                if whichDoor == "Yellow":
                    print(f"Captain {name}, you win!")
                elif whichDoor == "Red":
                    print(f"Captain {name} got burned by fire...")
                elif whichDoor == "Blue":
                    print(f"Captain {name} got eaten by beasts...")
                else:
                    print("Game over.")            
            else:
                print(f"Captain {name} got eaten by a shark... ")
        else:
            print(f"Captain {name} fell into a hole...")
        pass
    
    print('''
*******************************************************************************
          |                   |                  |                     |
 _________|________________.=""_;=.______________|_____________________|_______
|                   |  ,-"_,=""     `"=.|                  |
|___________________|__"=._o`"-._        `"=.______________|___________________
          |                `"=._o`"=._      _`"=._                     |
 _________|_____________________:=._o "=._."_.-="'"=.__________________|_______
|                   |    __.--" , ; `"=._o." ,-"""-._ ".   |
|___________________|_._"  ,. .` ` `` ,  `"-._"-._   ". '__|___________________
          |           |o`"=._` , "` `; .". ,  "-._"-._; ;              |
 _________|___________| ;`-.o`"=._; ." ` '`."\` . "-._ /_______________|_______
|                   | |o;    `"-.o`"=._``  '` " ,__.--o;   |
|___________________|_| ;     (#) `-.o `"=.`_.--"_o.-; ;___|___________________
____/______/______/___|o;._    "      `".o|o_.--"    ;o;____/______/______/____
/______/______/______/_"=._o--._        ; | ;        ; ;/______/______/______/_
____/______/______/______/__"=._o--._   ;o|o;     _._;o;____/______/______/____
/______/______/______/______/____"=._o._; | ;_.--"o.--"_/______/______/______/_
____/______/______/______/______/_____"=.o|o_.--""___/______/______/______/____
/______/______/______/______/______/______/______/______/______/______/[TomekK]
*******************************************************************************          
''')
    print("Welcome to Treasure Island!")
    captain = input("What is your name, captain? ")
    treasureIsLand(captain)