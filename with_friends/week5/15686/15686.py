import sys
input = sys.stdin.readline

class P_15686:
    def __init__(self):
        self.ans = sys.maxsize

        self.N, self.M = map(int, input().split())
        self.city = []
        self.home = []
        self.chicken = []
        for i in range(self.N):
            self.city.append(list(map(int, input().split())))
            for j in range(self.N):
                if self.city[i][j] == 1: # home
                    self.home.append((i, j))
                elif self.city[i][j] == 2: # chicken
                    self.chicken.append((i, j))
        self.open = [False for _ in range(len(self.chicken))]
    
    def run(self):
        self.dfs(0, 0)
        print(self.ans)

    def dfs(self, idx, select):
        if select == self.M:
            d = self.cal_chicken_distance()
            self.ans = min(self.ans, d)
            return

        if idx >= len(self.chicken):
            return
        
        self.open[idx] = True
        self.dfs(idx+1, select+1)
        self.open[idx] = False
        self.dfs(idx+1, select)
    
    def cal_chicken_distance(self):
        total_distance = 0
        for home in self.home:
            chicken_distance = sys.maxsize
            for idx, chicken in enumerate(self.chicken):
                if not self.open[idx]:
                    continue
                d = abs(home[0] - chicken[0]) + abs(home[1] - chicken[1])
                chicken_distance = min(chicken_distance, d)
            total_distance += chicken_distance
        return total_distance


if __name__ == "__main__":
    P = P_15686()
    P.run()