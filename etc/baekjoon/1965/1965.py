# TBW

import sys

class P_1965:
    def __init__(self):
        self.N = int(input())
        self.boxes = list(map(int, input().split()))
        self.dp = [0 for _ in range(self.N)]

    def run(self):
        ans = self.dfs(0, 0)
        print(ans)
        print(self.dp)

    def dfs(self, idx, pre_size):
        if idx >= self.N:
            return 0

        if self.dp[idx] != 0:
            return self.dp[idx]
        
        if pre_size < self.boxes[idx]:
            self.dp[idx] = self.dfs(idx+1, self.boxes[idx]) + 1
        elif pre_size > self.boxes[idx]:
            self.dfs(idx+1, self.boxes[idx])
        M = max(M, self.dfs(idx+1, pre_size))

        return M


if __name__ == "__main__":
    sys.setrecursionlimit(2000)
    P = P_1965()
    P.run()