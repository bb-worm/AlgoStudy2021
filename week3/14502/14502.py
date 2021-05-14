from collections import deque
import sys
input = sys.stdin.readline

class P_14502:
    def __init__(self):
        self.q = deque()
        self.total_safe = 0

        self.N, self.M = map(int, input().split())
        self.map = []
        for i in range(self.N):
            self.map.append(list(map(int, input().split())))
            for j in range(self.M):
                if self.map[i][j] == 2:
                    self.q.append((i, j))
                elif self.map[i][j] == 0:
                    self.total_safe += 1

        self.ans = -1
        self.dr = [-1, 1, 0, 0]
        self.dc = [0, 0, -1, 1]

    def run(self):
        self.set_wall(0, 0, 0)
        print(self.ans)

    def set_wall(self, r, c, set_num):
        if set_num == 3:
            safe_zone = self.bfs()
            self.ans = max(self.ans, safe_zone)
            return

        if r >= self.N:
            return
        if c >= self.M:
            self.set_wall(r+1, 0, set_num)
            return

        if self.map[r][c] == 0:
            self.map[r][c] = 1
            self.set_wall(r, c+1, set_num+1)
            self.map[r][c] = 0
        self.set_wall(r, c+1, set_num)

    def bfs(self):
        q = self.q.copy()
        n_map = [self.map[i].copy() for i in range(self.N)]
        total_safe = self.total_safe - 3

        while q:
            r, c = q.popleft()
            for i in range(4):
                nr = r + self.dr[i]
                nc = c + self.dc[i]
                if nr<0 or nc<0 or nr>=self.N or nc>=self.M:
                    continue
                if n_map[nr][nc] != 0:
                    continue
                n_map[nr][nc] = 2
                q.append((nr, nc))
                total_safe -= 1
                if total_safe <= self.ans:
                    q.clear()
                    break
        return total_safe

if __name__ == "__main__":
    P = P_14502()
    P.run()