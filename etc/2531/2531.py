class PlaceStudent:
    def __init__(self):
        self.N = int(input())
        self.jumps = map(int, input().split())

    def run(self):
        student = [str(i+1) for i in range(self.N)]
        self.place(student)
        print(' '.join(student))

    def place(self, student):
        for i, jump in enumerate(self.jumps):
            self.swap(i, jump, student)

    def swap(self, i, jump, student):
        if jump == 0 or i == 0:
            return
        
        tmp = student[i-1]
        student[i-1] = student[i]
        student[i] = tmp

        self.swap(i-1, jump-1, student)


if __name__ == "__main__":
    PS = PlaceStudent()
    PS.run()