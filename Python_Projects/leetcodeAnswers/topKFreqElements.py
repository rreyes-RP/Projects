'''
Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.
'''
class TopKFreqElements:
    def topKFreqElements(nums, k):
        # - input: array or numbers, target k most repeated values
        # - array contains a list of numbers with possibilies of repeating or being unique
        # - use hashMap, the length of the array starting at 0 to len(nums) - 1 will be the key while 
        # the values will contain a list of values in nums that represents the number of repeats based on the key
        # - output: array populated with the key of the hashMap with the top k most repeated values
        # O(n)
        
        count = {} # hashMap/dictionary used to count the occurrences of each value
        
        ##
        # special array will be the same size as the input, 
        # the index will be the frequency of the element (or count)
        # and the value is going to be a list of values that occur for that amount of time
        ##
        freq = [[] for i in range(len(nums) + 1)]

        ##
        # go through every value in nums
        # and count how many times it occurs
        ##
        for n in nums:
            count[n] = 1 + count.get(n, 0) # if n doesn't exist in our count dict, then put a default value of 0
        
        ##
        # going through each value we counted
        # return every key value pair
        ##
        for n, c in count.items():
            freq[c].append(n) # value n occurs c number of times
        
        res = []
        for i in range(len(freq) - 1, 0, -1):
            for n in freq[i]:
                res.append(n)
                if len(res) == k:
                    return res
    
    
    nums = [1,2,3,1,1,2,3,3,4,5,5,5,3,3,3,5,5,3]
    k = 2
    print(topKFreqElements(nums, k))