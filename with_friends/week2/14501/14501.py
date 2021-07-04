class P_14501:
    def __init__(self):
        self.N = int(input())
        self.schedule = [0 for _ in range(self.N)]
        for i in range(self.N):
            self.schedule[i] = tuple(map(int, input().split()))
        self.ans = 0
    
    def run(self):
        self.pick_schedule(0, 0)
        print(self.ans)

    def pick_schedule(self, idx, sum):
        self.ans = max(self.ans, sum)

        if idx >= self.N:
            return

        t = self.schedule[idx][0]
        p = self.schedule[idx][1]

        if idx+t <= self.N:
            self.pick_schedule(idx+t, sum+p) # pick
        if idx+1 <= self.N:
            self.pick_schedule(idx+1, sum) # unpick


if __name__ == "__main__":
    P = P_14501()
    P.run()