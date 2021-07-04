import sys
input = sys.stdin.readline

class P_14503:
    def __init__(self):
        self.N, self.M = map(int, input().split())
        self.r, self.c, self.d = map(int, input().split())
        self.board = []
        for _ in range(self.N):
            self.board.append(list(map(int, input().split())))

    def run(self):
        """
        self.d
        - 0: 북
        - 1: 동
        - 2: 남
        - 3: 서
        """
        dr = [-1, 0, 1, 0]
        dc = [0, 1, 0, -1]
        visit = [[0 for _ in range(self.M)] for _ in range(self.N)]

        visit[self.r][self.c] = 1
        total_clean = 1
        while True:
            # check space
            can_clean = False
            for _ in range(4):
                self.d = (self.d + 3) % 4
                nr = self.r + dr[self.d]
                nc = self.c + dc[self.d]
                if self.board[nr][nc] != 1 and visit[nr][nc] == 0:
                    can_clean = True
                    visit[nr][nc] = 1
                    total_clean += 1
                    self.r = nr
                    self.c = nc
                    break

            # if no space to clean
            if not can_clean:
                self.r += dr[(self.d + 2) % 4]
                self.c += dc[(self.d + 2) % 4]
                if self.board[self.r][self.c] == 1: # finish
                    break
        print(total_clean)


if __name__ == "__main__":
    P = P_14503()
    P.run()