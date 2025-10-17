# George Hu 10/17
# O 1 time complexity
# N: using map(base struct) with array(for getRandom functionality)
# array is imperative for logical operations, but I contains no O1time removal by itself
# array needs dedicated mapping, mapped indexing, then swapping with last index
# to finally chop of with O1time complexity on all cases
class RandomizedSet:
    def __init__(self):

        self.arr = []
        self.map = {}

    def insert(self, val: int) -> bool:
        if(val not in self.map):

            self.arr.append(val)
            self.map[val] = len(self.arr)-1

            return True
        else:
            return False

    def remove(self, val: int) -> bool:
        if(val in self.map):
            # Remove from arr (need map)
            self.arr[self.map[val]] = self.arr[-1]
            self.map[self.arr[-1]] = self.map[val]
            del self.arr[-1]# del end-ONLY O(1)
            del self.map[val]
            return True
        else:
            return False

    def getRandom(self) -> int:
        # has index, needs value for it
        '''
        print(self.map, end = ' ')
        print(self.arr)
        print(self.mySet)
        '''
        randy = random.randint(0, len(self.arr)-1)
        return self.arr[randy]


# Your RandomizedSet object will be instantiated and called as such:
# obj = RandomizedSet()
# param_1 = obj.insert(val)
# param_2 = obj.remove(val)
# param_3 = obj.getRandom()
