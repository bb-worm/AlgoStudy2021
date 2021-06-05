import sys
input = sys.stdin.readline

from collections import deque

class P_16235:
    def __init__(self):
        self.N, self.M, self.K = map(int, input().split())
        self.board = [[5 for _ in range(self.N)] for _ in range(self.N)]

        self.food = []
        for _ in range(self.N):
            self.food.append(list(map(int, input().split())))
            
        self.trees = [[deque() for _ in range(self.N)] for _ in range(self.N)]
        for _ in range(self.M):
            r, c, age = map(int, input().split())
            self.trees[r-1][c-1].append(age)

    def run(self):
        for _ in range(self.K):
            self.spring_summer()
            self.fall_winter()
        total_trees = self.get_total_trees()
        print(total_trees)
        # self.print_board()

    def spring_summer(self):
        for r in range(self.N):
            for c in range(self.N):
                # spring
                q = self.trees[r][c]
                size = len(q)
                dead_age = 0
                for _ in range(size):
                    age = q.popleft()
                    if self.board[r][c] >= age:
                        self.board[r][c] -= age
                        q.append(age + 1)
                    else:
                        dead_age += age // 2
                # summer
                self.board[r][c] += dead_age

    def fall_winter(self):
        dr = [-1, -1, -1, 0, 0, 1, 1, 1]
        dc = [-1, 0, 1, -1, 1, -1, 0, 1]
        for r in range(self.N):
            for c in range(self.N):
                # fall
                for age in self.trees[r][c]:
                    if age % 5 == 0:
                        for i in range(8):
                            nr = r + dr[i]
                            nc = c + dc[i]
                            if nr<0 or nc<0 or nr>=self.N or nc >= self.N:
                                continue
                            self.trees[nr][nc].appendleft(1)
                # winter
                self.board[r][c] += self.food[r][c]

    def get_total_trees(self):
        total_trees = 0
        for r in range(self.N):
            for c in range(self.N):
                total_trees += len(self.trees[r][c])
        return total_trees

    def print_board(self):
        for r in range(self.N):
            print(self.board[r])
            print(self.trees[r])


if __name__ == "__main__":
    P = P_16235()
    P.run()