#include <iostream>
#include <vector>
#include <queue>

using namespace std;


int N, M;
vector<vector<char>> board(1000, vector<char>(1000));
vector<vector<int>> visit(1000, vector<int>(1000, 0));

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

int get_dir(char dir) {
    if (dir == 'N')
        return 0;
    else if (dir == 'S')
        return 1;
    else if (dir == 'W')
        return 2;
    else
        return 3;
}

int dfs(int y, int x, int num) {
    if (y < 0 || y >= N || x < 0 || x >= M) // out of range
        return 1;
    if (visit[y][x] != 0) { // visited
        if (visit[y][x] == num) // same dfs visit
            return 1;
        else // diff dfs visit
            return 0;
    }
    visit[y][x] = num;

    int dir = get_dir(board[y][x]);
    int ny = y + dy[dir];
    int nx = x + dx[dir];
    return dfs(ny, nx, num);
}

// 처음 dfs 들어가는 곳이 시작점이 아닐 수도 있다는 걸 생각 못해서 틀렸음
// dfs 하다가 이전 단계에서 방문했던 곳을 만나면 다른 시작점을 발견했다는 의미
int main() {
    cin >> N >> M;

    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            cin >> board[i][j];
        }
    }

    int ans = 0;
    int num = 1;
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            if (visit[i][j])
                continue;
            ans += dfs(i, j, num);
            num++;
        }
    }

    cout << ans << endl;
}