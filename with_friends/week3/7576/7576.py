import sys
from collections import deque

input = sys.stdin.readline

class P_7576:
    def __init__(self):
        self.total_zero_tomato = 0
        self.M, self.N = map(int, input().split())
        self.box = []
        for _ in range(self.N):
            row = list(map(int, input().split()))
            for t in row:
                if t == 0:
                    self.total_zero_tomato += 1
            self.box.append(row)

    def run(self):
        days = self.get_ripe_days()
        if self.zero_tomato_exist():
            print(-1)
        else:
            print(days)

    def get_ripe_days(self):
        # no zero tomato
        if self.total_zero_tomato == 0:
            return 0

        dr = [-1, 1, 0, 0]
        dc = [0, 0, -1, 1]
        
        days = -1
        q = deque()
        for r in range(self.N):
            for c in range(self.M):
                if self.box[r][c] == 1:
                    q.append((r,c))
        
        while q:
            size = len(q)
            days += 1
            for _ in range(size):
                r, c = q.popleft()
                for i in range(4):
                    nr = r + dr[i]
                    nc = c + dc[i]
                    if nr<0 or nr>=self.N or nc<0 or nc>=self.M:
                        continue
                    if self.box[nr][nc] != 0:
                        continue
                    self.box[nr][nc] = 1
                    q.append((nr, nc))
        return days


    def zero_tomato_exist(self):
        for row in self.box:
            if 0 in row:
                return True
        return False


if __name__ == "__main__":
    P = P_7576()
    P.run()