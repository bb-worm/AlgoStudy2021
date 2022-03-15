#include <iostream>
#include <vector>
#include <queue>

using namespace std;


int N, M;
vector<vector<int>> board(300, vector<int>(300));

queue<pair<int, int>> q;

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

void print_board(vector<vector<int>> tmp) {
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            cout << tmp[i][j] << " ";
        }cout << endl;
    }cout << endl;
    cout << endl;
}

bool is_valid_range(int y, int x) {
    if (y < 0 || y >= N || x < 0 || x >= M)
        return false;
    return true;
}

bool is_split(vector<vector<int>>& tmp_board) {
    if (q.empty())
        return false;

    int y = q.front().first;
    int x = q.front().second;
    queue<pair<int, int>> bfs_q;
    vector<vector<bool>> visit(N, vector<bool>(M, false));
    bfs_q.push({y, x});
    visit[y][x] = true;

    int visited_ice = 0;
    while (!bfs_q.empty()) {
        visited_ice++;

        y = bfs_q.front().first;
        x = bfs_q.front().second;
        bfs_q.pop();

        int ny, nx;
        for (int i=0; i<4; i++) {
            ny = y + dy[i];
            nx = x + dx[i];
            if (!is_valid_range(ny, nx) || visit[ny][nx] || tmp_board[ny][nx] == 0)
                continue;
            bfs_q.push({ny, nx});
            visit[ny][nx] = true;
        }
    }
    
    if (visited_ice == q.size())
        return false;
    return true;
}

int find_zero_num(int y, int x) {
    int zero_num = 0;

    int ny, nx;
    for (int i=0; i<4; i++) {
        ny = y + dy[i];
        nx = x + dx[i];
        if (!is_valid_range(ny, nx) || board[ny][nx] != 0)
            continue;
        zero_num++;
    }
    return zero_num;
}

int run() {
    int time = 0;
    auto tmp_board = board;

    int size, y, x, zero_num;
    while (true) {
        time++;
        size = q.size();

        // no ice
        if (size == 0) {
            time = 0;
            break;
        }
            
        for (int i=0; i<size; i++) {
            y = q.front().first;
            x = q.front().second;
            q.pop();
            
            zero_num = find_zero_num(y, x);
            
            // 다 녹으면 0을 넣고, 아니면 다시 q에 push
            tmp_board[y][x] -= zero_num;
            if (tmp_board[y][x] <= 0)
                tmp_board[y][x] = 0;
            else
                q.push({y, x});
        }

        if (is_split(tmp_board)) {
            break;
        }

        board = tmp_board;
    }
    return time;
}

int main() {
    cin >> N >> M;
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            cin >> board[i][j];
            if (board[i][j] != 0)
                q.push({i, j});
        }
    }

    int ans = run();
    cout << ans << endl;
}