class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        # first implementation
        myArray = [0] * len(nums)
        read = 0
        write = k % len(nums)
        while(read < len(nums)):
            # begin
            # loop
            myArray[write] = nums[read]
            # end
            read += 1
            write += 1
            if(write == len(nums)):
                write = 0
            
        for i in range(0, len(myArray)):
            nums[i] = myArray[i]
        return
 
        '''
        _k = k % len(nums)

        for i in range(0, len(nums)):
            nums[i] = 0
        # skip method (0(1) in place)
        head = 0
        cap = math.ceil(len(nums)/_k)
        while(head < cap):
            # begin
            # loop
            i = 1
            read = head
            write = read
            temp = None
            while(i < math.ceil(len(nums) / _k)):
                # begin

                write = (write + k) % len(nums)
                # loop
                print(read, " to ", write, end = ' ')
                nums[write] += 1
                # end
                read += k
                read %= len(nums)
                i += 1
            print()
            # end
            head += 1
        return
        '''
