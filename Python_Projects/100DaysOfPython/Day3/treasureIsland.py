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
    
    print("Welcome to Treasure Island!")
    captain = input("What is your name, captain? ")
    treasureIsLand(captain)