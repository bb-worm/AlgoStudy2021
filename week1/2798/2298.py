import sys
input = sys.stdin.readline

class Blackjack:
    def __init__(self):
        self.N, self.M = map(int, input().split())
        self.cards = list(map(int, input().split()))
        self.ans = -1

    def run(self):
        self.pick_cards(0, 0, 0)
        print(self.ans)

    def pick_cards(self, idx, picked, sum):
        if picked == 3:
            if sum <= self.M:
                self.ans = max(self.ans, sum)
            return

        if idx >= self.N or sum >= self.M:
            return
        
        # pick now
        self.pick_cards(idx+1, picked+1, sum+self.cards[idx])

        # don't pick
        self.pick_cards(idx+1, picked, sum)


if __name__ == "__main__":
    B = Blackjack()
    B.run()