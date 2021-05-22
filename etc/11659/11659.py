import sys
input = sys.stdin.readline

class P_11659:
    def __init__(self):
        self.N, self.M = map(int, input().split())
        self.nums = list(map(int, input().split()))
        self.nums_acc = [0]
        for idx, num in enumerate(self.nums):
            self.nums_acc.append(self.nums_acc[idx] + num)

    def run(self):
        ans = []
        for _ in range(self.M):
            i, j = map(int, input().split())
            ans.append(str(self.nums_acc[j] - self.nums_acc[i-1]))
        print('\n'.join(ans))

if __name__ == "__main__":
    P = P_11659()
    P.run()