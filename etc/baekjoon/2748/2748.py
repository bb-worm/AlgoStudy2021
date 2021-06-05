class P_2748:
    def __init__(self):
        self.N = int(input())
        self.fibo = {}

    def run(self):
        ans = self.get_fibo(self.N)
        print(ans)

    def get_fibo(self, n):
        if n == 0 or n == 1:
            return n
        elif n in self.fibo:
            return self.fibo[n]

        self.fibo[n] = self.get_fibo(n-1) + self.get_fibo(n-2)
        return self.fibo[n]


if __name__ == "__main__":
    P = P_2748()
    P.run()