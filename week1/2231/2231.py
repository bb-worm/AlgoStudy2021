import sys
input = sys.stdin.readline

class Decomposition:
    def __init__(self):
        self.N = int(input())

    def run(self):
        start = max(1, self.N - len(str(self.N))*9)
        for i in range(start, self.N+1):
            if self.is_constructor(i):
                print(i)
                return
        print(0)

    def is_constructor(self, i):
        total = i + sum(list(map(int, str(i))))
        return total == self.N


if __name__=="__main__":
    d = Decomposition()
    d.run()