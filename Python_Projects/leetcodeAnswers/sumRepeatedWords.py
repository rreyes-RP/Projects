paragraph = "The Sun is the star at the center of the Solar System. It is a nearly perfect sphere of hot plasma, with internal convective motion that generates a magnetic field via a dynamo process. It is, by far, the most important source of energy for life on Earth."

paragraph = paragraph.replace(',','').lower()

# hence number of repetitions is 4+2+2+1+2 = 11

# convert paragraph string to an array for each words
paraArr = paragraph.split(" ")
# use a hashmap, each word will be the key in the dictionary, value will be count for each word: i.e {"is": 3}
paraHash = {}
for i, n in enumerate(paraArr): # i = index, n = word
    if n in paraHash: # check if n is in paraHash, if it is update the value by adding to the count
        paraHash[n] += 1
    else:
        paraHash[n] = 1 # input n as a key in paraHash if it doesn't exist

# grab all key : values that are greater than 1 from the paraHash
sum = 0
for count in paraHash.values():
    if count > 1:
        sum += count - 1
# take each value and subtract by 1 in order to represent how many times it was repeated
# find the sum for all repeated words
print(sum)