from collections import deque


class P_16236:
    def __init__(self):
        self.N = int(input())
        self.ocean = []
        for i in range(self.N):
            self.ocean.append(list(map(int, input().split())))
            for j in range(self.N):
                if self.ocean[i][j] == 9:
                    self.start = (i, j)
                    self.ocean[i][j] = 0
        self.visit = [[0 for _ in range(self.N)] for _ in range(self.N)]
    
    def run(self):
        max_time = self.bfs()
        print(max_time)
    
    def bfs(self):
        max_time = 0

        dr = [-1, 0, 0, 1]
        dc = [0, -1, 1, 0]
        q = deque()

        q.append((self.start[0], self.start[1]))
        self.visit[self.start[0]][self.start[1]] = 1

        time = 0
        size = 2
        eat_num = 0
        while q:
            time += 1
            iter_size = len(q)
            eaten_fish = None
            for _ in range(iter_size):
                r, c = q.popleft()
                for k in range(4):
                    nr = r + dr[k]
                    nc = c + dc[k]
                    if nr<0 or nc<0 or nr>=self.N or nc>=self.N:
                        continue
                    if self.visit[nr][nc] == 1 or self.ocean[nr][nc] > size:
                        continue
                    if self.ocean[nr][nc] != 0 and self.ocean[nr][nc] < size: # eat fish
                        if eaten_fish is None:
                            eaten_fish = (nr, nc)
                        elif eaten_fish[0]>nr or (eaten_fish[0]==nr and eaten_fish[1]>nc):
                            eaten_fish = (nr, nc)
                        continue
                    q.append((nr, nc))
                    self.visit[nr][nc] = 1
            if eaten_fish is not None: # start from new point
                max_time = max(max_time, time)
                r, c = eaten_fish
                self.ocean[r][c] = 0
                self.visit = [[0 for _ in range(self.N)] for _ in range(self.N)]
                self.visit[r][c] = 1
                q.clear()
                q.append((r, c))
                eat_num += 1
                if eat_num == size:
                    size += 1
                    eat_num = 0
            
        return max_time

if __name__ == "__main__":
    P = P_16236()
    P.run()