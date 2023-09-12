'''
You are going to write a virtual coin toss program. It will randomly tell the user "Heads" or "Tails".

Important, the first letter should be capitalised and spelt exactly like in the example e.g. Heads, not heads.

There are many ways of doing this. But to practice what we learnt in the last lesson, you should generate a random number, either 0 or 1. Then use that number to print out Heads or Tails.

e.g. 1 means Heads 0 means Tails
'''

#Remember to use the random module
#Hint: Remember to import the random module here at the top of the file. 🎲
	 
#Write the rest of your code below this line 👇

import random

class HeadsOrTails:
    def heads_or_tails(coin_flip_value):
        if coin_flip_value == 1:
            print("Heads")
        else:
            print("Tails")
        return None
    
    coin_flip_value = random.randint(0,1)
    heads_or_tails(coin_flip_value)