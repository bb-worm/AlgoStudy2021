from collections import deque

class P_4963:
    def __init__(self):
        self.w = None
        self.h = None
        self.map = None
        self.visit = None
        self.dr = [-1, 1, 0, 0, -1, -1, 1, 1]
        self.dc = [0, 0, -1, 1, -1, 1, -1, 1]

    def run(self):
        ans = []
        while (True):
            self.w, self.h = map(int, input().split())
            if self.w + self.h == 0:
                break
            self.map = self.get_map()
            self.visit = [[0 for _ in range(self.w)] for _ in range(self.h)]
            island_num = self.get_island_num()
            ans.append(str(island_num))
        print('\n'.join(ans))
            
    def get_map(self):
        m = []
        for _ in range(self.h):
            m.append(list(map(int, input().split())))
        return m

    def get_island_num(self):
        island_num = 0
        for r in range(self.h):
            for c in range(self.w):
                if self.map[r][c] == 1 and self.visit[r][c] == 0:
                    island_num += 1
                    self.bfs(r, c)
        return island_num

    def bfs(self, i, j):
        q = deque()
        q.append((i, j))
        self.visit[i][j] = 1

        while q:
            r, c = q.popleft()
            for k in range(8):
                nr = r + self.dr[k]
                nc = c + self.dc[k]
                if nr<0 or nc<0 or nr>=self.h or nc>=self.w:
                    continue
                if self.map[nr][nc] == 0 or self.visit[nr][nc] == 1:
                    continue
                q.append((nr, nc))
                self.visit[nr][nc] = 1


if __name__ == "__main__":
    P = P_4963()
    P.run()