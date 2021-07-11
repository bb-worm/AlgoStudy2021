import sys
input = sys.stdin.readline

class Dungch:
    def __init__(self):
        self.N = int(input())
        self.dungches = []
        for _ in range(self.N):
            h, w = map(int, input().split())
            self.dungches.append((h, w))

    def run(self):
        bigger_nums = self.get_bigger_nums()
        print (' '.join(bigger_nums))
    
    def get_bigger_nums(self):
        bigger_nums = [1 for _ in range(self.N)]
        for i in range(self.N):
            for j in range(i+1, self.N):
                i_h, i_w = self.dungches[i]
                j_h, j_w = self.dungches[j]
                if i_h > j_h and i_w > j_w:
                    bigger_nums[j] += 1
                elif i_h < j_h and i_w < j_w:
                    bigger_nums[i] += 1
        return [str(i) for i in bigger_nums]


if __name__ == "__main__":
    D = Dungch()
    D.run()