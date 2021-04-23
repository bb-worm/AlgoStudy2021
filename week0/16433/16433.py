def run():
    N, R, C = map(int, input().split())
    
    farm = [['.' for _ in range(N)] for _ in range(N)]

    R -= 1
    C -= 1
    make_farm(farm, R, C%2, True) # up
    make_farm(farm, R+1, (C+1)%2, False) # down

    for row in farm:
        print(''.join(row))

def make_farm(farm, r, c, is_upper):
    if r < 0 or r >= len(farm):
        return

    while c < len(farm):
        farm[r][c] = 'v'
        c += 2
    
    if is_upper:
        make_farm(farm, r-1, (c+1) % 2, is_upper)
    else:
        make_farm(farm, r+1, (c+1) % 2, is_upper)


if __name__ == '__main__':
    run()