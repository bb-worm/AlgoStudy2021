import sys
input = sys.stdin.readline

from collections import deque

class Robot:
    def __init__(self, location):
        self.location = location

class P_20055:
    def __init__(self):
        self.N, self.K = map(int, input().split())
        self.duration = list(map(int, input().split()))
        self.robot_num = [0 for _ in range(self.N*2)]

        self.q = deque()

        self.total_empty = 0
    
    def run(self):
        stage = 0
        while self.total_empty < self.K:
            stage += 1

            #1 rotate
            self.rotate_belt()
            self.rotate_robot()

            #2 move robot
            self.move_robot()

            #3 raise robot
            self.raise_robot()

        print(stage)

    def rotate_belt(self):
        tmp_d = self.duration[-1]
        for i in reversed(range(self.N*2-1)):
            self.duration[i+1] = self.duration[i]
        self.duration[0] = tmp_d

    def rotate_robot(self):
        size = len(self.q)
        for _ in range(size):
            r = self.q.popleft()
            self.robot_num[r.location] -= 1
            next_loca = (r.location + 1) % (self.N * 2)
            if next_loca != self.N-1: # down
                r.location = next_loca
                self.robot_num[next_loca] += 1
                self.q.append(r)

    def move_robot(self):
        size = len(self.q)
        for _ in range(size):
            r = self.q.popleft()
            next_loca = (r.location+1)%(self.N*2)
            if self.robot_num[next_loca] == 0 and self.duration[next_loca] != 0:
                self.robot_num[r.location] -= 1
                r.location = next_loca
                self.duration[next_loca] -= 1
                self.robot_num[next_loca] += 1
                if self.duration[next_loca] == 0:
                    self.total_empty += 1

                if r.location == self.N-1: # down
                    self.robot_num[r.location] -= 1
                    continue
            self.q.append(r)

    def raise_robot(self):
        if self.duration[0] != 0:
            r = Robot(0)
            self.q.append(r)
            self.duration[0] -= 1
            self.robot_num[0] += 1
            if self.duration[0] == 0:
                self.total_empty += 1
    

if __name__ == "__main__":
    P = P_20055()
    P.run()