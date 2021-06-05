import sys
input = sys.stdin.readline

class P_1009:
    def __init__(self):
        self.T = int(input())
        self.map = [
            [0, 0, 0, 0],
            [1, 1, 1, 1],
            [2, 4, 8, 6],
            [3, 9, 7, 1],
            [4, 6, 4, 6],
            [5, 5, 5, 5],
            [6, 6, 6, 6],
            [7, 9, 3, 1],
            [8, 4, 2, 6],
            [9, 1, 9, 1]
        ]
        """
        1 2 3 4 5 6
        -----------
        0 0 0 0 0 0
        1 1 1 1 1 1
        2 4 8 6 2 4
        3 9 7 1 3 9
        4 6 4 6 4 6
        5 5 5 5 5 5
        6 6 6 6 6 6
        7 9 3 1 7 9
        8 4 2 6 8 4
        9 1 9 1 9 1
        """

    def run(self):
        ans = []
        for _ in range(self.T):
            a, b = map(int, input().split())
            a %= 10
            last = self.map[a][(b-1)%4]
            if last == 0:
                ans.append('10')
            else:
                ans.append(str(last))
        print('\n'.join(ans))


if __name__ == "__main__":
    P = P_1009()
    P.run()