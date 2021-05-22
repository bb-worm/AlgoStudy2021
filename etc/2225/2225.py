class P_2225:
    def __init__(self):
        self.N, self.K = map(int, input().split())
        self.mod = 10**9

    def run(self):
        dp = [[0 for _ in range(self.K+1)] for _ in range(self.N+1)]

        # init first row & col
        for row in range(self.N + 1):
            dp[row][1] = 1
        for col in range(self.K + 1):
            dp[0][col] = 1

        # calualte dp
        for row in range(1, self.N+1):
            for col in range(2, self.K+1):
                dp[row][col] = (dp[row-1][col] + dp[row][col-1]) % self.mod

        # answer
        print(dp[self.N][self.K])


if __name__ == '__main__':
    P = P_2225()
    P.run()