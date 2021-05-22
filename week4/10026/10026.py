from collections import deque

class P_10026:
    def __init__(self):
        self.dr = [-1, 1, 0, 0]
        self.dc = [0, 0, -1, 1]

        self.N = int(input())
        self.pic = []
        for _ in range(self.N):
            self.pic.append(input())
            
    def run(self):
        area1 = self.get_area(False)
        area2 = self.get_area(True)
        print(area1, area2)

    def get_area(self, include_red_blue):
        total_area = 0
        visit = [[0 for _ in range(self.N)] for _ in range(self.N)]
        for i in range(self.N):
            for j in range(self.N):
                if visit[i][j] == 0:
                    self.bfs(i, j, visit, include_red_blue)
                    total_area += 1
        return total_area

    def bfs(self, i, j, visit, include_red_blue):
        base_color = self.pic[i][j]

        q = deque()
        q.append((i, j))
        visit[i][j] = 1
        while q:
            r, c = q.popleft()
            for k in range(4):
                nr = r + self.dr[k]
                nc = c + self.dc[k]
                if nr<0 or nc<0 or nr>=self.N or nc>=self.N or visit[nr][nc]==1:
                    continue

                next_color = self.pic[nr][nc]
                if base_color == next_color:
                    q.append((nr, nc))
                    visit[nr][nc] = 1
                elif include_red_blue:
                    if (base_color=='R' and next_color=='G') or (base_color=='G' and next_color=='R'):
                        q.append((nr, nc))
                        visit[nr][nc] = 1


if __name__ == "__main__":
    P = P_10026()
    P.run()