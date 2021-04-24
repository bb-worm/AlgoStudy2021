import sys
input = sys.stdin.readline

def run():
    N, d, k, c = map(int, input().split())
    chobab = [int(input()) for _ in range(N)]

    now_eat = [0 for _ in range(d + 1)]
    now_eat[c] = 1

    ans = 1
    cnt = 1
    
    # init
    for i in range(k):
        now_eat[chobab[i]] += 1
        if now_eat[chobab[i]] == 1:
            cnt += 1

    ans = cnt

    for i in range(0, N):
        # left
        now_eat[chobab[i]] -= 1
        if now_eat[chobab[i]] == 0:
                cnt -= 1
        
        # right
        now_eat[chobab[(i+k) % N]] += 1
        if now_eat[chobab[(i+k) % N]] == 1:
            cnt += 1

        ans = max(ans, cnt)

    print (ans)


if __name__ == "__main__":
    run()