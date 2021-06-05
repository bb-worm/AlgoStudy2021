class P_2846:
    def __init__(self):
        self.N = int(input())
        self.nums = list(map(int, input().split()))

    def run(self):
        ans = 0

        start_idx = 0
        for idx in range(1, self.N):
            if self.nums[idx] <= self.nums[idx-1]:
                ans = max(ans, self.nums[idx-1] - self.nums[start_idx])
                start_idx = idx
            elif idx == self.N-1:
                ans = max(ans, self.nums[idx] - self.nums[start_idx])

        print(ans)


if __name__ == "__main__":
    P = P_2846()
    P.run()