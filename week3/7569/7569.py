import sys
input = sys.stdin.readline

from collections import deque

class Tomato:
    def __init__(self, h, n, m):
        self.h = h
        self.n = n
        self.m = m

class P_7569:
    def __init__(self):
        self.q = deque()
        self.total_not_raped = 0
        self.M, self.N, self.H = map(int, input().split())
        self.box = [[] for _ in range(self.H)]
        for h in range(self.H):
            for n in range(self.N):
                self.box[h].append(list(map(int, input().split())))
                for m in range(self.M):
                    if self.box[h][n][m] == 0:
                        self.total_not_raped += 1
                    elif self.box[h][n][m] == 1:
                        self.q.append(Tomato(h, n, m))

    def run(self):
        days = self.bfs()
        if self.is_all_raped():
            print(days)
        else:
            print(-1)

    def bfs(self):
        dh = [-1, 1, 0, 0, 0, 0]
        dn = [0, 0, -1, 1, 0, 0]
        dm = [0, 0, 0, 0, -1, 1]

        days = -1
        while self.q:
            days += 1
            size = len(self.q)
            for _ in range(size):
                now = self.q.popleft()
                for i in range(6):
                    nh = dh[i] + now.h
                    nn = dn[i] + now.n
                    nm = dm[i] + now.m
                    if nh<0 or nn<0 or nm<0 or nh>=self.H or nn>=self.N or nm>=self.M:
                        continue
                    if self.box[nh][nn][nm] != 0:
                        continue
                    self.q.append(Tomato(nh, nn, nm))
                    self.box[nh][nn][nm] = 1
                    self.total_not_raped -= 1
        return days

    def is_all_raped(self):
        if self.total_not_raped == 0:
            return True
        else:
            return False

if __name__ == "__main__":
    P = P_7569()
    P.run()