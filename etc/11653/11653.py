class P_11654:
    def __init__(self):
        self.N = int(input())

    def run(self):
        if self.N == 1:
            return
        now = self.N
        while (now > 1):
            for i in range(2, self.N+1):
                if now % i == 0:
                    now /= i
                    print(i)
                    break


if __name__ == "__main__":
    P = P_11654()
    P.run()