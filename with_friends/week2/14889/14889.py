import sys
input = sys.stdin.readline

class P_14889:
    def __init__(self):
        self.N = int(input())
        self.ability = []
        for _ in range(self.N):
            self.ability.append(list(map(int, input().split())))
        self.total = set(range(self.N))
        self.teamA = []
        self.ans = -1
    
    def run(self):
        self.set_team_and_find_ans(0, 0, self.N/2)
        print(self.ans)

    def set_team_and_find_ans(self, idx, set_num, limit):
        if set_num == limit:
            diff = self.get_team_diff()
            if self.ans == -1:
                self.ans = abs(diff)
            else:
                self.ans = min(self.ans, abs(diff))
            return

        if idx >= self.N or (self.N - idx)+set_num < limit:
            return
        
        # set idx's team to 1
        self.teamA.append(idx)
        self.set_team_and_find_ans(idx+1, set_num+1, limit)
        self.teamA.pop()

        # set idx's team to 0
        self.set_team_and_find_ans(idx+1, set_num, limit)

    def get_team_diff(self):
        teamA_sum = 0
        teamB_sum = 0

        teamB = list(self.total - set(self.teamA))
        for i in range(int(self.N/2)):
            for j in range(i+1, int(self.N/2)):
                teamA_sum += self.ability[self.teamA[i]][self.teamA[j]] + self.ability[self.teamA[j]][self.teamA[i]]
                teamB_sum += self.ability[teamB[i]][teamB[j]] + self.ability[teamB[j]][teamB[i]]
        return teamA_sum - teamB_sum


if __name__=="__main__":
    P = P_14889()
    P.run()