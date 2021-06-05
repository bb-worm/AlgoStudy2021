class P_1111:
    def __init__(self):
        self.N = int(input())
        self.nums = list(map(int, input().split()))

    def run(self):
        if self.N == 1:
            print('A')
            return
        elif self.N == 2:
            if self.nums[0] == self.nums[1]:
                print(self.nums[0])
            else:
                print('A')
            return

        a = None
        b = None
        diff1 = self.nums[1] - self.nums[0]
        diff2 = self.nums[2] - self.nums[1]
        if diff1 == 0:
            a = 0
        elif (diff2 % diff1 == 0):
            a = int(diff2 / diff1)
        
        if a is not None:
            b = self.nums[1] - self.nums[0]*a
            for i in range(1, self.N-1):
                if self.nums[i]*a + b != self.nums[i+1]:
                    print('B')
                    return
            print(self.nums[-1]*a + b)
        else:
            print('B')


if __name__ == "__main__":
    P = P_1111()
    P.run()