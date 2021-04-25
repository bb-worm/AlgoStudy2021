import sys
input = sys.stdin.readline

class Blackjack:
    def __init__(self):
        self.N, self.M = map(int, input().split())
        self.cards = list(map(int, input().split()))
        self.ans = -1

    def run(self):
        self.get_max()
        print (self.ans)

    def get_max(self):
        for i in range(self.N):
            for j in range(i+1, self.N):
                for k in range(j+1, self.N):
                    s = self.cards[i] + self.cards[j] + self.cards[k]
                    if s <= self.M and s > self.ans:
                        self.ans = s
                        if self.ans == self.M:
                            return
                        


if __name__ == "__main__":
    B = Blackjack()
    B.run()