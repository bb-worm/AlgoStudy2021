class Gear:
    def __init__(self, gear):
        self.gear = gear
        self.topidx = 0
        
    def rotate_clockwise(self):
        self.topidx = (self.topidx + 7) % 8

    def rotate_counterclockwise(self):
        self.topidx = (self.topidx + 1) % 8

    def get_top(self):
        return int(self.gear[self.topidx])

    def get_left(self):
        return int(self.gear[(self.topidx + 6) % 8])
        
    def get_right(self):
        return int(self.gear[(self.topidx + 2) % 8])

class P_14891:
    def __init__(self):
        self.gears = []
        for _ in range(4):
            self.gears.append(Gear(input()))
        self.K = int(input())
        self.opers = []
        for _ in range(self.K):
            n, d = map(int, input().split())
            self.opers.append((n-1, d))

    def run(self):
        for n, d in self.opers:
            rotate = [0, 0, 0, 0]
            rotate[n] = d
            for left in reversed(range(n)):
                if self.gears[left].get_right() == self.gears[left+1].get_left():
                    break
                rotate[left] = rotate[left + 1] * -1
            for right in range(n+1, 4):
                if self.gears[right].get_left() == self.gears[right-1].get_right():
                    break
                rotate[right] = rotate[right - 1] * -1
            self.rotate_all(rotate)
        ans = self.cal_score()
        print(ans)

    def rotate_all(self, rotate):
        for idx, dir in enumerate(rotate):
            if dir == 1:
                self.gears[idx].rotate_clockwise()
            elif dir == -1:
                self.gears[idx].rotate_counterclockwise()
    
    def cal_score(self):
        total_score = 0
        for i in range(4):
            total_score += pow(2, i) * self.gears[i].get_top()
        return total_score


if __name__ == "__main__":
    P = P_14891()
    P.run()