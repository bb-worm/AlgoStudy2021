import sys
input = sys.stdin.readline

from collections import deque

class P_3190:
    def __init__(self):
        self.q = deque()
        """
        self.board
        - 0: empty
        - 1: snake
        - 2: apple

        self.dir
        - up: 0
        - right: 1
        - down: 2
        - left:3
        """
        self.N = int(input())
        self.board = [[0 for _ in range(self.N)] for _ in range(self.N)]
        self.board[0][0] = 1
        self.q.append((0, 0))
        self.dir = 1

        self.K = int(input())
        for _ in range(self.K):
            r, c = map(int, input().split())
            self.board[r-1][c-1] = 2

        self.L = int(input())
        self.change_dir = []
        for _ in range(self.L):
            t, d = input().split()
            self.change_dir.append((int(t), d))
    
    def run(self):
        time = 0
        r, c = 0, 0
        dr = [-1, 0, 1, 0]
        dc = [0, 1, 0, -1]
        dir_idx = 0
        while True:
            time += 1

            # move snake
            r += dr[self.dir]
            c += dc[self.dir]
            self.q.append((r, c))
            if r<0 or c<0 or r>=self.N or c>=self.N or self.board[r][c] == 1:
                break
            if self.board[r][c] == 0: # empty
                remove_r, remove_c = self.q.popleft()
                self.board[remove_r][remove_c] = 0
            self.board[r][c] = 1

            # check direction
            if dir_idx < self.L and self.change_dir[dir_idx][0] == time:
                if self.change_dir[dir_idx][1] == 'L':
                    self.dir = (self.dir + 3) % 4
                else:
                    self.dir = (self.dir + 1) % 4
                dir_idx += 1
        print(time)

    def print_board(self):
        for r in range(self.N):
            print(self.board[r])
        print()

if __name__ == "__main__":
    P = P_3190()
    P.run()