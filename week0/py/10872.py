
def run():
    N = int(input())
    factorial = get_factorial(N)
    print(factorial)

def get_factorial(num):
    if num == 0 or num == 1:
        return 1
    else:
        return num * get_factorial(num-1)

if __name__ == '__main__':
    run()