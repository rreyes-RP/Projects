'''
lists: set of square brackets with items popylated in them
 - always starts with an open square bracket [, and ends with a closing square bracket ]
 - can store many pieces of related data
 - stored in an order
 - anytime you see square brackets, we're dealing with a list
 - to start with the last index, use -1, etc.
'''

us_states = ["Delaware", "Pennsylvania"]

us_states[1] = "Pencilvania"

us_states.append("Angelaland")

us_states.extend(["Rorieville", "Jeaninetown"])

print(us_states)