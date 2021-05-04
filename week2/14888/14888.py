class P_14888:
    def __init__(self):
        self.N = int(input())
        self.nums = list(map(int, input().split()))
        self.operator = list(map(int, input().split()))
        self.min_val = float('inf')
        self.max_val = float('-inf')

    def run(self):
        self.set_operator_and_find_ans(1, self.nums[0])
        print(self.max_val)
        print(self.min_val)

    def set_operator_and_find_ans(self, idx, result):
        if idx >= self.N:
            self.min_val = min(self.min_val, result)
            self.max_val = max(self.max_val, result)
            return

        for i in range(4):
            if self.operator[i] > 0:
                self.operator[i] -= 1
                next_result = self.cal(i, result, self.nums[idx])
                self.set_operator_and_find_ans(idx+1, next_result)
                self.operator[i] += 1
    
    def cal(self, operator_idx, A, B):
        if operator_idx == 0:
            return A+B
        elif operator_idx == 1:
            return A-B
        elif operator_idx == 2:
            return A*B
        else:
            if A >= 0:
                return A//B
            else:
                return ((-1*A)//B) * (-1)


if __name__=="__main__":
    P = P_14888()
    P.run()